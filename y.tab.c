
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
#define	STRING_LITERAL	314
#define	IDENTIFIER	315
#define	CHAR_LITERAL	316

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
	char			*type_string;
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



#define	YYFINAL		268
#define	YYFLAG		-32768
#define	YYNTBASE	63

#define YYTRANSLATE(x) ((unsigned)(x) <= 316 ? yytranslate[x] : 103)

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
    57,    58,    59,    60,    61,    62
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     1,     4,     7,    10,    12,    15,    17,    19,    22,
    24,    25,    28,    31,    34,    37,    40,    43,    46,    48,
    50,    52,    55,    58,    61,    63,    64,    67,    70,    73,
    76,    78,    81,    86,    90,    97,    99,   102,   110,   117,
   121,   131,   132,   135,   143,   144,   149,   157,   167,   173,
   181,   187,   193,   199,   208,   217,   226,   237,   248,   259,
   261,   263,   266,   268,   269,   272,   273,   277,   280,   283,
   287,   291,   294,   296,   300,   304,   308,   312,   316,   320,
   324,   328,   330,   334,   338,   340,   344,   348,   350,   352,
   354,   356,   358,   360,   365,   370,   374,   377,   380,   383,
   384,   388,   389,   392,   393,   397,   399,   403,   405,   407,
   409
};

static const short yyrhs[] = {    -1,
    64,    63,     0,    69,    36,     0,    72,    36,     0,    81,
     0,    82,    36,     0,    83,     0,    84,     0,    87,    36,
     0,    36,     0,     0,    66,    65,     0,    69,    36,     0,
    70,    36,     0,    71,    36,     0,    72,    36,     0,    73,
    36,     0,    74,    36,     0,    75,     0,    79,     0,    80,
     0,    85,    36,     0,    86,    36,     0,    87,    36,     0,
    36,     0,     0,    68,    67,     0,    69,    36,     0,    72,
    36,     0,    82,    36,     0,    36,     0,   102,    61,     0,
   102,    61,    39,    91,     0,    96,    39,    91,     0,    96,
    34,    91,    35,    39,    91,     0,    91,     0,   101,    61,
     0,   101,    61,    39,   102,    34,    91,    35,     0,    96,
    39,   102,    34,    91,    35,     0,    96,    39,    19,     0,
    15,    30,    91,    31,    32,    65,    33,    76,    78,     0,
     0,    77,    76,     0,     9,    30,    91,    31,    32,    65,
    33,     0,     0,    10,    32,    65,    33,     0,    24,    30,
    91,    31,    32,    65,    33,     0,    14,    30,    61,    17,
    96,    31,    32,    65,    33,     0,     6,    59,    32,    67,
    33,     0,     6,    59,    11,    59,    32,    67,    33,     0,
   102,    61,    30,    88,    31,     0,   101,    61,    30,    88,
    31,     0,    23,    61,    30,    88,    31,     0,   102,    61,
    30,    88,    31,    32,    65,    33,     0,   101,    61,    30,
    88,    31,    32,    65,    33,     0,    23,    61,    30,    88,
    31,    32,    65,    33,     0,   102,    59,    58,    61,    30,
    88,    31,    32,    65,    33,     0,   101,    59,    58,    61,
    30,    88,    31,    32,    65,    33,     0,    23,    59,    58,
    61,    30,    88,    31,    32,    65,    33,     0,     4,     0,
     7,     0,    20,    91,     0,    20,     0,     0,    90,    89,
     0,     0,    37,    90,    89,     0,   102,    61,     0,   101,
    61,     0,    92,    49,    91,     0,    92,    48,    91,     0,
    42,    91,     0,    92,     0,    93,    44,    93,     0,    93,
    44,    19,     0,    93,    47,    93,     0,    93,    47,    19,
     0,    93,    41,    93,     0,    93,    46,    93,     0,    93,
    40,    93,     0,    93,    45,    93,     0,    93,     0,    94,
    50,    93,     0,    94,    51,    93,     0,    94,     0,    95,
    52,    94,     0,    95,    53,    94,     0,    95,     0,    26,
     0,    27,     0,    62,     0,    60,     0,    96,     0,    96,
    34,    91,    35,     0,    96,    30,    98,    31,     0,    30,
    91,    31,     0,    51,    26,     0,    51,    27,     0,    61,
    97,     0,     0,    38,    61,    97,     0,     0,   100,    99,
     0,     0,    37,   100,    99,     0,    91,     0,   102,    34,
    35,     0,    18,     0,     8,     0,     5,     0,    59,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    52,    55,    69,    70,    71,    72,    73,    74,    75,    76,
    82,    85,    95,    96,    97,    98,    99,   100,   101,   102,
   103,   104,   105,   106,   107,   113,   116,   126,   127,   128,
   129,   136,   142,   148,   151,   154,   161,   167,   173,   176,
   184,   190,   193,   200,   206,   209,   216,   222,   229,   232,
   240,   243,   246,   252,   255,   258,   264,   267,   270,   277,
   283,   290,   293,   300,   303,   310,   313,   320,   323,   331,
   334,   337,   340,   344,   347,   350,   353,   356,   359,   362,
   365,   368,   372,   375,   378,   382,   385,   388,   392,   395,
   398,   401,   404,   407,   410,   413,   416,   419,   425,   432,
   435,   442,   445,   452,   455,   462,   471,   477,   478,   479,
   480
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
"CLASS_IDENTIFIER","STRING_LITERAL","IDENTIFIER","CHAR_LITERAL","outerStatements",
"outerStatement","functionStatements","functionStatement","classStatements",
"classStatement","varDeclareStatement","varDefineStatement","varAssignStatement",
"arrayDeclareStatement","arrayDefineStatement","arrayAssignStatement","ifStatement",
"elifParts","elifPart","elsePart","whileStatement","foreachStatement","classDefineStatement",
"functionDeclareStatement","functionDefineStatement","classMethodDefineStatement",
"breakStatement","continueStatement","returnStatement","formParams","formParamSet",
"formParam","expression","compareExpression","mathExpression","term","factor",
"leftValue","leftValueSet","factParams","factParamSet","factParam","arrayType",
"type", NULL
};
#endif

static const short yyr1[] = {     0,
    63,    63,    64,    64,    64,    64,    64,    64,    64,    64,
    65,    65,    66,    66,    66,    66,    66,    66,    66,    66,
    66,    66,    66,    66,    66,    67,    67,    68,    68,    68,
    68,    69,    70,    71,    71,    71,    72,    73,    74,    74,
    75,    76,    76,    77,    78,    78,    79,    80,    81,    81,
    82,    82,    82,    83,    83,    83,    84,    84,    84,    85,
    86,    87,    87,    88,    88,    89,    89,    90,    90,    91,
    91,    91,    91,    92,    92,    92,    92,    92,    92,    92,
    92,    92,    93,    93,    93,    94,    94,    94,    95,    95,
    95,    95,    95,    95,    95,    95,    95,    95,    96,    97,
    97,    98,    98,    99,    99,   100,   101,   102,   102,   102,
   102
};

static const short yyr2[] = {     0,
     0,     2,     2,     2,     1,     2,     1,     1,     2,     1,
     0,     2,     2,     2,     2,     2,     2,     2,     1,     1,
     1,     2,     2,     2,     1,     0,     2,     2,     2,     2,
     1,     2,     4,     3,     6,     1,     2,     7,     6,     3,
     9,     0,     2,     7,     0,     4,     7,     9,     5,     7,
     5,     5,     5,     8,     8,     8,    10,    10,    10,     1,
     1,     2,     1,     0,     2,     0,     3,     2,     2,     3,
     3,     2,     1,     3,     3,     3,     3,     3,     3,     3,
     3,     1,     3,     3,     1,     3,     3,     1,     1,     1,
     1,     1,     1,     4,     4,     3,     2,     2,     2,     0,
     3,     0,     2,     0,     3,     1,     3,     1,     1,     1,
     1
};

static const short yydefact[] = {     1,
   110,     0,   109,   108,    63,     0,    10,   111,     1,     0,
     0,     5,     0,     7,     8,     0,     0,     0,     0,    89,
    90,     0,     0,     0,    92,   100,    91,    62,    73,    82,
    85,    88,    93,     0,     0,     2,     3,     4,     6,     9,
     0,    37,     0,     0,    32,     0,    26,     0,    72,    97,
    98,     0,    99,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,   102,     0,     0,    64,     0,
    64,   107,     0,    64,     0,     0,    31,     0,    26,     0,
     0,     0,     0,     0,    96,   100,    71,    70,    80,    78,
    75,    74,    81,    79,    77,    76,    83,    84,    86,    87,
   106,     0,   104,     0,     0,     0,    66,     0,     0,     0,
     0,     0,     0,    26,     0,    49,    27,    28,    29,    30,
    37,    32,   101,    95,     0,   103,    94,    64,    53,     0,
    65,    69,    68,    64,    52,    64,    51,     0,    64,    64,
    64,   104,     0,    11,    66,     0,    11,     0,    11,    50,
     0,     0,     0,   105,     0,    60,    61,     0,     0,     0,
    25,     0,    11,     0,     0,     0,     0,     0,     0,    19,
    20,    21,     0,     0,     0,    36,    93,     0,     0,    67,
     0,     0,     0,     0,    53,    52,    51,    11,     0,     0,
     0,    56,    12,    13,    14,    15,    16,    17,    18,    22,
    23,    24,     0,     0,    37,    32,    11,    55,    11,    54,
     0,     0,     0,     0,     0,    40,    34,     0,     0,     0,
     0,     0,    59,     0,     0,     0,    94,     0,     0,    33,
    58,    57,     0,    11,    11,     0,     0,     0,     0,     0,
     0,    35,    39,     0,    11,    42,    47,    38,     0,     0,
    45,    42,    48,     0,     0,    41,    43,     0,    11,     0,
     0,    11,    46,     0,    44,     0,     0,     0
};

static const short yydefgoto[] = {    36,
     9,   162,   163,    78,    79,   164,   165,   166,   167,   168,
   169,   170,   251,   252,   256,   171,   172,    12,    82,    14,
    15,   173,   174,   175,   106,   131,   107,   176,    29,    30,
    31,    32,    33,    53,   102,   126,   103,   178,   179
};

static const short yypact[] = {   237,
-32768,   -24,-32768,-32768,   226,   -17,-32768,-32768,   237,    22,
    24,-32768,    33,-32768,-32768,    38,   -16,   -27,    -2,-32768,
-32768,   226,   226,    55,-32768,    27,-32768,-32768,    40,   267,
    41,    49,    23,    -4,    37,-32768,-32768,-32768,-32768,-32768,
    21,    54,    51,    45,    66,    46,    -3,    76,-32768,-32768,
-32768,    58,-32768,   226,   226,   244,   244,    87,   244,   244,
   239,   244,   244,   244,   244,   226,   226,    61,    18,    63,
    18,-32768,    64,    18,    84,    67,-32768,    94,    -3,    96,
    97,    98,    75,   -20,-32768,    27,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,   108,   114,   118,   128,   130,   122,   102,   -15,   134,
   145,   147,   148,    -3,   152,-32768,-32768,-32768,-32768,-32768,
   157,   158,-32768,-32768,   226,-32768,-32768,    18,   146,    18,
-32768,-32768,-32768,    18,   160,    18,   161,   156,    18,    18,
    18,   114,   164,   176,   122,   166,   176,   170,   176,-32768,
   173,   177,   178,-32768,   175,-32768,-32768,   180,   181,   183,
-32768,   184,   176,   185,   186,   188,   189,   192,   194,-32768,
-32768,-32768,   196,   198,   205,-32768,    25,   153,   -10,-32768,
   187,   211,   214,   217,-32768,-32768,-32768,   176,   155,   226,
   226,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,   226,   221,   215,   220,   176,-32768,   176,-32768,
   228,   245,   233,   236,   240,-32768,-32768,   242,    18,   226,
   246,   251,-32768,   224,   257,   259,   253,   226,   260,-32768,
-32768,-32768,   247,   176,   176,   226,   258,   226,   265,   269,
   270,-32768,-32768,   263,   176,   300,-32768,-32768,   277,   285,
   306,   300,-32768,   226,   286,-32768,-32768,   288,   176,   289,
   284,   176,-32768,   287,-32768,   322,   323,-32768
};

static const short yypgoto[] = {   324,
-32768,  -136,-32768,   -75,-32768,    29,-32768,-32768,    31,-32768,
-32768,-32768,    73,-32768,-32768,-32768,-32768,-32768,    12,-32768,
-32768,-32768,-32768,    28,    26,   182,   199,    -5,-32768,   112,
    47,-32768,  -141,   248,-32768,   190,   201,    16,     1
};


#define	YYLAST		334


static const short yytable[] = {    28,
    18,     1,   177,   117,     3,   177,    43,   177,    46,    18,
   182,    13,   184,    43,     4,    17,    48,    49,    43,    76,
    13,   177,     1,    43,    17,     3,   193,    16,    10,    47,
    11,    44,    77,    45,    19,     4,    16,    10,   138,    11,
   122,    34,    41,    35,    42,   133,   177,    84,    87,    88,
   206,   211,    66,    68,    66,     8,    67,    37,   203,    38,
   101,   104,    83,   204,    52,   177,    69,   177,    39,   109,
   221,   109,   222,    40,   109,    80,     8,    81,    70,    84,
    50,    51,   233,    71,   108,    72,   108,    54,    55,   108,
    62,    63,   177,   177,    83,    74,   111,   240,   241,   113,
    64,    65,    73,   177,    75,    91,    85,    80,   249,    81,
    99,   100,    20,    21,    84,   114,    22,   177,    86,   101,
   177,   105,   261,   110,   112,   264,   116,   115,   109,    83,
   109,   118,   119,   120,   109,   121,   109,    24,   124,   109,
   109,   109,    80,   108,    81,   108,    25,    26,    27,   108,
   125,   108,   127,   143,   108,   108,   108,   128,   130,   146,
   129,   148,   132,   134,   151,   152,   153,    89,    90,    92,
    93,    94,    96,    97,    98,   135,   136,   144,   137,   156,
     1,   139,   157,     3,   213,   214,   140,   141,   150,   158,
   159,   147,   149,     4,   155,     5,   181,   215,   217,   160,
   183,    20,    21,   185,   218,    22,   188,   186,   187,   189,
   190,   161,   191,   205,   230,   212,   192,    23,   207,   229,
   194,   195,   237,   196,   197,     1,    24,   198,     3,   199,
   242,   200,   244,   201,     8,    25,    26,    27,     4,   216,
   202,     1,     2,   208,     3,   209,    20,    21,   258,   210,
    22,    20,    21,   219,     4,    22,     5,    95,   220,     6,
   223,   224,    23,   225,    20,    21,   226,    23,    22,    20,
    21,    24,     7,    22,   227,   228,    24,   239,   231,     8,
    25,    26,    27,   232,    26,    25,    26,    27,   234,    24,
   235,   236,   243,   238,    24,     8,   245,   248,    25,    26,
    27,   246,   247,    25,    26,    27,    56,    57,   250,   253,
    58,    59,    60,    61,   254,   255,   263,   259,   260,   265,
   262,   267,   268,   266,   257,   142,   180,     0,   145,     0,
     0,   154,     0,   123
};

static const short yycheck[] = {     5,
     0,     5,   144,    79,     8,   147,    34,   149,    11,     9,
   147,     0,   149,    34,    18,     0,    22,    23,    34,    23,
     9,   163,     5,    34,     9,     8,   163,     0,     0,    32,
     0,    59,    36,    61,    59,    18,     9,     9,   114,     9,
    61,    59,    59,    61,    61,    61,   188,    47,    54,    55,
    61,   188,    30,    58,    30,    59,    34,    36,    34,    36,
    66,    67,    47,    39,    38,   207,    30,   209,    36,    69,
   207,    71,   209,    36,    74,    47,    59,    47,    58,    79,
    26,    27,   224,    30,    69,    35,    71,    48,    49,    74,
    50,    51,   234,   235,    79,    30,    71,   234,   235,    74,
    52,    53,    58,   245,    59,    19,    31,    79,   245,    79,
    64,    65,    26,    27,   114,    32,    30,   259,    61,   125,
   262,    61,   259,    61,    61,   262,    33,    61,   128,   114,
   130,    36,    36,    36,   134,    61,   136,    51,    31,   139,
   140,   141,   114,   128,   114,   130,    60,    61,    62,   134,
    37,   136,    35,   128,   139,   140,   141,    30,    37,   134,
    31,   136,    61,    30,   139,   140,   141,    56,    57,    58,
    59,    60,    61,    62,    63,    31,    30,    32,    31,     4,
     5,    30,     7,     8,   190,   191,    30,    30,    33,    14,
    15,    32,    32,    18,    31,    20,    31,   203,   204,    24,
    31,    26,    27,    31,   204,    30,    32,    31,    31,    30,
    30,    36,    30,    61,   220,    61,    33,    42,    32,   219,
    36,    36,   228,    36,    36,     5,    51,    36,     8,    36,
   236,    36,   238,    36,    59,    60,    61,    62,    18,    19,
    36,     5,     6,    33,     8,    32,    26,    27,   254,    33,
    30,    26,    27,    39,    18,    30,    20,    19,    39,    23,
    33,    17,    42,    31,    26,    27,    31,    42,    30,    26,
    27,    51,    36,    30,    35,    34,    51,    31,    33,    59,
    60,    61,    62,    33,    61,    60,    61,    62,    32,    51,
    32,    39,    35,    34,    51,    59,    32,    35,    60,    61,
    62,    33,    33,    60,    61,    62,    40,    41,     9,    33,
    44,    45,    46,    47,    30,    10,    33,    32,    31,    33,
    32,     0,     0,     0,   252,   125,   145,    -1,   130,    -1,
    -1,   142,    -1,    86
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
#line 52 "oa.y"
{
		yyval.node = NULL;
	;
    break;}
case 2:
#line 55 "oa.y"
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
case 10:
#line 76 "oa.y"
{
		yyval.node = NULL;
	;
    break;}
case 11:
#line 82 "oa.y"
{
		yyval.node = NULL;
	;
    break;}
case 12:
#line 85 "oa.y"
{
		if(yyvsp[-1].node){
			yyvsp[-1].node->next = yyvsp[0].node;
		}else{
			yyval.node = yyvsp[0].node;
		}
	;
    break;}
case 25:
#line 107 "oa.y"
{
		yyval.node = NULL;
	;
    break;}
case 26:
#line 113 "oa.y"
{
		yyval.node = NULL;
	;
    break;}
case 27:
#line 116 "oa.y"
{
		if(yyvsp[-1].node){
			yyvsp[-1].node->next = yyvsp[0].node;
		}else{
			yyval.node = yyvsp[0].node;
		}
	;
    break;}
case 31:
#line 129 "oa.y"
{
		yyval.node = NULL;
	;
    break;}
case 32:
#line 136 "oa.y"
{
		yyval.node = createVarDeclare(yyvsp[-1].type, yyvsp[0].name);
	;
    break;}
case 33:
#line 142 "oa.y"
{
		yyval.node = createVarDefine(yyvsp[-3].type, yyvsp[-2].name, yyvsp[0].expression);
	;
    break;}
case 34:
#line 148 "oa.y"
{
		yyval.node = createVarAssign(yyvsp[-2].leftValue, yyvsp[0].expression, NULL);
	;
    break;}
case 35:
#line 151 "oa.y"
{
		yyval.node = createVarAssign(yyvsp[-5].leftValue, yyvsp[0].expression, yyvsp[-3].expression);
	;
    break;}
case 36:
#line 154 "oa.y"
{
		yyval.node = createVarAssign(NULL, yyvsp[0].expression, NULL);
	;
    break;}
case 37:
#line 161 "oa.y"
{
		yyval.node = createArrayDeclare(yyvsp[-1].type, yyvsp[0].name);
	;
    break;}
case 38:
#line 167 "oa.y"
{
		yyval.node = createArrayDefine(yyvsp[-6].type, yyvsp[-5].name, yyvsp[-3].type, yyvsp[-1].expression);
	;
    break;}
case 39:
#line 173 "oa.y"
{
		yyval.node = createArrayAssign(yyvsp[-5].leftValue, yyvsp[-3].type, yyvsp[-1].expression);
	;
    break;}
case 40:
#line 176 "oa.y"
{
		yyval.node = createArrayAssign(yyvsp[-2].leftValue, NULL, NULL);
	;
    break;}
case 41:
#line 184 "oa.y"
{
		yyval.node = createIf(yyvsp[-6].expression, yyvsp[-3].node, yyvsp[-1].node, yyvsp[0].node);
	;
    break;}
case 42:
#line 190 "oa.y"
{
		yyval.node = NULL;
	;
    break;}
case 43:
#line 193 "oa.y"
{
		yyvsp[-1].node->next = yyvsp[0].node;
		yyval.node = yyvsp[-1].node;
	;
    break;}
case 44:
#line 200 "oa.y"
{
		yyval.node = createElifPart(yyvsp[-4].expression, yyvsp[-1].node);
	;
    break;}
case 45:
#line 206 "oa.y"
{
		yyval.node = NULL;
	;
    break;}
case 46:
#line 209 "oa.y"
{
		yyval.node = createElsePart(yyvsp[-1].node);
	;
    break;}
case 47:
#line 216 "oa.y"
{
		yyval.node = createWhile(yyvsp[-4].expression, yyvsp[-1].node);
	;
    break;}
case 48:
#line 222 "oa.y"
{
		yyval.node = createForeach(yyvsp[-6].name, yyvsp[-4].leftValue, yyvsp[-1].node);
	;
    break;}
case 49:
#line 229 "oa.y"
{
		yyval.node = createClassDefine(yyvsp[-3].type, NULL, yyvsp[-1].node);
	;
    break;}
case 50:
#line 232 "oa.y"
{
		yyval.node = createClassDefine(yyvsp[-5].type, yyvsp[-3].type, yyvsp[-1].node);
	;
    break;}
case 51:
#line 240 "oa.y"
{
		yyval.node = createFunctionDeclare(yyvsp[-4].type, yyvsp[-3].name, yyvsp[-1].formParam);
	;
    break;}
case 52:
#line 243 "oa.y"
{
		yyval.node = createFunctionDeclare(yyvsp[-4].type, yyvsp[-3].name, yyvsp[-1].formParam);
	;
    break;}
case 53:
#line 246 "oa.y"
{
		yyval.node = createFunctionDeclare(NULL, yyvsp[-3].name, yyvsp[-1].formParam);
	;
    break;}
case 54:
#line 252 "oa.y"
{
		yyval.node = createFunctionDefine(yyvsp[-7].type, yyvsp[-6].name, yyvsp[-4].formParam, yyvsp[-1].node);
	;
    break;}
case 55:
#line 255 "oa.y"
{
		yyval.node = createFunctionDefine(yyvsp[-7].type, yyvsp[-6].name, yyvsp[-4].formParam, yyvsp[-1].node);
	;
    break;}
case 56:
#line 258 "oa.y"
{
		yyval.node = createFunctionDefine(NULL, yyvsp[-6].name, yyvsp[-4].formParam, yyvsp[-1].node);
	;
    break;}
case 57:
#line 264 "oa.y"
{
		yyval.node = createClassMethodDefine(yyvsp[-9].type, yyvsp[-6].name, yyvsp[-4].formParam, yyvsp[-1].node, yyvsp[-8].type);
	;
    break;}
case 58:
#line 267 "oa.y"
{
		yyval.node = createClassMethodDefine(yyvsp[-9].type, yyvsp[-6].name, yyvsp[-4].formParam, yyvsp[-1].node, yyvsp[-8].type);
	;
    break;}
case 59:
#line 270 "oa.y"
{
		yyval.node = createClassMethodDefine(NULL, yyvsp[-6].name, yyvsp[-4].formParam, yyvsp[-1].node, yyvsp[-8].type);
	;
    break;}
case 60:
#line 277 "oa.y"
{
		yyval.node = createBreak();
	;
    break;}
case 61:
#line 283 "oa.y"
{
		yyval.node = createContinue();
	;
    break;}
case 62:
#line 290 "oa.y"
{
		yyval.node = createReturn(yyvsp[0].expression);
	;
    break;}
case 63:
#line 293 "oa.y"
{
		yyval.node = createReturn(NULL);
	;
    break;}
case 64:
#line 300 "oa.y"
{
		yyval.formParam = NULL;
	;
    break;}
case 65:
#line 303 "oa.y"
{
		yyvsp[-1].formParam->next = yyvsp[0].formParam;
		yyval.formParam = yyvsp[-1].formParam;
	;
    break;}
case 66:
#line 310 "oa.y"
{
		yyval.formParam = NULL;
	;
    break;}
case 67:
#line 313 "oa.y"
{
		yyvsp[-1].formParam->next = yyvsp[0].formParam;
		yyval.formParam = yyvsp[-1].formParam;
	;
    break;}
case 68:
#line 320 "oa.y"
{
		yyval.formParam = createFormParam(yyvsp[-1].type, yyvsp[0].name);
	;
    break;}
case 69:
#line 323 "oa.y"
{
		yyval.formParam = createFormParam(yyvsp[-1].type, yyvsp[0].name);
	;
    break;}
case 70:
#line 331 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_AND);
	;
    break;}
case 71:
#line 334 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_OR);
	;
    break;}
case 72:
#line 337 "oa.y"
{
		yyval.expression = createExpression(yyvsp[0].expression, NULL, OA_EXP_NOT);
	;
    break;}
case 74:
#line 344 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_EQ);
	;
    break;}
case 75:
#line 347 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, NULL, OA_EXP_EQ);
	;
    break;}
case 76:
#line 350 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_NE);
	;
    break;}
case 77:
#line 353 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, NULL, OA_EXP_EQ);
	;
    break;}
case 78:
#line 356 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_GT);
	;
    break;}
case 79:
#line 359 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_GE);
	;
    break;}
case 80:
#line 362 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_LT);
	;
    break;}
case 81:
#line 365 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_LE);
	;
    break;}
case 83:
#line 372 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_PLUS);
	;
    break;}
case 84:
#line 375 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_MINUS);
	;
    break;}
case 86:
#line 382 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_MULTIPLE);
	;
    break;}
case 87:
#line 385 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_DIVIDE);
	;
    break;}
case 89:
#line 392 "oa.y"
{
		yyval.expression = createExpressionIntLeaf(yyvsp[0].number_int, 0);
	;
    break;}
case 90:
#line 395 "oa.y"
{
		yyval.expression = createExpressionDoubleLeaf(yyvsp[0].number_double, 0);
	;
    break;}
case 91:
#line 398 "oa.y"
{
		yyval.expression = createExpressionCharLeaf(yyvsp[0].type_char);
	;
    break;}
case 92:
#line 401 "oa.y"
{
		yyval.expression = createExpressionStringLeaf(yyvsp[0].type_string);
	;
    break;}
case 93:
#line 404 "oa.y"
{
		yyval.expression = createExpressionLeftValueLeaf(yyvsp[0].leftValue);
	;
    break;}
case 94:
#line 407 "oa.y"
{
		yyval.expression = createExpressionArrayValue(yyvsp[-3].leftValue, yyvsp[-1].expression);
	;
    break;}
case 95:
#line 410 "oa.y"
{
		yyval.expression = createExpressionFunctionValue(yyvsp[-3].leftValue, yyvsp[-1].factParam);
	;
    break;}
case 96:
#line 413 "oa.y"
{
		yyval.expression = yyvsp[-1].expression;
	;
    break;}
case 97:
#line 416 "oa.y"
{
		yyval.expression = createExpressionIntLeaf(yyvsp[0].number_int, 1);
	;
    break;}
case 98:
#line 419 "oa.y"
{
		yyval.expression = createExpressionDoubleLeaf(yyvsp[0].number_double, 1);
	;
    break;}
case 99:
#line 425 "oa.y"
{
		yyval.leftValue = createLeftValue(yyvsp[-1].name);
		yyval.leftValue->next = yyvsp[0].leftValue;
	;
    break;}
case 100:
#line 432 "oa.y"
{
		yyval.leftValue = NULL;
	;
    break;}
case 101:
#line 435 "oa.y"
{
		yyval.leftValue = createLeftValue(yyvsp[-1].name);
		yyval.leftValue->next = yyvsp[0].leftValue;
	;
    break;}
case 102:
#line 442 "oa.y"
{
		yyval.factParam = NULL;
	;
    break;}
case 103:
#line 445 "oa.y"
{
		yyvsp[-1].factParam->next = yyvsp[0].factParam;
		yyval.factParam = yyvsp[-1].factParam;
	;
    break;}
case 104:
#line 452 "oa.y"
{
		yyval.factParam = NULL;
	;
    break;}
case 105:
#line 455 "oa.y"
{
		yyvsp[-1].factParam->next = yyvsp[0].factParam;
		yyval.factParam = yyvsp[-1].factParam;
	;
    break;}
case 106:
#line 462 "oa.y"
{
		yyval.factParam = createFactParam(yyvsp[0].expression);
	;
    break;}
case 107:
#line 471 "oa.y"
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
#line 484 "oa.y"

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