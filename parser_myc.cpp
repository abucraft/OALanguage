#include"oa.h"
#include"compiler.h"

#define N_INT_CHAR 11
std::string result;
struct ParseTree *parseTree;
static int lineno;

//---------------------tree node part---------------------
void parseNodeList(std::string &result, struct TreeNode* seg, std::string name);
void parseTreeNode(std::string &result, struct TreeNode *seg);
void parseVarDeclareNode(std::string &result, struct VarDeclareNode *seg);
void parseVarDefineNode(std::string &result, struct VarDefineNode *seg);
void parseVarAssignNode(std::string &result, struct VarAssignNode *seg);
void parseArrayDeclareNode(std::string &result, struct ArrayDeclareNode *seg);
void parseArrayDefineNode(std::string &result, struct ArrayDefineNode *seg);
void parseArrayAssignNode(std::string &result, struct ArrayAssignNode *seg);
void parseIfNode(std::string &result, struct IfNode *seg);//----
void parseElifNode(std::string &result, struct ElifNode *seg);//----
void parseElseNode(std::string &result, struct ElseNode *seg);//----
void parseWhileNode(std::string &result, struct WhileNode *seg);//----
void parseForeachNode(std::string &result, struct ForeachNode *seg);//----
void parseClassDefineNode(std::string &result, struct ClassDefineNode *seg);//----
void parseFunctionDeclareNode(std::string &result, struct FunctionDeclareNode *seg);
void parseFunctionDefineNode(std::string &result, struct FunctionDefineNode *seg);//----
void parseClassMethodDefineNode(std::string &result, struct ClassMethodDefineNode *seg);//----
void parseBreakNode(std::string &result);
void parseContinueNode(std::string &result);
void parseReturnNode(std::string &result, struct ReturnNode *seg);
//-------------- -----end tree node part-------------------
//---------------------expression part---------------------
void parseExpression(std::string& result, struct Expression* seg);
void parseLeftValue(std::string&result, struct LeftValue* seg);
void parseArrayValue(std::string&result, struct ArrayValue* seg);
void parseFunctionValue(std::string&result, struct FunctionValue* seg);
//-------------------end expression part-------------------
//---------------------parameter part---------------------
void parseFormParam(std::string&result,FormParam*seg);
void parseFactParam(std::string&result, struct FactParam* seg);
//-------------------end parameter part-------------------





//---------------------tree node part---------------------
void parseNodeList(std::string& result,TreeNode* seg,std::string name){
	result+="{\"name\":\"";
	result+=name;
	result += "\",\"children\":[\n";
	while(seg!=NULL){
		parseTreeNode(result,seg);
		if(seg->next != NULL){
			result+=",\n";
		}
		seg = seg->next;
	}
	result+="]}";
}

void parseTreeNode(std::string& result,TreeNode* seg){
	if(seg == NULL){
		return;
	}

	switch(seg->type){
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

void parseVarDeclareNode(std::string& result, struct VarDeclareNode* seg){
	if(seg == NULL){
		return;
	}
	char numStr[N_INT_CHAR];
	sprintf(numStr, "%d", ++lineno);

	result += "{\"name\":\"" + std::string(numStr) + ": var declare\",\"children\":[";
	result += "{\"name\":\"" + std::string(seg->type) + "\"},";
	result+="{\"name\":\""+ std::string(seg->name)+"\"}";
	result+="]}";
}

void parseVarDefineNode(std::string& result,VarDefineNode* seg){
	if(seg == NULL){
		return;
	}
	char numStr[N_INT_CHAR];
	sprintf(numStr, "%d", ++lineno);

	result+="{\"name\":\"" + std::string(numStr) + ": var define\",\"children\":[";
	result+="{\"name\":\"" + std::string(seg->type) + "\"},";
	result+="{\"name\":\"" + std::string(seg->name) + "\"},";
	result += "{\"name\":\"exp\",\"children\":[{\"name\":\"";
	parseExpression(result, seg->exp);
	result += "\"}]}";
	result += "]}";
}

void parseVarAssignNode(std::string& result,VarAssignNode* seg){
	if (seg == NULL) {
		return;
	}
	char numStr[N_INT_CHAR];
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
	result += "]}";
}

void parseArrayDeclareNode(std::string&result,ArrayDeclareNode* seg){
	if(seg == NULL){
		return;
	}
	char numStr[N_INT_CHAR];
	sprintf(numStr, "%d", ++lineno);

	result+="{\"name\":\"" + std::string(numStr) + ": array declare\",\"children\":[";
	result+="{\"name\":\"" + std::string(seg->type) + "\"},";
	result+="{\"name\":\"" + std::string(seg->name) + "\"}";
	result+="]}";
}

void parseArrayDefineNode(std::string&result,ArrayDefineNode*seg){
	if(seg == NULL){
		return;
	}
	char numStr[N_INT_CHAR];
	sprintf(numStr, "%d", ++lineno);

	result+="{\"name\":\"" + std::string(numStr) + ": array define\",\"children\":[";
	result+="{\"name\":\"" + std::string(seg->type) + "\"},";
	result+="{\"name\":\"" + std::string(seg->name) + "\"},";
	result += "{\"name\":\"nElement\",\"children\":[{\"name\":\"";
	parseExpression(result, seg->exp);
	result += "\"}]}";
	result+="]}";
}

void parseArrayAssignNode(std::string&result,ArrayAssignNode*seg){
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

void parseIfNode(std::string&result,IfNode*seg){
	if(seg == NULL){
		return;
	}

lineno++;
printf("%d if\n", lineno);
return;



	result+="{\"name\":\"if node\",\"children\":[";
	parseExpression(result,seg->exp);
	result+=',';
	parseNodeList(result,seg->stmts,"stmts");
	result+=',';
	parseNodeList(result,seg->elifStmts,"elifStmts");
	result+=',';
	parseNodeList(result,seg->elseStmts,"elseStmts");
	result+="]}";
}

void parseElifNode(std::string&result,ElifNode*seg){
	if(seg == NULL){
		return;
	}

lineno++;
printf("%d elif\n", lineno);
return;



	result+="{\"name\":\"else if node\",\"children\":[";
	parseExpression(result,seg->exp);
	result+=',';
	parseNodeList(result,seg->stmts,"stmts");
	result+="]}";
}

void parseElseNode(std::string&result,ElseNode*seg){
	if(seg == NULL){
		return;
	}

lineno++;
printf("%d else\n", lineno);
return;



	result+="{\"name\":\"else node\",\"children\":[";
	parseNodeList(result,seg->stmts,"stmts");
	result+="]}";
}

void parseWhileNode(std::string&result,WhileNode*seg){
	if(seg == NULL){
		return;
	}

lineno++;
printf("%d while\n", lineno);
return;



	result+="{\"name\":\"while node\",\"children\":[";
	parseExpression(result,seg->exp);
	result+=',';
	parseNodeList(result,seg->stmts,"stmts");
	result+="]}";
}

void parseForeachNode(std::string &result ,ForeachNode *seg){
	if(seg == NULL){
		return;
	}

lineno++;
printf("%d foreach\n", lineno);
return;


/*
	result+="{\"name\":\"foreach node\",\"children\":[";
	result+="{\"name\":\""+seg->nameIn+"\"},";
	result+="{\"name\":\""+seg->nameOut+"\"},";
	parseNodeList(result,seg->stmts,"stmts");
	result+="]}";
	*/
}

void parseClassDefineNode(std::string&result, struct ClassDefineNode *seg){
	if(seg == NULL){
		return;
	}

lineno++;
printf("%d class define\n", lineno);
return;


/*
	result+="{\"name\":\"class node\",\"children\":[";
	result+="{\"name\":\""+seg->type+"\"},";
	if(seg->typeParent!=NULL)
		result+="{\"name\":\"extends "+seg->typeParent+"\"},";
	parseNodeList(result,seg->stmts,"stmts");
	result+="]}";
	*/
}

void parseFunctionDeclareNode(std::string&result,FunctionDeclareNode*seg){
	if (seg == NULL) {
		return;
	}
	char numStr[N_INT_CHAR];
	sprintf(numStr, "%d", ++lineno);
	result+="{\"name\":\"function dec node\",\"children\":[";
	if (seg->type) {
		result += "{\"ret type\":\"" + std::string(seg->type) + "\"},";
	}
	else {
		result += "{\"name\":\"void\"},";
	}
	result+="{\"name\":\"" + std::string(seg->name) + "\"},";
	result += "{\"name\":\"args\",\"children\":[{\"name\":\"";
	parseFormParam(result, seg->formParams);
	result += "\"}]}";
	result+="]}";
}

void parseFunctionDefineNode(std::string&result,FunctionDefineNode*seg){
	if(seg == NULL){
		return;
	}

lineno++;
printf("%d func define\n", lineno);
return;

/*

	result+="{\"name\":\"function def node\",\"children\":[";
	result+="{\"name\":\""+seg->type+"\"},";
	result+="{\"name\":\""+seg->name+"\"},";
	parseFormParam(result,seg->formParams);
	result+=',';
	parseNodeList(result,seg->stmts,"stmts");
	result+="]}";
	*/
}

void parseClassMethodDefineNode(std::string&result,ClassMethodDefineNode*seg){
	if(seg == NULL){
		return;
	}

lineno++;
printf("%d class method def\n", lineno);
return;

/*

	result+="{\"name\":\"class method node\",\"children\":[";
	result+="{\"name\":\""+seg->classType+"\"},";
	result+="{\"name\":\""+seg->type+"\"},";
	result+="{\"name\":\""+seg->name+"\"},";
	parseFormParam(result,seg->formParams);
	result+=',';
	parseNodeList(result,seg->stmts,"stmts");
	result+="]}";
	*/
}

void parseBreakNode(std::string &result){
	char numStr[N_INT_CHAR];
	sprintf(numStr, "%d", ++lineno);

	result += "{\"name\":\"" + std::string(numStr) + ": break\"}";
}

void parseContinueNode(std::string &result){
	char numStr[N_INT_CHAR];
	sprintf(numStr, "%d", ++lineno);

	result += "{\"name\":\"" + std::string(numStr) + ": continue\"}";
}

void parseReturnNode(std::string &result, struct ReturnNode *seg){
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
void parseExpression(std::string &result,Expression* seg){
	if(seg == NULL){
		return;
	}
	switch (seg->op) {
	case OA_EXP_NONE:
		//leaf node
		switch (seg->leafType) {
		case OA_INT: {
			std::ostringstream oss;
			if (oss << seg->number_int)
				result += oss.str();
			break;
		}
		case OA_DOUBLE: {
			std::ostringstream oss;
			if (oss << seg->number_double)
				result += oss.str();
			break;
		}
		case OA_CHAR:
			result += seg->type_char;
			break;
		case OA_LEFT_VALUE:
			parseLeftValue(result, seg->name);
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
	case OA_EXP_MULTIPLE:
		parseExpression(result, seg->left);
		result += " * ";
		parseExpression(result, seg->right);
		break;
	case OA_EXP_DIVIDE:
		parseExpression(result, seg->left);
		result += " / ";
		parseExpression(result, seg->right);
		break;
	case OA_EXP_PLUS:
		parseExpression(result, seg->left);
		result += " + ";
		parseExpression(result, seg->right);
		break;
	case OA_EXP_MINUS:
		parseExpression(result, seg->left);
		result += " - ";
		parseExpression(result, seg->right);
		break;
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
}

void parseLeftValue(std::string&result,LeftValue* seg){
	if(seg==NULL){
		return;
	}
	while(seg!=NULL){
		result+=seg->name;
		if(seg->next!=NULL){
			result+='.';
		}
		seg= seg->next;
	}
}

void parseArrayValue(std::string&result,ArrayValue* seg){
	if(seg == NULL){
		return;
	}
	parseLeftValue(result,seg->name);
	result += '[';
	parseExpression(result,seg->index);
	result += ']';
}

void parseFunctionValue(std::string&result,FunctionValue* seg){
	if(seg == NULL){
		return;
	}
	parseLeftValue(result, seg->name);
	result+='(';
	parseFactParam(result,seg->factParam);
	result += ')';
}
//------------------end expression part-------------------

//---------------------parameter part---------------------
void parseFormParam(std::string&result,FormParam*seg){
	if(seg == NULL){
		return;
	}
	while (seg != NULL) {
		result += std::string(seg->type);
		result += " ";
		result += std::string(seg->name);
		if (seg->next != NULL) {
			result += ',';
		}
		seg = seg->next;
	}
}

void parseFactParam(std::string&result,FactParam* seg){
	if(seg == NULL){
		return;
	}
	while(seg != NULL){
		parseExpression(result,seg->exp);
		if(seg->next != NULL){
			result +=',';
		}
		seg = seg->next;
	}
}
//-------------------end parameter part-------------------


//------------------------main part-----------------------
int getTreeRaw(const char* filename){
	int rtcode = executeParser(filename);
	if(rtcode != 0){
		printf("error\n");
	}

lineno = 0;
	parseNodeList(result,parseTree->root,"root");
	printf("result: %s\n",result.c_str());
	return rtcode;
}

/*int main() {
	getTreeRaw("hello.oa");
	std::cin.get();
}*/