
/*  A Bison parser, made from oa.y
    by GNU Bison version 1.28  */

#define YYBISON 1  /* Identify Bison output.  */

#define	BOOLEAN	257
#define	BREAK	258
#define	CHAR	259
#define	CLASS	260
#define	CONTINUE	261
#define	DOUBLE	262
#define	ELIF	263
#define	ELSE	264
#define	EXTENDS	265
#define	FALSE	266
#define	FOR	267
#define	FOREACH	268
#define	IF	269
#define	IMPORT	270
#define	IN	271
#define	INT	272
#define	MY_NULL	273
#define	RETURN	274
#define	THIS	275
#define	TRUE	276
#define	VOID	277
#define	WHILE	278
#define	PART_LETTER	279
#define	DECIMAL_LITERAL	280
#define	DECIMAL_FLOATING_POINT_LITERAL	281
#define	TYPE_CHAR	282
#define	STRING	283
#define	LPAREN	284
#define	RPAREN	285
#define	LBRACE	286
#define	RBRACE	287
#define	LBRACKET	288
#define	RBRACKET	289
#define	SEMICOLON	290
#define	COMMA	291
#define	DOT	292
#define	ASSIGN	293
#define	LT	294
#define	GT	295
#define	BANG	296
#define	TILDE	297
#define	EQ	298
#define	LE	299
#define	GE	300
#define	NE	301
#define	SC_OR	302
#define	SC_AND	303
#define	PLUS	304
#define	MINUS	305
#define	STAR	306
#define	SLASH	307
#define	BIT_AND	308
#define	BIT_OR	309
#define	XOR	310
#define	REM	311
#define	NAME_SPACE	312
#define	CLASS_IDENTIFIER	313
#define	IDENTIFIER	314
#define	CHAR_LITERAL	315

#line 1 "oa.y"

#include <stdio.h>
#include <stdlib.h>
#include "oa.h"
#define YYDEBUG 1

#line 9 "oa.y"
typedef union {
	int				number_int;
	double			number_double;
	char			type_char;
	char			*type;
	char			*name;
	struct TreeNode	*node;
	struct Expression *expression;
	struct FormParam *formParam;
	struct LeftValue *leftValue;
	struct FactParam *factParam;
} YYSTYPE;
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		269
#define	YYFLAG		-32768
#define	YYNTBASE	62

#define YYTRANSLATE(x) ((unsigned)(x) <= 315 ? yytranslate[x] : 102)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
    47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
    57,    58,    59,    60,    61
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     1,     4,     7,    10,    13,    16,    19,    22,    24,
    26,    28,    30,    33,    35,    37,    40,    43,    46,    48,
    49,    52,    55,    58,    61,    64,    67,    70,    72,    74,
    76,    79,    82,    85,    87,    88,    91,    94,    97,   100,
   103,   106,   108,   110,   113,   118,   122,   129,   131,   134,
   142,   149,   159,   160,   163,   171,   172,   177,   185,   195,
   201,   209,   215,   221,   227,   236,   245,   254,   265,   276,
   287,   289,   291,   294,   296,   297,   300,   301,   305,   308,
   311,   315,   319,   322,   324,   328,   332,   336,   340,   344,
   348,   350,   354,   358,   360,   364,   368,   370,   372,   374,
   376,   378,   383,   388,   392,   395,   396,   400,   401,   404,
   405,   409,   411,   415,   417,   419,   421
};

static const short yyrhs[] = {    -1,
    63,    62,     0,    68,    36,     0,    69,    36,     0,    70,
    36,     0,    71,    36,     0,    72,    36,     0,    73,    36,
     0,    74,     0,    78,     0,    79,     0,    80,     0,    81,
    36,     0,    82,     0,    83,     0,    84,    36,     0,    85,
    36,     0,    86,    36,     0,    36,     0,     0,    65,    64,
     0,    68,    36,     0,    69,    36,     0,    70,    36,     0,
    71,    36,     0,    72,    36,     0,    73,    36,     0,    74,
     0,    78,     0,    79,     0,    84,    36,     0,    85,    36,
     0,    86,    36,     0,    36,     0,     0,    67,    66,     0,
    68,    36,     0,    69,    36,     0,    71,    36,     0,    72,
    36,     0,    81,    36,     0,    82,     0,    36,     0,   101,
    60,     0,   101,    60,    39,    90,     0,    95,    39,    90,
     0,    95,    34,    90,    35,    39,    90,     0,    90,     0,
   100,    60,     0,   100,    60,    39,   101,    34,    90,    35,
     0,    95,    39,   101,    34,    90,    35,     0,    15,    30,
    90,    31,    32,    64,    33,    75,    77,     0,     0,    76,
    75,     0,     9,    30,    90,    31,    32,    64,    33,     0,
     0,    10,    32,    64,    33,     0,    24,    30,    90,    31,
    32,    64,    33,     0,    14,    30,    60,    17,    60,    31,
    32,    64,    33,     0,     6,    59,    32,    66,    33,     0,
     6,    59,    11,    59,    32,    66,    33,     0,   101,    60,
    30,    87,    31,     0,   100,    60,    30,    87,    31,     0,
    23,    60,    30,    87,    31,     0,   101,    60,    30,    87,
    31,    32,    64,    33,     0,   100,    60,    30,    87,    31,
    32,    64,    33,     0,    23,    60,    30,    87,    31,    32,
    64,    33,     0,   101,    59,    58,    60,    30,    87,    31,
    32,    64,    33,     0,   100,    59,    58,    60,    30,    87,
    31,    32,    64,    33,     0,    23,    59,    58,    60,    30,
    87,    31,    32,    64,    33,     0,     4,     0,     7,     0,
    20,    90,     0,    20,     0,     0,    89,    88,     0,     0,
    37,    89,    88,     0,   101,    60,     0,   100,    60,     0,
    91,    49,    90,     0,    91,    48,    90,     0,    42,    90,
     0,    91,     0,    92,    44,    92,     0,    92,    47,    92,
     0,    92,    41,    92,     0,    92,    46,    92,     0,    92,
    40,    92,     0,    92,    45,    92,     0,    92,     0,    93,
    50,    92,     0,    93,    51,    92,     0,    93,     0,    94,
    52,    93,     0,    94,    53,    93,     0,    94,     0,    26,
     0,    27,     0,    61,     0,    95,     0,    95,    34,    90,
    35,     0,    95,    30,    97,    31,     0,    30,    90,    31,
     0,    60,    96,     0,     0,    38,    60,    96,     0,     0,
    99,    98,     0,     0,    37,    99,    98,     0,    90,     0,
   101,    34,    35,     0,    18,     0,     8,     0,     5,     0,
    59,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    50,    53,    66,    67,    68,    69,    70,    71,    72,    73,
    74,    75,    76,    77,    78,    79,    80,    81,    82,   103,
   106,   116,   117,   118,   119,   120,   121,   122,   123,   124,
   125,   126,   127,   128,   134,   137,   147,   148,   149,   150,
   151,   152,   153,   160,   166,   172,   175,   178,   185,   191,
   197,   205,   211,   214,   220,   226,   229,   236,   242,   249,
   252,   260,   263,   266,   272,   275,   278,   284,   287,   290,
   297,   303,   310,   313,   320,   323,   330,   333,   340,   343,
   351,   354,   357,   360,   364,   367,   370,   373,   376,   379,
   382,   386,   389,   392,   396,   399,   402,   406,   409,   412,
   415,   418,   421,   424,   430,   437,   440,   447,   450,   457,
   460,   467,   476,   482,   483,   484,   485
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","BOOLEAN",
"BREAK","CHAR","CLASS","CONTINUE","DOUBLE","ELIF","ELSE","EXTENDS","FALSE","FOR",
"FOREACH","IF","IMPORT","IN","INT","MY_NULL","RETURN","THIS","TRUE","VOID","WHILE",
"PART_LETTER","DECIMAL_LITERAL","DECIMAL_FLOATING_POINT_LITERAL","TYPE_CHAR",
"STRING","LPAREN","RPAREN","LBRACE","RBRACE","LBRACKET","RBRACKET","SEMICOLON",
"COMMA","DOT","ASSIGN","LT","GT","BANG","TILDE","EQ","LE","GE","NE","SC_OR",
"SC_AND","PLUS","MINUS","STAR","SLASH","BIT_AND","BIT_OR","XOR","REM","NAME_SPACE",
"CLASS_IDENTIFIER","IDENTIFIER","CHAR_LITERAL","outerStatements","outerStatement",
"functionStatements","functionStatement","classStatements","classStatement",
"varDeclareStatement","varDefineStatement","varAssignStatement","arrayDeclareStatement",
"arrayDefineStatement","arrayAssignStatement","ifStatement","elifParts","elifPart",
"elsePart","whileStatement","foreachStatement","classDefineStatement","functionDeclareStatement",
"functionDefineStatement","classMethodDefineStatement","breakStatement","continueStatement",
"returnStatement","formParams","formParamSet","formParam","expression","compareExpression",
"mathExpression","term","factor","leftValue","leftValueSet","factParams","factParamSet",
"factParam","arrayType","type", NULL
};
#endif

static const short yyr1[] = {     0,
    62,    62,    63,    63,    63,    63,    63,    63,    63,    63,
    63,    63,    63,    63,    63,    63,    63,    63,    63,    64,
    64,    65,    65,    65,    65,    65,    65,    65,    65,    65,
    65,    65,    65,    65,    66,    66,    67,    67,    67,    67,
    67,    67,    67,    68,    69,    70,    70,    70,    71,    72,
    73,    74,    75,    75,    76,    77,    77,    78,    79,    80,
    80,    81,    81,    81,    82,    82,    82,    83,    83,    83,
    84,    85,    86,    86,    87,    87,    88,    88,    89,    89,
    90,    90,    90,    90,    91,    91,    91,    91,    91,    91,
    91,    92,    92,    92,    93,    93,    93,    94,    94,    94,
    94,    94,    94,    94,    95,    96,    96,    97,    97,    98,
    98,    99,   100,   101,   101,   101,   101
};

static const short yyr2[] = {     0,
     0,     2,     2,     2,     2,     2,     2,     2,     1,     1,
     1,     1,     2,     1,     1,     2,     2,     2,     1,     0,
     2,     2,     2,     2,     2,     2,     2,     1,     1,     1,
     2,     2,     2,     1,     0,     2,     2,     2,     2,     2,
     2,     1,     1,     2,     4,     3,     6,     1,     2,     7,
     6,     9,     0,     2,     7,     0,     4,     7,     9,     5,
     7,     5,     5,     5,     8,     8,     8,    10,    10,    10,
     1,     1,     2,     1,     0,     2,     0,     3,     2,     2,
     3,     3,     2,     1,     3,     3,     3,     3,     3,     3,
     1,     3,     3,     1,     3,     3,     1,     1,     1,     1,
     1,     4,     4,     3,     2,     0,     3,     0,     2,     0,
     3,     1,     3,     1,     1,     1,     1
};

static const short yydefact[] = {     1,
    71,   116,     0,    72,   115,     0,     0,   114,    74,     0,
     0,    98,    99,     0,    19,     0,   117,   106,   100,     1,
     0,     0,     0,     0,     0,     0,     9,    10,    11,    12,
     0,    14,    15,     0,     0,     0,    48,    84,    91,    94,
    97,   101,     0,     0,     0,     0,     0,    73,   101,     0,
     0,     0,     0,    83,     0,   105,     2,     3,     4,     5,
     6,     7,     8,    13,    16,    17,    18,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,   108,
     0,     0,     0,    49,     0,     0,    44,     0,    35,     0,
     0,     0,     0,    75,     0,   104,   106,    82,    81,    89,
    87,    85,    90,    88,    86,    92,    93,    95,    96,   112,
     0,   110,     0,    46,     0,     0,    75,     0,   113,     0,
    75,     0,     0,     0,    43,     0,    35,     0,     0,     0,
     0,     0,    42,     0,     0,     0,     0,     0,     0,     0,
    77,     0,     0,     0,   107,   103,     0,   109,   102,     0,
     0,     0,     0,     0,     0,    45,    35,    60,    36,    37,
    38,    39,    40,    41,     0,    20,   102,    75,    64,     0,
    76,    80,    79,    20,   110,     0,     0,    75,    63,     0,
    75,    62,     0,     0,    34,     0,    20,     0,     0,     0,
     0,     0,     0,    28,    29,    30,     0,     0,     0,     0,
     0,     0,    20,    77,     0,   111,    47,    51,     0,    20,
     0,     0,    20,    61,    20,    53,    21,    22,    23,    24,
    25,    26,    27,    31,    32,    33,    49,    44,     0,     0,
    78,    58,     0,     0,    50,     0,     0,     0,     0,    56,
    53,    20,    67,    20,    66,    20,    65,    59,     0,     0,
    52,    54,     0,     0,     0,     0,    20,    70,    69,    68,
     0,     0,    20,    57,     0,    55,     0,     0,     0
};

static const short yydefgoto[] = {    57,
    20,   186,   187,   126,   127,   188,   189,   190,   191,   192,
   193,   194,   240,   241,   251,   195,   196,    30,   132,   133,
    33,   197,   198,   199,   140,   171,   141,    37,    38,    39,
    40,    41,    49,    56,   111,   148,   112,   200,   201
};

static const short yypact[] = {   194,
-32768,-32768,   -50,-32768,-32768,   -18,    -4,-32768,    51,    46,
    23,-32768,-32768,    51,-32768,    51,-32768,   -10,-32768,   194,
     4,    86,    92,   102,   125,   127,-32768,-32768,-32768,-32768,
   129,-32768,-32768,   133,   141,   143,-32768,    77,   149,    85,
    94,   111,    89,     9,    35,    -9,    51,-32768,    22,    29,
   152,    51,    88,-32768,    56,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,    51,    51,    83,
    83,    83,    83,    83,    83,    83,    83,    83,    83,    51,
    51,   264,    75,    25,   148,   128,    78,   126,     6,   175,
   166,    51,   144,    30,   174,-32768,   -10,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
   176,   169,   181,-32768,   177,   159,    30,    30,-32768,   162,
    30,    51,   191,   165,-32768,   193,     6,   192,   195,   196,
   197,   198,-32768,   167,    -2,   178,   203,   202,   199,   208,
   206,   180,    11,   213,-32768,-32768,    51,-32768,   211,    51,
   217,   225,   226,   231,   234,-32768,     6,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,   235,   244,-32768,    30,   241,    30,
-32768,-32768,-32768,   244,   169,    51,   232,    30,   243,    51,
    30,   245,   246,   249,-32768,   250,   244,   240,   242,   248,
   251,   252,   253,-32768,-32768,-32768,   256,   257,   259,   236,
    15,   254,   244,   206,   265,-32768,-32768,-32768,   266,   244,
   267,   268,   244,-32768,   244,   291,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,   262,   269,   275,   276,
-32768,-32768,   278,   279,-32768,   281,   282,   283,   284,   301,
   291,   244,-32768,   244,-32768,   244,-32768,-32768,    51,   285,
-32768,-32768,   286,   287,   288,   295,   244,-32768,-32768,-32768,
   290,   294,   244,-32768,   296,-32768,   318,   328,-32768
};

static const short yypgoto[] = {   330,
-32768,  -156,-32768,  -123,-32768,     2,     5,    16,     7,    13,
    17,    21,    90,-32768,-32768,    50,    62,-32768,    63,    80,
-32768,    95,    98,   103,  -102,   130,   163,    -8,-32768,    81,
    97,-32768,     0,   238,-32768,   157,   189,    10,     3
};


#define	YYLAST		336


static const short yytable[] = {    42,
    48,    21,    44,   159,    22,    53,    24,    54,    45,    43,
     2,    46,    25,     5,   152,    23,    26,   205,   155,    42,
    27,    21,    44,     8,    22,    47,    24,    55,   124,    43,
   217,    85,    25,   183,     2,    23,    26,     5,    91,    58,
    27,   125,    85,    95,    85,    88,   230,     8,    85,    28,
    90,    80,    52,   234,   117,    92,   237,    87,   238,    98,
    99,    29,    31,   118,    17,   202,    89,    86,    87,    28,
   173,   110,   113,   114,   228,   209,    12,    13,   212,    32,
    14,    29,    31,   138,   115,   253,    93,   254,    17,   255,
   128,   135,    16,   129,    34,   130,   143,    35,   134,    32,
   262,   131,    36,   142,    50,    51,   265,   121,    12,    13,
    18,    19,    14,   156,    34,    97,   122,    35,    96,   143,
   153,    59,    36,   143,    68,    69,   142,    60,   128,   135,
   142,   129,   116,   130,    76,    77,   134,    61,   110,   131,
    80,   177,    18,    19,    81,    78,    79,    83,    84,    82,
   100,   101,   102,   103,   104,   105,   106,   107,   128,   135,
    62,   129,    63,   130,    64,    42,   134,   207,    65,   131,
   143,   211,   143,    42,   108,   109,    66,   142,    67,   142,
   143,    94,   119,   143,   123,   120,    42,   142,    70,    71,
   142,   136,    72,    73,    74,    75,   137,     1,     2,     3,
     4,     5,    42,   139,   144,   147,   146,     6,     7,    42,
   150,     8,    42,     9,    42,   149,    10,    11,   151,    12,
    13,   154,   157,    14,    51,   158,    84,   160,   168,    15,
   161,   162,   163,   164,   166,    16,   167,   165,   169,   172,
   256,    42,   170,    42,   174,    42,   178,     1,     2,   176,
     4,     5,    17,    18,    19,   179,    42,     6,     7,   180,
   181,     8,    42,     9,   182,   184,   208,    11,     2,    12,
    13,     5,   203,    14,   210,   218,   213,   219,   214,   185,
   215,     8,   216,   220,   229,    16,   221,   222,   223,    12,
    13,   224,   225,    14,   226,   227,   233,   232,   236,   239,
   118,   235,    17,    18,    19,    16,   242,   122,   243,   244,
   250,   245,   246,   249,   247,   248,   257,   268,   258,   259,
   260,   263,    17,    18,    19,   261,   264,   269,   266,   267,
   252,   206,   204,   231,   145,   175
};

static const short yycheck[] = {     0,
     9,     0,     0,   127,     0,    14,     0,    16,    59,     0,
     5,    30,     0,     8,   117,     0,     0,   174,   121,    20,
     0,    20,    20,    18,    20,    30,    20,    38,    23,    20,
   187,    34,    20,   157,     5,    20,    20,     8,    47,    36,
    20,    36,    34,    52,    34,    11,   203,    18,    34,     0,
    60,    30,    30,   210,    30,    34,   213,    60,   215,    68,
    69,     0,     0,    39,    59,   168,    32,    59,    60,    20,
    60,    80,    81,    82,    60,   178,    26,    27,   181,     0,
    30,    20,    20,    92,    82,   242,    58,   244,    59,   246,
    89,    89,    42,    89,     0,    89,    94,     0,    89,    20,
   257,    89,     0,    94,    59,    60,   263,    30,    26,    27,
    60,    61,    30,   122,    20,    60,    39,    20,    31,   117,
   118,    36,    20,   121,    48,    49,   117,    36,   127,   127,
   121,   127,    58,   127,    50,    51,   127,    36,   147,   127,
    30,   150,    60,    61,    34,    52,    53,    59,    60,    39,
    70,    71,    72,    73,    74,    75,    76,    77,   157,   157,
    36,   157,    36,   157,    36,   166,   157,   176,    36,   157,
   168,   180,   170,   174,    78,    79,    36,   168,    36,   170,
   178,    30,    35,   181,    59,    58,   187,   178,    40,    41,
   181,    17,    44,    45,    46,    47,    31,     4,     5,     6,
     7,     8,   203,    60,    31,    37,    31,    14,    15,   210,
    34,    18,   213,    20,   215,    35,    23,    24,    60,    26,
    27,    60,    32,    30,    60,    33,    60,    36,    30,    36,
    36,    36,    36,    36,    32,    42,    35,    60,    31,    60,
   249,   242,    37,   244,    32,   246,    30,     4,     5,    39,
     7,     8,    59,    60,    61,    31,   257,    14,    15,    34,
    30,    18,   263,    20,    31,    31,    35,    24,     5,    26,
    27,     8,    32,    30,    32,    36,    32,    36,    33,    36,
    32,    18,    33,    36,    31,    42,    36,    36,    36,    26,
    27,    36,    36,    30,    36,    60,    31,    33,    31,     9,
    39,    35,    59,    60,    61,    42,    32,    39,    33,    32,
    10,    33,    32,    30,    33,    33,    32,     0,    33,    33,
    33,    32,    59,    60,    61,    31,    33,     0,    33,     0,
   241,   175,   170,   204,    97,   147
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/usr/local/share/bison.simple"
/* This file comes from bison-1.28.  */

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

#ifndef YYSTACK_USE_ALLOCA
#ifdef alloca
#define YYSTACK_USE_ALLOCA
#else /* alloca not defined */
#ifdef __GNUC__
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi) || (defined (__sun) && defined (__i386))
#define YYSTACK_USE_ALLOCA
#include <alloca.h>
#else /* not sparc */
/* We think this test detects Watcom and Microsoft C.  */
/* This used to test MSDOS, but that is a bad idea
   since that symbol is in the user namespace.  */
#if (defined (_MSDOS) || defined (_MSDOS_)) && !defined (__TURBOC__)
#if 0 /* No need for malloc.h, which pollutes the namespace;
	 instead, just don't use alloca.  */
#include <malloc.h>
#endif
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
/* I don't know what this was needed for, but it pollutes the namespace.
   So I turned it off.   rms, 2 May 1997.  */
/* #include <malloc.h>  */
 #pragma alloca
#define YYSTACK_USE_ALLOCA
#else /* not MSDOS, or __TURBOC__, or _AIX */
#if 0
#ifdef __hpux /* haible@ilog.fr says this works for HPUX 9.05 and up,
		 and on HPUX 10.  Eventually we can turn this on.  */
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#endif /* __hpux */
#endif
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc */
#endif /* not GNU C */
#endif /* alloca not defined */
#endif /* YYSTACK_USE_ALLOCA not defined */

#ifdef YYSTACK_USE_ALLOCA
#define YYSTACK_ALLOC alloca
#else
#define YYSTACK_ALLOC malloc
#endif

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Define __yy_memcpy.  Note that the size argument
   should be passed with type unsigned int, because that is what the non-GCC
   definitions require.  With GCC, __builtin_memcpy takes an arg
   of type size_t, but it can handle unsigned int.  */

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     unsigned int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *to, char *from, unsigned int count)
{
  register char *t = to;
  register char *f = from;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 217 "/usr/local/share/bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
#ifdef YYPARSE_PARAM
int yyparse (void *);
#else
int yyparse (void);
#endif
#endif

int
yyparse(YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;
  int yyfree_stacks = 0;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  if (yyfree_stacks)
	    {
	      free (yyss);
	      free (yyvs);
#ifdef YYLSP_NEEDED
	      free (yyls);
#endif
	    }
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
#ifndef YYSTACK_USE_ALLOCA
      yyfree_stacks = 1;
#endif
      yyss = (short *) YYSTACK_ALLOC (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1,
		   size * (unsigned int) sizeof (*yyssp));
      yyvs = (YYSTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1,
		   size * (unsigned int) sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1,
		   size * (unsigned int) sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 50 "oa.y"
{
		yyval.node = NULL;
	;
    break;}
case 2:
#line 53 "oa.y"
{
		if(yyvsp[-1].node){
			yyvsp[-1].node->next = yyvsp[0].node;
      extern struct ParseTree *parseTree;
			parseTree->root = yyvsp[-1].node;
		}else{
			yyval.node = yyvsp[0].node;
		}
	;
    break;}
case 19:
#line 82 "oa.y"
{
		yyval.node = NULL;
	;
    break;}
case 20:
#line 103 "oa.y"
{
		yyval.node = NULL;
	;
    break;}
case 21:
#line 106 "oa.y"
{
		if(yyvsp[-1].node){
			yyvsp[-1].node->next = yyvsp[0].node;
		}else{
			yyval.node = yyvsp[0].node;
		}
	;
    break;}
case 34:
#line 128 "oa.y"
{
		yyval.node = NULL;
	;
    break;}
case 35:
#line 134 "oa.y"
{
		yyval.node = NULL;
	;
    break;}
case 36:
#line 137 "oa.y"
{
		if(yyvsp[-1].node){
			yyvsp[-1].node->next = yyvsp[0].node;
		}else{
			yyval.node = yyvsp[0].node;
		}
	;
    break;}
case 43:
#line 153 "oa.y"
{
		yyval.node = NULL;
	;
    break;}
case 44:
#line 160 "oa.y"
{
		yyval.node = createVarDeclare(yyvsp[-1].type, yyvsp[0].name);
	;
    break;}
case 45:
#line 166 "oa.y"
{
		yyval.node = createVarDefine(yyvsp[-3].type, yyvsp[-2].name, yyvsp[0].expression);
	;
    break;}
case 46:
#line 172 "oa.y"
{
		yyval.node = createVarAssign(yyvsp[-2].leftValue, yyvsp[0].expression, NULL);
	;
    break;}
case 47:
#line 175 "oa.y"
{
		yyval.node = createVarAssign(yyvsp[-5].leftValue, yyvsp[0].expression, yyvsp[-3].expression);
	;
    break;}
case 48:
#line 178 "oa.y"
{
		yyval.node = createVarAssign(NULL, yyvsp[0].expression, NULL);
	;
    break;}
case 49:
#line 185 "oa.y"
{
		yyval.node = createArrayDeclare(yyvsp[-1].type, yyvsp[0].name);
	;
    break;}
case 50:
#line 191 "oa.y"
{
		yyval.node = createArrayDefine(yyvsp[-6].type, yyvsp[-5].name, yyvsp[-3].type, yyvsp[-1].expression);
	;
    break;}
case 51:
#line 197 "oa.y"
{
		yyval.node = createArrayAssign(yyvsp[-5].leftValue, yyvsp[-3].type, yyvsp[-1].expression);
	;
    break;}
case 52:
#line 205 "oa.y"
{
		yyval.node = createIf(yyvsp[-6].expression, yyvsp[-3].node, yyvsp[-1].node, yyvsp[0].node);
	;
    break;}
case 53:
#line 211 "oa.y"
{
		yyval.node = NULL;
	;
    break;}
case 54:
#line 214 "oa.y"
{
		yyval.node->next = yyvsp[-1].node;
	;
    break;}
case 55:
#line 220 "oa.y"
{
		yyval.node = createElifPart(yyvsp[-4].expression, yyvsp[-1].node);
	;
    break;}
case 56:
#line 226 "oa.y"
{
		yyval.node = NULL;
	;
    break;}
case 57:
#line 229 "oa.y"
{
		yyval.node = createElsePart(yyvsp[-1].node);
	;
    break;}
case 58:
#line 236 "oa.y"
{
		yyval.node = createWhile(yyvsp[-4].expression, yyvsp[-1].node);
	;
    break;}
case 59:
#line 242 "oa.y"
{
		yyval.node = createForeach(yyvsp[-6].name, yyvsp[-4].name, yyvsp[-1].node);
	;
    break;}
case 60:
#line 249 "oa.y"
{
		yyval.node = createClassDefine(yyvsp[-3].type, NULL, yyvsp[-1].node);
	;
    break;}
case 61:
#line 252 "oa.y"
{
		yyval.node = createClassDefine(yyvsp[-5].type, yyvsp[-3].type, yyvsp[-1].node);
	;
    break;}
case 62:
#line 260 "oa.y"
{
		yyval.node = createFunctionDeclare(yyvsp[-4].type, yyvsp[-3].name, yyvsp[-1].formParam);
	;
    break;}
case 63:
#line 263 "oa.y"
{
		yyval.node = createFunctionDeclare(yyvsp[-4].type, yyvsp[-3].name, yyvsp[-1].formParam);
	;
    break;}
case 64:
#line 266 "oa.y"
{
		yyval.node = createFunctionDeclare(NULL, yyvsp[-3].name, yyvsp[-1].formParam);
	;
    break;}
case 65:
#line 272 "oa.y"
{
		yyval.node = createFunctionDefine(yyvsp[-7].type, yyvsp[-6].name, yyvsp[-4].formParam, yyvsp[-1].node);
	;
    break;}
case 66:
#line 275 "oa.y"
{
		yyval.node = createFunctionDefine(yyvsp[-7].type, yyvsp[-6].name, yyvsp[-4].formParam, yyvsp[-1].node);
	;
    break;}
case 67:
#line 278 "oa.y"
{
		yyval.node = createFunctionDefine(NULL, yyvsp[-6].name, yyvsp[-4].formParam, yyvsp[-1].node);
	;
    break;}
case 68:
#line 284 "oa.y"
{
		yyval.node = createClassMethodDefine(yyvsp[-9].type, yyvsp[-6].name, yyvsp[-4].formParam, yyvsp[-1].node, yyvsp[-8].type);
	;
    break;}
case 69:
#line 287 "oa.y"
{
		yyval.node = createClassMethodDefine(yyvsp[-9].type, yyvsp[-6].name, yyvsp[-4].formParam, yyvsp[-1].node, yyvsp[-8].type);
	;
    break;}
case 70:
#line 290 "oa.y"
{
		yyval.node = createClassMethodDefine(NULL, yyvsp[-6].name, yyvsp[-4].formParam, yyvsp[-1].node, yyvsp[-8].type);
	;
    break;}
case 71:
#line 297 "oa.y"
{
		yyval.node = createBreak();
	;
    break;}
case 72:
#line 303 "oa.y"
{
		yyval.node = createContinue();
	;
    break;}
case 73:
#line 310 "oa.y"
{
		yyval.node = createReturn(yyvsp[0].expression);
	;
    break;}
case 74:
#line 313 "oa.y"
{
		yyval.node = createReturn(NULL);
	;
    break;}
case 75:
#line 320 "oa.y"
{
		yyval.formParam = NULL;
	;
    break;}
case 76:
#line 323 "oa.y"
{
		yyvsp[-1].formParam->next = yyvsp[0].formParam;
		yyval.formParam = yyvsp[-1].formParam;
	;
    break;}
case 77:
#line 330 "oa.y"
{
		yyval.formParam = NULL;
	;
    break;}
case 78:
#line 333 "oa.y"
{
		yyvsp[-1].formParam->next = yyvsp[0].formParam;
		yyval.formParam = yyvsp[-1].formParam;
	;
    break;}
case 79:
#line 340 "oa.y"
{
		yyval.formParam = createFormParam(yyvsp[-1].type, yyvsp[0].name);
	;
    break;}
case 80:
#line 343 "oa.y"
{
		yyval.formParam = createFormParam(yyvsp[-1].type, yyvsp[0].name);
	;
    break;}
case 81:
#line 351 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_AND);
	;
    break;}
case 82:
#line 354 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_OR);
	;
    break;}
case 83:
#line 357 "oa.y"
{
		yyval.expression = createExpression(yyvsp[0].expression, NULL, OA_EXP_NOT);
	;
    break;}
case 85:
#line 364 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_EQ);
	;
    break;}
case 86:
#line 367 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_NE);
	;
    break;}
case 87:
#line 370 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_GT);
	;
    break;}
case 88:
#line 373 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_GE);
	;
    break;}
case 89:
#line 376 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_LT);
	;
    break;}
case 90:
#line 379 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_LE);
	;
    break;}
case 92:
#line 386 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_PLUS);
	;
    break;}
case 93:
#line 389 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_MINUS);
	;
    break;}
case 95:
#line 396 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_MULTIPLE);
	;
    break;}
case 96:
#line 399 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_DIVIDE);
	;
    break;}
case 98:
#line 406 "oa.y"
{
		yyval.expression = createExpressionIntLeaf(yyvsp[0].number_int);
	;
    break;}
case 99:
#line 409 "oa.y"
{
		yyval.expression = createExpressionDoubleLeaf(yyvsp[0].number_double);
	;
    break;}
case 100:
#line 412 "oa.y"
{
		yyval.expression = createExpressionCharLeaf(yyvsp[0].type_char);
	;
    break;}
case 101:
#line 415 "oa.y"
{
		yyval.expression = createExpressionLeftValueLeaf(yyvsp[0].leftValue);
	;
    break;}
case 102:
#line 418 "oa.y"
{
		yyval.expression = createExpressionArrayValue(yyvsp[-3].leftValue, yyvsp[-1].expression);
	;
    break;}
case 103:
#line 421 "oa.y"
{
		yyval.expression = createExpressionFunctionValue(yyvsp[-3].leftValue, yyvsp[-1].factParam);
	;
    break;}
case 104:
#line 424 "oa.y"
{
		yyval.expression = yyvsp[-1].expression;
	;
    break;}
case 105:
#line 430 "oa.y"
{
		yyval.leftValue = createLeftValue(yyvsp[-1].name);
		yyval.leftValue->next = yyvsp[0].leftValue;
	;
    break;}
case 106:
#line 437 "oa.y"
{
		yyval.leftValue = NULL;
	;
    break;}
case 107:
#line 440 "oa.y"
{
		yyval.leftValue = createLeftValue(yyvsp[-1].name);
		yyval.leftValue->next = yyvsp[0].leftValue;
	;
    break;}
case 108:
#line 447 "oa.y"
{
		yyval.factParam = NULL;
	;
    break;}
case 109:
#line 450 "oa.y"
{
		yyvsp[-1].factParam->next = yyvsp[0].factParam;
		yyval.factParam = yyvsp[-1].factParam;
	;
    break;}
case 110:
#line 457 "oa.y"
{
		yyval.factParam = NULL;
	;
    break;}
case 111:
#line 460 "oa.y"
{
		yyvsp[-1].factParam->next = yyvsp[0].factParam;
		yyval.factParam = yyvsp[-1].factParam;
	;
    break;}
case 112:
#line 467 "oa.y"
{
		yyval.factParam = createFactParam(yyvsp[0].expression);
	;
    break;}
case 113:
#line 476 "oa.y"
{
		yyval.type = createArrayType(yyvsp[-2].type);
	;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 543 "/usr/local/share/bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;

 yyacceptlab:
  /* YYACCEPT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 0;

 yyabortlab:
  /* YYABORT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 1;
}
#line 489 "oa.y"

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