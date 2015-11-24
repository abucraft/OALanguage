#include<node.h>
#include<string>
#include<sstream>
#include"oa.h"
namespace OAparser{
	using v8::FunctionCallbackInfo;
	using v8::Isolate;
	using v8::Local;
	using v8::Object;
	using v8::String;
	using v8::Value;
	
	void Method(const FunctionCallbackInfo<Value>& args) {
  		Isolate* isolate = args.GetIsolate();
  		args.GetReturnValue().Set(String::NewFromUtf8(isolate, "world"));
	}
//---------------------tree node part---------------------
	void recursiveParseTree(std::string& result,TreeNode* seg);
	void parseVarDeclareNode(std::string& result,VarDeclareNode* seg);
	void parseVarDefineNode(std::string& result,VarDefineNode* seg);
	void parseArrayDeclareNode(std::string&result,ArrayDeclareNode* seg);
	void parseArrayDefineNode(std::string&result,ArrayDefineNode*seg);
	void parseArrayAssignNode(std::string&result,ArrayAssignNode*seg);
	void parseIfNode(std::string&result,IfNode*seg);
	void parseElifNode(std::string&result,ElifNode*seg);
	void parseElseNode(std::string&result,ElseNode*seg);
	void parseWhileNode(std::string&result,WhileNode*seg);
	void parseForeachNode(std::string&result,ForeachNode*seg);
	void parseClassDefineNode(std::string&result,ClassDefineNode*seg);
	void parseFunctionDeclareNode(std::string&result,FunctionDeclareNode*seg);
	void parseFunctionDefineNode(std::string&result,FunctionDefineNode*seg);
	void parseClassMethodDefineNode(std::string&result,ClassMethodDefineNode*seg);
//---------------------tree node part---------------------

//---------------------expression part---------------------
	void parseExpression(std::string& result,Expression* seg);
	void parseLeftValue(std::string&result,LeftValue* seg);
	void parseArrayValue(std::string&result,ArrayValue* seg);
	void parseFactParam(std::string&result,FactParam* seg);
	void parseFunctionValue(std::string&result,FunctionValue* seg);
//---------------------expression part---------------------

//---------------------parameter part---------------------
	void parseFormParam(std::string&result,FormParam*seg);
//---------------------parameter part---------------------


//---------------------tree node part---------------------
	void parseNodeList(std::string& result,TreeNode* seg,std::string name){
		result+="{\"name\":\"";
		result+=name;
		result+="\",\"children\":["
		while(seg!=NULL){
			recursiveParseTree(result,seg);
			if(seg->next != NULL){
				result+=',';
			}
			seg = seg->next;
		}
		result+="]}";
	}
	
	
	void parseVarDeclareNode(std::string& result,VarDeclareNode* seg){
		if(seg == NULL){
			return;
		}
		result+="{\"name\":\"var declare\",\"children\":[";
		result+="{\"name\":\""+seg->type+"\"},";
		result+="{\"name\":\""+seg->name+"\"}";
		result+="]}";
	}
	
	void parseVarDefineNode(std::string& result,VarDefineNode* seg){
		if(seg == NULL){
			return;
		}
		result+="{\"name\":\"var define\",\"children\":[";
		result+="{\"name\":\""+seg->type+"\"},";
		result+="{\"name\":\""+seg->name+"\"},";
		parseExpression(result,seg->exp);
		result+="]}";
	}
	
	void parseArrayDeclareNode(std::string&result,ArrayDeclareNode* seg){
		if(seg == NULL){
			return;
		}
		result+="{\"name\":\"array declare\",\"children\":[";
		result+="{\"name\":\""+seg->type+"\"},";
		result+="{\"name\":\""+seg->name+"\"}";
		result+="]}";
	}
	
	void parseArrayDefineNode(std::string&result,ArrayDefineNode*seg){
		if(seg == NULL){
			return;
		}
		result+="{\"name\":\"array define\",\"children\":[";
		result+="{\"name\":\""+seg->type+"\"},";
		result+="{\"name\":\""+seg->name+"\"},";
		parseExpression(result,seg->exp);
		result+="]}";
	}
	
	void parseArrayAssignNode(std::string&result,ArrayAssignNode*seg){
		if(seg == NULL){
			return;
		}
		result+="{\"name\":\"array assign\",\"children\":[";
		result+="{\"name\":\""+seg->type+"\"},";
		parseLeftValue(result,seg->name);
		result+=",";
		parseExpression(result,seg->exp);
		result+="]}";
	}
	
	void parseIfNode(std::string&result,IfNode*seg){
		if(seg == NULL){
			return;
		}
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
		result+="{\"name\":\"else node\",\"children\":[";
		parseNodeList(result,seg->stmts,"stmts");
		result+="]}";
	}
	
	void parseWhileNode(std::string&result,WhileNode*seg){
		if(seg == NULL){
			return;
		}
		result+="{\"name\":\"while node\",\"children\":[";
		parseExpression(result,seg->exp);
		result+=',';
		parseNodeList(result,seg->stmts,"stmts");
		result+="]}";
	}
	void parseForeachNode(std::string&result,ForeachNode*seg){
		if(seg == NULL){
			return;
		}
		result+="{\"name\":\"foreach node\",\"children\":[";
		result+="{\"name\":\""+seg->nameIn+"\"},";
		result+="{\"name\":\""+seg->nameOut+"\"},";
		parseNodeList(result,seg->stmts,"stmts");
		result+="]}";
	}
	void parseClassDefineNode(std::string&result,ClassDefineNode*seg){
		if(seg == NULL){
			return;
		}
		result+="{\"name\":\"class node\",\"children\":[";
		result+="{\"name\":\""+seg->type+"\"},";
		if(seg->typeParent!=NULL)
			result+="{\"name\":\"extends "+seg->typeParent+"\"},";
		parseNodeList(result,seg->stmts,"stmts");
		result+="]}";
	}
	void parseFunctionDeclareNode(std::string&result,FunctionDeclareNode*seg){
		if(seg == NULL){
			return;
		}
		result+="{\"name\":\"function dec node\",\"children\":[";
		result+="{\"name\":\""+seg->type+"\"},";
		result+="{\"name\":\""+seg->name+"\"},";
		parseFormParam(result,seg->formParams);
		result+="]}";
	}
	void parseFunctionDefineNode(std::string&result,FunctionDefineNode*seg){
		if(seg == NULL){
			return;
		}
		result+="{\"name\":\"function def node\",\"children\":[";
		result+="{\"name\":\""+seg->type+"\"},";
		result+="{\"name\":\""+seg->name+"\"},";
		parseFormParam(result,seg->formParams);
		result+=',';
		parseNodeList(result,seg->stmts,"stmts");
		result+="]}";
	}
	void parseClassMethodDefineNode(std::string&result,ClassMethodDefineNode*seg){
		if(seg == NULL){
			return;
		}
		result+="{\"name\":\"class method node\",\"children\":[";
		result+="{\"name\":\""+seg->classType+"\"},";
		result+="{\"name\":\""+seg->type+"\"},";
		result+="{\"name\":\""+seg->name+"\"},";
		parseFormParam(result,seg->formParams);
		result+=',';
		parseNodeList(result,seg->stmts,"stmts");
		result+="]}";
	}
	
//---------------------tree node part---------------------
	
//---------------------expression part---------------------
	void parseLeftValue(std::string&result,LeftValue* seg){
		if(seg==NULL){
			return;
		}
		result+="{\"name\":\"";
		while(seg!=NULL){
			result+=seg->name;
			if(seg->next!=NULL){
				result+='.';
			}
			seg= seg->next;
		}
		result+="\"}";
	}
	
	
	void parseArrayValue(std::string&result,ArrayValue* seg){
		if(seg == NULL){
			return;
		}
		result+="{\"name\":\"array value\",\"children\":[";
		parseLeftValue(result,seg->name);
		parseExpression(result,seg->index);
		result+="]}";
	}
	
	void parseFactParam(std::string&result,FactParam* seg){
		if(seg == NULL){
			return;
		}
		result+="{\"name\":\"fact param\",\"children\":[";
		while(seg != NULL){
			parseExpression(result,seg->exp);
			if(seg ->next != NULL){
				result +=',';
			}
			seg = seg->next;
		}
		result+="]}";
	}
	
	void parseFunctionValue(std::string&result,FunctionValue* seg){
		if(seg == NULL){
			return;
		}
		result+="{\"name\":\"function value\",\"children\":[";
		parseExpression(result,seg->name);
		result+=',';
		parseFactParam(result,seg->factParam);
		result+="]}";
	}
	
	void parseExpression(std::string& result,Expression* seg){
		if(seg == NULL){
			return;
		}
		result+="{\"name\":\"expression\",\"children\":[";
		std::stringstream sst;
		std::string buf;
		std::string op;
		switch(seg->op){
			case OA_EXP_NONE:
			switch(seg->leafType){
				case OA_INT:
				result+="{\"name\":\"";
				sst<<seg->number_int;
				sst>>buf;
				result+=buf;
				break;
				case OA_DOUBLE:
				result+="{\"name\":\"";
				sst<<seg->number_double;
				sst>>buf;
				result+=buf;
				break;
				case OA_CHAR:
				result+="{\"name\":\"";
				result+=seg->type_char;
				break;
				case OA_LEFT_VALUE:
				parseLeftValue(result,seg->name);
				break;
				case OA_ARRAY_VALUE:
				parseFactParam(result,seg->arrayValue);
				break;
				case OA_FUNCTION_VALUE:
				parseFunctionValue(result,seg->functionValue);
				break;
			}
			result+="\"}";
			break;
			case OA_EXP_MULTIPLE:
			op = "*";
			case OA_EXP_DIVIDE:
			op = "/";
			case OA_EXP_PLUS:
			op = "+";
			case OA_EXP_MINUS:
			op = "-";
			case OA_EXP_EQ:
			op = "==";
			case OA_EXP_NE:
			op = "!=";
			case OA_EXP_GT:
			op = ">";
			case OA_EXP_GE:
			op = ">=";
			case OA_EXP_LT:
			op = "<";
			case OA_EXP_LE:
			op = "<=";
			case OA_EXP_AND:
			op = "&";
			case OA_EXP_OR:
			op = "|";
			result+="{\"name\":\"exp "+op+"\",\"children\":[";
			parseExpression(result,seg->left);
			result+=',';
			parseExpression(result,seg->right);
			result+="]}";
			break;
			case OA_EXP_NOT:
			op = "!";
			result+="{\"name\":\"exp "+op+"\",\"children\":[";
			parseExpression(result,seg->left);
			result+="]}";
			break;
		}
		result+="]}";
	}
//---------------------expression part---------------------

//---------------------parameter part---------------------
	void parseFormParam(std::string&result,FormParam*seg){
		if(seg == NULL){
			return;
		}
		result+="{\"name\":\"form node\",\"children\":[";
		result+="{\"name\":\""+seg->type+"\"},";
		result+="{\"name\":\""+seg->name+"\"},";
		//parseNodeList(result,seg->stmts,"stmts");
		result+="]}";
	}
//---------------------parameter part---------------------


	void recursiveParseTree(std::string& result,TreeNode* seg){
		if(seg == NULL){
			return;
		}
		result+="{\"name\":";
		result+='\"';
		result+=" ";
		result+='\"';
		result+=",\"children\":[";
		switch(seg->type){
			case VAR_DECLARE_NODE:
			
			case VAR_DEFINE_NODE:
			case VAR_ASSIGN_NODE:
			case ARRAY_DECLARE_NODE:
			case ARRAY_DEFINE_NODE:
			case ARRAY_ASSIGN_NODE:
			case IF_NODE:
			case ELIF_NODE:
			case ELSE_NODE:
			case WHILE_NODE:
			case FOREACH_NODE:
			case CLASS_DEFINE_NODE:
			case FUNCTION_DECLARE_NODE:
			case FUNCTION_DEFINE_NODE:
			case CLASS_METHOD_DEFINE_NODE:
			break;
		}
		result+="]}";
	}
	
	void getTree(const FunctionCallbackInfo<Value>& args){
		Isolate* isolate = args.GetIsolate();
		std::string result;
		if(args.Length() < 1){
			result = "{\"error\":\"need argument\"}";
			args.GetReturnValue().Set(String::NewFromUtf8(isolate, result.c_str()));
			return;
		}
		if(!args[0]->IsString()){
			result = "{\"error\":\"argument is not string\"}";
			args.GetReturnValue().Set(String::NewFromUtf8(isolate, result.c_str()));
			return;
		}
		Local<String> strArg = args[0]->ToString();
		char* cStr = new char[strArg->Length()+1];
		strArg->WriteUtf8(cStr);
		std::string cppStr(cStr);
		delete [] cStr;
		int rtcode = execute(cppStr.c_str());
		if(rtcode != 0){
			result = "{\"error\":\"compiler error\"}";
			args.GetReturnValue().Set(String::NewFromUtf8(isolate, result.c_str()));
			return;
		}
		result+="{\"name\":\"root\",\"children\":[";
		parseNodeList(result,parseTree->root,"root");
		result+="]}";
		args.GetReturnValue().Set(String::NewFromUtf8(isolate, result.c_str()));
	}
	
	
	
	void recursiveParseIfElse(std::string& result,IfElseNode* seg){
		if(seg == NULL){
			return;
		}
	}

	void init(Local<Object> exports) {
  		NODE_SET_METHOD(exports, "hello", Method);
		NODE_SET_METHOD(exports, "getTree",getTree);
	}

	NODE_MODULE(addon, init);

}