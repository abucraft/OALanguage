#include"oa.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <map>
#define N_INT_CHAR 11

std::string result;
struct ParseTree *parseTree;
static int lineno;

//Added by @Xie LW----------------------
static int temVarNo;
struct OaVar {
	std::string name;
	std::string type;
	int align;
};
struct OaArray {
	std::string name;
	std::string type;
	int align;
	int size;
};
std::vector<struct OaVar*>allVars;
std::vector<struct OaArray*>allArrays;
const std::string endLine = "\n";
std::string myItoa(int num);
std::string myDtoa(double num);
std::string myDtoa(std::string num);
std::string reduceAt(std::string varName);
std::string getType(std::string varName);
int getAlign(std::string varName);
struct OaVar* getVar(std::string varName);
struct OaArray* getArray(std::string arrayName);
void addVar(struct OaVar* oaVar);
void addArray(struct OaArray* oaArray);
struct OaFunction {
	std::string name;
	std::string type;
	std::string className;
	FormParam *params;
};

struct OaClassMember {
	std::string name;
	int isFunc;
	std::string type;
	FormParam *params;
};

struct OaClass {
	std::string name;
	std::string parent;
	std::map<std::string, OaClassMember> members;
};

int OaIfIdx = 0;
int OaCmpIdx = 0;

std::map<std::string, OaFunction> oaFunctions;
std::map<std::string, OaClass> oaClasses;

std::string classNow = "";
//--------------------------------------
//---------------------tree node part---------------------
void parseNodeList(std::string &result, struct TreeNode* seg, std::string name);
void parseTreeNode(std::string &result, struct TreeNode *seg);
void parseVarDeclareNode(std::string &result, struct VarDeclareNode *seg);
void parseVarDefineNode(std::string &result, struct VarDefineNode *seg);
void parseVarAssignNode(std::string &result, struct VarAssignNode *seg);
void parseArrayDeclareNode(std::string &result, struct ArrayDeclareNode *seg);
void parseArrayDefineNode(std::string &result, struct ArrayDefineNode *seg);
void parseArrayAssignNode(std::string &result, struct ArrayAssignNode *seg);
void parseIfNode(std::string &result, struct IfNode *seg);
void parseElifNode(std::string &result, struct ElifNode *seg);
void parseElseNode(std::string &result, struct ElseNode *seg);
void parseWhileNode(std::string &result, struct WhileNode *seg);//----A
void parseForeachNode(std::string &result, struct ForeachNode *seg);//----A
void parseClassDefineNode(std::string &result, struct ClassDefineNode *seg);//----A
void parseFunctionDeclareNode(std::string &result, struct FunctionDeclareNode *seg);
void parseFunctionDefineNode(std::string &result, struct FunctionDefineNode *seg);//----A
void parseClassMethodDefineNode(std::string &result, struct ClassMethodDefineNode *seg);//----A
void parseBreakNode(std::string &result);
void parseContinueNode(std::string &result);
void parseReturnNode(std::string &result, struct ReturnNode *seg);
//-------------- -----end tree node part-------------------
//---------------------expression part---------------------

struct OaVar* parseExpression(std::string& result, struct Expression* seg);
struct OaVar* parseLeftValue(std::string&result, struct LeftValue* seg);
void parseArrayValue(std::string&result, struct ArrayValue* seg);
void parseFunctionValue(std::string&result, struct FunctionValue* seg);
//-------------------end expression part-------------------
//---------------------parameter part---------------------
void parseFormParam(std::string&result, FormParam*seg);
void parseFactParam(std::string&result, struct FactParam* seg);
//-------------------end parameter part-------------------





//---------------------tree node part---------------------
void parseNodeList(std::string& result, TreeNode* seg, std::string name) {
	//result += "{\"name\":\"";
	//result += name;
	//result += "\",\"children\":[\n";
	while (seg != NULL) {
		parseTreeNode(result, seg);
		if (seg->next != NULL) {
			//result += ",\n";
		}
		seg = seg->next;
	}
	//result += "]}";
}

void parseTreeNode(std::string& result, TreeNode* seg) {
	if (seg == NULL) {
		return;
	}

	switch (seg->type) {
	case VAR_DECLARE_NODE:
		parseVarDeclareNode(result, seg->varDeclareNode);
		break;
	case VAR_DEFINE_NODE:
		parseVarDefineNode(result, seg->varDefineNode);
		break;
	case VAR_ASSIGN_NODE:
		parseVarAssignNode(result, seg->varAssignNode);
		break;
	case ARRAY_DECLARE_NODE:
		parseArrayDeclareNode(result, seg->arrayDeclareNode);
		break;
	case ARRAY_DEFINE_NODE:
		parseArrayDefineNode(result, seg->arrayDefineNode);
		break;
	case ARRAY_ASSIGN_NODE:
		parseArrayAssignNode(result, seg->arrayAssignNode);
		break;
	case IF_NODE:
		parseIfNode(result, seg->ifNode);
		break;
	case ELIF_NODE:
		parseElifNode(result, seg->elifNode);
		break;
	case ELSE_NODE:
		parseElseNode(result, seg->elseNode);
		break;
	case WHILE_NODE:
		parseWhileNode(result, seg->whileNode);
		break;
	case FOREACH_NODE:
		parseForeachNode(result, seg->foreachNode);
		break;
	case CLASS_DEFINE_NODE:
		parseClassDefineNode(result, seg->classDefineNode);
		break;
	case FUNCTION_DECLARE_NODE:
		parseFunctionDeclareNode(result, seg->functionDeclareNode);
		break;
	case FUNCTION_DEFINE_NODE:
		parseFunctionDefineNode(result, seg->functionDefineNode);
		break;
	case CLASS_METHOD_DEFINE_NODE:
		parseClassMethodDefineNode(result, seg->classMethodDefineNode);
		break;
	case BREAK_NODE:
		parseBreakNode(result);
		break;
	case CONTINUE_NODE:
		parseContinueNode(result);
		break;
	case RETURN_NODE:
		parseReturnNode(result, seg->returnNode);
		break;
	default:
		break;
	}
}

void parseVarDeclareNode(std::string& result, struct VarDeclareNode* seg) {
	if (seg == NULL) {
		return;
	}
	char numStr[N_INT_CHAR];
	sprintf(numStr, "%d", ++lineno);

	/*result += "{\"name\":\"" + std::string(numStr) + ": var declare\",\"children\":[";
	result += "{\"name\":\"" + std::string(seg->type) + "\"},";
	result += "{\"name\":\"" + std::string(seg->name) + "\"}";
	result += "]}";*/

	//Modified by @Xie LW--------------------------------------
	struct OaVar *temVar = new struct OaVar;
	temVar->name = "%"+reduceAt(std::string(seg->name));
	if (seg->type == std::string("int")) {
		temVar->type = "i32";
		temVar->align = 4;
	}
	if (seg->type == std::string("char")) {
		temVar->type = "i8";
		temVar->align = 1;
	}
	if (seg->type == std::string("double")) {
		temVar->type = "double";
		temVar->align = 8;
	}
	addVar(temVar);
	result += temVar->name + " ";
	result += "= " + std::string("alloca " + temVar->type + ", ");
	result += std::string("align ") + myItoa(temVar->align) + endLine;
	//----------------------------------------------------------
}

void parseVarDefineNode(std::string& result, VarDefineNode* seg) {
	if (seg == NULL) {
		return;
	}
	/*char numStr[N_INT_CHAR];
	sprintf(numStr, "%d", ++lineno);
	result += "{\"name\":\"" + std::string(numStr) + ": var define\",\"children\":[";
	result += "{\"name\":\"" + std::string(seg->type) + "\"},";
	result += "{\"name\":\"" + std::string(seg->name) + "\"},";
	result += "{\"name\":\"exp\",\"children\":[{\"name\":\"";
	parseExpression(result, seg->exp);
	result += "\"}]}";
	result += "]}";*/

	//Modified by @Xie LW
	struct OaVar *temVar = new struct OaVar;
	temVar->name = "%" + reduceAt(std::string(seg->name));
	if (seg->type == std::string("int")) {
		temVar->type = "i32";
		temVar->align = 4;
	}
	if (seg->type == std::string("char")) {
		temVar->type = "i8";
		temVar->align = 1;
	}
	if (seg->type == std::string("double")) {
		temVar->type = "double";
		temVar->align = 8;
	}
	addVar(temVar);
	result +=  temVar->name + " ";
	result += "= " + std::string("alloca " + temVar->type + ", ");
	result += std::string("align ") + myItoa(temVar->align) + endLine;
	struct OaVar* refVar = parseExpression(result, seg->exp);
	result += "store " + temVar->type + " ";
	if (temVar->type == "double"&&refVar->name[0] != '%')
		result += myDtoa(refVar->name) + ", ";
	else
		result += refVar->name + ", ";
	result += temVar->type + "* " + temVar->name + ", ";
	result += "align " + myItoa(temVar->align) + endLine;
}

void parseVarAssignNode(std::string& result, VarAssignNode* seg) {
	if (seg == NULL) {
		return;
	}
	/*char numStr[N_INT_CHAR];
	sprintf(numStr, "%d", ++lineno);

	result += "{\"name\":\"" + std::string(numStr) + ": var assign\",\"children\":[";
	result += "{\"name\":\"";
	parseLeftValue(result, seg->name);
	result += "\"},";
	if (seg->expOfVar) {
		result += "{\"name\":\"expOfVar\",\"children\":[{\"name\":\"";
		parseExpression(result, seg->expOfVar);
		result += "\"}]},";
	}
	result += "{\"name\":\"expValue\",\"children\":[{\"name\":\"";
	parseExpression(result, seg->exp);
	result += "\"}]}";
	result += "]}";*/
	struct OaVar *temVar = new struct OaVar;
	if (seg->expOfVar != NULL) {
		struct OaArray* temArray = getArray("%" + reduceAt(seg->name->name));
		if (temArray != NULL) {
			struct OaVar* idxVar = parseExpression(result, seg->expOfVar);
			result += "%" + myItoa(temVarNo++) + " = ";
			result += "load " + temArray->type + "** " + temArray->name + ", ";
			result += "align 8" + endLine;
			temVar->name = "%" + myItoa(temVarNo - 1);
			result += "%" + myItoa(temVarNo++) + " = ";
			result += "getelementptr inbounds " + temArray->type + " " + temVar->name + ", ";
			result += "i64 " + idxVar->name + endLine;
			temVar->name = "%" + myItoa(temVarNo - 1);
		}
	}
	else
		temVar = getVar("%" + reduceAt(seg->name->name));
	if (temVar != NULL) {
		struct OaVar* refVar = parseExpression(result, seg->exp);
		result += "store " + temVar->type + " ";
		if (temVar->type == "double"&&refVar->name[0] != '%')
			result += myDtoa(refVar->name) + ", ";
		else
			result += refVar->name + ", ";
		result += temVar->type + "* " + temVar->name + ", ";
		result += "align " + myItoa(temVar->align) + endLine;
	}
}

void parseArrayDeclareNode(std::string&result, ArrayDeclareNode* seg) {
	if (seg == NULL) {
		return;
	}
	/*char numStr[N_INT_CHAR];
	sprintf(numStr, "%d", ++lineno);

	result += "{\"name\":\"" + std::string(numStr) + ": array declare\",\"children\":[";
	result += "{\"name\":\"" + std::string(seg->type) + "\"},";
	result += "{\"name\":\"" + std::string(seg->name) + "\"}";
	result += "]}";*/
	struct OaArray *temArray = new struct OaArray;
	temArray->name = "%" + reduceAt(std::string(seg->name));
	//std::cout << "Debug: " << seg->type << std::endl;
	if (seg->type == std::string("int[]")) {
		temArray->type = "i32";
		temArray->align = 4;
	}
	if (seg->type == std::string("char[]")) {
		temArray->type = "i8";
		temArray->align = 1;
	}
	if (seg->type == std::string("double[]")) {
		temArray->type = "double";
		temArray->align = 8;
	}
	addArray(temArray);
	result += temArray->name + " ";
	result += "= " + std::string("alloca " + temArray->type + "*, ");
	result += std::string("align 8") + endLine;
}

void parseArrayDefineNode(std::string&result, ArrayDefineNode*seg) {
	if (seg == NULL) {
		return;
	}
	/*char numStr[N_INT_CHAR];
	sprintf(numStr, "%d", ++lineno);

	result += "{\"name\":\"" + std::string(numStr) + ": array define\",\"children\":[";
	result += "{\"name\":\"" + std::string(seg->type) + "\"},";
	result += "{\"name\":\"" + std::string(seg->name) + "\"},";
	result += "{\"name\":\"nElement\",\"children\":[{\"name\":\"";
	parseExpression(result, seg->exp);
	result += "\"}]}";
	result += "]}";*/
	struct OaArray *temArray = new struct OaArray;
	temArray->name = "%" + reduceAt(std::string(seg->name));
	//std::cout << "Debug: " << seg->type << std::endl;
	if (seg->type == std::string("int[]")) {
		temArray->type = "i32*";
		temArray->align = 4;
	}
	if (seg->type == std::string("char[]")) {
		temArray->type = "i8*";
		temArray->align = 1;
	}
	if (seg->type == std::string("double[]")) {
		temArray->type = "double*";
		temArray->align = 8;
	}
	struct OaVar* szeVar = parseExpression(result, seg->exp);
	if (szeVar != NULL) {
		std::stringstream oss(szeVar->name);
		oss >> temArray->size;
		std::cout << temArray->size << std::endl;
		addArray(temArray);
		result += temArray->name + " ";
		result += "= " + std::string("alloca " + temArray->type + "*, ");
		result += std::string("align 8") + endLine;
		result += "%" + myItoa(temVarNo++) + " = ";
		result += "call i8* @malloc";
		result +=  "(i64 " + myItoa(temArray->size*temArray->align)+")" + endLine;
		result += "%" + myItoa(temVarNo++) + " = ";
		result += "bitcast i8* %" + myItoa(temVarNo - 2) + " to " + temArray->type + endLine;
		result += "store " + temArray->type + " %" + myItoa(temVarNo - 1) + ", ";
		result += temArray->type + "* " + temArray->name + ", ";
		result += "align 8" + endLine;
	}
}

void parseArrayAssignNode(std::string&result, ArrayAssignNode*seg) {
	if (seg == NULL) {
		return;
	}
	char numStr[N_INT_CHAR];
	sprintf(numStr, "%d", ++lineno);

	result += "{\"name\":\"" + std::string(numStr) + ": array assign\",\"children\":[";
	result += "{\"name\":\"";
	parseLeftValue(result, seg->name);
	result += "\"},";
	result += "{\"name\":\"" + std::string(seg->type) + "\"},";
	result += "{\"name\":\"nElement\",\"children\":[{\"name\":\"";
	parseExpression(result, seg->exp);
	result += "\"}]}";
	result += "]}";
}

void parseIfNode(std::string&result, IfNode*seg) {
	if (seg == NULL) {
		return;
	}
	char ifIdx[25];
	char cmpIdx[25];
	itoa(OaIfIdx,ifIdx,10);
	itoa(OaCmpIdx,cmpIdx,10);
	std::string cmpLabel = std::string("%cmp")+cmpIdx;
	std::string ifLabel= std::string("if.then.")+ifIdx;
	std::string nextLabel;
	if(seg->elseStmts!=NULL||seg->elifStmts!=NULL){
		nextLabel = std::string("if.else.")+ifIdx;
	}else{
		nextLabel = std::string("if.end.")+ifIdx;
	}
	parseExpression(result, seg->exp);
	OaCmpIdx++;
	OaIfIdx++;
	result+=std::string("  br i1 ")+cmpLabel+','+" label %"+ifLabel+','+" label %"+nextLabel+'\n';
	result+=ifLabel+":\n";
	parseNodeList(result,seg->stmts,ifLabel);
	result+=nextLabel+":\n";
	struct TreeNode *tmp= seg->elifStmts;
	while(tmp!=NULL){
		parseTreeNode(result,seg->elifStmts);
		tmp = tmp->next;
	}
	if(seg->elseStmts){
		parseTreeNode(result,seg->elseStmts);
	}
	/*char numStr[N_INT_CHAR];
	sprintf(numStr, "%d", ++lineno);
	result += "{\"name\":\"" + std::string(numStr) + ": if node\",\"children\":[";
	result += "{\"name\":\"condition\",\"children\":[{\"name\":\"";
	parseExpression(result, seg->exp);
	result += "\"}]},";
	parseNodeList(result, seg->stmts, "if_stmts");
	struct TreeNode * tmp = seg->elifStmts;
	char tmpNumC[N_INT_CHAR];
	int tmpNum = 0;
	while (tmp != NULL) {
		result += ",";
		tmpNum++;
		sprintf(tmpNumC, "%d", tmpNum);
		result += "{\"name\":\"elif_part" + std::string(tmpNumC) + "\",\"children\":[";
		parseTreeNode(result, seg->elifStmts);
		tmp = tmp->next;
	}
	if (seg->elseStmts) {
		result += ",";
		result += "{\"name\":\"else_part\",\"children\":[";
		parseTreeNode(result, seg->elseStmts);
		result += "]}";
	}
	result += "]}";*/
}

void parseElifNode(std::string&result, ElifNode*seg) {
	if (seg == NULL) {
		return;
	}
	char ifIdx[25];
	char cmpIdx[25];
	itoa(OaIfIdx,ifIdx,10);
	itoa(OaCmpIdx,cmpIdx,10);
	std::string cmpLabel = std::string("%cmp")+cmpIdx;
	std::string ifLabel= std::string("if.then.")+ifIdx;
	std::string nextLabel = std::string("if.else.")+ifIdx;
	parseExpression(result, seg->exp);
	OaCmpIdx++;
	OaIfIdx++;
	result+=std::string("  br i1 ")+cmpLabel+','+" label %"+ifLabel+','+" label %"+nextLabel+'\n';
	result+=ifLabel+":\n";
	parseNodeList(result,seg->stmts,ifLabel);
	result+=nextLabel+":\n";
	/*result += "{\"name\":\"condition\",\"children\":[{\"name\":\"";
	parseExpression(result, seg->exp);
	result += "\"}]}";
	if (seg->stmts) {
		result += ",";
		parseNodeList(result, seg->stmts, "elif_stmts");
	}*/
}

void parseElseNode(std::string&result, ElseNode*seg) {
	if (seg == NULL) {
		return;
	}
	parseTreeNode(result, seg->stmts);
	//parseNodeList(result, seg->stmts, "else_stmts");
}

void parseWhileNode(std::string&result, WhileNode*seg) {
	if (seg == NULL) {
		return;
	}
	char numStr[N_INT_CHAR];
	sprintf(numStr, "%d", ++lineno);

	result += "{\"name\":\"" + std::string(numStr) + ": while node\",\"children\":[";
	result += "{\"name\":\"condition\",\"children\":[{\"name\":\"";
	parseExpression(result, seg->exp);
	result += "\"}]}";
	if (seg->stmts) {
		result += ",";
		parseNodeList(result, seg->stmts, "stmts");
	}
	result += "]}";
}

void parseForeachNode(std::string &result, ForeachNode *seg) {
	if (seg == NULL) {
		return;
	}
	char numStr[N_INT_CHAR];
	sprintf(numStr, "%d", ++lineno);

	result += "{\"name\":\"" + std::string(numStr) + ": foreach node\",\"children\":[";
	result += "{\"name\":\"" + std::string(seg->nameIn) + "\"},";
	result += "{\"name\":\"in " + std::string(seg->nameOut) + "\"}";
	if (seg->stmts) {
		result += ",";
		parseNodeList(result, seg->stmts, "stmts");
	}
	result += "]}";
}

//[TODO] variable declare in class
void parseClassDefineNode(std::string&result, struct ClassDefineNode *seg) {
	if (seg == NULL) {
		return;
	}
	classNow = seg->type;
	OaClass oaclass;
	oaclass.name = classNow;
	if (seg->typeParent) {
		oaclass.parent = std::string(seg->typeParent);
	}
	else {
		oaclass.parent = "";
	}
	result += "%class." + oaclass.name + " = type { ";
	//parseNodeList(result, seg->stmts, "stmts");
	result += "}\n";


	oaClasses.insert(std::pair<std::string, OaClass>(oaclass.name, oaclass));
	classNow = "";
}

void parseFunctionDeclareNode(std::string&result, FunctionDeclareNode*seg) {
	if (seg == NULL) {
		return;
	}
	char numStr[N_INT_CHAR];
	sprintf(numStr, "%d", ++lineno);

	result += "{\"name\":\"" + std::string(numStr) + ": function dec\",\"children\":[";
	if (seg->type) {
		result += "{\"ret type\":\"" + std::string(seg->type) + "\"},";
	}
	else {
		result += "{\"ret type\":\"void\"},";
	}
	result += "{\"name\":\"" + std::string(seg->name) + "\"},";
	result += "{\"name\":\"args\",\"children\":[{\"name\":\"";
	parseFormParam(result, seg->formParams);
	result += "\"}]}";
	result += "]}";
}



void parseFunctionDefineNode(std::string&result, FunctionDefineNode*seg) {
	if (seg == NULL) {
		return;
	}
	OaFunction oafunc;
	oafunc.className = classNow;
	//define
	result += "define ";
	//return type
	if (seg->type) {
		oafunc.type = std::string(seg->type);
	}
	else {
		oafunc.type = "void";
	}
	result += oafunc.type;

	//function name
	result += " ";
	oafunc.name = std::string(seg->name);
	result += oafunc.name;

	//parameters
	result += '(';
	parseFormParam(result, seg->formParams);
	result += ')';
	//statements
	result += "{\nentry:\n";
	if (seg->stmts) {
		parseNodeList(result, seg->stmts, "stmts");
	}
	result += '}';
	oafunc.params = seg->formParams;
	oaFunctions.insert(std::pair<std::string, OaFunction>(oafunc.className + oafunc.name, oafunc));
}

void parseClassMethodDefineNode(std::string&result, ClassMethodDefineNode*seg) {
	if (seg == NULL) {
		return;
	}
	char numStr[N_INT_CHAR];
	sprintf(numStr, "%d", ++lineno);

	result += "{\"name\":\"" + std::string(numStr) + ": class method def\",\"children\":[";
	if (seg->type) {
		result += "{\"ret type\":\"" + std::string(seg->type) + "\"}";
	}
	else {
		result += "{\"ret type\":\"void\"}";
	}
	result += ",{\"name\":\"class " + std::string(seg->classType) + "\"}";
	result += ",{\"name\":\"" + std::string(seg->name) + "\"}";
	if (seg->formParams) {
		result += ",{\"name\":\"args\",\"children\":[{\"name\":\"";
		parseFormParam(result, seg->formParams);
		result += "\"}]}";
	}
	if (seg->stmts) {
		result += ",";
		parseNodeList(result, seg->stmts, "stmts");
	}
	result += "]}";
}

void parseBreakNode(std::string &result) {
	char numStr[N_INT_CHAR];
	sprintf(numStr, "%d", ++lineno);

	result += "{\"name\":\"" + std::string(numStr) + ": break\"}";
}

void parseContinueNode(std::string &result) {
	char numStr[N_INT_CHAR];
	sprintf(numStr, "%d", ++lineno);

	result += "{\"name\":\"" + std::string(numStr) + ": continue\"}";
}

void parseReturnNode(std::string &result, struct ReturnNode *seg) {
	char numStr[N_INT_CHAR];
	sprintf(numStr, "%d", ++lineno);

	result += "{\"name\":\"" + std::string(numStr) + ": return\"";

	if (seg->exp) {
		result += ", \"children\":[{\"name\":\"";
		parseExpression(result, seg->exp);
		result += "\"}]";
	}
	result += '}';
}
//--------------------end tree node part-------------------

//---------------------expression part---------------------

struct OaVar* parseExpression(std::string &result, Expression* seg) {
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
		case OA_LEFT_VALUE:
			return parseLeftValue(result, seg->name);
			break;
		case OA_ARRAY_VALUE:
			parseArrayValue(result, seg->arrayValue);
			break;
		case OA_FUNCTION_VALUE:
			parseFunctionValue(result, seg->functionValue);
			break;
		default:
			std::cout << "Wrong with expression, leafType\n";
			break;
		}
		break;
	case OA_EXP_NOT:
		printf("! ");
		printExpression(seg->left);
		break;
	case OA_EXP_MULTIPLE: {
		/*parseExpression(result, seg->left);
		result += " * ";
		parseExpression(result, seg->right);*/
		//Added by @Xie LW
		struct OaVar*  leftVar = parseExpression(result, seg->left);
		struct OaVar* rightVar = parseExpression(result, seg->right);
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
	case OA_EXP_DIVIDE:
		parseExpression(result, seg->left);
		result += " / ";
		parseExpression(result, seg->right);
		break;
	case OA_EXP_PLUS: {
		/*parseExpression(result, seg->left);
		result += " + ";
		parseExpression(result, seg->right);*/
		//Added by @Xie LW
		struct OaVar*  leftVar = parseExpression(result, seg->left);
		struct OaVar* rightVar = parseExpression(result, seg->right);
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
		struct OaVar*  leftVar = parseExpression(result, seg->left);
		struct OaVar* rightVar = parseExpression(result, seg->right);
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
	case OA_EXP_EQ:
		parseExpression(result, seg->left);
		result += " == ";
		parseExpression(result, seg->right);
		break;
	case OA_EXP_NE:
		parseExpression(result, seg->left);
		result += " != ";
		parseExpression(result, seg->right);
		break;
	case OA_EXP_GT:
		parseExpression(result, seg->left);
		result += " > ";
		parseExpression(result, seg->right);
		break;
	case OA_EXP_GE:
		parseExpression(result, seg->left);
		result += " >= ";
		parseExpression(result, seg->right);
		break;
	case OA_EXP_LT:
		parseExpression(result, seg->left);
		result += " < ";
		parseExpression(result, seg->right);
		break;
	case OA_EXP_LE:
		parseExpression(result, seg->left);
		result += " <= ";
		parseExpression(result, seg->right);
		break;
	case OA_EXP_AND:
		parseExpression(result, seg->left);
		result += " && ";
		parseExpression(result, seg->right);
		break;
	case OA_EXP_OR:
		parseExpression(result, seg->left);
		result += " || ";
		parseExpression(result, seg->right);
		break;
	default:
		std::cout << "Wrong with expression, operator\n";
		break;
	}
	return NULL;
}

struct OaVar* parseLeftValue(std::string&result, LeftValue* seg) {
	if (seg == NULL) {
		return NULL;
	}
	/*while (seg != NULL) {
		result += seg->name;
		if (seg->next != NULL) {
			result += '.';
		}
		seg = seg->next;
	}*/
	//Modified by @Xie LW
	std::string temName;
	while (seg != NULL) {
		temName += seg->name;
		if (seg->next != NULL) {
			temName += '.';
		}
		seg = seg->next;
	}
	//std::cout << "Debug: " << temName << std::endl;
	struct OaVar* refVar = getVar("%"+reduceAt(temName));
	if (refVar != NULL) {
		struct OaVar* temVar = new struct OaVar;
		temVar->name = "%" + myItoa(temVarNo++);
		temVar->align = refVar->align;
		temVar->type = refVar->type;
		result += temVar->name + " = ";
		result += "load " + refVar->type + "* " + refVar->name + ", ";
		result += "align " + myItoa(refVar->align) + endLine;
		return temVar;
	}
	else {
		std::cout << "Debug: null" << std::endl;
		return NULL;
	}
}

void parseArrayValue(std::string&result, ArrayValue* seg) {
	if (seg == NULL) {
		return;
	}
	parseLeftValue(result, seg->name);
	result += '[';
	parseExpression(result, seg->index);
	result += ']';
}

void parseFunctionValue(std::string&result, FunctionValue* seg) {
	if (seg == NULL) {
		return;
	}
	parseLeftValue(result, seg->name);
	result += '(';
	parseFactParam(result, seg->factParam);
	result += ')';
}
//------------------end expression part-------------------

//---------------------parameter part---------------------
void parseFormParam(std::string&result, FormParam*seg) {
	if (seg == NULL) {
		return;
	}
	while (seg != NULL) {
		result += std::string(seg->type);
		result += " %";
		result += std::string(seg->name).substr(1);
		if (seg->next != NULL) {
			result += ", ";
		}
		seg = seg->next;
	}
}

void parseFactParam(std::string&result, FactParam* seg) {
	if (seg == NULL) {
		return;
	}
	while (seg != NULL) {
		parseExpression(result, seg->exp);
		if (seg->next != NULL) {
			result += ',';
		}
		seg = seg->next;
	}
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
struct OaVar* getVar(std::string varName) {
	for (int i = 0; i < allVars.size(); i++) {
		if (allVars[i]->name == varName)
			return allVars[i];
	}
	return NULL;
}
struct OaArray* getArray(std::string arrayName) {
	for (int i = 0; i < allArrays.size(); i++) {
		if (allArrays[i]->name == arrayName)
			return allArrays[i];
	}
}
std::string reduceAt(std::string varName) {
	if (varName[0] == '@')
		varName.erase(varName.begin());
	return varName;
}

void addVar(struct OaVar *oaVar) {
	allVars.push_back(oaVar);
}
void addArray(struct OaArray *oaArray) {
	allArrays.push_back(oaArray);
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


//------------------------main part-----------------------
int getTreeRaw(const char* filename) {
	int rtcode = executeParser(filename);
	if (rtcode != 0) {
		printf("error\n");
	}

	lineno = 0;
	//Added by @Xie LW
	temVarNo = 0;
	parseNodeList(result, parseTree->root, "root");
	return rtcode;
}

int main() {
	getTreeRaw("hello.oa");
	std::cout << result << std::endl;
	std::cin.get();
}
