#include "oa.h"
#include <stdio.h>

//---------------------expression part---------------------
struct LeftValue *createLeftValue(char *name){
	struct LeftValue *leftValue = (struct LeftValue*)malloc(sizeof(struct LeftValue));
	leftValue->name = name;
	leftValue->next = NULL;
	return leftValue;
}

struct FactParam *createFactParam(struct Expression *exp){
	struct FactParam *factParam = (struct FactParam*)malloc(sizeof(struct FactParam));
	factParam->exp = exp;
	factParam->next = NULL;
	return factParam;
}

struct Expression *createExpression(struct Expression *left, struct Expression *right, int op){
	struct Expression *exp = (struct Expression*)malloc(sizeof(struct Expression));
	exp->left = left;
	exp->right = right;
	exp->op = op;
	return exp;
}
struct Expression *createExpressionIntLeaf(int value){
	struct Expression *exp = (struct Expression*)malloc(sizeof(struct Expression));
	exp->left = NULL;
	exp->right = NULL;
	exp->op = OA_EXP_NONE;
	exp->leafType = OA_INT;
	exp->number_int = value;
	return exp;
}
struct Expression *createExpressionDoubleLeaf(double value){
	struct Expression *exp = (struct Expression*)malloc(sizeof(struct Expression));
	exp->left = NULL;
	exp->right = NULL;
	exp->op = OA_EXP_NONE;
	exp->leafType = OA_DOUBLE;
	exp->number_double = value;
	return exp;
}
struct Expression *createExpressionCharLeaf(char value){
	struct Expression *exp = (struct Expression*)malloc(sizeof(struct Expression));
	exp->left = NULL;
	exp->right = NULL;
	exp->op = OA_EXP_NONE;
	exp->leafType = OA_CHAR;
	exp->type_char = value;
	return exp;
}
struct Expression *createExpressionLeftValueLeaf(struct LeftValue *name){
	struct Expression *exp = (struct Expression*)malloc(sizeof(struct Expression));
	exp->left = NULL;
	exp->right = NULL;
	exp->op = OA_EXP_NONE;
	exp->leafType = OA_LEFT_VALUE;
	exp->name = name;
	return exp;
}

struct Expression *createExpressionArrayValue(struct LeftValue *name, struct Expression *index){
	struct ArrayValue *arrayValue = (struct ArrayValue*)malloc(sizeof(struct ArrayValue));
	arrayValue->name = name;
	arrayValue->index = index;
	
	struct Expression *exp = (struct Expression*)malloc(sizeof(struct Expression));
	exp->left = NULL;
	exp->right = NULL;
	exp->op = OA_EXP_NONE;
	exp->leafType = OA_ARRAY_VALUE;
	exp->arrayValue = arrayValue;
	return exp;
}

struct Expression *createExpressionFunctionValue(struct LeftValue *name, struct FactParam *factParam){
	struct FunctionValue *functionValue = (struct FunctionValue*)malloc(sizeof(struct FunctionValue));
	functionValue->name = name;
	functionValue->factParam = factParam;
	
	struct Expression *exp = (struct Expression*)malloc(sizeof(struct Expression));
	exp->left = NULL;
	exp->right = NULL;
	exp->op = OA_EXP_NONE;
	exp->leafType = OA_FUNCTION_VALUE;
	exp->functionValue = functionValue;
	return exp;
}

//---------------------statement part---------------------
struct TreeNode *createVarDeclare(char *type, char *name){
	//int @a
	//type, name is malloced by caller
	struct VarDeclareNode *varNode = (struct VarDeclareNode*)malloc(sizeof(struct VarDeclareNode));
	varNode->type = type;
	varNode->name = name;
	
	struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	node->type = VAR_DECLARE_NODE;
	node->next = NULL;
	node->varDeclareNode = varNode;
	return node;
}
struct TreeNode *createVarDefine(char *type, char *name, struct Expression *exp){
	//int @a = 1
	//type, name is malloced by caller
	struct VarDefineNode *varNode = (struct VarDefineNode*)malloc(sizeof(struct VarDefineNode));
	varNode->type = type;
	varNode->name = name;
	varNode->exp = exp;
	
	struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	node->type = VAR_DEFINE_NODE;
	node->next = NULL;
	node->varDefineNode = varNode;
	return node;
}
struct TreeNode *createVarAssign(struct LeftValue *name ,struct Expression *exp){
	//@a = 1
	//name is malloced by caller
	struct VarAssignNode *varNode = (struct VarAssignNode*)malloc(sizeof(struct VarAssignNode));
	varNode->name = name;
	varNode->exp = exp;
	
	struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	node->type = VAR_ASSIGN_NODE;
	node->next = NULL;
	node->varAssignNode = varNode;
	return node;
}
struct TreeNode *createArrayDeclare(char *type, char *name){
	//int[] @a
	//name, type is malloced by caller
	struct ArrayDeclareNode *varNode = (struct ArrayDeclareNode*)malloc(sizeof(struct ArrayDeclareNode));
	varNode->type = type;
	varNode->name = name;
	
	struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	node->type = ARRAY_DECLARE_NODE;
	node->next = NULL;
	node->arrayDeclareNode = varNode;
	return node;
}
struct TreeNode *createArrayDefine(char *type, char *name, char *type2, struct Expression *exp){
	//int[] @a = int[1]
	//name, type is malloced by caller
	if(strncmp(type, type2, strlen(type2)) != 0){
		printf("wrong type in array defination\n");
		return 0;
	}
	struct ArrayDefineNode *varNode = (struct ArrayDefineNode*)malloc(sizeof(struct ArrayDefineNode));
	varNode->type = type;
	varNode->name = name;
	varNode->exp = exp;
	
	struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	node->type = ARRAY_DEFINE_NODE;
	node->next = NULL;
	node->arrayDefineNode = varNode;
	return node;
}
struct TreeNode *createArrayAssign(struct LeftValue *name, char *type, struct Expression *exp){
	//@a = int[1]
	//name, type is malloced by caller
	struct ArrayAssignNode *varNode = (struct ArrayAssignNode*)malloc(sizeof(struct ArrayAssignNode));
	varNode->name = name;
	varNode->type = type;
	varNode->exp = exp;
	
	struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	node->type = ARRAY_ASSIGN_NODE;
	node->next = NULL;
	node->arrayAssignNode = varNode;
	return node;
}
struct TreeNode *createIf(struct Expression *exp, struct TreeNode *stmts, struct TreeNode *elifStmts, struct TreeNode *elseStmts){
	//if(2>1){stmts}elif(3>2){stmts}else{stmts}
	//elif and else can respectively be nothing
	struct IfNode *ifNode = (struct IfNode*)malloc(sizeof(struct IfNode));
	ifNode->exp = exp;
	ifNode->stmts = stmts;
	ifNode->elifStmts = elifStmts;
	ifNode->elseStmts = elseStmts;
	
	struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	node->type = IF_NODE;
	node->next = NULL;
	node->ifNode = ifNode;
	return node;
}
struct TreeNode *createElifPart(struct Expression *exp, struct TreeNode *stmts){
	//elif(3>2){stmts}
	struct ElifNode *elifNode = (struct ElifNode*)malloc(sizeof(struct ElifNode));
	elifNode->exp = exp;
	elifNode->stmts = stmts;
	
	struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	node->type = ELIF_NODE;
	node->next = NULL;
	node->elifNode = elifNode;
	return node;
}
struct TreeNode *createElsePart(struct TreeNode *stmts){
	//else{stmts}
	struct ElseNode *elseNode = (struct ElseNode*)malloc(sizeof(struct ElseNode));
	elseNode->stmts = stmts;
	
	struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	node->type = ELSE_NODE;
	node->next = NULL;
	node->elseNode = elseNode;
	return node;
}

struct TreeNode *createWhile(struct Expression *exp, struct TreeNode *stmts){
	//while(exp)
	struct WhileNode *whileNode = (struct WhileNode*)malloc(sizeof(struct WhileNode));
	whileNode->exp = exp;
	whileNode->stmts = stmts;
	
	struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	node->type = WHILE_NODE;
	node->next = NULL;
	node->whileNode = whileNode;
	return node;
}

struct TreeNode *createForeach(char *nameIn, char*nameOut, struct TreeNode *stmts){
	//foreach(@a in @aa){stmts}
	struct ForeachNode *foreachNode = (struct ForeachNode*)malloc(sizeof(struct ForeachNode));
	foreachNode->nameIn = nameIn;
	foreachNode->nameOut = nameOut;
	foreachNode->stmts = stmts;
	
	struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	node->type = FOREACH_NODE;
	node->next = NULL;
	node->foreachNode = foreachNode;
	return node;
}

struct TreeNode *createClassDefine(char *type, char *typeParent, struct TreeNode *stmts){
	//class A {stmts}
	//class A extends AA{stmts}
	struct ClassDefineNode *classDefineNode = (struct ClassDefineNode*)malloc(sizeof(struct ClassDefineNode));
	classDefineNode->type = type;
	classDefineNode->typeParent = typeParent;
	classDefineNode->stmts = stmts;
	
	struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	node->type = CLASS_DEFINE_NODE;
	node->next = NULL;
	node->classDefineNode = classDefineNode;
	return node;
}

struct TreeNode *createFunctionDeclare(char *type, char *name, struct FormParam *formParams){
	//int @func(int @a, int @b)
	struct FunctionDeclareNode *functionDeclareNode = (struct FunctionDeclareNode*)malloc(sizeof(struct FunctionDeclareNode));
	functionDeclareNode->type = type;
	functionDeclareNode->name = name;
	functionDeclareNode->formParams = formParams;
	
	struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	node->type = FUNCTION_DECLARE_NODE;
	node->next = NULL;
	node->functionDeclareNode = functionDeclareNode;
	return node;
}

struct TreeNode *createFunctionDefine(char *type, char *name, struct FormParam *formParams, struct TreeNode *stmts){
	//int @func(int @a, int @b)
	struct FunctionDefineNode *functionDefineNode = (struct FunctionDefineNode*)malloc(sizeof(struct FunctionDefineNode));
	functionDefineNode->type = type;
	functionDefineNode->name = name;
	functionDefineNode->formParams = formParams;
	functionDefineNode->stmts = stmts;
	
	struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	node->type = FUNCTION_DEFINE_NODE;
	node->next = NULL;
	node->functionDefineNode = functionDefineNode;
	return node;
}

struct TreeNode *createClassMethodDefine(char *type, char *name, struct FormParam *formParams, struct TreeNode *stmts, char *classType){
	//int #A::@func(int @a, int @b)
	struct ClassMethodDefineNode *classMethodDefineNode = (struct ClassMethodDefineNode*)malloc(sizeof(struct ClassMethodDefineNode));
	classMethodDefineNode->type = type;
	classMethodDefineNode->name = name;
	classMethodDefineNode->formParams = formParams;
	classMethodDefineNode->stmts = stmts;
	classMethodDefineNode->classType = classType;
	
	struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	node->type = FUNCTION_DEFINE_NODE;
	node->next = NULL;
	node->classMethodDefineNode = classMethodDefineNode;
	return node;
}

//---------------------parameter part---------------------
struct FormParam *createFormParam(char *type, char *name){
	struct FormParam *formParam = (struct FormParam*)malloc(sizeof(struct FormParam));
	formParam->type = type;
	formParam->name = name;
	formParam->next = NULL;
	return formParam;
}

//---------------------type part---------------------
char *createArrayType(char *type){
	int len = strlen(type);
	char *ret = (char*)malloc(len + 3);
	strncpy(ret, type, len);
	free(type);
	ret[len] = '[';
	ret[len + 1] = ']';
	ret[len + 2] = '\0';
	return ret;
}


void printJason(struct TreeNode *node){
	FILE *fp = NULL;
	fp = fopen("jason.txt", "w");
	fprintf(fp, "{\"name\":\"root\",\"children\":[");
	
	
	fprintf(fp, "]}");
	fclose(fp);
}

void printExpression(struct Expression *exp){
	switch(exp->op){
	case OA_EXP_NONE:
		if(exp->leafType == OA_INT) printf("%d ", exp->number_int);
		else if(exp->leafType == OA_DOUBLE) printf("%lf ", exp->number_double);
		else if(exp->leafType == OA_LEFT_VALUE) printf("%s ", exp->name);
		break;
	case OA_EXP_NOT:
		printf("! ");
		printExpression(exp->left);
		break;
	default:
		printExpression(exp->left);
		printf("(op %d)", exp->op);
		printExpression(exp->right);
	}
}