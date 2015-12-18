%option yylineno
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
int yywrap(void){
    return 1;
}

%}
%start COMMENT LONG_COMMENT
%%

<INITIAL>"//" {
	BEGIN COMMENT;
}
<INITIAL>"/*" {
	BEGIN LONG_COMMENT;
}
<COMMENT>"\n" {
	BEGIN INITIAL;
}
<LONG_COMMENT>"*/" {
	BEGIN INITIAL;
}
<INITIAL>"boolean"		{ extern FILE *tokenStream; fprintf(tokenStream, "boolean "); return BOOLEAN; }
<INITIAL>"break"		{ extern FILE *tokenStream; fprintf(tokenStream, "break "); return BREAK;}
<INITIAL>"char"			{
	extern FILE *tokenStream; fprintf(tokenStream, "char ");
	yylval.type = (char*)malloc(strlen(yytext) + 1);
    sscanf(yytext, "%s", yylval.type);
    return CHAR;
}
<INITIAL>"class"		{ extern FILE *tokenStream; fprintf(tokenStream, "class "); return CLASS; }
<INITIAL>"continue"		{ extern FILE *tokenStream; fprintf(tokenStream, "continue "); return CONTINUE;}
<INITIAL>"double"	{
	extern FILE *tokenStream; fprintf(tokenStream, "double "); 
    yylval.type = (char*)malloc(strlen(yytext) + 1);
    sscanf(yytext, "%s", yylval.type);
    return DOUBLE;
}
<INITIAL>"elif"		{ extern FILE *tokenStream; fprintf(tokenStream, "elif "); return ELIF; }
<INITIAL>"else"		{ extern FILE *tokenStream; fprintf(tokenStream, "else "); return ELSE; }
<INITIAL>"extends"	{ extern FILE *tokenStream; fprintf(tokenStream, "extends "); return EXTENDS; }
<INITIAL>"false"	{ extern FILE *tokenStream; fprintf(tokenStream, "false "); return FALSE; }
<INITIAL>"for"		{ extern FILE *tokenStream; fprintf(tokenStream, "for "); return FOR;}
<INITIAL>"foreach"	{ extern FILE *tokenStream; fprintf(tokenStream, "foreach "); return FOREACH; }
<INITIAL>"if"		{ extern FILE *tokenStream; fprintf(tokenStream, "if "); return IF; }
<INITIAL>"import"	{ extern FILE *tokenStream; fprintf(tokenStream, "import "); return IMPORT; }
<INITIAL>"in"		{ extern FILE *tokenStream; fprintf(tokenStream, "in "); return IN; }
<INITIAL>"int"		{
	extern FILE *tokenStream; fprintf(tokenStream, "int "); 
    yylval.type = (char*)malloc(strlen(yytext) + 1);
    sscanf(yytext, "%s", yylval.type);
    return INT;
}
<INITIAL>"null"		{ extern FILE *tokenStream; fprintf(tokenStream, "null "); return MY_NULL; }
<INITIAL>"return"	{ extern FILE *tokenStream; fprintf(tokenStream, "return "); return RETURN; }
<INITIAL>"this"		{ extern FILE *tokenStream; fprintf(tokenStream, "this "); return THIS; }
<INITIAL>"true"		{ extern FILE *tokenStream; fprintf(tokenStream, "true "); return TRUE; }
<INITIAL>"void"		{ extern FILE *tokenStream; fprintf(tokenStream, "void "); return VOID; }
<INITIAL>"while"	{ extern FILE *tokenStream; fprintf(tokenStream, "while "); return WHILE; }

<INITIAL>([1-9][0-9]*)|0 {
    int temp;
    sscanf(yytext, "%d", &temp);
    yylval.number_int = temp;
	extern FILE *tokenStream; fprintf(tokenStream, "%d ", temp); 
    return DECIMAL_LITERAL;
}
<INITIAL>[0-9]+\.[1-9]* {
	double temp;
    sscanf(yytext, "%lf", &temp);
    yylval.number_double = temp;
	extern FILE *tokenStream; fprintf(tokenStream, "%lf ", temp); 
	return DECIMAL_FLOATING_POINT_LITERAL;
}
<INITIAL>"'"([0-9]|[a-z]|[A-Z]|"\\"|"!"|" ")"'" {
	char temp[4];
    sscanf(yytext, "%s", temp);
	yylval.type_char = temp[1];
	extern FILE *tokenStream; fprintf(tokenStream, "%s ", temp); 
    return CHAR_LITERAL;
}

<INITIAL>"\""([0-9]|[a-z]|[A-Z]|"\\"|"!"|" ")+"\"" {
	yylval.type_string = (char*)malloc(strlen(yytext) + 1);
    strcpy(yylval.type_string, yytext);
	extern FILE *tokenStream; fprintf(tokenStream, "%s ", yylval.type_string); 
    return STRING_LITERAL;
}

<INITIAL>"("		{ extern FILE *tokenStream; fprintf(tokenStream, "( "); return LPAREN; }
<INITIAL>")"		{ extern FILE *tokenStream; fprintf(tokenStream, ") "); return RPAREN; }
<INITIAL>"{"		{ extern FILE *tokenStream; fprintf(tokenStream, "{ "); return LBRACE; }
<INITIAL>"}"		{ extern FILE *tokenStream; fprintf(tokenStream, "} "); return RBRACE; }
<INITIAL>"["		{ extern FILE *tokenStream; fprintf(tokenStream, "[ "); return LBRACKET; }
<INITIAL>"]"		{ extern FILE *tokenStream; fprintf(tokenStream, "] "); return RBRACKET; }
<INITIAL>";"		{ extern FILE *tokenStream; fprintf(tokenStream, "; "); return SEMICOLON; }
<INITIAL>","		{ extern FILE *tokenStream; fprintf(tokenStream, ", "); return COMMA; }
<INITIAL>"."		{ extern FILE *tokenStream; fprintf(tokenStream, ". "); return DOT; }

<INITIAL>"="		{ extern FILE *tokenStream; fprintf(tokenStream, "= "); return ASSIGN; }
<INITIAL>"<"		{ extern FILE *tokenStream; fprintf(tokenStream, "< "); return LT; }
<INITIAL>">"		{ extern FILE *tokenStream; fprintf(tokenStream, "> "); return GT; }
<INITIAL>"!"		{ extern FILE *tokenStream; fprintf(tokenStream, "! "); return BANG; }
<INITIAL>"~"		{ extern FILE *tokenStream; fprintf(tokenStream, "~ "); return TILDE; }
<INITIAL>"=="		{ extern FILE *tokenStream; fprintf(tokenStream, "== "); return EQ; }
<INITIAL>"<="		{ extern FILE *tokenStream; fprintf(tokenStream, "<= "); return LE; }
<INITIAL>">="		{ extern FILE *tokenStream; fprintf(tokenStream, ">= "); return GE; }
<INITIAL>"!="		{ extern FILE *tokenStream; fprintf(tokenStream, "!= "); return NE; }
<INITIAL>"||"		{ extern FILE *tokenStream; fprintf(tokenStream, "|| "); return SC_OR; }
<INITIAL>"&&"		{ extern FILE *tokenStream; fprintf(tokenStream, "&& "); return SC_AND; }
<INITIAL>"+"		{ extern FILE *tokenStream; fprintf(tokenStream, "+ "); return PLUS; }
<INITIAL>"-"		{ extern FILE *tokenStream; fprintf(tokenStream, "- "); return MINUS; }
<INITIAL>"*"		{ extern FILE *tokenStream; fprintf(tokenStream, "* "); return STAR; }
<INITIAL>"/"		{ extern FILE *tokenStream; fprintf(tokenStream, "/ "); return SLASH; }
<INITIAL>"&"		{ extern FILE *tokenStream; fprintf(tokenStream, "& "); return BIT_AND; }
<INITIAL>"|"		{ extern FILE *tokenStream; fprintf(tokenStream, "| "); return BIT_OR; }
<INITIAL>"^"		{ extern FILE *tokenStream; fprintf(tokenStream, "^ "); return XOR; }
<INITIAL>"%"		{ extern FILE *tokenStream; fprintf(tokenStream, "% "); return REM; }
<INITIAL>"::"		{ extern FILE *tokenStream; fprintf(tokenStream, ":: "); return NAME_SPACE; }

<INITIAL>"@"([a-z]|[A-Z]|"_")([0-9]|[a-z]|[A-Z]|"_")*	{
    yylval.name = (char*)malloc(strlen(yytext) + 1);
    sscanf(yytext, "%s", yylval.name);
	extern FILE *tokenStream; fprintf(tokenStream, "%s ", yytext); 
    return IDENTIFIER;
}
<INITIAL>"#"([0-9]|[a-z]|[A-Z]|"_")([0-9]|[a-z]|[A-Z]|"_")*	{
    yylval.type = (char*)malloc(strlen(yytext) + 1);
    sscanf(yytext, "%s", yylval.type);
	extern FILE *tokenStream; fprintf(tokenStream, "%s ", yytext); 
    return CLASS_IDENTIFIER;
}
%%