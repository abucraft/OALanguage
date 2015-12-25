#include"generate.h"
static std::string result;
extern struct ParseTree *parseTree;
static int lineno;
static bool compilePass = true;
static std::string compileLog = "";
//Added by @Xie LW----------------------
static int temVarNo;

std::vector<struct OaVar*>allVars;
const std::string endLine = "\n";

int OaIfIdx = 0;
int OaCmpIdx = 0;
int OaWhileIdx = 0;

//作用域的栈
std::list<std::string> oaPathStk;
std::list<std::string> endLbStk;

//内建数组的length
const char array_length[] = ".length";

std::map<std::string, OaFunction> oaFunctions;
std::map<std::string, OaClass> oaClasses;

OaClass classNow;
std::string classNameNow = "";
bool inClassMethod = false;
std::string methodClassNameNow = "";
bool inGlobal = true;
int classMemberIndex;
bool hasPrint = false;
bool hasMalloc = false;
bool hasFree = false;
int printStringIndex = 0;
std::vector<std::string> printStrings;
std::vector<std::string> globalVariables;

//---------------------tree node part---------------------
void g_parseNodeList(std::string& result, TreeNode* seg, std::string name) {
	while (seg != NULL) {
		g_parseTreeNode(result, seg);
		if (!compilePass) return;
		seg = seg->next;
	}
}

void g_parseTreeNode(std::string& result, TreeNode* seg) {
	if (seg == NULL) {
		return;
	}
	lineno = seg->lineno;
	switch (seg->type) {
	case VAR_DECLARE_NODE:
		g_parseVarDeclareNode(result, seg->varDeclareNode);
		break;
	case VAR_DEFINE_NODE:
		g_parseVarDefineNode(result, seg->varDefineNode);
		break;
	case VAR_ASSIGN_NODE:
		g_parseVarAssignNode(result, seg->varAssignNode);
		break;
	case ARRAY_DECLARE_NODE:
		g_parseArrayDeclareNode(result, seg->arrayDeclareNode);
		break;
	case ARRAY_DEFINE_NODE:
		g_parseArrayDefineNode(result, seg->arrayDefineNode);
		break;
	case ARRAY_ASSIGN_NODE:
		g_parseArrayAssignNode(result, seg->arrayAssignNode);
		break;
	case IF_NODE:
		g_parseIfNode(result, seg->ifNode);
		break;
	case ELIF_NODE:
		g_parseElifNode(result, seg->elifNode);
		break;
	case ELSE_NODE:
		g_parseElseNode(result, seg->elseNode);
		break;
	case WHILE_NODE:
		g_parseWhileNode(result, seg->whileNode);
		break;
	case FOREACH_NODE:
		g_parseForeachNode(result, seg->foreachNode);
		break;
	case CLASS_DEFINE_NODE:
		inGlobal = false;
		g_parseClassDefineNode(result, seg->classDefineNode);
		inGlobal = true;
		break;
	case FUNCTION_DECLARE_NODE:
		inGlobal = false;
		g_parseFunctionDeclareNode(result, seg->functionDeclareNode);
		inGlobal = true;
		break;
	case FUNCTION_DEFINE_NODE:
		inGlobal = false;
		g_parseFunctionDefineNode(result, seg->functionDefineNode);
		inGlobal = true;
		break;
	case CLASS_METHOD_DEFINE_NODE:
		inGlobal = false;
		g_parseClassMethodDefineNode(result, seg->classMethodDefineNode);
		inGlobal = true;
		break;
	case BREAK_NODE:
		g_parseBreakNode(result);
		break;
	case CONTINUE_NODE:
		g_parseContinueNode(result);
		break;
	case RETURN_NODE:
		g_parseReturnNode(result, seg->returnNode);
		break;
	default:
		break;
	}
}

void g_parseVarDeclareNode(std::string& result, struct VarDeclareNode* seg) {
	if (seg == NULL) {
		return;
	}
	//Modified by @Xie LW--------------------------------------
	struct OaVar *temVar = new struct OaVar;
	if (getVar("%" + reduceAt(std::string(seg->name))) != NULL) {
		panic("Already Declared Identifier");
		return;
	}
	if (inGlobal) {
		temVar->name = "@" + reduceAt(std::string(seg->name));
	}
	else if(oaPathStk.size() != 0){
		temVar->name = "%";
		for (std::list<std::string>::iterator iter = oaPathStk.begin(); iter != oaPathStk.end(); ++iter) {
			temVar->name += *iter + ".";
		}
		temVar->name += reduceAt(std::string(seg->name));
	}
	else {
		temVar->name = "%" + reduceAt(std::string(seg->name));
	}
	temVar->align = 0;
	if (seg->type == std::string("int")) {
		temVar->type = "i32";
		temVar->align = 4;
	}
	else if (seg->type == std::string("char")) {
		temVar->type = "i8";
		temVar->align = 1;
	}
	else if (seg->type == std::string("double")) {
		temVar->type = "double";
		temVar->align = 8;
	}
	else if (seg->type[0] == '#') {
		//class object declare
		temVar->type = std::string(seg->type);
		std::map<std::string, OaClass>::iterator iter = oaClasses.find(temVar->type.substr(1));
		if (iter == oaClasses.end()) {
			panic("in varDeclare Node, no such class");
			return;
		}
		temVar->align = iter->second.align;
	}
	else {
		panic("error in varDeclareNode: type error");
		return;
	}

	if (inGlobal) {
		addVar(temVar);
		std::string tmpStr;
		if (temVar->type == "i32") {
			tmpStr = temVar->name + " = common global i32 0, align 4\n";
		}
		else if (temVar->type == "double") {
			tmpStr = temVar->name + " = common global double 0.000000e+00, align 8\n";
		}
		else if (temVar->type == "i8") {
			tmpStr = temVar->name + " = common global i8 0, align 1\n";
		}
		else {
			//[TODO] wrong type
		}
		globalVariables.push_back(tmpStr);
	}
	else if (classNameNow != "") {
		result += temVar->type;
		result += ", ";
		OaClassMember tmpMember;
		tmpMember.isFunc = false;
		tmpMember.name = temVar->name;
		tmpMember.params = NULL;
		tmpMember.type = temVar->type;
		tmpMember.align = temVar->align;
		classNow.align = (classNow.align > tmpMember.align) ? classNow.align : tmpMember.align;
		tmpMember.pos = classMemberIndex++;
		classNow.members.insert(std::pair<std::string, OaClassMember>(tmpMember.name, tmpMember));
	}
	else {
		addVar(temVar);
		if (temVar->type[0] == '#') {
			result += temVar->name + " ";
			result += "= " + std::string("alloca %class." + temVar->type.substr(1) + ", ");
			result += std::string("align ") + myItoa(temVar->align) + endLine;
			
			//let initial array length be zero
			std::string classType = std::string(temVar->type).substr(1);
			std::string className = std::string(temVar->name);
			zeroClassArrayLength(className, classType);
		}
		else {
			result += temVar->name + " ";
			result += "= " + std::string("alloca " + temVar->type + ", ");
			result += std::string("align ") + myItoa(temVar->align) + endLine;
		}
	}
}

void g_parseVarDefineNode(std::string& result, VarDefineNode* seg) {
	if (seg == NULL) {
		return;
	}
	VarDeclareNode decNode;
	VarAssignNode assNode;
	decNode.name = seg->name;
	decNode.type = seg->type;
	LeftValue lv;
	lv.name = seg->name;
	lv.next = NULL;
	assNode.name = &lv;
	assNode.exp = seg->exp;
	assNode.expOfVar = NULL;
	g_parseVarDeclareNode(result, &decNode);
	g_parseVarAssignNode(result, &assNode);
}

void g_parseVarAssignNode(std::string& result, VarAssignNode* seg) {
	if (seg == NULL) {
		return;
	}
	if (seg->expOfVar == NULL && seg->name == NULL) {
		if (seg->exp->op == OA_EXP_NONE && seg->exp->leafType == OA_FUNCTION_VALUE) {
			if (std::string(seg->exp->functionValue->name->name) == "@print" && seg->exp->functionValue->name->next == NULL) {
				parsePrintFunction(seg->exp->functionValue->factParam);
				return;
			}
			else {
				g_parseExpression(result, seg->exp);
				return;
			}
		}
	}
	
	LeftValue *lv = seg->name;
	OaClassMember *member = NULL;
	if (lv->next != NULL) {
		//class
		std::string classType = getVar('%' + std::string(lv->name).substr(1))->type.substr(1);
		while (lv->next != NULL) {
			OaClass *oaClass = &(oaClasses.find(classType)->second);
			member = findMemberInClass('%' + std::string(lv->next->name).substr(1), oaClass);
			bool inParent = false;
			while (member == NULL && oaClass->parent != "") {
				result += '%' + myItoa(temVarNo++) + " = getelementptr inbounds %class." + oaClass->name + ", %class." + oaClass->name + "* %" + std::string(lv->name).substr(1) + ", i32 0, i32 0\n";
				classType = oaClass->parent;
				oaClass = &(oaClasses.find(oaClass->parent)->second);
				member = findMemberInClass('%' + std::string(lv->next->name).substr(1), oaClass);
				inParent = true;
			}
			if (member == NULL) { panic("in parseVarAssign: no member in class"); return; }
			if (inParent) {
				result += '%' + myItoa(temVarNo++) + " = getelementptr inbounds %class." + oaClass->name + ", %class." + oaClass->name + "* %" + myItoa(temVarNo - 2) + ", i32 0, i32 " + myItoa(member->pos) + "\n";
			}
			else {
				result += '%' + myItoa(temVarNo++) + " = getelementptr inbounds %class." + oaClass->name + ", %class." + oaClass->name + "* %" + std::string(lv->name).substr(1) + ", i32 0, i32 " + myItoa(member->pos) + "\n";
			}
			classType = std::string(member->type).substr(1);
			lv = lv->next;
		}
		int index = temVarNo - 1;
		OaVar *var = g_parseExpression(result, seg->exp);
		//[TODO] [without check] var->type + '*' and var->type (var and array)
		OaVar *arrayIndex = g_parseExpression(result, seg->expOfVar);
		if (arrayIndex == NULL && member->type != var->type) { panic("in parseVarAssign: type error"); return; }
		else if (arrayIndex != NULL && member->type != var->type + '*') { panic("in parseVarAssign: type error"); return;}
		else if (arrayIndex != NULL && arrayIndex->type != "i32") { panic("in parseVarAssign: index should be int"); return;}
		if(arrayIndex)  result += '%' + myItoa(temVarNo++) + " = load " + var->type + "*, " + var->type + "** %" + myItoa(index) + ", align " + myItoa(var->align) + '\n';
		if(arrayIndex != NULL) result += '%' + myItoa(temVarNo++) + " = getelementptr inbounds " + var->type + ", " + var->type + "* %" + myItoa(temVarNo-2) + ", i32 " + arrayIndex->name + '\n';
		result += "store " + var->type + ' ' + var->name + ", " + var->type + "* %" + myItoa(temVarNo - 1) + ", align " + myItoa(var->align) + '\n';
		return;
	}

	//not class
	std::string temName;
	LeftValue* temLv = seg->name;
	while (temLv != NULL) {
		temName += reduceAt(temLv->name);
		if (temLv->next != NULL) {
			temName += '.';
		}
		temLv = temLv->next;
	}
	if (temName == "") { panic("Lack of LeftValue"); return; }

	struct OaVar *temVar = NULL;
	temVar = getVar("%" + temName);
	if (temVar == NULL && inClassMethod) {
		LeftValue lv1;
		LeftValue lv2;
		lv1.name = "%.this";
		lv1.next = &lv2;
		temName = '%' + temName;
		int tmpSize = temName.size();
		char *tmpCh = new char[tmpSize + 1];
		for (int i = 0; i < tmpSize; ++i) {
			tmpCh[i] = temName[i];
		}
		tmpCh[tmpSize] = '\0';
		lv2.name = tmpCh;
		lv2.next = NULL;
		temVar = g_parseLeftValue(result, &lv1);
		delete[] tmpCh;
		if (temVar == NULL) { panic("Undeclared Identifier"); return; }
	}
	if (temVar == NULL) {
		//[TODO] not found
		return;
	}
	std::string tmpName = temVar->name;
	if (seg->expOfVar != NULL) {
		struct OaVar* idxVar = g_parseExpression(result, seg->expOfVar);
		result += "%" + myItoa(temVarNo++) + " = ";
		//load i32, i32* %first, align 4
		result += "load " + temVar->type + ", " + temVar->type + "* " + temVar->name + ", ";
		result += "align 8" + endLine;
		tmpName = "%" + myItoa(temVarNo - 1);
		result += "%" + myItoa(temVarNo++) + " = ";
		result += "getelementptr inbounds i32, " + temVar->type + " " + tmpName + ", ";
		result += "i32 " + idxVar->name + endLine;
		tmpName = "%" + myItoa(temVarNo - 1);
	}

	struct OaVar* refVar = g_parseExpression(result, seg->exp);
	if (refVar->type == "i1" && temVar->type == "i32") {
		refVar->name = "%" + myItoa(temVarNo++);
		result += refVar->name + " = ";
		result += "zext i1 %" + myItoa(temVarNo - 2);
		result += " to " + temVar->type + endLine;
	}
	result += "store " + refVar->type + " ";
	if (temVar->type == "double" && refVar->name[0] != '%')
		result += myDtoa(refVar->name) + ", ";
	else
		result += refVar->name + ", ";
	result += refVar->type + "* " + tmpName + ", ";
	result += "align " + myItoa(temVar->align) + endLine;
}

void g_parseArrayDeclareNode(std::string&result, ArrayDeclareNode* seg) {
	if (seg == NULL) {
		return;
	}
	
	struct OaVar *temArray = new struct OaVar;
	if (inGlobal) {
		temArray->name = "@" + reduceAt(std::string(seg->name));
	}
	else if (oaPathStk.size() != 0) {
		temArray->name = "%";
		for (std::list<std::string>::iterator iter = oaPathStk.begin(); iter != oaPathStk.end(); ++iter) {
			temArray->name += *iter + ".";
		}
		temArray->name = "%" + reduceAt(std::string(seg->name));
	}
	else {
		temArray->name = "%" + reduceAt(std::string(seg->name));
	}

	if (seg->type == std::string("int[]")) {
		temArray->type = "i32*";
		temArray->align = 4;
	}
	else if (seg->type == std::string("char[]")) {
		temArray->type = "i8*";
		temArray->align = 4;
	}
	else if (seg->type == std::string("double[]")) {
		temArray->type = "double*";
		temArray->align = 4;
	}
	else if (seg->type[0] == '#') {
		//class object declare
		temArray->type = std::string(seg->type);
		temArray->align = 0;
	}
	else {
		panic("error in varDeclareNode: type error");
		return;
	}

	if (inGlobal) {
		addVar(temArray);
		std::string tmpStr;
		if (temArray->type == "i32*") {
			tmpStr = temArray->name + " = common global i32* null, align 4";
		}
		else if (temArray->type == "double*") {
			tmpStr = temArray->name + " = common global double* null, align 4";

		}
		else if (temArray->type == "i8*") {
			tmpStr = temArray->name + " = common global i8* null, align 4";
		}
		else {
			//[TODO] wrong type
		}
		globalVariables.push_back(tmpStr);
		tmpStr = temArray->name +".length = common global i32 0, align 4\n";
		OaVar *lengthVar = new OaVar;
		lengthVar->align = 4;
		lengthVar->name = temArray->name + ".length";
		lengthVar->type = "i32";
		globalVariables.push_back(tmpStr);
		addVar(lengthVar);
	}
	else if (classNameNow != "") {
		result += temArray->type;
		result += ", ";
		OaClassMember tmpMember;
		tmpMember.isFunc = false;
		tmpMember.name = temArray->name;
		tmpMember.params = NULL;
		tmpMember.type = temArray->type;
		tmpMember.align = temArray->align;
		tmpMember.pos = classMemberIndex++;
		classNow.align = (classNow.align > tmpMember.align) ? classNow.align : tmpMember.align;
		classNow.members.insert(std::pair<std::string, OaClassMember>(tmpMember.name, tmpMember));
	}
	else {
		temArray->size = 0;
		addArray(temArray);
		result += temArray->name + " ";
		result += "= " + std::string("alloca " + temArray->type + ", align ");
		result += myItoa(temArray->align) + endLine;

		OaVar *tmpVar = new OaVar;
		tmpVar->align = 4;
		tmpVar->type = "i32";
		tmpVar->name = temArray->name + ".length";
		addVar(tmpVar);
		result += tmpVar->name + " ";
		result += "= " + std::string("alloca " + tmpVar->type + ", ");
		result += std::string("align ") + myItoa(tmpVar->align) + endLine;
		result += "store " + tmpVar->type + " ";
		result += "0, ";
		result += tmpVar->type + "* " + tmpVar->name + ", ";
		result += "align " + myItoa(tmpVar->align) + endLine;
	}
}

void g_parseArrayDefineNode(std::string&result, ArrayDefineNode*seg) {
	if (seg == NULL) {
		return;
	}
	ArrayDeclareNode decNode;
	ArrayAssignNode assNode;
	decNode.name = seg->name;
	decNode.type = seg->type;
	LeftValue lv;
	lv.name = seg->name;
	lv.next = NULL;
	assNode.name = &lv;
	assNode.type = seg->type;
	assNode.exp = seg->exp;
	g_parseArrayDeclareNode(result, &decNode);
	g_parseArrayAssignNode(result, &assNode);
}

void g_parseArrayAssignNode(std::string&result, ArrayAssignNode*seg) {
	if (seg == NULL) {
		return;
	}

	LeftValue *lv = seg->name;
	OaClassMember *member = NULL;
	OaClass *oaClass = NULL;
	if (lv->next != NULL) {
		//class
		std::string classType = getVar('%' + std::string(lv->name).substr(1))->type.substr(1);
		while (lv->next != NULL) {
			oaClass = &(oaClasses.find(classType)->second);
			member = findMemberInClass('%' + std::string(lv->next->name).substr(1), oaClass);
			bool inParent = false;
			while (member == NULL && oaClass->parent != "") {
				result += '%' + myItoa(temVarNo++) + " = getelementptr inbounds %class." + oaClass->name + ", %class." + oaClass->name + "* %" + std::string(lv->name).substr(1) + ", i32 0, i32 0\n";
				classType = oaClass->parent;
				oaClass = &(oaClasses.find(oaClass->parent)->second);
				member = findMemberInClass('%' + std::string(lv->next->name).substr(1), oaClass);
				inParent = true;
			}
			if (member == NULL) { panic("in parseArrayAssign: no member in class"); return; }
			if (inParent) {
				result += '%' + myItoa(temVarNo++) + " = getelementptr inbounds %class." + oaClass->name + ", %class." + oaClass->name + "* %" + myItoa(temVarNo - 2) + ", i32 0, i32 " + myItoa(member->pos) + "\n";
			}
			else {
				result += '%' + myItoa(temVarNo++) + " = getelementptr inbounds %class." + oaClass->name + ", %class." + oaClass->name + "* %" + std::string(lv->name).substr(1) + ", i32 0, i32 " + myItoa(member->pos) + "\n";
			}
			classType = std::string(member->type).substr(1);
			lv = lv->next;
		}
		//[WARNING] not check index maybe change, see below else
		int index = temVarNo - 1;
		//do not free if .length is zero
		//[WARNING] size == 0 to indicate the first time to malloc
		lv = seg->name;
		std::string tmpName = "";
		tmpName = '%' + std::string(lv->name).substr(1);
		lv = lv->next;
		while (lv != NULL) {
			tmpName += '.' + std::string(lv->name).substr(1);
			lv = lv->next;
		}
		tmpName += ".length";
		OaVar *tmpVar = getVar(tmpName);
		if(tmpVar == NULL){ panic("in parseArrayAssign: no such array in class"); return; }
		if (tmpVar->size != 0) {
			freeArray('%' + myItoa(index), member->type, member->align);
		}
		OaVar *var = g_parseExpression(result, seg->exp);
		std::string tmpType = "";
		if (strcmp(seg->type, "int[]") == 0) {
			tmpType = "i32*";
		}
		else if (strcmp(seg->type, "char[]") == 0) {
			tmpType = "i8*";
		}
		else if (strcmp(seg->type, "double[]") == 0) {
			tmpType = "double*";
		}

		if (tmpType != member->type) { panic("in parseArrayAssign: type error"); return;}
		if(var->type != "i32") { panic("in parseArrayAssign: array size should be int"); return; }
		//malloc
		std::string size = mallocArray('%' + myItoa(index), member->type, member->align, var->name);
		//upadte .length variable
		result += "store i32 " + var->name + ", i32* " + tmpVar->name + ", align 4\n";
	}
	else {
		// not in class
		//[WARNING] not checked
		//do not free if .length is zero
		//[WARNING] size == 0 to indicate the first time to malloc
		lv = seg->name;
		std::string tmpName = "";
		while (lv != NULL) {
			tmpName += '%' + std::string(lv->name).substr(1);
			lv = lv->next;
		}
		OaVar *nameVar = getVar(tmpName);
		tmpName += ".length";
		OaVar *tmpVar = getVar(tmpName);
		if (tmpVar == NULL) { panic("in parseArrayAssign: no such array in class"); return; }
		if (tmpVar->size != 0){
			freeArray(nameVar->name.substr(1), nameVar->type, nameVar->align);
		}
		OaVar *var = g_parseExpression(result, seg->exp);
		std::string tmpType = "";
		if (strcmp(seg->type, "int[]") == 0) {
			tmpType = "i32*";
		}
		else if (strcmp(seg->type, "char[]") == 0) {
			tmpType = "i8*";
		}
		else if (strcmp(seg->type, "double[]") == 0) {
			tmpType = "double*";
		}

		if (tmpType != nameVar->type) { panic("in parseArrayAssign: type error"); return; }
		if (var->type != "i32") { panic("in parseArrayAssign: array size should be int"); return; }
		//malloc
		std::string size = mallocArray(nameVar->name.substr(1), nameVar->type, nameVar->align, var->name);
		//upadte .length variable
		result += "store i32 " + var->name + ", i32* " + tmpVar->name + ", align 4\n";
	}
}

void g_parseIfNode(std::string&result, IfNode*seg) {
	if (seg == NULL) {
		return;
	}
	char ifIdx[25];
	char cmpIdx[25];
	_itoa(OaIfIdx, ifIdx, 10);
	_itoa(OaCmpIdx, cmpIdx, 10);
	//std::string cmpLabel = std::string("%cmp") + cmpIdx;
	std::string ifLabel = std::string("if.then.") + ifIdx;
	std::string nextLabel;
	std::string endLabel = std::string("if.final.") + ifIdx;
	if (seg->elseStmts != NULL || seg->elifStmts != NULL) {
		nextLabel = std::string("if.else.") + ifIdx;
	}
	else {
		nextLabel = std::string("if.end.") + ifIdx;
	}
	endLbStk.push_back(endLabel);
	OaVar *p_midVar = g_parseExpression(result, seg->exp);
	OaCmpIdx++;
	OaIfIdx++;
	result += std::string("  br i1 ") + p_midVar->name + ',' + " label %" + ifLabel + ',' + " label %" + nextLabel + '\n';
	result += "\n";
	result += ifLabel + ":\n";
	oaPathStk.push_back(ifLabel);

	//store allVars and allArrays(added in parseFormParam() function and used in parsers in function)
	int sizeOldVar = allVars.size();
	g_parseNodeList(result, seg->stmts, ifLabel);
	//recover allVars
	int sizeNewVar = allVars.size();

	while (sizeNewVar != sizeOldVar) {
		allVars.pop_back();
		sizeNewVar--;
	}
	oaPathStk.pop_back();
	result += "  br label %" + endLabel + "\n";
	result += "\n";
	result += nextLabel + ":\n";
	struct TreeNode *tmp = seg->elifStmts;
	while (tmp != NULL) {
		g_parseTreeNode(result, seg->elifStmts);
		nextLabel = oaPathStk.back();
		oaPathStk.pop_back();
		tmp = tmp->next;
	}
	if (seg->elseStmts) {
		oaPathStk.push_back(nextLabel);
		g_parseTreeNode(result, seg->elseStmts);
		oaPathStk.pop_back();
	}
	result += "  br label %" + endLabel + "\n";
	result += endLabel + ":\n";
	endLbStk.pop_back();
}

void g_parseElifNode(std::string&result, ElifNode*seg) {
	if (seg == NULL) {
		return;
	}
	char ifIdx[25];
	char cmpIdx[25];
	_itoa(OaIfIdx, ifIdx, 10);
	_itoa(OaCmpIdx, cmpIdx, 10);
	//std::string cmpLabel = std::string("%cmp") + cmpIdx;
	std::string ifLabel = std::string("if.then.") + ifIdx;
	std::string nextLabel = std::string("if.else.") + ifIdx;
	std::string endLabel = endLbStk.back();
	OaVar *p_midVar = g_parseExpression(result, seg->exp);
	OaCmpIdx++;
	OaIfIdx++;
	result += std::string("  br i1 ") + p_midVar->name + ',' + " label %" + ifLabel + ',' + " label %" + nextLabel + '\n';
	result += "\n";
	result += ifLabel + ":\n";
	oaPathStk.push_back(ifLabel);
	//store allVars and allArrays(added in parseFormParam() function and used in parsers in function)
	int sizeOldVar = allVars.size();
	g_parseNodeList(result, seg->stmts, ifLabel);
	//recover allVars
	int sizeNewVar = allVars.size();
	while (sizeNewVar != sizeOldVar) {
		allVars.pop_back();
		sizeNewVar--;
	}
	oaPathStk.pop_back();
	result += "  br label %" + endLabel + "\n";
	result += "\n";
	result += nextLabel + ":\n";
	oaPathStk.push_back(nextLabel);
	temVarNo++;			//llvm regular
}

void g_parseElseNode(std::string&result, ElseNode*seg) {
	if (seg == NULL) {
		return;
	}
	//store allVars and allArrays(added in parseFormParam() function and used in parsers in function)
	int sizeOldVar = allVars.size();
	g_parseTreeNode(result, seg->stmts);
	//recover allVars
	int sizeNewVar = allVars.size();
	while (sizeNewVar != sizeOldVar) {
		allVars.pop_back();
		sizeNewVar--;
	}
	temVarNo++;			//llvm regular
}

void g_parseWhileNode(std::string&result, WhileNode*seg) {
	if (seg == NULL) {
		return;
	}
	char wIdx[25];
	_itoa(OaWhileIdx, wIdx, 10);
	std::string wCondLabel = std::string("while.cond.") + wIdx;
	std::string wBodyLabel = std::string("while.body.") + wIdx;
	std::string wEndLabel = std::string("while.end.") + wIdx;
	OaWhileIdx++;
	result += std::string("  br label %") + wCondLabel + '\n';
	result += "\n";
	result += wCondLabel + ":\n";
	OaVar *p_midVar = g_parseExpression(result, seg->exp);
	result += std::string("  br i1 ") + p_midVar->name + ',' + " label %" + wBodyLabel + ',' + " label %" + wEndLabel + '\n';
	result += "\n";
	result += wBodyLabel + ":\n";
	oaPathStk.push_back(wBodyLabel);
	//store allVars and allArrays(added in parseFormParam() function and used in parsers in function)
	int sizeOldVar = allVars.size();
	g_parseNodeList(result, seg->stmts, wBodyLabel);
	//recover allVars
	int sizeNewVar = allVars.size();
	while (sizeNewVar != sizeOldVar) {
		allVars.pop_back();
		sizeNewVar--;
	}
	oaPathStk.pop_back();
	result += std::string("  br label %") + wCondLabel + '\n';
	result += "\n";
	result += wEndLabel + ":\n";
}

void replaceUtilForeachVDF(struct VarDefineNode *seg, char* namein, LeftValue* nameout, std::string idx) {
	if (seg == NULL) {
		return;
	}
	replaceUtilForeachEXP(seg->exp, namein, nameout, idx);
}

void replaceUtilForeachVA(struct VarAssignNode* seg, char* namein, LeftValue* nameout, std::string idx) {
	if (seg == NULL) {
		return;
	}
	if (seg->name != NULL) {
		if (strcmp(seg->name->name, namein) == 0) {
			char* nameidx = new char[idx.size() + 1];
			strcpy(nameidx, idx.c_str());
			struct LeftValue *newlft = createLeftValue(nameidx);
			struct Expression *newexp = createExpressionLeftValueLeaf(newlft);
			seg->expOfVar = newexp;
			LeftValue* origin = seg->name;
			seg->name = nameout;
			//free(origin);
		}
	}
	replaceUtilForeachEXP(seg->exp, namein, nameout, idx);
}

void replaceUtilForeachADF(struct ArrayDefineNode* seg, char* namein, LeftValue* nameout, std::string idx) {

}

void replaceUtilForeachAA(struct ArrayAssignNode* seg, char* namein, LeftValue* nameout, std::string idx) {

}

void replaceUtilForeachIF(struct IfNode* seg, char* namein, LeftValue* nameout, std::string idx) {
	if (seg == NULL) {
		return;
	}
	replaceUtilForeachEXP(seg->exp, namein, nameout, idx);
	replaceUtilForeach(seg->elifStmts, namein, nameout, idx);
	replaceUtilForeach(seg->elseStmts, namein, nameout, idx);
	replaceUtilForeach(seg->stmts, namein, nameout, idx);
}

void replaceUtilForeachELIF(struct ElifNode* seg, char* namein, LeftValue* nameout, std::string idx) {
	if (seg == NULL) {
		return;
	}
	replaceUtilForeachEXP(seg->exp, namein, nameout, idx);
	replaceUtilForeach(seg->stmts, namein, nameout, idx);
}

void replaceUtilForeachELSE(struct ElseNode* seg, char* namein, LeftValue* nameout, std::string idx) {
	if (seg == NULL) {
		return;
	}
	replaceUtilForeach(seg->stmts, namein, nameout, idx);
}

void replaceUtilForeachWHILE(struct WhileNode* seg, char* namein, LeftValue* nameout, std::string idx) {
	if (seg == NULL) {
		return;
	}
	replaceUtilForeachEXP(seg->exp, namein, nameout, idx);
	replaceUtilForeach(seg->stmts, namein, nameout, idx);
}

void replaceUtilForeachRT(struct ReturnNode* seg, char* namein, LeftValue* nameout, std::string idx) {
	if (seg == NULL) {
		return;
	}
	replaceUtilForeachEXP(seg->exp, namein, nameout, idx);
}

void replaceUtilForeachEXP(struct Expression* seg, char* namein, LeftValue* nameout, std::string idx) {
	if (seg == NULL) {
		return;
	}
	if (seg->left == NULL&&seg->right == NULL) {
		switch (seg->leafType)
		{
		case OA_LEFT_VALUE:
			if (seg->name != NULL) {
				if (std::string(namein) == std::string(seg->name->name)) {
					//替换成array value
					char* nameidx = new char[idx.size() + 1];
					strcpy(nameidx, idx.c_str());
					LeftValue *idxvalue = createLeftValue(nameidx);
					Expression *idxexp = createExpressionLeftValueLeaf(idxvalue);
					ArrayValue *newvalue = new ArrayValue;
					newvalue->name = nameout;
					newvalue->index = idxexp;
					seg->leafType = OA_ARRAY_VALUE;
					seg->arrayValue = newvalue;
				}
			}
			break;
		case OA_ARRAY_VALUE:
			replaceUtilForeachEXP(seg->arrayValue->index, namein, nameout, idx);
			break;
		case OA_FUNCTION_VALUE:
			FactParam *params = seg->functionValue->factParam;
			while (params != NULL) {
				replaceUtilForeachEXP(params->exp, namein, nameout, idx);
				params = params->next;
			}
			break;
		
		}
	}
	else {
		replaceUtilForeachEXP(seg->left, namein, nameout, idx);
		replaceUtilForeachEXP(seg->right, namein, nameout, idx);
	}
}

void replaceUtilForeach(struct TreeNode* seg, char* namein, LeftValue* nameout, std::string idx) {
	if (seg == NULL) {
		return;
	}
	struct TreeNode* next = seg->next;
	while (next != NULL) {
		replaceUtilForeach(next, namein, nameout, idx);
		next = next->next;
	}
	switch (seg->type) {
	case VAR_DEFINE_NODE:
		replaceUtilForeachVDF(seg->varDefineNode,namein,nameout,idx);
		break;
	case VAR_ASSIGN_NODE:
		replaceUtilForeachVA(seg->varAssignNode, namein, nameout, idx);
		break;
	case ARRAY_DEFINE_NODE:
		replaceUtilForeachADF(seg->arrayDefineNode, namein, nameout, idx);
		break;
	case ARRAY_ASSIGN_NODE:
		replaceUtilForeachAA(seg->arrayAssignNode, namein, nameout, idx);
		break;
	case IF_NODE:
		replaceUtilForeachIF(seg->ifNode, namein, nameout, idx);
		break;
	case ELIF_NODE:
		replaceUtilForeachELIF(seg->elifNode, namein, nameout, idx);
		break;
	case ELSE_NODE:
		replaceUtilForeachELSE(seg->elseNode, namein, nameout, idx);
		break;
	case WHILE_NODE:
		replaceUtilForeachWHILE(seg->whileNode, namein, nameout, idx);
		break;
	case RETURN_NODE:
		replaceUtilForeachRT(seg->returnNode, namein, nameout, idx);
		break;
	default:
		break;
	}
}

void g_parseForeachNode(std::string &result, ForeachNode *seg) {
	if (seg == NULL) {
		return;
	}
	LeftValue *array_name = seg->nameOut;
	//首先添加一个循环index的定义
	std::string idx = std::string(seg->nameIn) + ".idx";
	//这里取值-1方便把赋值放在while.cond label之后
	Expression *assign_zero = createExpressionIntLeaf(-1, 0);
	char *idxname = new char[idx.size() + 1];
	strcpy(idxname, idx.c_str());
	LeftValue *idxleft = createLeftValue(idxname);
	TreeNode *assign_node = createVarDefine("int",idxname, assign_zero);

	//创建一个比较index是否超过数组长度的语句,深拷贝leftvalue 成为next为NULL的单独字符串
	LeftValue *new_final = new LeftValue;
	LeftValue *tmpLv = seg->nameOut;
	new_final->next = NULL;
	std::string tmpName = "%";
	while (tmpLv) {
		tmpName += std::string(tmpLv->name).substr(1);
		if (tmpLv->next) {
			tmpName += '.';
		}
		tmpLv = tmpLv->next;
	}
	tmpName += array_length;
	int tmpSize = tmpName.size();
	char *tmpCh = new char[tmpSize + 1];
	for (int i = 0; i < tmpSize; ++i) {
		tmpCh[i] = tmpName[i];
	}
	tmpCh[tmpSize] = '\0';
	new_final->name = tmpCh;
	
	Expression *cmp_left = createExpressionLeftValueLeaf(idxleft);
	Expression *cmp_right = createExpressionLeftValueLeaf(new_final);
	Expression *is_more = createExpression(cmp_right, cmp_left, OA_EXP_GT);
	
	//创建一个递增index的语句
	Expression *assign_one = createExpressionIntLeaf(1, 0);
	Expression *add_one = createExpression(cmp_left, assign_one, OA_EXP_PLUS);
	TreeNode *assign_add = createVarAssign(idxleft, add_one, NULL);

	//接下来开始while循环
	char wIdx[25];
	_itoa(OaWhileIdx, wIdx, 10);
	std::string wCondLabel = std::string("while.cond.") + wIdx;
	std::string wBodyLabel = std::string("while.body.") + wIdx;
	std::string wEndLabel = std::string("while.end.") + wIdx;
	OaWhileIdx++;
	//首先给index赋值
	g_parseTreeNode(result, assign_node);
	result += std::string("  br label %") + wCondLabel + '\n';
	result += "\n";
	result += wCondLabel + ":\n";
	//进行递增以及比较
	g_parseTreeNode(result, assign_add);
	OaVar *p_midVar = g_parseExpression(result, is_more);
	result += std::string("  br i1 ") + p_midVar->name + ',' + " label %" + wBodyLabel + ',' + " label %" + wEndLabel + '\n';
	result += "\n";
	result += wBodyLabel + ":\n";
	
	//对body部分进行替换

	replaceUtilForeach(seg->stmts, seg->nameIn, seg->nameOut, idx);	
	oaPathStk.push_back(wBodyLabel);
	//store allVars and allArrays(added in parseFormParam() function and used in parsers in function)
	int sizeOldVar = allVars.size();
	g_parseNodeList(result, seg->stmts, wBodyLabel);
	//recover allVars
	int sizeNewVar = allVars.size();
	while (sizeNewVar != sizeOldVar) {
		allVars.pop_back();
		sizeNewVar--;
	}
	oaPathStk.pop_back();
	result += std::string("  br label %") + wCondLabel + '\n';
	result += "\n";
	result += wEndLabel + ":\n";
}

void g_parseClassDefineNode(std::string&result, struct ClassDefineNode *seg) {
	if (seg == NULL) {
		return;
	}
	classNameNow = std::string(seg->type).substr(1);
	classNow.align = 0;
	classNow.name = classNameNow;
	classMemberIndex = 0;
	if (seg->typeParent) {
		classNow.parent = std::string(seg->typeParent).substr(1);
		classNow.align = oaClasses.find(classNow.parent)->second.align;
	}
	else {
		classNow.parent = "";
	}
	result += "%class." + classNow.name + " = type { ";
	if (seg->typeParent) {
		result += "%class." + classNow.parent + ", ";
	}
	g_parseNodeList(result, seg->stmts, "stmts");
	result.pop_back();
	result.pop_back();
	result += " }\n\n";

	oaClasses.insert(std::pair<std::string, OaClass>(classNow.name, classNow));
	classNow.members.clear();
	classNow.name = "";
	classNow.parent = "";
	classNameNow = "";
}

void g_parseFunctionDeclareNode(std::string&result, FunctionDeclareNode*seg) {
	if (seg == NULL) {
		return;
	}
	OaFunction oafunc;
	//className and name
	oafunc.className = classNameNow;
	oafunc.name = std::string(seg->name);

	//check for redeclare
	if (oaFunctions.find(oafunc.className + oafunc.name) != oaFunctions.end()) {
		panic("wrong in declare node, function " + oafunc.name + "has been declared!");
		return;
	}

	oafunc.isDefined = false;
	if (seg->type) {
		oafunc.type = std::string(seg->type);
	}
	else {
		oafunc.type = "void";
	}
	
	//parameters
	oafunc.params = seg->formParams;
	oaFunctions.insert(std::pair<std::string, OaFunction>(oafunc.className + oafunc.name, oafunc));
}

void g_parseFunctionDefineNode(std::string&result, FunctionDefineNode *seg) {
	if (seg == NULL) {
		return;
	}
	temVarNo = 0;
	OaFunction oafunc;
	//className and name
	if (classNameNow != "") {
		panic("functionDefineNode error: cannot define function in class");
		return;
	}
	oafunc.className = classNameNow;
	oafunc.name = std::string(seg->name);

	//check for redefine
	std::map<std::string, OaFunction>::iterator iter = oaFunctions.find(oafunc.className + oafunc.name);
	if (iter != oaFunctions.end()) {
		if (iter->second.isDefined == true) {
			panic("wrong in defined node, function " + oafunc.name + "has been defined!");
			return;
		}
		else {
			//[TODO] check params and return type
			oaFunctions.erase(iter);
			oafunc.isDefined = true;
		}
	}
	//define
	result += "define ";

	//return type
	if (seg->type) {
		if (strcmp(seg->type, "int") == 0) {
			oafunc.type = "i32";
		}
		else if (strcmp(seg->type, "char") == 0) {
			oafunc.type = "i8";
		}
		else if (strcmp(seg->type, "double") == 0) {
			oafunc.type = "double";
		}
		else if(strcmp(seg->type, "void") == 0){
			oafunc.type = "void";
		}
		else {
			//class
		}
	}
	
	result += oafunc.type;

	//function name
	result += " ";
	result += oafunc.name;

	//store allVars and allArrays(added in parseFormParam() function and used in parsers in function)
	int sizeOldVar = allVars.size();

	//parameters
	result += '(';
	std::string predefine = g_parseFormParam(result, seg->formParams);
	result += ')';
	oafunc.params = seg->formParams;

	//add into function
	//recursive case
	oaFunctions.insert(std::pair<std::string, OaFunction>(oafunc.className + oafunc.name, oafunc));

	//statements
	result += "{\nentry:\n";
	result += predefine;
	if (seg->stmts) {
		g_parseNodeList(result, seg->stmts, "stmts");
	}
	result += "}\n\n";

	//recover allVars (remain global variables)
	int sizeNewVar = allVars.size();

	while (sizeNewVar != sizeOldVar) {
		allVars.pop_back();
		sizeNewVar--;
	}
}

void g_parseClassMethodDefineNode(std::string&result, ClassMethodDefineNode*seg) {
	if (seg == NULL) {
		return;
	}
	temVarNo = 0;
	OaFunction oafunc;
	//className and name
	if (classNameNow != "") {
		panic("functionDefineNode error: cannot define class method in class");
		return;
	}
	oafunc.className = std::string(seg->classType).substr(1);
	oafunc.name = std::string(seg->name);
	inClassMethod = true;
	methodClassNameNow = oafunc.className;

	//check for redefine
	std::map<std::string, OaFunction>::iterator iter = oaFunctions.find(oafunc.className + oafunc.name);
	if (iter != oaFunctions.end()) {
		if (iter->second.isDefined == true) {
			panic("wrong in defined node, function " + oafunc.name + "has been defined!");
			inClassMethod = false;
			methodClassNameNow = "";
			return;
		}
		else {
			//[TODO] check params and return type
			oaFunctions.erase(iter);
			oafunc.isDefined = true;
		}
	}
	//define
	result += "define ";

	//return type
	if (seg->type) {
		if (strcmp(seg->type, "int") == 0) {
			oafunc.type = "i32";
		}
		else if (strcmp(seg->type, "char") == 0) {
			oafunc.type = "i8";
		}
		else if (strcmp(seg->type, "double") == 0) {
			oafunc.type = "double";
		}
		else if (strcmp(seg->type, "void") == 0) {
			oafunc.type = "void";
		}
		else {
			//class
		}
	}
	else {
		oafunc.type = "void";
	}

	result += oafunc.type;

	//function name
	result += " @" + oafunc.className + '.' + oafunc.name.substr(1);

	//store allVars and allArrays(added in parseFormParam() function and used in parsers in function)
	int sizeOldVar = allVars.size();

	//parameters
	//add class to params
	FormParam *newParams = new FormParam;
	newParams->next = seg->formParams;
	newParams->type = seg->classType;
	newParams->name = "%.this";
	result += '(';
	std::string predefine = g_parseFormParam(result, newParams);
	result += ')';
	oafunc.params = newParams;
	
	//add into function
	//recursive case
	oaFunctions.insert(std::pair<std::string, OaFunction>(oafunc.className + oafunc.name, oafunc));

	//statements
	result += "{\nentry:\n";
	result += predefine;
	if (seg->stmts) {
		g_parseNodeList(result, seg->stmts, "stmts");
	}
	result += "}\n\n";

	//recover allVars (remain global variables)
	int sizeNewVar = allVars.size();
	while (sizeNewVar != sizeOldVar) {
		allVars.pop_back();
		sizeNewVar--;
	}
	
	inClassMethod = false;
	methodClassNameNow = "";
}

void g_parseBreakNode(std::string &result) {
	std::string num;
	for (std::list<std::string>::reverse_iterator i = oaPathStk.rbegin(); i != oaPathStk.rend(); i++) {
		std::size_t first = (*i).find('.');
		std::string loopType = (*i).substr(0, first);
		if (loopType == "while") {
			std::size_t rfirst = (*i).rfind('.');
			num = (*i).substr(rfirst + 1);
			break;
		}
	}
	result += "  br label %while.end." + num;
}

void g_parseContinueNode(std::string &result) {
	std::string num;
	for (std::list<std::string>::reverse_iterator i = oaPathStk.rbegin();i != oaPathStk.rend();i++) {
		std::size_t first = (*i).find('.');
		std::string loopType = (*i).substr(0, first);
		if (loopType == "while") {
			std::size_t rfirst = (*i).rfind('.');
			num = (*i).substr(rfirst + 1);
			break;
		}
	}
	result += "  br label %while.cond." + num;
}

void g_parseReturnNode(std::string &result, struct ReturnNode *seg) {
	//[TODO] check type
	if (seg == NULL) return;
	if (seg->exp == NULL) {
		result += "ret void\n";
		temVarNo++;			//llvm regular
		return;
	}
	OaVar *retVal = new struct OaVar;
	retVal = g_parseExpression(result, seg->exp);
	//[TODO] CHECK TYPE
	result += "ret " + retVal->type + ' ' + retVal->name + '\n';
	temVarNo++;			//llvm regular
}
//--------------------end tree node part-------------------

//---------------------expression part---------------------

struct OaVar* g_parseExpression(std::string &result, Expression* seg) {
	if (seg == NULL) {
		return NULL;
	}
	switch (seg->op) {
	case OA_EXP_NONE:
		//leaf node
		switch (seg->leafType) {
		case OA_INT: {
			/*std::ostringstream oss;
			if (oss << seg->number_int)
			result += oss.str();*/
			//Modified by @Xie LW
			struct OaVar* temVar = new struct OaVar;
			temVar->type = "i32";
			temVar->align = 4;
			temVar->name = myItoa(seg->number_int);
			return temVar;
			break;
		}
		case OA_DOUBLE: {
			/*std::ostringstream oss;
			if (oss << seg->number_double)
			result += oss.str();*/
			//Modified by @Xie LW
			struct OaVar* temVar = new struct OaVar;
			temVar->type = "double";
			temVar->align = 8;
			temVar->name = myDtoa(seg->number_double);
			return temVar;
			break;
		}
		case OA_CHAR: {
			/*result += seg->type_char;*/
			//Modified by @Xie LW
			struct OaVar* temVar = new struct OaVar;
			temVar->type = "i8";
			temVar->align = 1;
			temVar->name = myItoa((int)seg->type_char);
			return temVar;
			break;
		}
		case OA_STRING: {
			struct OaVar* temVar = new struct OaVar;
			temVar->type = "string";
			temVar->align = 1;
			temVar->name = std::string(seg->type_string);
		}
		case OA_LEFT_VALUE:
			return g_parseLeftValue(result, seg->name);
			break;
		case OA_ARRAY_VALUE:
			return g_parseArrayValue(result, seg->arrayValue);
			break;
		case OA_FUNCTION_VALUE:
			return g_parseFunctionValue(result, seg->functionValue);
			break;
		default:
			std::cout << "Wrong with expression, leafType\n";
			break;
		}
		break;
	case OA_EXP_NOT: {
		struct OaVar*  leftVar = g_parseExpression(result, seg->left);
		struct OaVar*   temVar = new struct OaVar;
		temVar->name = "%" + myItoa(temVarNo++);
		result += temVar->name + " = ";
		result += "icmp ne ";
		result += leftVar->type + " ";
		result += leftVar->name + ", 0"  + endLine;

		temVar->type = "i1";
		temVar->align = leftVar->align;
		return temVar;
		break;
		break;
	}
	case OA_EXP_MULTIPLE: {
		/*parseExpression(result, seg->left);
		result += " * ";
		parseExpression(result, seg->right);*/
		//Added by @Xie LW
		struct OaVar*  leftVar = g_parseExpression(result, seg->left);
		struct OaVar* rightVar = g_parseExpression(result, seg->right);
		struct OaVar*   temVar = new struct OaVar;
		temVar->name = "%" + myItoa(temVarNo++);
		result += temVar->name + " = ";
		result += "mul nsw ";
		result += leftVar->type + " ";
		result += leftVar->name + ", " + rightVar->name + endLine;
		temVar->type = leftVar->type;
		temVar->align = leftVar->align;
		return temVar;
		break;
	}
	case OA_EXP_DIVIDE: {
		/*parseExpression(result, seg->left);
		result += " / ";
		parseExpression(result, seg->right);*/
		//Added by @Xie LW
		struct OaVar*  leftVar = g_parseExpression(result, seg->left);
		struct OaVar* rightVar = g_parseExpression(result, seg->right);
		struct OaVar*   temVar = new struct OaVar;
		temVar->name = "%" + myItoa(temVarNo++);
		result += temVar->name + " = ";
		if (leftVar->type == "double")
			result += "fdiv ";
		if (leftVar->type == "i32" || leftVar->type == "i8")
			result += "sdiv ";
		result += leftVar->type + " ";
		result += leftVar->name + ", " + rightVar->name + endLine;
		temVar->type = leftVar->type;
		temVar->align = leftVar->align;
		return temVar;
		break;
	}
	case OA_EXP_PLUS: {
		/*parseExpression(result, seg->left);
		result += " + ";
		parseExpression(result, seg->right);*/
		//Added by @Xie LW
		struct OaVar*  leftVar = g_parseExpression(result, seg->left);
		struct OaVar* rightVar = g_parseExpression(result, seg->right);
		struct OaVar*   temVar = new struct OaVar;
		temVar->name = "%" + myItoa(temVarNo++);
		result += temVar->name + " = ";
		result += "add nsw ";
		result += leftVar->type + " ";
		result += leftVar->name + ", " + rightVar->name + endLine;
		temVar->type = leftVar->type;
		temVar->align = leftVar->align;
		return temVar;
		break;
	}
	case OA_EXP_MINUS: {
		/*parseExpression(result, seg->left);
		result += " - ";
		parseExpression(result, seg->right);
		break;*/
		//Added by @Xie LW
		struct OaVar*  leftVar = g_parseExpression(result, seg->left);
		struct OaVar* rightVar = g_parseExpression(result, seg->right);
		struct OaVar*   temVar = new struct OaVar;
		temVar->name = "%" + myItoa(temVarNo++);
		result += temVar->name + " = ";
		result += "sub nsw ";
		result += leftVar->type + " ";
		result += leftVar->name + ", " + rightVar->name + endLine;
		temVar->type = leftVar->type;
		temVar->align = leftVar->align;
		return temVar;
		break;
	}
	case OA_EXP_EQ: {
		/*parseExpression(result, seg->left);
		result += " == ";
		parseExpression(result, seg->right);*/
		struct OaVar*  leftVar = g_parseExpression(result, seg->left);
		struct OaVar* rightVar = g_parseExpression(result, seg->right);
		struct OaVar*   temVar = new struct OaVar;
		temVar->name = "%" + myItoa(temVarNo++);
		result += temVar->name + " = ";
		result += "icmp eq ";
		result += leftVar->type + " ";
		result += leftVar->name + ", " + rightVar->name + endLine;

		temVar->type = "i1";
		temVar->align = leftVar->align;
		return temVar;
		break;
	}
	case OA_EXP_NE: {
		/*parseExpression(result, seg->left);
		result += " != ";
		parseExpression(result, seg->right);*/
		struct OaVar*  leftVar = g_parseExpression(result, seg->left);
		struct OaVar* rightVar = g_parseExpression(result, seg->right);
		struct OaVar*   temVar = new struct OaVar;
		temVar->name = "%" + myItoa(temVarNo++);
		result += temVar->name + " = ";
		result += "icmp ne ";
		result += leftVar->type + " ";
		result += leftVar->name + ", " + rightVar->name + endLine;

		temVar->type = "i1";
		temVar->align = leftVar->align;
		return temVar;
		break;
	}
	case OA_EXP_GT: {
		/*parseExpression(result, seg->left);
		result += " > ";
		parseExpression(result, seg->right);*/
		struct OaVar*  leftVar = g_parseExpression(result, seg->left);
		struct OaVar* rightVar = g_parseExpression(result, seg->right);
		struct OaVar*   temVar = new struct OaVar;
		temVar->name = "%" + myItoa(temVarNo++);
		result += temVar->name + " = ";
		result += "icmp sgt ";
		result += leftVar->type + " ";
		result += leftVar->name + ", " + rightVar->name + endLine;
		
		temVar->type = "i1";
		temVar->align = leftVar->align;
		return temVar;
		break;
	}
	case OA_EXP_GE: {
		/*parseExpression(result, seg->left);
		result += " >= ";
		parseExpression(result, seg->right);*/
		//Added by @Xie LW
		struct OaVar*  leftVar = g_parseExpression(result, seg->left);
		struct OaVar* rightVar = g_parseExpression(result, seg->right);
		struct OaVar*   temVar = new struct OaVar;
		temVar->name = "%" + myItoa(temVarNo++);
		result += temVar->name + " = ";
		result += "icmp sge ";
		result += leftVar->type + " ";
		result += leftVar->name + ", " + rightVar->name + endLine;

		temVar->type = "i1";
		temVar->align = leftVar->align;
		return temVar;
		break;
	}
	case OA_EXP_LT: {
		/*parseExpression(result, seg->left);
		result += " < ";
		parseExpression(result, seg->right);*/
		struct OaVar*  leftVar = g_parseExpression(result, seg->left);
		struct OaVar* rightVar = g_parseExpression(result, seg->right);
		struct OaVar*   temVar = new struct OaVar;
		temVar->name = "%" + myItoa(temVarNo++);
		result += temVar->name + " = ";
		result += "icmp slt ";
		result += leftVar->type + " ";
		result += leftVar->name + ", " + rightVar->name + endLine;

		temVar->type = "i1";
		temVar->align = leftVar->align;
		return temVar;
		break;
	}
	case OA_EXP_LE: {
		/*parseExpression(result, seg->left);
		result += " <= ";
		parseExpression(result, seg->right);*/
		struct OaVar*  leftVar = g_parseExpression(result, seg->left);
		struct OaVar* rightVar = g_parseExpression(result, seg->right);
		struct OaVar*   temVar = new struct OaVar;
		temVar->name = "%" + myItoa(temVarNo++);
		result += temVar->name + " = ";
		result += "icmp sle ";
		result += leftVar->type + " ";
		result += leftVar->name + ", " + rightVar->name + endLine;

		temVar->type = "i1";
		temVar->align = leftVar->align;
		return temVar;
		break;
	}
	case OA_EXP_AND: {
		/*parseExpression(result, seg->left);
		result += " && ";
		parseExpression(result, seg->right);*/
		struct OaVar* temVar = new struct OaVar;
		struct OaVar* leftVar = g_parseExpression(result, seg->left);
		result += "%" + myItoa(temVarNo++) + " = ";
		result += "icmp ne " + leftVar->type + " " + leftVar->name;
		result += ", 0" + endLine;

		result += "br i1 %" + myItoa(temVarNo - 1) + ", ";
		result += "label %" + myItoa(temVarNo++) + ", ";
		result += "label %" + myItoa(temVarNo++) + endLine;
		int temLabel = temVarNo - 1;
		result += myItoa(temVarNo - 2)+endLine;

		struct OaVar* rightVar = g_parseExpression(result, seg->right);
		result += "%" + myItoa(temVarNo++) + " = ";
		result += "icmp ne " + rightVar->type + " " + rightVar->name;
		result += ", 0" + endLine;

		result += "br label %" + myItoa(temLabel) + endLine;

		result += myItoa(temLabel) + endLine;

		result += "%" + myItoa(temVarNo++) + " = ";
		result += "phi i1 [ false, %0 ], [ %" + myItoa(temVarNo - 2) + ", ";
		result += "%" + myItoa(temLabel - 1) + " ]" + endLine;;

		temVar->name = "%" + myItoa(temVarNo - 1);
		temVar->type = "i1";
		temVar->align = 4;
		return temVar;
		break;
	}
	case OA_EXP_OR: {
		/*parseExpression(result, seg->left);
		result += " || ";
		parseExpression(result, seg->right);*/
		struct OaVar* temVar = new struct OaVar;
		struct OaVar* leftVar = g_parseExpression(result, seg->left);
		result += "%" + myItoa(temVarNo++) + " = ";
		result += "icmp ne " + leftVar->type + " " + leftVar->name;
		result += ", 0" + endLine;

		result += "br i1 %" + myItoa(temVarNo - 1) + ", ";
		result += "label %" + myItoa(temVarNo++) + ", ";
		result += "label %" + myItoa(temVarNo++) + endLine;
		int temLabel = temVarNo-2;
		result += myItoa(temVarNo - 1) + endLine;

		struct OaVar* rightVar = g_parseExpression(result, seg->right);
		result += "%" + myItoa(temVarNo++) + " = ";
		result += "icmp ne " + rightVar->type + " " + rightVar->name;
		result += ", 0" + endLine;

		result += "br label %" + myItoa(temLabel) + endLine;

		result += myItoa(temLabel) + endLine;

		result += "%" + myItoa(temVarNo++) + " = ";
		result += "phi i1 [ true, %0 ], [ %" + myItoa(temVarNo - 2) + ", ";
		result += "%" + myItoa(temLabel+1) + " ]" + endLine;;

		temVar->name = "%" + myItoa(temVarNo - 1);
		temVar->type = "i1";
		temVar->align = 4;
		return temVar;
		break;
	}
	default:
		std::cout << "Wrong with expression, operator\n";
		break;
	}
	return NULL;
}

struct OaVar* g_parseLeftValue(std::string&result, LeftValue* seg) {
	if (seg == NULL) {
		return NULL;
	}
	//just reuturn when identifier not found, left for caller to deal error
	//[WARNING] retVar should be freed by caller
	LeftValue *lv = seg;
	OaClassMember *member = NULL;
	if (lv->next != NULL) {
		//class
		OaVar *tmpVar = getVar('%' + std::string(lv->name).substr(1));
		if (tmpVar == NULL) return NULL;
		std::string classType = tmpVar->type.substr(1);
		while (lv->next != NULL) {
			OaClass *oaClass = &(oaClasses.find(classType)->second);
			member = findMemberInClass('%' + std::string(lv->next->name).substr(1), oaClass);
			bool inParent = false;
			while (member == NULL && oaClass->parent != "") {
				result += '%' + myItoa(temVarNo++) + " = getelementptr inbounds %class." + oaClass->name + ", %class." + oaClass->name + "* %" + std::string(lv->name).substr(1) + ", i32 0, i32 0\n";
				classType = oaClass->parent;
				oaClass = &(oaClasses.find(oaClass->parent)->second);
				member = findMemberInClass('%' + std::string(lv->next->name).substr(1), oaClass);
				inParent = true;
			}
			if (member == NULL) { panic("Error in parseLeftValue: no member in class"); return NULL; }
			if (inParent) {
				result += '%' + myItoa(temVarNo++) + " = getelementptr inbounds %class." + oaClass->name + ", %class." + oaClass->name + "* %" + myItoa(temVarNo - 2) + ", i32 0, i32 " + myItoa(member->pos) + "\n";
			}
			else {
				result += '%' + myItoa(temVarNo++) + " = getelementptr inbounds %class." + oaClass->name + ", %class." + oaClass->name + "* %" + std::string(lv->name).substr(1) + ", i32 0, i32 " + myItoa(member->pos) + "\n";
			}
			classType = std::string(member->type).substr(1);
			lv = lv->next;
		}
		int index = temVarNo - 1;
		result += '%' + myItoa(temVarNo++) + " = load " + member->type + ", " + member->type + "* %" + myItoa(index) + ", align " + myItoa(member->align) + '\n';
		

		//[WARNING] retVar should be freed by caller
		OaVar *retVar = new OaVar;
		retVar->name = '%' + myItoa(temVarNo - 1);
		retVar->align = member->align;
		retVar->type = member->type;
		retVar->size = 0;
		return retVar;
	}
	else {
		//[WARNING] retVar should be freed by caller
		OaVar *tmpVar = getVar('%' + std::string(seg->name).substr(1));
		if (tmpVar == NULL) {
			return NULL;
		}
		if (tmpVar->type[0] == '#') {
			OaVar *retVar = new OaVar;
			retVar->name = tmpVar->name;
			retVar->align = tmpVar->align;
			retVar->type = tmpVar->type;
			return retVar;
		}
		else{
			int index = temVarNo - 1;
			result += '%' + myItoa(temVarNo++) + " = load " + tmpVar->type + ", " + tmpVar->type + "* " + tmpVar->name + ", align " + myItoa(tmpVar->align) + '\n';
			OaVar *retVar = new OaVar;
			retVar->name = '%' + myItoa(temVarNo - 1);
			retVar->align = tmpVar->align;
			retVar->type = tmpVar->type;
			return retVar;
		}
	}
	
}

struct OaVar* g_parseArrayValue(std::string&result, ArrayValue* seg) {
	if (seg == NULL) {
		return NULL;
	}
	//[WARNING] temVar should be freed by caller
	struct OaVar* refVar = g_parseLeftValue(result, seg->name);
	if (refVar == NULL && inClassMethod) {
		//class method
		LeftValue lv;
		char tmpCh[7] = "%.this";
		lv.name = tmpCh;
		lv.next = seg->name;
		refVar = g_parseLeftValue(result, &lv);
		if (refVar == NULL) { panic("Error in parseArrayValue: no variable found"); return NULL; }
	}
	
	struct OaVar* idxVar = g_parseExpression(result, seg->index);
	if (idxVar == NULL && inClassMethod) {
		//class method
		LeftValue lv;
		char tmpCh[7] = "%.this";
		lv.name = tmpCh;
		lv.next = seg->index->name;
		idxVar = g_parseLeftValue(result, &lv);
		if (idxVar == NULL) { panic("Error in parseArrayValue: no variable found"); return NULL; }
	}
	struct OaVar* temVar = new struct OaVar;
	if (refVar != NULL && idxVar != NULL) {
		result += '%' + myItoa(temVarNo++) + " = ";
		result += "getelementptr inbounds i32, " + refVar->type + " ";
		result += refVar->name + ", ";
		result += "i32 " + idxVar->name + endLine;
		result += '%' + myItoa(temVarNo++) + " = load i32, i32* %" + myItoa(temVarNo - 2) + ", align 4\n";
		temVar->name = '%' + myItoa(temVarNo - 1);
		temVar->type = refVar->type;
		temVar->type.pop_back();
		temVar->align = refVar->align;
		return temVar;
	}
}

struct OaVar* g_parseFunctionValue(std::string&result, FunctionValue* seg) {
	if (seg == NULL) {
		return NULL;
	}

	//[TODO] for now, not consider function call in the class which in another class
	std::string funcName = "";
	std::string callerName = seg->name->name;
	if (seg->name->next != NULL) {
		OaVar *tmpVar = getVar('%' + std::string(seg->name->name).substr(1));
		if (tmpVar == NULL) { panic("Error in parseFunctionValue: class name not found"); return NULL; }
		funcName = tmpVar->type.substr(1) + seg->name->next->name;
	}
	else {
		funcName = seg->name->name;
	}
	std::map<std::string, OaFunction>::iterator iter = oaFunctions.find(funcName);
	if (iter == oaFunctions.end() && inClassMethod) {
		//call function in class method
		iter = oaFunctions.find(methodClassNameNow + funcName);
		callerName = "%.this";
		if (iter == oaFunctions.end()) {
			panic("in parseFunctionValue: no function named" + std::string(seg->name->name));
			return NULL;
		}
	}

	std::string retType = iter->second.type;
	std::string className = iter->second.className;
	std::string name = "";
	if (iter->second.className != "") {
		name = '@' + iter->second.className + '.' + iter->second.name.substr(1);
	}
	else {
		name = '@' + iter->second.name.substr(1);
	}
	struct FormParam *formParams = iter->second.params;
	
	struct FactParam *factParams = seg->factParam;
	//[TODO] check params, return type etc.
	
	//parameters
	//add class to params
	//[TODO] see above, no function in extended class
	std::string paramStr;
	if (iter->second.className != "") {
		FactParam *newParams = new FactParam;
		newParams->next = seg->factParam;
		Expression tmpExp;
		tmpExp.left = NULL;
		tmpExp.right = NULL;
		tmpExp.op = OA_EXP_NONE;
		tmpExp.leafType = OA_LEFT_VALUE;
		//[TODO] see above, revise callerName
		int tmpSize = callerName.size();
		char *tmpCh = new char[tmpSize + 1];
		for (int i = 0; i < tmpSize; ++i) {
			tmpCh[i] = callerName[i];
		}
		tmpCh[tmpSize] = '\0';
		LeftValue tmpLv;
		tmpLv.name = tmpCh;
		tmpLv.next = NULL;
		tmpExp.name = &tmpLv;
		newParams->exp = &tmpExp;
		paramStr = g_parseFactParam(result, newParams);
		delete[] tmpCh;
	}
	else {
		paramStr = g_parseFactParam(result, factParams);
	}
	//[TODO] align due to ret Type, now just deal with int return value
	
	if(retType == "void"){
		result += "call " + retType + ' ' + name + "(" + paramStr + ")\n";
	}
	else {
		struct OaVar *oaVar = new OaVar;
		oaVar->name = '%' + myItoa(temVarNo++);
		oaVar->type = retType;
		oaVar->align = 4;
		result += oaVar->name + " = call " + retType + ' ' + name + "(" + paramStr + ")\n";
		return oaVar;
	}
}
//------------------end expression part-------------------

//---------------------parameter part---------------------
std::string g_parseFormParam(std::string&result, FormParam*seg) {
	//generate formparam part, and add local variables into allVars
	//return predefine statements
	if (seg == NULL) {
		return "" ;
	}
	std::string retStr = "";
	while (seg != NULL) {
		if (seg->type[0] == '#') {
			result += "%class." + std::string(seg->type).substr(1) + '*';
			//add to allVars
			std::map<std::string, OaClass>::iterator iter = oaClasses.find(std::string(seg->type).substr(1));
			if (iter == oaClasses.end()) { panic("class method wrong: class type not found"); return ""; }
			OaVar *var = new OaVar;
			var->name = "%.this";
			var->type = seg->type;
			var->align = iter->second.align;
			addVar(var);
		}
		else {
			//add to allVars
			if (std::string(seg->type) == "int") {
				OaVar *paramVar = new OaVar;
				paramVar->name = '%' + std::string(seg->name).substr(1);
				paramVar->type = "i32";
				paramVar->align = 4;
				addVar(paramVar);
				//temVarNo++;	//llvm regular
				result += paramVar->type;
				retStr += paramVar->name + " = alloca " + paramVar->type + ", align " + myItoa(paramVar->align) +'\n';
				retStr += "store " + paramVar->type + ' ' + paramVar->name + "., " + paramVar->type + "* " + paramVar->name + ", align " + myItoa(paramVar->align) + '\n';
			}
			else if (std::string(seg->type) == "double") {
				OaVar *paramVar = new OaVar;
				paramVar->name = '%' + std::string(seg->name).substr(1);
				paramVar->type = "double";
				paramVar->align = 8;
				addVar(paramVar);
				//temVarNo++;	//llvm regular
				result += paramVar->type;
				retStr += paramVar->name + " = alloca " + paramVar->type + ", align " + myItoa(paramVar->align) + '\n';
				retStr += "store " + paramVar->type + ' ' + paramVar->name + "., " + paramVar->type + "* " + paramVar->name + ", align " + myItoa(paramVar->align) + '\n';
			}
			else if (std::string(seg->type) == "char") {
				OaVar *paramVar = new OaVar;
				paramVar->name = '%' + std::string(seg->name).substr(1);
				paramVar->type = "i8";
				paramVar->align = 1;
				addVar(paramVar);
				//temVarNo++;	//llvm regular
				result += paramVar->type;
				retStr += paramVar->name + " = alloca " + paramVar->type + ", align " + myItoa(paramVar->align) + '\n';
				retStr += "store " + paramVar->type + ' ' + paramVar->name + "., " + paramVar->type + "* " + paramVar->name + ", align " + myItoa(paramVar->align) + '\n';
			}
			else if (std::string(seg->type) == "int[]") {
				OaVar *paramArray = new OaVar;
				paramArray->name = '%' + std::string(seg->name).substr(1);
				paramArray->type = "i32*";
				paramArray->align = 4;
				paramArray->size = 0;
				addArray(paramArray);
				result += paramArray->type;
				retStr += paramArray->name + " = alloca " + paramArray->type + ", align " + myItoa(paramArray->align) + '\n';
				retStr += "store " + paramArray->type + ' ' + paramArray->name + "., " + paramArray->type + "* " + paramArray->name + ", align " + myItoa(paramArray->align) + '\n';

				//[WARNING] let size = 0 to indicate the first time to malloc
				OaVar *tmpVar = new OaVar;
				tmpVar->align = 4;
				tmpVar->type = "i32";
				tmpVar->size = 0;
				tmpVar->name = paramArray->name + ".length";
				addVar(tmpVar);

			}
			else if (std::string(seg->type) == "double[]") {
				OaVar *paramArray = new OaVar;
				paramArray->name = '%' + std::string(seg->name).substr(1);
				paramArray->type = "double*";
				paramArray->align = 8;
				paramArray->size = 0;
				addArray(paramArray);
				result += paramArray->type;
				retStr += paramArray->name + " = alloca " + paramArray->type + ", align " + myItoa(paramArray->align) + '\n';
				retStr += "store " + paramArray->type + ' ' + paramArray->name + "., " + paramArray->type + "* " + paramArray->name + ", align " + myItoa(paramArray->align) + '\n';

				//[WARNING] let size = 0 to indicate the first time to malloc
				OaVar *tmpVar = new OaVar;
				tmpVar->align = 4;
				tmpVar->type = "i32";
				tmpVar->size = 0;
				tmpVar->name = paramArray->name + ".length";
				addVar(tmpVar);

			}
			else if (std::string(seg->type) == "char[]") {
				OaVar *paramArray = new OaVar;
				paramArray->name = '%' + std::string(seg->name).substr(1);
				paramArray->type = "i8*";
				paramArray->align = 1;
				paramArray->size = 0;
				addArray(paramArray);
				result += paramArray->type;
				retStr += paramArray->name + " = alloca " + paramArray->type + ", align " + myItoa(paramArray->align) + '\n';
				retStr += "store " + paramArray->type + ' ' + paramArray->name + "., " + paramArray->type + "* " + paramArray->name + ", align " + myItoa(paramArray->align) + '\n';

				//[WARNING] let size = 0 to indicate the first time to malloc
				OaVar *tmpVar = new OaVar;
				tmpVar->align = 4;
				tmpVar->type = "i32";
				tmpVar->size = 0;
				tmpVar->name = paramArray->name + ".length";
				addVar(tmpVar);
			}
			else if (seg->type[0] == '#') {
				//class
				OaVar *paramVar = new OaVar;
				std::map<std::string, OaClass>::iterator iter = oaClasses.find(std::string(seg->type).substr(1));
				if (iter == oaClasses.end()) { panic("Error in parseFormParam: unknown class type"); return ""; }
				paramVar->align = iter->second.align;
				paramVar->type = std::string(seg->type);
				paramVar->name = '%' + std::string(seg->name).substr(1);
				addVar(paramVar);
			}
			else {
				panic("Error in parseFormParam: wrong type");
				return "";
			}
		}
		result += " %" + std::string(seg->name).substr(1);
		if (seg->type[0] != '#') {
			result += '.';	//llvm regular, for loading value due to address alloc
		}
		
		if (seg->next != NULL) {
			result += ", ";
		}
		seg = seg->next;
	}
	return retStr;
}

std::string g_parseFactParam(std::string&result, FactParam* seg) {
	if (seg == NULL) {
		return "";
	}
	std::string str;
	OaVar *tmpVar = NULL;
	while (seg != NULL) {
		tmpVar = g_parseExpression(result, seg->exp);
		
		if (tmpVar == NULL && inClassMethod) {
			LeftValue lv;
			lv.name = "%.this";
			lv.next = seg->exp->name;
			tmpVar = g_parseLeftValue(result, &lv);
		}
		if (tmpVar == NULL) { panic("wrong param"); return ""; }

		if (tmpVar->type[0] == '#'){
			//class type
			str += "%class." + tmpVar->type.substr(1) + "* " + tmpVar->name;
		}
		else {
			//not class type
			str += tmpVar->type + " " + tmpVar->name;
		}
		if (seg->next != NULL) {
			str += ", ";
		}
		seg = seg->next;
	}
	return str;
}
//Added by @Xie LW
std::string myItoa(int num) {
	char temNum[32];
	sprintf(temNum, "%d", num);
	return std::string(temNum);
}

std::string myDtoa(double num) {
	char temNum[16];
	sprintf(temNum, "%.6e", num);
	return std::string(temNum);
}
std::string myDtoa(std::string num_s) {
	std::stringstream iss(num_s);
	double num;
	iss >> num;
	return myDtoa(num);
}
struct OaVar* getVar(std::string varName, int *isGlobal) {
	//if, elif, else, while, foreach oaPathStk local variable
	std::list<std::string> tmpStack = oaPathStk;
	while (tmpStack.size() != 0) {
		std::string tmpVarName = "%";
		for (std::list<std::string>::iterator iter = tmpStack.begin(); iter != tmpStack.end(); ++iter) {
			tmpVarName += *iter + ".";
		}
		tmpVarName += varName.substr(1);
		for (int i = 0; i < allVars.size(); i++) {
			if (allVars[i]->name == tmpVarName)
				return allVars[i];
		}
		tmpStack.pop_back();
	}
	//normal local variable
	for (int i = 0; i < allVars.size(); i++) {
		if (allVars[i]->name == varName)
			return allVars[i];
	}
	//global variable
	varName = '@' + varName.substr(1);
	for (int i = 0; i < allVars.size(); i++) {
		if (allVars[i]->name == varName) {
			if (isGlobal != NULL) *isGlobal = 1;
			return allVars[i];
		}
	}
	return NULL;
}

std::string reduceAt(std::string varName) {
	if (varName[0] == '@')
		varName.erase(varName.begin());
	return varName;
}

void addVar(struct OaVar *oaVar) {
	oaVar->size = 0;
	allVars.push_back(oaVar);
}
void addArray(struct OaVar *oaVar) {
	allVars.push_back(oaVar);
}
std::string getType(std::string varName) {
	for (int i = 0; i < allVars.size(); i++) {
		if (allVars[i]->name == varName)
			return allVars[i]->type;
	}
}

int getAlign(std::string varName) {
	for (int i = 0; i < allVars.size(); i++) {
		if (allVars[i]->name == varName)
			return allVars[i]->align;
	}
}
//-------------------end parameter part-------------------


void parsePrintFunction(struct FactParam *params) {
	//[TODO] check parameters
	//[TODO] % param
	hasPrint = true;
	std::string tmpstr = std::string(params->exp->type_string).substr(1);
	std::string str = "";
	int size = tmpstr.size();
	for (int i = 0; i < size; ++i) {
		if (tmpstr[i] == '\\') {
			if (i == size - 1) {
				panic("wrong print string");
				return;
			}
			i++;
			if (tmpstr[i] == '\\') {
				str += '\\';
			}
			else if(tmpstr[i] == 'n') {
				str += "\\0A";
			}
		}
		else {
			str += tmpstr[i];
		}
	}

	//update result
	size = str.size();
	for (int i = 0; i < size; ++i) {
		if (str[i] == '\\') size -= 2;
	}
	std::string paramStr = "";
	if(params->next) paramStr = g_parseFactParam(result, params->next);
	result += "call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([" + myItoa(size) + " x i8], [" + myItoa(size) + " x i8]* @.str." + myItoa(printStringIndex) + ", i32 0, i32 0)";
	if (params->next) result += ", " + paramStr;
	result += ")\n";

	//update printStrings vector
	str.pop_back();
	printStrings.push_back(str);
	printStringIndex++;
	temVarNo++;		//llvm regular
}

void freeArray(std::string index, std::string type, int align){
	//index: contain %: register
	//index: not conain %: in allVars
	hasFree = true;
	if (index[0] == '%') {
		result += '%' + myItoa(temVarNo++) + " = load " + type + ", " + type + "* " + index + " align " + myItoa(align) + '\n';
	}
	else {
		int fromGlobal = 0;
		if (getVar('%' + index, &fromGlobal) == NULL){
			//[TODO] wrong
			return;
		}
		if (fromGlobal == 1) {
			result += '%' + myItoa(temVarNo++) + " = load " + type + ", " + type + "* @" + index + " align " + myItoa(align) + '\n';
		}
		else {
			result += '%' + myItoa(temVarNo++) + " = load " + type + ", " + type + "* %" + index + " align " + myItoa(align) + '\n';
		}
	}
	if (type != "i8*")  result += '%' + myItoa(temVarNo++) + " = bitcast " + type + "* %" + myItoa(temVarNo-2) + " to i8*\n";
	result += "call void @free(i8* %" + myItoa(temVarNo-1) + ")\n";
}
std::string mallocArray(std::string index, std::string type, int align, std::string size) {
	//index: contain %: register
	//index: not conain %: in allVars
	hasMalloc = true;
	if (size[0] != '%') {
		int newSize = atoi(size.c_str());
		newSize *= align;
		size = myItoa(newSize);
	}
	else {
		result += '%' + myItoa(temVarNo++) + " = mul nsw i32 " + myItoa(align) + ", " + size + '\n';
		size = '%' + myItoa(temVarNo - 1);
	}

	result += '%' + myItoa(temVarNo++) + " = call noalias i8* @malloc (i32 " + size + ")\n";
	result += '%' + myItoa(temVarNo++) + " = bitcast i8* %" + myItoa(temVarNo-2) + " to " + type + '\n';
	if (index[0] == '%') {
		result += "store " + type + " %" + myItoa(temVarNo - 1) + ", " + type + "* " + index + ", align " + myItoa(align) + '\n';
	}
	else {
		int fromGlobal = 0;
		if (getVar('%' + index, &fromGlobal) == NULL) {
			//[TODO] wrong
			return 0;
		}
		if (fromGlobal == 1) {
			result += "store " + type + " %" + myItoa(temVarNo - 1) + ", " + type + "* @" + index + ", align " + myItoa(align) + '\n';
		}
		else {
			result += "store " + type + " %" + myItoa(temVarNo - 1) + ", " + type + "* %" + index + ", align " + myItoa(align) + '\n';
		}
	}


	return size;
}

OaClassMember *findMemberInClass(std::string member, OaClass *oaClass) {
	std::map<std::string, OaClassMember>::iterator iter = oaClass->members.find(member);
	if (iter == oaClass->members.end()) return NULL;
	else return &(iter->second);
}

void zeroClassArrayLength(const std::string &name, const std::string &classType) {
	std::map<std::string, OaClass>::iterator classIter = oaClasses.find(classType);
	if (classIter == oaClasses.end()) { panic("error in zeroClassArrayLength: class" + classType + "not found"); return; }
	std::map<std::string, OaClassMember>::iterator iter;
	for (iter = classIter->second.members.begin(); iter != classIter->second.members.end(); ++iter) {
		if (iter->second.type[0] == '#') {
			std::string newName = name + iter->second.name;
			zeroClassArrayLength(newName, std::string(iter->second.type).substr(1));
		}
		else if(iter->second.type[iter->second.type.size()-1] == '*'){
			//[WARNINIG] using parseVarDefineNode function
			//llvm statememnts
			std::string newName = name + '.' + iter->second.name.substr(1) + ".length";
			int size = newName.size();
			//exp
			Expression exp;
			exp.left = NULL;
			exp.right = NULL;
			exp.op = OA_EXP_NONE;
			exp.leafType = OA_INT;
			exp.number_int = 0;
			//name
			char *tmpCh = new char[size+1];
			for (int i = 0; i < size; ++i) {
				tmpCh[i] = newName[i];
			}
			tmpCh[0] = '@';
			tmpCh[size] = '\0';
			//node
			VarDefineNode node;
			node.exp = &exp;
			node.name = tmpCh;
			node.type = "int";
			g_parseVarDefineNode(result, &node);
			delete[] tmpCh;
		}
	}

	if (classIter->second.parent != "") {
		zeroClassArrayLength(name, classIter->second.parent);
	}
}

void panic(const std::string &wrongInfo) {
	compilePass = false;
	compileLog = "Error[Line " + myItoa(lineno) + "]:" + wrongInfo;
	return;
}

int g_getTreeRaw(const char* filename) {
	int rtcode = executeParser(filename);
	if (rtcode != 0) {
		printf("error\n");
	}

	lineno = 0;
	//Added by @Xie LW
	temVarNo = 0;
	g_parseNodeList(result, parseTree->root, "root");
	return rtcode;
}

int main(int argc, char** argv) {
	if (argc < 3) {
		std::cout << "oa_compiler.exe [input_name] [output_name]";
		return 1;
	}
	g_getTreeRaw(argv[1]);
	//check function declared but not defined
	std::map<std::string, OaFunction>::iterator iter;
	for (iter = oaFunctions.begin(); iter != oaFunctions.end(); ++iter) {
		if (iter->second.isDefined == false) { compilePass = false;  compileLog = "function" + iter->second.name + "declared but not defined\n"; }
	}

	if (compilePass) {
		//generate code to file
		std::ofstream ost("tmp.ll");
		ost << "target triple = \"i686-pc-windows-gnu\"\n\n";
		for (int i = 0; i < printStringIndex; ++i) {
			int size = printStrings[i].size() + 1;
			int tmpsize = printStrings[i].size();
			for (int j = 0; j < tmpsize; ++j) {
				if (printStrings[i][j] == '\\') size -= 2;
			}
			ost << "@.str." + myItoa(i) + " = constant [" + myItoa(size) + " x i8] c\"" + printStrings[i] + "\\00\", align 1\n";
		}
		ost << "\n";

		//print global variables
		int tmpSize = globalVariables.size();
		for (int i = 0; i < tmpSize; ++i) {
			ost << globalVariables[i];
		}

		ost << result << std::endl;
		if (hasPrint) {
			ost << "declare i32 @printf(i8*, ...)\n";
		}
		if(hasMalloc){
			ost << "declare noalias i8* @malloc(i32)\n";
		}
		if(hasFree){
			ost << "declare void @free(i8*)\n";
		}
		ost.close();
		std::string sysStr = "clang -o " + std::string(argv[2]) + " tmp.ll";
		system(sysStr.c_str());
		std::cout << "code generate successfully!\n";
	}
	else {
		std::cout << compileLog << std::endl;
	}
}