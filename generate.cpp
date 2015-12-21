#include"oa.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <map>
#include <fstream>
#include<list>

#define N_INT_CHAR 11

std::string result;
struct ParseTree *parseTree;
static int lineno;
static bool compilePass = true;
static std::string compileLog = "";
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
	bool isDefined;
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
int OaWhileIdx = 0;

//×÷ÓÃÓòµÄÕ»
std::list<std::string> oaPathStk;


std::map<std::string, OaFunction> oaFunctions;
std::map<std::string, OaClass> oaClasses;

std::string classNow = "";
bool hasPrint = false;
int printStringIndex = 0;
std::vector<std::string> printStrings;

void replaceUtilForeach(struct TreeNode* seg, char* namein, char* nameout, std::string idx);
void replaceUtilForeachEXP(struct Expression* seg, char* namein, char* nameout, std::string idx);
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
void parseWhileNode(std::string &result, struct WhileNode *seg);
void parseForeachNode(std::string &result, struct ForeachNode *seg);
void parseClassDefineNode(std::string &result, struct ClassDefineNode *seg);
void parseFunctionDeclareNode(std::string &result, struct FunctionDeclareNode *seg);
void parseFunctionDefineNode(std::string &result, struct FunctionDefineNode *seg);
void parseClassMethodDefineNode(std::string &result, struct ClassMethodDefineNode *seg);
void parseBreakNode(std::string &result);
void parseContinueNode(std::string &result);
void parseReturnNode(std::string &result, struct ReturnNode *seg);
//-------------- -----end tree node part-------------------
//---------------------expression part---------------------

struct OaVar* parseExpression(std::string& result, struct Expression* seg);
struct OaVar* parseLeftValue(std::string&result, struct LeftValue* seg);
struct OaVar* parseArrayValue(std::string&result, struct ArrayValue* seg);
struct OaVar* parseFunctionValue(std::string&result, struct FunctionValue* seg);
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
	lineno++;
	/*char numStr[N_INT_CHAR];
	sprintf(numStr, "%d", ++lineno);*/

	/*result += "{\"name\":\"" + std::string(numStr) + ": var declare\",\"children\":[";
	result += "{\"name\":\"" + std::string(seg->type) + "\"},";
	result += "{\"name\":\"" + std::string(seg->name) + "\"}";
	result += "]}";*/

	//Modified by @Xie LW--------------------------------------
	struct OaVar *temVar = new struct OaVar;
	if (getVar("%" + reduceAt(std::string(seg->name))) != NULL) {
		compilePass = false;
		compileLog += "Error[Line " + myItoa(lineno) + "]: ";
		compileLog += "Already Declared Identifier" + endLine;
		return;
	}
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

	if (classNow != "") {
		result += temVar->type;
		result += ", ";
		return;
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
	lineno++;
	//Modified by @Xie LW
	if (getVar("%" + reduceAt(std::string(seg->name))) != NULL) {
		compilePass = false;
		compileLog += "Error[Line " + myItoa(lineno) + "]: ";
		compileLog += "Already Declared Identifier" + endLine;
		return;
	}
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
	result += temVar->name + " ";
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
	if (seg->expOfVar == NULL && seg->name == NULL) {
		//[TODOD] onlydeal print function call
		if (seg->exp->op == OA_EXP_NONE && seg->exp->leafType == OA_FUNCTION_VALUE) {
			if (std::string(seg->exp->functionValue->name->name) == "@print" && seg->exp->functionValue->name->next == NULL) {
				parsePrintFunction(seg->exp->functionValue->factParam);
			}
		}
	}
	std::string temName;
	LeftValue* temLv = seg->name;
	while (temLv != NULL) {
		temName += reduceAt(temLv->name);
		if (temLv->next != NULL) {
			temName += '.';
		}
		temLv = temLv->next;
	}
	if (temName == "") {
		compilePass = false;
		compileLog += "Error[Line " + myItoa(lineno) + "]: ";
		compileLog += "Lack of LeftValue" + endLine;
		return;
	}
	if (getVar("%" + temName) == NULL&&getArray("%"+temName)==NULL) {
		compilePass = false;
		compileLog += "Error[Line " + myItoa(lineno) + "]: ";
		compileLog += "Undeclared Identifier" + endLine;
		return;
	}
	struct OaVar *temVar = new struct OaVar;
	if (seg->expOfVar != NULL) {
		struct OaArray* temArray = getArray("%" + temName);
		if (temArray != NULL) {
			struct OaVar* idxVar = parseExpression(result, seg->expOfVar);
			result += "%" + myItoa(temVarNo++) + " = ";
			result += "load " + temArray->type + "** " + temArray->name + ", ";
			result += "align 8" + endLine;
			temVar->name = "%" + myItoa(temVarNo - 1);
			result += "%" + myItoa(temVarNo++) + " = ";
			result += "getelementptr inbounds " + temArray->type + "* " + temVar->name + ", ";
			result += "i64 " + idxVar->name + endLine;
			temVar->name = "%" + myItoa(temVarNo - 1);
			temVar->type = temArray->type;
			temVar->align = temArray->align;
		}
	}
	else
		temVar = getVar("%" + temName);
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

	if (classNow != "") {
		result += temArray->type;
		result += "*, ";
		return;
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
	struct OaVar* szeVar = parseExpression(result, seg->exp);
	if (szeVar != NULL) {
		std::stringstream oss(szeVar->name);
		oss >> temArray->size;
		addArray(temArray);
		result += temArray->name + " ";
		result += "= " + std::string("alloca " + temArray->type + "*, ");
		result += std::string("align 8") + endLine;
		result += "%" + myItoa(temVarNo++) + " = ";
		result += "call i8* @malloc";
		result += "(i64 " + myItoa(temArray->size*temArray->align) + ")" + endLine;
		result += "%" + myItoa(temVarNo++) + " = ";
		result += "bitcast i8* %" + myItoa(temVarNo - 2) + " to " + temArray->type + endLine;
		result += "store " + temArray->type + "* %" + myItoa(temVarNo - 1) + ", ";
		result += temArray->type + "** " + temArray->name + ", ";
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
	_itoa(OaIfIdx, ifIdx, 10);
	_itoa(OaCmpIdx, cmpIdx, 10);
	//std::string cmpLabel = std::string("%cmp") + cmpIdx;
	std::string ifLabel = std::string("if.then.") + ifIdx;
	std::string nextLabel;
	if (seg->elseStmts != NULL || seg->elifStmts != NULL) {
		nextLabel = std::string("if.else.") + ifIdx;
	}
	else {
		nextLabel = std::string("if.end.") + ifIdx;
	}
	OaVar *p_midVar = parseExpression(result, seg->exp);
	OaCmpIdx++;
	OaIfIdx++;
	result += std::string("  br i1 ") + p_midVar->name + ',' + " label %" + ifLabel + ',' + " label %" + nextLabel + '\n';
	result += "\n";
	result += ifLabel + ":\n";
	oaPathStk.push_back(ifLabel);
	parseNodeList(result, seg->stmts, ifLabel);
	oaPathStk.pop_back();
	result += "\n";
	result += nextLabel + ":\n";
	struct TreeNode *tmp = seg->elifStmts;
	while (tmp != NULL) {
		parseTreeNode(result, seg->elifStmts);
		nextLabel = oaPathStk.back();
		oaPathStk.pop_back();
		tmp = tmp->next;
	}
	if (seg->elseStmts) {
		oaPathStk.push_back(nextLabel);
		parseTreeNode(result, seg->elseStmts);
		oaPathStk.pop_back();
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
	_itoa(OaIfIdx, ifIdx, 10);
	_itoa(OaCmpIdx, cmpIdx, 10);
	//std::string cmpLabel = std::string("%cmp") + cmpIdx;
	std::string ifLabel = std::string("if.then.") + ifIdx;
	std::string nextLabel = std::string("if.else.") + ifIdx;
	OaVar *p_midVar = parseExpression(result, seg->exp);
	OaCmpIdx++;
	OaIfIdx++;
	result += std::string("  br i1 ") + p_midVar->name + ',' + " label %" + ifLabel + ',' + " label %" + nextLabel + '\n';
	result += "\n";
	result += ifLabel + ":\n";
	oaPathStk.push_back(ifLabel);
	parseNodeList(result, seg->stmts, ifLabel);
	oaPathStk.pop_back();
	result += "\n";
	result += nextLabel + ":\n";
	oaPathStk.push_back(nextLabel);
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
	char wIdx[25];
	_itoa(OaWhileIdx, wIdx, 10);
	std::string wCondLabel = std::string("while.cond.") + wIdx;
	std::string wBodyLabel = std::string("while.body.") + wIdx;
	std::string wEndLabel = std::string("while.end.") + wIdx;
	OaWhileIdx++;
	result += std::string("  br label %") + wCondLabel + '\n';
	result += "\n";
	result += wCondLabel + ":\n";
	OaVar *p_midVar = parseExpression(result, seg->exp);
	result += std::string("  br i1 ") + p_midVar->name + ',' + " label %" + wBodyLabel + ',' + " label %" + wEndLabel + '\n';
	result += "\n";
	result += wBodyLabel + ":\n";
	oaPathStk.push_back(wBodyLabel);
	parseNodeList(result, seg->stmts, wBodyLabel);
	oaPathStk.pop_back();
	result += std::string("  br label %") + wCondLabel + '\n';
	result += "\n";
	result += wEndLabel + ":\n";

	/*char numStr[N_INT_CHAR];
	sprintf(numStr, "%d", ++lineno);

	result += "{\"name\":\"" + std::string(numStr) + ": while node\",\"children\":[";
	result += "{\"name\":\"condition\",\"children\":[{\"name\":\"";
	parseExpression(result, seg->exp);
	result += "\"}]}";
	if (seg->stmts) {
		result += ",";
		parseNodeList(result, seg->stmts, "stmts");
	}
	result += "]}";*/
}

void replaceUtilForeachVDF(struct VarDefineNode *seg, char* namein, char* nameout, std::string idx) {
	if (seg == NULL) {
		return;
	}
	replaceUtilForeachEXP(seg->exp, namein, nameout, idx);
}

void replaceUtilForeachVA(struct VarAssignNode* seg, char* namein, char* nameout, std::string idx) {
	if (seg == NULL) {
		return;
	}
	if (strcmp(seg->name->name,namein)==0) {
		char* nameidx = new char[idx.size()+1];
		strcpy(nameidx, idx.c_str());
		struct LeftValue *newlft = createLeftValue(nameidx);
		struct Expression *newexp = createExpressionLeftValueLeaf(newlft);
		seg->expOfVar = newexp;
	}
}

void replaceUtilForeachADF(struct ArrayDefineNode* seg, char* namein, char* nameout, std::string idx) {

}

void replaceUtilForeachAA(struct ArrayAssignNode* seg, char* namein, char* nameout, std::string idx) {

}

void replaceUtilForeachIF(struct IfNode* seg, char* namein, char* nameout, std::string idx) {
	if (seg == NULL) {
		return;
	}
	replaceUtilForeachEXP(seg->exp, namein, nameout, idx);
	replaceUtilForeach(seg->elifStmts, namein, nameout, idx);
	replaceUtilForeach(seg->elseStmts, namein, nameout, idx);
	replaceUtilForeach(seg->stmts, namein, nameout, idx);
}

void replaceUtilForeachELIF(struct ElifNode* seg, char* namein, char* nameout, std::string idx) {
	if (seg == NULL) {
		return;
	}
	replaceUtilForeachEXP(seg->exp, namein, nameout, idx);
	replaceUtilForeach(seg->stmts, namein, nameout, idx);
}

void replaceUtilForeachELSE(struct ElseNode* seg, char* namein, char* nameout, std::string idx) {
	if (seg == NULL) {
		return;
	}
	replaceUtilForeach(seg->stmts, namein, nameout, idx);
}

void replaceUtilForeachWHILE(struct WhileNode* seg, char* namein, char* nameout, std::string idx) {
	if (seg == NULL) {
		return;
	}
	replaceUtilForeachEXP(seg->exp, namein, nameout, idx);
	replaceUtilForeach(seg->stmts, namein, nameout, idx);
}

void replaceUtilForeachRT(struct ReturnNode* seg, char* namein, char* nameout, std::string idx) {
	if (seg == NULL) {
		return;
	}
	replaceUtilForeachEXP(seg->exp, namein, nameout, idx);
}


void replaceUtilForeachEXP(struct Expression* seg, char* namein, char* nameout, std::string idx) {
	if (seg == NULL) {
		return;
	}
	if (seg->left == NULL&&seg->right == NULL) {
		switch (seg->leafType)
		{
		case OA_LEFT_VALUE:
		case OA_ARRAY_VALUE:
		case OA_FUNCTION_VALUE:
			break;
		default:
			break;
		}
	}
	else {
		replaceUtilForeachEXP(seg->left, namein, nameout, idx);
		replaceUtilForeachEXP(seg->right, namein, nameout, idx);
	}
}

void replaceUtilForeach(struct TreeNode* seg, char* namein, char* nameout, std::string idx) {
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
		replaceUtilForeachVDF(seg->varDefineNode, namein, nameout, idx);
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

void parseForeachNode(std::string &result, ForeachNode *seg) {
	if (seg == NULL) {
		return;
	}
	/*
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
	*/
}

void parseClassDefineNode(std::string&result, struct ClassDefineNode *seg) {
	if (seg == NULL) {
		return;
	}
	classNow = std::string(seg->type).substr(1);
	OaClass oaclass;
	oaclass.name = classNow;
	if (seg->typeParent) {
		oaclass.parent = std::string(seg->typeParent).substr(1);
	}
	else {
		oaclass.parent = "";
	}
	result += "%class." + oaclass.name + " = type { ";
	if (seg->typeParent) {
		result += "%class." + oaclass.parent + ", ";
	}
	parseNodeList(result, seg->stmts, "stmts");
	result.pop_back();
	result.pop_back();
	result += " }\n\n";

	oaClasses.insert(std::pair<std::string, OaClass>(oaclass.name, oaclass));
	classNow = "";
}

void parseFunctionDeclareNode(std::string&result, FunctionDeclareNode*seg) {
	if (seg == NULL) {
		return;
	}
	OaFunction oafunc;
	//className and name
	oafunc.className = classNow;
	oafunc.name = std::string(seg->name);

	//check for redeclare
	if (oaFunctions.find(oafunc.className + oafunc.name) != oaFunctions.end()) {
		compileLog = "wrong in declare node, function " + oafunc.name + "has been declared!\n";
		compilePass = false;
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

void parseFunctionDefineNode(std::string&result, FunctionDefineNode*seg) {
	if (seg == NULL) {
		return;
	}
	OaFunction oafunc;
	//className and name
	oafunc.className = classNow;
	oafunc.name = std::string(seg->name);

	//check for redefine
	std::map<std::string, OaFunction>::iterator iter = oaFunctions.find(oafunc.className + oafunc.name);
	if (iter != oaFunctions.end()) {
		if (iter->second.isDefined == true) {
			compileLog = "wrong in defined node, function " + oafunc.name + "has been defined!\n";
			compilePass = false;
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
	}
	else {
		oafunc.type = "void";
	}
	result += oafunc.type;

	//function name
	result += " ";
	result += oafunc.name;

	//parameters
	result += '(';
	parseFormParam(result, seg->formParams);
	result += ')';
	oafunc.params = seg->formParams;
	//statements
	result += "{\nentry:\n";
	if (seg->stmts) {
		parseNodeList(result, seg->stmts, "stmts");
	}
	result += "}\n\n";
	oaFunctions.insert(std::pair<std::string, OaFunction>(oafunc.className + oafunc.name, oafunc));
}

void parseClassMethodDefineNode(std::string&result, ClassMethodDefineNode*seg) {
	if (seg == NULL) {
		return;
	}
	OaFunction oafunc;
	//name
	oafunc.className = std::string(seg->classType).substr(1);
	oafunc.name = std::string(seg->name);

	//check if the class has this function
	std::map<std::string, OaFunction>::iterator iter = oaFunctions.find(oafunc.className + oafunc.name);
	if (iter != oaFunctions.end()) {
		if (iter->second.isDefined == true) {
			compileLog = "wrong in defined node, function " + oafunc.name + "has been defined!\n";
			compilePass = false;
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
	}
	else {
		oafunc.type = "void";
	}
	result += oafunc.type;

	//function name
	result += " ";
	result += oafunc.className +oafunc.name;

	//parameters
	result += '(';
	parseFormParam(result, seg->formParams);
	result += ')';
	oafunc.params = seg->formParams;
	//statements
	result += "{\nentry:\n";
	if (seg->stmts) {
		parseNodeList(result, seg->stmts, "stmts");
	}
	result += "}\n\n";
	oaFunctions.insert(std::pair<std::string, OaFunction>(oafunc.className + oafunc.name, oafunc));
}

void parseBreakNode(std::string &result) {
	std::string curScop = oaPathStk.back();
	char num = curScop[curScop.size() - 1];
	std::size_t first = curScop.find('.');
	std::string loopType = curScop.substr(0, first);
	std::string jmpLabel = loopType + ".end." + num;
	result += "  br label %" + jmpLabel +'\n';
	/*
	char numStr[N_INT_CHAR];
	sprintf(numStr, "%d", ++lineno);

	result += "{\"name\":\"" + std::string(numStr) + ": break\"}";
	*/
}

void parseContinueNode(std::string &result) {
	std::string curScop = oaPathStk.back();
	char num = curScop[curScop.size() - 1];
	std::size_t first = curScop.find('.');
	std::string loopType = curScop.substr(0, first);
	std::string jmpLabel = loopType + ".cond." + num;
	result += "  br label %" + jmpLabel +'\n';
	/*char numStr[N_INT_CHAR];
	sprintf(numStr, "%d", ++lineno);

	result += "{\"name\":\"" + std::string(numStr) + ": continue\"}";*/
}

void parseReturnNode(std::string &result, struct ReturnNode *seg) {
	OaVar *retVal = new struct OaVar;
	retVal = parseExpression(result, seg->exp);
	result += "ret " + retVal->type + ' ' + retVal->name + '\n';
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
		case OA_STRING: {
			struct OaVar* temVar = new struct OaVar;
			temVar->type = "string";
			temVar->align = 1;
			temVar->name = std::string(seg->type_string);
		}
		case OA_LEFT_VALUE:
			return parseLeftValue(result, seg->name);
			break;
		case OA_ARRAY_VALUE:
			return parseArrayValue(result, seg->arrayValue);
			break;
		case OA_FUNCTION_VALUE:
			return parseFunctionValue(result, seg->functionValue);
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
	case OA_EXP_DIVIDE: {
		/*parseExpression(result, seg->left);
		result += " / ";
		parseExpression(result, seg->right);*/
		//Added by @Xie LW
		struct OaVar*  leftVar = parseExpression(result, seg->left);
		struct OaVar* rightVar = parseExpression(result, seg->right);
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
	case OA_EXP_EQ: {
		/*parseExpression(result, seg->left);
		result += " == ";
		parseExpression(result, seg->right);*/
		struct OaVar*  leftVar = parseExpression(result, seg->left);
		struct OaVar* rightVar = parseExpression(result, seg->right);
		struct OaVar*   temVar = new struct OaVar;
		result += "%" + myItoa(temVarNo++) + " = ";
		result += "icmp eq ";
		result += leftVar->type + " ";
		result += leftVar->name + ", " + rightVar->name + endLine;
		temVar->name = "%" + myItoa(temVarNo++);
		result += temVar->name + " = ";
		result += "zext i1 %" + myItoa(temVarNo - 2);
		result += " to " + leftVar->type + endLine;
		temVar->type = leftVar->type;
		temVar->align = leftVar->align;
		return temVar;
		break;
	}
	case OA_EXP_NE: {
		/*parseExpression(result, seg->left);
		result += " != ";
		parseExpression(result, seg->right);*/
		struct OaVar*  leftVar = parseExpression(result, seg->left);
		struct OaVar* rightVar = parseExpression(result, seg->right);
		struct OaVar*   temVar = new struct OaVar;
		result += "%" + myItoa(temVarNo++) + " = ";
		result += "icmp ne ";
		result += leftVar->type + " ";
		result += leftVar->name + ", " + rightVar->name + endLine;
		temVar->name = "%" + myItoa(temVarNo++);
		result += temVar->name + " = ";
		result += "zext i1 %" + myItoa(temVarNo - 2);
		result += " to " + leftVar->type + endLine;
		temVar->type = leftVar->type;
		temVar->align = leftVar->align;
		return temVar;
		break;
	}
	case OA_EXP_GT: {
		/*parseExpression(result, seg->left);
		result += " > ";
		parseExpression(result, seg->right);*/
		struct OaVar*  leftVar = parseExpression(result, seg->left);
		struct OaVar* rightVar = parseExpression(result, seg->right);
		struct OaVar*   temVar = new struct OaVar;
		result += "%" + myItoa(temVarNo++) + " = ";
		result += "icmp sgt ";
		result += leftVar->type + " ";
		result += leftVar->name + ", " + rightVar->name + endLine;
		temVar->name = "%" + myItoa(temVarNo++);
		result += temVar->name + " = ";
		result += "zext i1 %" + myItoa(temVarNo - 2);
		result += " to " + leftVar->type + endLine;
		temVar->type = leftVar->type;
		temVar->align = leftVar->align;
		return temVar;
		break;
	}
	case OA_EXP_GE: {
		/*parseExpression(result, seg->left);
		result += " >= ";
		parseExpression(result, seg->right);*/
		//Added by @Xie LW
		struct OaVar*  leftVar = parseExpression(result, seg->left);
		struct OaVar* rightVar = parseExpression(result, seg->right);
		struct OaVar*   temVar = new struct OaVar;
		result += "%" + myItoa(temVarNo++) + " = ";
		result += "icmp sge ";
		result += leftVar->type + " ";
		result += leftVar->name + ", " + rightVar->name + endLine;
		temVar->name = "%" + myItoa(temVarNo++);
		result += temVar->name + " = ";
		result += "zext i1 %" + myItoa(temVarNo - 2);
		result += " to " + leftVar->type + endLine;
		temVar->type = leftVar->type;
		temVar->align = leftVar->align;
		return temVar;
		break;
	}
	case OA_EXP_LT: {
		/*parseExpression(result, seg->left);
		result += " < ";
		parseExpression(result, seg->right);*/
		struct OaVar*  leftVar = parseExpression(result, seg->left);
		struct OaVar* rightVar = parseExpression(result, seg->right);
		struct OaVar*   temVar = new struct OaVar;
		result += "%" + myItoa(temVarNo++) + " = ";
		result += "icmp sle ";
		result += leftVar->type + " ";
		result += leftVar->name + ", " + rightVar->name + endLine;
		temVar->name = "%" + myItoa(temVarNo++);
		result += temVar->name + " = ";
		result += "zext i1 %" + myItoa(temVarNo - 2);
		result += " to " + leftVar->type + endLine;
		temVar->type = leftVar->type;
		temVar->align = leftVar->align;
		return temVar;
		break;
	}
	case OA_EXP_LE: {
		/*parseExpression(result, seg->left);
		result += " <= ";
		parseExpression(result, seg->right);*/
		struct OaVar*  leftVar = parseExpression(result, seg->left);
		struct OaVar* rightVar = parseExpression(result, seg->right);
		struct OaVar*   temVar = new struct OaVar;
		result += "%" + myItoa(temVarNo++) + " = ";
		result += "icmp sle ";
		result += leftVar->type + " ";
		result += leftVar->name + ", " + rightVar->name + endLine;
		temVar->name = "%" + myItoa(temVarNo++);
		result += temVar->name + " = ";
		result += "zext i1 %" + myItoa(temVarNo - 2);
		result += " to " + leftVar->type + endLine;
		temVar->type = leftVar->type;
		temVar->align = leftVar->align;
		return temVar;
		break;
	}
	case OA_EXP_AND: {
		/*parseExpression(result, seg->left);
		result += " && ";
		parseExpression(result, seg->right);*/
		struct OaVar* temVar = new struct OaVar;
		struct OaVar* leftVar = parseExpression(result, seg->left);
		result += "%" + myItoa(temVarNo++) + " = ";
		result += "icmp ne " + leftVar->type + " " + leftVar->name;
		result += ", 0" + endLine;

		result += "br i1 %" + myItoa(temVarNo - 1) + ", ";
		result += "label %" + myItoa(temVarNo++) + ", ";
		result += "label %" + myItoa(temVarNo++) + endLine;
		int temLabel = temVarNo - 1;
		result += myItoa(temVarNo - 2)+endLine;

		struct OaVar* rightVar = parseExpression(result, seg->right);
		result += "%" + myItoa(temVarNo++) + " = ";
		result += "icmp ne " + rightVar->type + " " + rightVar->name;
		result += ", 0" + endLine;

		result += "br label %" + myItoa(temLabel) + endLine;

		result += myItoa(temLabel) + endLine;

		result += "%" + myItoa(temVarNo++) + " = ";
		result += "phi i1 [ false, %0 ], [ %" + myItoa(temVarNo - 2) + ", ";
		result += "%" + myItoa(temLabel - 1) + " ]" + endLine;;

		result += "%" + myItoa(temVarNo++) + " = ";
		result += "zext i1 %" + myItoa(temVarNo - 2) + " to i32"+endLine;

		temVar->name = "%" + myItoa(temVarNo - 1);
		temVar->type = "i32";
		temVar->align = 4;
		return temVar;
		break;
	}
	case OA_EXP_OR: {
		/*parseExpression(result, seg->left);
		result += " || ";
		parseExpression(result, seg->right);*/
		struct OaVar* temVar = new struct OaVar;
		struct OaVar* leftVar = parseExpression(result, seg->left);
		result += "%" + myItoa(temVarNo++) + " = ";
		result += "icmp ne " + leftVar->type + " " + leftVar->name;
		result += ", 0" + endLine;

		result += "br i1 %" + myItoa(temVarNo - 1) + ", ";
		result += "label %" + myItoa(temVarNo++) + ", ";
		result += "label %" + myItoa(temVarNo++) + endLine;
		int temLabel = temVarNo-2;
		result += myItoa(temVarNo - 1) + endLine;

		struct OaVar* rightVar = parseExpression(result, seg->right);
		result += "%" + myItoa(temVarNo++) + " = ";
		result += "icmp ne " + rightVar->type + " " + rightVar->name;
		result += ", 0" + endLine;

		result += "br label %" + myItoa(temLabel) + endLine;

		result += myItoa(temLabel) + endLine;

		result += "%" + myItoa(temVarNo++) + " = ";
		result += "phi i1 [ true, %0 ], [ %" + myItoa(temVarNo - 2) + ", ";
		result += "%" + myItoa(temLabel+1) + " ]" + endLine;;

		result += "%" + myItoa(temVarNo++) + " = ";
		result += "zext i1 %" + myItoa(temVarNo - 2) + " to i32" + endLine;

		temVar->name = "%" + myItoa(temVarNo - 1);
		temVar->type = "i32";
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

struct OaVar* parseLeftValue(std::string&result, LeftValue* seg) {
	if (seg == NULL) {
		return NULL;
	}
	//Modified by @Xie LW
	std::string temName;
	while (seg != NULL) {
		temName += seg->name;
		if (seg->next != NULL) {
			temName += '.';
		}
		seg = seg->next;
	}
	struct OaVar* refVar = getVar("%" + reduceAt(temName));
	struct OaArray* refArray = getArray("%" + reduceAt(temName));
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
	else if(refArray!=NULL){
		struct OaVar* temVar = new struct OaVar;
		temVar->name = "%" + myItoa(temVarNo++);
		temVar->align = refArray->align;
		temVar->type = refArray->type;
		result += temVar->name + " = ";
		result += "load " + refArray->type + "** " + refArray->name + ", ";
		result += "align " + myItoa(refArray->align) + endLine;
		return temVar;
	}
	else {
		compilePass = false;
		compileLog += "Error[" + myItoa(lineno) + "]: ";
		compileLog += "Unideclared identifier." + endLine;
	}
}

struct OaVar* parseArrayValue(std::string&result, ArrayValue* seg) {
	if (seg == NULL) {
		return NULL;
	}
	/*parseLeftValue(result, seg->name);
	result += '[';
	parseExpression(result, seg->index);
	result += ']';*/
	struct OaVar* refVar = parseLeftValue(result, seg->name);
	struct OaVar* idxVar = parseExpression(result, seg->index);
	struct OaVar* temVar = new struct OaVar;
	if (refVar != NULL&&idxVar != NULL) {
		temVar->name = "%" + myItoa(temVarNo++);
		result += temVar->name + " = ";
		result += "getelementptr inbounds " + refVar->type + "* ";
		result += refVar->name + ", ";
		result += "i64 " + idxVar->name + endLine;
	}
}

struct OaVar* parseFunctionValue(std::string&result, FunctionValue* seg) {
	if (seg == NULL) {
		return NULL;
	}

	//[TODO] no left value case
	std::map<std::string, OaFunction>::iterator iter = oaFunctions.find(seg->name->name);
	if (iter == oaFunctions.end()) {
		//no this function
		compilePass = false;
		compileLog = "in parseFunctionValue: no function named" + std::string(seg->name->name) + "\n";
		return NULL;
	}

	std::string retType = iter->second.type;
	std::string name = iter->second.name;
	std::string className = iter->second.className;
	struct FormParam *formParams = iter->second.params;
	
	struct FactParam *factParams = seg->factParam;
	//[TODO] check params, return type etc.
	
	//[TODO] align
	struct OaVar *oaVar = new OaVar;
	oaVar->name = myItoa(temVarNo++);
	oaVar->type = retType;
	oaVar->align = 4;

	result += "%" + oaVar->name + " = call " + retType + ' ' + name + '(';
	parseFactParam(result, factParams);
	result += ")\n";
	return oaVar;
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
	OaVar *tmpVar = NULL;
	while (seg != NULL) {
		tmpVar = parseExpression(result, seg->exp);
		result += tmpVar->type + ' ' + tmpVar->name;
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

void parsePrintFunction(struct FactParam *params) {
	//[TODO] literals of char and string in oa.l
	//[TODO] check parameters
	//[TODO] % param
	//[TODO] meaning-change for \n \t etc.
	hasPrint = true;
	std::string tmpstr = std::string(params->exp->type_string).substr(1);
	std::string str = "";
	int size = tmpstr.size();
	for (int i = 0; i < size; ++i) {
		if (tmpstr[i] == '\\') {
			if (i == size - 1) {
				compileLog = "wrong print string";
				compilePass = false;
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
	result += "call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([" + myItoa(size) + " x i8], [" + myItoa(size) + " x i8]* @.str." + myItoa(printStringIndex) + ", i32 0, i32 0))\n";

	//update printStrings vector
	str.pop_back();
	printStrings.push_back(str);
	printStringIndex++;
}

int main() {
	getTreeRaw("helloworld.oa");
	if (compilePass) {
		std::cout << result << std::endl;
		//generate code to file
		/*std::ofstream ost("hello.ll");
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
		ost << result << std::endl;
		if (hasPrint) {
			ost << "declare i32 @printf(i8*, ...)";
		}*/
		std::cout << "code generate successfully!\n";
	}
	else
		std::cout << compileLog << std::endl;
	std::cin.get();
}