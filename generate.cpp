void parseFunctionDefineNode(std::string&result, FunctionDefineNode*seg) {
	if (seg == NULL) {
		return;
	}
	//define
	result += "define ";
	//return type
	if (seg->type) {
		result += std::string(seg->type);
	}
	else {
		result += "void";
	}
	//function name
	result += " @";
	result += std::string(seg->name);
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
}


void parseFormParam(std::string&result, FormParam*seg) {
	if (seg == NULL) {
		return;
	}
	while (seg != NULL) {
		result += std::string(seg->type);
		result += " %";
		result += std::string(seg->name);
		if (seg->next != NULL) {
			result += ", ";
		}
		seg = seg->next;
	}
}