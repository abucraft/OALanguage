%{
#include <stdio.h>
#include <stdlib.h>
#include "oa.h"
#define YYDEBUG 1
%}


%union {
	int				number_int;
	double			number_double;
	char			type_char;
	char			*type_string;
	char			*type;
	char			*name;
	struct TreeNode	*node;
	struct Expression *expression;
	struct FormParam *formParam;
	struct LeftValue *leftValue;
	struct FactParam *factParam;
}

%token BOOLEAN BREAK CHAR CLASS CONTINUE DOUBLE ELIF ELSE EXTENDS FALSE FOR FOREACH IF IMPORT IN INT MY_NULL RETURN THIS TRUE VOID WHILE PART_LETTER DECIMAL_LITERAL DECIMAL_FLOATING_POINT_LITERAL TYPE_CHAR STRING LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET SEMICOLON COMMA DOT ASSIGN LT GT BANG TILDE EQ LE GE NE SC_OR SC_AND PLUS MINUS STAR SLASH BIT_AND BIT_OR XOR REM NAME_SPACE CLASS_IDENTIFIER STRING_LITERAL


%token <type> INT DOUBLE CLASS_IDENTIFIER CHAR
%token <name> IDENTIFIER
%token <number_int> DECIMAL_LITERAL
%token <number_double> DECIMAL_FLOATING_POINT_LITERAL
%token <type_char> CHAR_LITERAL
%token <type_string> STRING_LITERAL

%type <type> type arrayType
%type <node> outerStatements outerStatement
			 functionStatements functionStatement
			 classStatements classStatement
			 varDeclareStatement varDefineStatement varAssignStatement
			 arrayDeclareStatement arrayDefineStatement arrayAssignStatement
			 ifStatement elifParts elifPart elsePart
			 whileStatement foreachStatement
			 classDefineStatement
			 functionDeclareStatement functionDefineStatement classMethodDefineStatement
			 breakStatement continueStatement returnStatement
%type <expression> expression compareExpression mathExpression term factor
%type <formParam> formParams formParamSet formParam
%type <leftValue> leftValue leftValueSet
%type <factParam> factParams factParamSet factParam


%%
outerStatements
	:/*empty*/{
		$$ = NULL;
	}
	|outerStatement outerStatements{
		if($1){
			$1->next = $2;
			extern struct ParseTree *parseTree;
			parseTree->root = $1;
		}else{
			$$ = $2;
		}
	}
	;



outerStatement
	:varDeclareStatement		SEMICOLON
	|varDefineStatement			SEMICOLON
	|arrayDeclareStatement		SEMICOLON
	|arrayDefineStatement		SEMICOLON
	|classDefineStatement 
	|functionDeclareStatement	SEMICOLON
	|functionDefineStatement
	|classMethodDefineStatement
	|returnStatement			SEMICOLON
	|SEMICOLON{
		$$ = NULL;
	}
	;

functionStatements
	:/*empty*/{
		$$ = NULL;
	}
	|functionStatement functionStatements{
		if($1){
			$1->next = $2;
		}else{
			$$ = $2;
		}
	}
	;
	
functionStatement
	:varDeclareStatement		SEMICOLON
	|varDefineStatement			SEMICOLON
	|varAssignStatement			SEMICOLON
	|arrayDeclareStatement		SEMICOLON
	|arrayDefineStatement		SEMICOLON
	|arrayAssignStatement		SEMICOLON
	|ifStatement
	|whileStatement
	|foreachStatement
	|breakStatement				SEMICOLON
	|continueStatement			SEMICOLON
	|returnStatement			SEMICOLON
	|SEMICOLON{
		$$ = NULL;
	}
	;

classStatements
	:/*empty*/{
		$$ = NULL;
	}
	|classStatement classStatements{
		if($1){
			$1->next = $2;
		}else{
			$$ = $2;
		}
	}
	;
	
classStatement
	:varDeclareStatement		SEMICOLON
	|arrayDeclareStatement		SEMICOLON
	|functionDeclareStatement	SEMICOLON
	|SEMICOLON{
		$$ = NULL;
	}
	;
	
/*--------------------variable part--------------------*/
varDeclareStatement
	:type IDENTIFIER {
		$$ = createVarDeclare($1, $2);
	}
	;

varDefineStatement
	:type IDENTIFIER ASSIGN expression {
		$$ = createVarDefine($1, $2, $4);
	}
	;
	
varAssignStatement	/* containinig array[expression] assignment and not giving value expression using*/
	:leftValue ASSIGN expression {
		$$ = createVarAssign($1, $3, NULL);
	}
	|leftValue LBRACKET expression RBRACKET ASSIGN expression {
		$$ = createVarAssign($1, $6, $3);
	}
	|expression{
		$$ = createVarAssign(NULL, $1, NULL);
	}
	;

/*--------------------array part--------------------*/
arrayDeclareStatement
	:arrayType IDENTIFIER{
		$$ = createArrayDeclare($1, $2);
	}
	;
	
arrayDefineStatement
	:arrayType IDENTIFIER ASSIGN type LBRACKET expression RBRACKET{
		$$ = createArrayDefine($1, $2, $4, $6);
	}
	;

arrayAssignStatement
	:leftValue ASSIGN type LBRACKET expression RBRACKET{
		$$ = createArrayAssign($1, $3, $5);
	}
	;

	
/*--------------------if-elif-else part----------------*/
ifStatement
	:IF LPAREN expression RPAREN LBRACE functionStatements RBRACE elifParts elsePart{
		$$ = createIf($3, $6, $8, $9);
	}
	;

elifParts
	:/*empty*/{
		$$ = NULL;
	}
	|elifPart elifParts{
		$1->next = $2;
		$$ = $1;
	}
	;
	
elifPart
	:ELIF LPAREN expression RPAREN LBRACE functionStatements RBRACE{
		$$ = createElifPart($3, $6);
	}
	;

elsePart
	:/*empty*/{
		$$ = NULL;
	}
	|ELSE LBRACE functionStatements RBRACE{
		$$ = createElsePart($3);
	}
	;

/*--------------------loop part----------------*/
whileStatement
	:WHILE LPAREN expression RPAREN LBRACE functionStatements RBRACE{
		$$ = createWhile($3, $6);
	}
	;
	
foreachStatement
	:FOREACH LPAREN IDENTIFIER IN leftValue RPAREN LBRACE functionStatements RBRACE{
		$$ = createForeach($3, $5, $8);
	}
	;
	
/*--------------------class part----------------*/
classDefineStatement
	:CLASS CLASS_IDENTIFIER LBRACE classStatements RBRACE{
		$$ = createClassDefine($2, NULL, $4);
	}
	|CLASS CLASS_IDENTIFIER EXTENDS	CLASS_IDENTIFIER LBRACE classStatements RBRACE{
		$$ = createClassDefine($2, $4, $6);
	}
	;

/*--------------------function part----------------*/

functionDeclareStatement
	:type IDENTIFIER LPAREN formParams RPAREN{
		$$ = createFunctionDeclare($1, $2, $4);
	}
	|arrayType IDENTIFIER LPAREN formParams RPAREN{
		$$ = createFunctionDeclare($1, $2, $4);
	}
	|VOID IDENTIFIER LPAREN formParams RPAREN{
		$$ = createFunctionDeclare(NULL, $2, $4);
	}
	;
	
functionDefineStatement
	:type IDENTIFIER LPAREN formParams RPAREN LBRACE functionStatements RBRACE{
		$$ = createFunctionDefine($1, $2, $4, $7);
	}
	|arrayType IDENTIFIER LPAREN formParams RPAREN LBRACE functionStatements RBRACE{
		$$ = createFunctionDefine($1, $2, $4, $7);
	}
	|VOID IDENTIFIER LPAREN formParams RPAREN LBRACE functionStatements RBRACE{
		$$ = createFunctionDefine(NULL, $2, $4, $7);
	}
	;
	
classMethodDefineStatement
	:type CLASS_IDENTIFIER NAME_SPACE IDENTIFIER LPAREN formParams RPAREN LBRACE functionStatements RBRACE{
		$$ = createClassMethodDefine($1, $4, $6, $9, $2);
	}
	|arrayType CLASS_IDENTIFIER NAME_SPACE IDENTIFIER LPAREN formParams RPAREN LBRACE functionStatements RBRACE{
		$$ = createClassMethodDefine($1, $4, $6, $9, $2);
	}
	|VOID CLASS_IDENTIFIER NAME_SPACE IDENTIFIER LPAREN formParams RPAREN LBRACE functionStatements RBRACE{
		$$ = createClassMethodDefine(NULL, $4, $6, $9, $2);
	}
	;
/*--------------------control part----------------*/
/*in loop*/
breakStatement
	:BREAK{
		$$ = createBreak();
	}
	;
	
continueStatement
	:CONTINUE{
		$$ = createContinue();
	}
	;

/*in function*/		
returnStatement
	:RETURN expression{
		$$ = createReturn($2);
	}
	|RETURN{
		$$ = createReturn(NULL);
	}
	;

/*--------------------parameter part----------------*/
formParams
	:/*empty*/{
		$$ = NULL;
	}
	|formParam formParamSet{
		$1->next = $2;
		$$ = $1;
	}
	;
	
formParamSet
	:/*empty*/{
		$$ = NULL;
	}
	|COMMA formParam formParamSet{
		$2->next = $3;
		$$ = $2;
	}
	;
	
formParam
	:type IDENTIFIER{
		$$ = createFormParam($1, $2);
	}
	|arrayType IDENTIFIER{
		$$ = createFormParam($1, $2);
	}
	;

	
/*--------------------expression part----------------*/
expression
	:compareExpression SC_AND expression{
		$$ = createExpression($1, $3, OA_EXP_AND);
	}
	|compareExpression SC_OR expression{
		$$ = createExpression($1, $3, OA_EXP_OR);
	}
	|BANG expression{
		$$ = createExpression($2, NULL, OA_EXP_NOT);
	}
	|compareExpression
	;

compareExpression
	:mathExpression EQ mathExpression{
		$$ = createExpression($1, $3, OA_EXP_EQ);
	}
	|mathExpression NE mathExpression{
		$$ = createExpression($1, $3, OA_EXP_NE);
	}
	|mathExpression GT mathExpression{
		$$ = createExpression($1, $3, OA_EXP_GT);
	}
	|mathExpression GE mathExpression{
		$$ = createExpression($1, $3, OA_EXP_GE);
	}
	|mathExpression LT mathExpression{
		$$ = createExpression($1, $3, OA_EXP_LT);
	}
	|mathExpression LE mathExpression{
		$$ = createExpression($1, $3, OA_EXP_LE);
	}
	|mathExpression
	;
	
mathExpression
	:term PLUS mathExpression{
		$$ = createExpression($1, $3, OA_EXP_PLUS);
	}
	|term MINUS mathExpression{
		$$ = createExpression($1, $3, OA_EXP_MINUS);
	}
	|term
	;
	
term
	:factor STAR term{
		$$ = createExpression($1, $3, OA_EXP_MULTIPLE);
	}
	|factor SLASH term{
		$$ = createExpression($1, $3, OA_EXP_DIVIDE);
	}
	|factor
	;
	
factor
	:DECIMAL_LITERAL{
		$$ = createExpressionIntLeaf($1, 1);
	}
	|DECIMAL_FLOATING_POINT_LITERAL{
		$$ = createExpressionDoubleLeaf($1, 1);
	}
	|CHAR_LITERAL{
		$$ = createExpressionCharLeaf($1);
	}
	|STRING_LITERAL{
		$$ = createExpressionStringLeaf($1);
	}
	|leftValue{
		$$ = createExpressionLeftValueLeaf($1);
	}
	|leftValue LBRACKET expression RBRACKET{
		$$ = createExpressionArrayValue($1, $3);
	}
	|leftValue LPAREN factParams RPAREN{
		$$ = createExpressionFunctionValue($1, $3);
	}
	|LPAREN expression RPAREN{
		$$ = $2;
	}
	|MINUS DECIMAL_LITERAL{
		$$ = createExpressionIntLeaf($2, 0);
	}
	|MINUS DECIMAL_FLOATING_POINT_LITERAL{
		$$ = createExpressionDoubleLeaf($2, 0);
	}
	;
	
leftValue
	:IDENTIFIER leftValueSet{
		$$ = createLeftValue($1);
		$$->next = $2;
	}
	;
		
leftValueSet
	:/*empty*/{
		$$ = NULL;
	}
	|DOT IDENTIFIER leftValueSet{
		$$ = createLeftValue($2);
		$$->next = $3;
	}
	;

factParams
	:/*empty*/{
		$$ = NULL;
	}
	|factParam factParamSet{
		$1->next = $2;
		$$ = $1;
	}
	;
	
factParamSet
	:/*empty*/{
		$$ = NULL;
	}
	|COMMA factParam factParamSet{
		$2->next = $3;
		$$ = $2;
	}
	;
	
factParam
	:expression{
		$$ = createFactParam($1);
	}
	;
	
/*--------------------type part----------------*/	

	
arrayType
	:type LBRACKET RBRACKET{
		$$ = createArrayType($1);
	}
	;

type
	:INT
	|DOUBLE
	|CHAR
	|CLASS_IDENTIFIER
	;
	
	
%%
int yyerror(char* s){
	extern int yylineno;
	extern char *yytext;
	fprintf(stderr, "%s ", s);
	fprintf(stderr, "\nERROR! line %d: ", yylineno);
	fprintf(stderr, "before \"%s\"\n", yytext);
	return 0;
}

int executeParser(const char *filename)
{
	extern FILE *tokenStream;
	extern struct ParseTree *parseTree;
	tokenStream = NULL;
	tokenStream = fopen("tokenStream.txt", "w");
	if(!tokenStream){
		printf("cannot open token stream file\n");
		return 1;
	}
    extern int yyparse(void);
    extern FILE *yyin;
    FILE* fp = NULL;
    fp = fopen(filename, "r");
    if(fp == NULL){
      return 1;
    }
	parseTree = (struct ParseTree*)malloc(sizeof(struct ParseTree));
	parseTree->root = NULL;
    yyin = fp;
    int result = yyparse();
    fclose(fp);
	fclose(tokenStream);
	//printJason(parseTree->root);
	return 0;
}

/*
int main(void)
{
    extern int yyparse(void);
    extern FILE *yyin;
	
	parseTree = (struct ParseTree*)malloc(sizeof(struct ParseTree));
	tokenStream = NULL;
	tokenStream = fopen("tokenStream.txt", "w");
	if(!tokenStream){
		printf("cannot open token stream file\n");
		return 1;
	}
	
    yyin = stdin;
    if (yyparse()) {
		fclose(tokenStream);
		return 1;
    }
	printJason(parseTree->root);
	fclose(tokenStream);
}
*/