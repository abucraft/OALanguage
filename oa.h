#ifndef OA_H
#define OA_H

#ifdef __cplusplus
extern "C" {
#endif

//expression variable type
#define OA_INT				0
#define OA_DOUBLE			1
#define OA_CHAR				2
#define OA_STRING			3
#define OA_LEFT_VALUE		4
#define OA_ARRAY_VALUE		5
#define OA_FUNCTION_VALUE	6

//parse tree node type
#define VAR_DECLARE_NODE			0
#define VAR_DEFINE_NODE				1
#define VAR_ASSIGN_NODE				2
#define ARRAY_DECLARE_NODE			3
#define ARRAY_DEFINE_NODE			4
#define ARRAY_ASSIGN_NODE			5
#define IF_NODE						6
#define ELIF_NODE					7
#define ELSE_NODE					8
#define WHILE_NODE					9
#define FOREACH_NODE				10
#define CLASS_DEFINE_NODE			11
#define FUNCTION_DECLARE_NODE		12
#define FUNCTION_DEFINE_NODE		13
#define CLASS_METHOD_DEFINE_NODE	14
#define BREAK_NODE					15
#define CONTINUE_NODE				16
#define RETURN_NODE					17

//expression operator type
#define OA_EXP_NONE		0
#define OA_EXP_MULTIPLE	1
#define OA_EXP_DIVIDE	2
#define OA_EXP_PLUS		3
#define OA_EXP_MINUS	4
#define OA_EXP_EQ		5
#define OA_EXP_NE		6
#define OA_EXP_GT		7
#define OA_EXP_GE		8
#define OA_EXP_LT		9
#define OA_EXP_LE		10
#define OA_EXP_AND		11
#define OA_EXP_OR		12
#define OA_EXP_NOT		13


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//------------------word and syntax part------------------
//---------------------parameter part---------------------
struct FormParam{
	char *type;
	char *name;
	struct FormParam *next;
};
struct FactParam{
	struct Expression *exp;
	struct FactParam *next;
};
struct FormParam *createFormParam(char *type, char *name);
struct FactParam *createFactParam(struct Expression *exp);
//-------------------end parameter part--------------------

//---------------------expression part---------------------
struct LeftValue{
	char *name;
	struct LeftValue *next;
};
struct ArrayValue{
	struct LeftValue *name;
	struct Expression *index;
};
struct FunctionValue{
	struct LeftValue *name;
	struct FactParam *factParam;
};

struct Expression{
	struct Expression *left;
	struct Expression *right;
	int op;
	int leafType;
	union{
		int number_int;
		double number_double;
		char type_char;
		char *type_string;
		struct LeftValue *name;
		struct ArrayValue *arrayValue;
		struct FunctionValue * functionValue;
	};
};
struct LeftValue *createLeftValue(char *name);
struct Expression *createExpression(struct Expression *left, struct Expression *right, int op);
struct Expression *createExpressionIntLeaf(int value);
struct Expression *createExpressionDoubleLeaf(double value);
struct Expression *createExpressionCharLeaf(char value);
struct Expression *createExpressionStringLeaf(char *value);
struct Expression *createExpressionLeftValueLeaf(struct LeftValue *name);
struct Expression *createExpressionArrayValue(struct LeftValue *name, struct Expression *index);
struct Expression *createExpressionFunctionValue(struct LeftValue *name, struct FactParam *factParam);

//-----------------end expression part-----------------

//------------------ statement part---------------------
struct VarDeclareNode{
	char *type;
	char *name;
};
struct VarDefineNode{
	char *type;
	char *name;
	struct Expression *exp;
};
struct VarAssignNode{
	struct LeftValue *name;
	struct Expression *exp;
	struct Expression *expOfVar;
};
struct ArrayDeclareNode{
	char *type;
	char *name;
};
struct ArrayDefineNode{
	char *type;
	char *name;
	struct Expression *exp;
};
struct ArrayAssignNode{
	struct LeftValue *name;
	char *type;
	struct Expression *exp;
};
struct IfNode{
	struct Expression *exp;
	struct TreeNode *stmts;
	struct TreeNode *elifStmts;
	struct TreeNode *elseStmts;
};
struct ElifNode{
	struct Expression *exp;
	struct TreeNode *stmts;
};
struct ElseNode{
	struct TreeNode *stmts;
};
struct WhileNode{
	struct Expression *exp;
	struct TreeNode *stmts;
};
struct ForeachNode{
	char *nameIn;
	struct LeftValue *nameOut;
	struct TreeNode *stmts;
};
struct ClassDefineNode{
	char *type;
	char *typeParent;
	struct TreeNode *stmts;
};
struct FunctionDeclareNode{
	char *type;
	char *name;
	struct FormParam *formParams;
};
struct FunctionDefineNode{
	char *type;
	char *name;
	struct FormParam *formParams;
	struct TreeNode *stmts;
};
struct ClassMethodDefineNode{
	char *classType;
	char *type;
	char *name;
	struct FormParam *formParams;
	struct TreeNode *stmts;
};
struct ReturnNode{
	struct Expression *exp;
};

struct TreeNode {
	int type;
	int lineno;
	char *str;
	struct TreeNode *next;
	union{
		//[WANING] break and continue statement has no node
		struct VarDeclareNode *varDeclareNode;
		struct VarDefineNode *varDefineNode;
		struct VarAssignNode *varAssignNode;
		struct ArrayDeclareNode *arrayDeclareNode;
		struct ArrayDefineNode *arrayDefineNode;
		struct ArrayAssignNode *arrayAssignNode;
		struct IfNode *ifNode;
		struct ElifNode *elifNode;
		struct ElseNode *elseNode;
		struct WhileNode *whileNode;
		struct ForeachNode *foreachNode;
		struct ClassDefineNode *classDefineNode;
		struct FunctionDeclareNode *functionDeclareNode;
		struct FunctionDefineNode *functionDefineNode;
		struct ClassMethodDefineNode *classMethodDefineNode;
		struct ReturnNode *returnNode;
	};
};
struct ParseTree{
	struct TreeNode *root;
};

char *createArrayType(char *type);
struct TreeNode *createVarDeclare(char *type, char *name);
struct TreeNode *createVarDefine(char *type, char *name, struct Expression *exp);
struct TreeNode *createVarAssign(struct LeftValue *name, struct Expression *exp, struct Expression *expOfVar);
struct TreeNode *createArrayDeclare(char *type, char *name);
struct TreeNode *createArrayDefine(char *type, char *name, char *type2, struct Expression *exp);
struct TreeNode *createArrayAssign(struct LeftValue *name, char *type, struct Expression *exp);
struct TreeNode *createIf(struct Expression *exp, struct TreeNode *stmts, struct TreeNode *elifStmts, struct TreeNode *elseStmts);
struct TreeNode *createElifPart(struct Expression *exp, struct TreeNode *stmts);
struct TreeNode *createElsePart(struct TreeNode *stmts);
struct TreeNode *createWhile(struct Expression *exp, struct TreeNode *stmts);
struct TreeNode *createForeach(char *nameIn, struct LeftValue *nameOut, struct TreeNode *stmts);
struct TreeNode *createClassDefine(char *type, char *typeParent, struct TreeNode *stmts);
struct TreeNode *createFunctionDeclare(char *type, char *name, struct FormParam *formParams);
struct TreeNode *createFunctionDefine(char *type, char *name, struct FormParam *formParams, struct TreeNode *stmts);
struct TreeNode *createClassMethodDefine(char *type, char *name, struct FormParam *formParams, struct TreeNode *stmts, char *classType);
struct TreeNode *createBreak();
struct TreeNode *createContinue();
struct TreeNode *createReturn(struct Expression *exp);
//-------------------end statement part-------------------
//----------------end word and syntax part----------------


//--------------------parase tree part--------------------

//-------------helper variables and functions-------------
extern struct ParseTree *parseTree;
void printJason(struct TreeNode *node);
void printExpression(struct Expression *exp);
int executeParser(const char *filename);
void parsePrintFunction(struct FactParam *params);

#ifdef __cplusplus
}
#endif

#endif