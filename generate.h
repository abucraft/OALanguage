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



struct OaVar {
	std::string name;
	std::string type;
	int align;
	int size;
};


std::string myItoa(int num);
std::string myDtoa(double num);
std::string myDtoa(std::string num);
std::string reduceAt(std::string varName);
std::string getType(std::string varName);
int getAlign(std::string varName);
struct OaVar* getVar(std::string varName, int *isGlobal = NULL);
void addVar(struct OaVar* oaVar);
void addArray(struct OaVar* oaVar);
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
	int pos;
	int align;
};

struct OaClass {
	std::string name;
	std::string parent;
	std::map<std::string, OaClassMember> members;
	int align;
};



OaClassMember *findMemberInClass(std::string member, OaClass *oaClass);
int allocaClass(std::string name, std::string type, int align, bool useNo = true);


void zeroClassArrayLength(const std::string &name, const std::string &classType);
void freeArray(std::string index, std::string type, int align);
std::string mallocArray(std::string index, std::string type, int align, std::string size);
void panic(const std::string &wrongInfo);

void replaceUtilForeach(struct TreeNode* seg, char* namein, LeftValue* nameout, std::string idx);
void replaceUtilForeachEXP(struct Expression* seg, char* namein, LeftValue* nameout, std::string idx);

//---------------------tree node part---------------------
void g_parseNodeList(std::string &result, struct TreeNode* seg, std::string name);
void g_parseTreeNode(std::string &result, struct TreeNode *seg);
void g_parseVarDeclareNode(std::string &result, struct VarDeclareNode *seg, bool check = true);
void g_parseVarDefineNode(std::string &result, struct VarDefineNode *seg, bool check = true);
void g_parseVarAssignNode(std::string &result, struct VarAssignNode *seg);
void g_parseArrayDeclareNode(std::string &result, struct ArrayDeclareNode *seg);
void g_parseArrayDefineNode(std::string &result, struct ArrayDefineNode *seg);
void g_parseArrayAssignNode(std::string &result, struct ArrayAssignNode *seg);
void g_parseIfNode(std::string &result, struct IfNode *seg);
void g_parseElifNode(std::string &result, struct ElifNode *seg);
void g_parseElseNode(std::string &result, struct ElseNode *seg);
void g_parseWhileNode(std::string &result, struct WhileNode *seg);
void g_parseForeachNode(std::string &result, struct ForeachNode *seg);
void g_parseClassDefineNode(std::string &result, struct ClassDefineNode *seg);
void g_parseFunctionDeclareNode(std::string &result, struct FunctionDeclareNode *seg);
void g_parseFunctionDefineNode(std::string &result, struct FunctionDefineNode *seg);
void g_parseClassMethodDefineNode(std::string &result, struct ClassMethodDefineNode *seg);
void g_parseBreakNode(std::string &result);
void g_parseContinueNode(std::string &result);
void g_parseReturnNode(std::string &result, struct ReturnNode *seg);
//-------------- -----end tree node part-------------------
//---------------------expression part---------------------

struct OaVar* g_parseExpression(std::string& result, struct Expression* seg);
struct OaVar* g_parseLeftValue(std::string&result, struct LeftValue* seg);
struct OaVar* g_parseArrayValue(std::string&result, struct ArrayValue* seg);
struct OaVar* g_parseFunctionValue(std::string&result, struct FunctionValue* seg);
//-------------------end expression part-------------------
//---------------------parameter part---------------------
std::string g_parseFormParam(std::string&result, FormParam*seg);
std::string g_parseFactParam(std::string&result, struct FactParam* seg);
//-------------------end parameter part-------------------
int g_main(const char* filename);


