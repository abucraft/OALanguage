#include<node.h>
#include<string>
#include<sstream>
#include"compiler.h"

extern std::string result;

namespace OAparser{
	using v8::Function;
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

	void getTree(const FunctionCallbackInfo<Value>& args){
		Isolate* isolate = args.GetIsolate();
		std::string _result;
		Local<Function> cb = Local<Function>::Cast(args[1]);
		const unsigned argc = 2;
		if(args.Length() < 1){
			_result = "need argument";
			Local<Value> argv[argc] = { String::NewFromUtf8(isolate, _result.c_str()),String::NewFromUtf8(isolate, "null") };
			cb->Call(Null(isolate), argc, argv);
			return;
		}
		if(!args[0]->IsString()){
			_result = "argument is not string";
			Local<Value> argv[argc] = { String::NewFromUtf8(isolate, _result.c_str()),String::NewFromUtf8(isolate, "null") };
			cb->Call(Null(isolate), argc, argv);
			return;
		}
		Local<String> strArg = args[0]->ToString();
		char* cStr = new char[strArg->Length()+1];
		strArg->WriteUtf8(cStr);
		std::string cppStr(cStr);
		delete [] cStr;
		int rtcode = getTreeRaw(cppStr.c_str());
		if(rtcode != 0){
			_result = "compiler error";
			Local<Value> argv[argc] = { String::NewFromUtf8(isolate, _result.c_str()),String::NewFromUtf8(isolate, "null") };
			cb->Call(Null(isolate), argc, argv);
			return;
		}
		Local<Value> argv[argc] = { String::NewFromUtf8(isolate, "null"),String::NewFromUtf8(isolate, result.c_str()) };
  		cb->Call(Null(isolate), argc, argv);
	}
	
	void RunCallback(const FunctionCallbackInfo<Value>& args) {
  		Isolate* isolate = args.GetIsolate();
  		Local<Function> cb = Local<Function>::Cast(args[0]);
  		const unsigned argc = 1;
  		Local<Value> argv[argc] = { String::NewFromUtf8(isolate, "hello world") };
  		cb->Call(Null(isolate), argc, argv);
	}

	void init(Local<Object> exports) {
  		NODE_SET_METHOD(exports, "hello", Method);
		NODE_SET_METHOD(exports, "getTree",getTree);
		NODE_SET_METHOD(exports, "callback", RunCallback);
	}

	NODE_MODULE(addon, init);

}