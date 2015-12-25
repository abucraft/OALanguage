
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



#define	YYFINAL		265
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
   127,   128,   131,   139,   140,   145,   153,   163,   169,   177,
   183,   189,   195,   204,   213,   222,   233,   244,   255,   257,
   259,   262,   264,   265,   268,   269,   273,   276,   279,   283,
   287,   290,   292,   296,   300,   304,   308,   312,   316,   318,
   322,   326,   328,   332,   336,   338,   340,   342,   344,   346,
   348,   353,   358,   362,   365,   368,   371,   372,   376,   377,
   380,   381,   385,   387,   391,   393,   395,   397
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
    39,   102,    34,    91,    35,     0,    15,    30,    91,    31,
    32,    65,    33,    76,    78,     0,     0,    77,    76,     0,
     9,    30,    91,    31,    32,    65,    33,     0,     0,    10,
    32,    65,    33,     0,    24,    30,    91,    31,    32,    65,
    33,     0,    14,    30,    61,    17,    96,    31,    32,    65,
    33,     0,     6,    59,    32,    67,    33,     0,     6,    59,
    11,    59,    32,    67,    33,     0,   102,    61,    30,    88,
    31,     0,   101,    61,    30,    88,    31,     0,    23,    61,
    30,    88,    31,     0,   102,    61,    30,    88,    31,    32,
    65,    33,     0,   101,    61,    30,    88,    31,    32,    65,
    33,     0,    23,    61,    30,    88,    31,    32,    65,    33,
     0,   102,    59,    58,    61,    30,    88,    31,    32,    65,
    33,     0,   101,    59,    58,    61,    30,    88,    31,    32,
    65,    33,     0,    23,    59,    58,    61,    30,    88,    31,
    32,    65,    33,     0,     4,     0,     7,     0,    20,    91,
     0,    20,     0,     0,    90,    89,     0,     0,    37,    90,
    89,     0,   102,    61,     0,   101,    61,     0,    92,    49,
    91,     0,    92,    48,    91,     0,    42,    91,     0,    92,
     0,    93,    44,    93,     0,    93,    47,    93,     0,    93,
    41,    93,     0,    93,    46,    93,     0,    93,    40,    93,
     0,    93,    45,    93,     0,    93,     0,    94,    50,    93,
     0,    94,    51,    93,     0,    94,     0,    95,    52,    94,
     0,    95,    53,    94,     0,    95,     0,    26,     0,    27,
     0,    62,     0,    60,     0,    96,     0,    96,    34,    91,
    35,     0,    96,    30,    98,    31,     0,    30,    91,    31,
     0,    51,    26,     0,    51,    27,     0,    61,    97,     0,
     0,    38,    61,    97,     0,     0,   100,    99,     0,     0,
    37,   100,    99,     0,    91,     0,   102,    34,    35,     0,
    18,     0,     8,     0,     5,     0,    59,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    52,    55,    69,    70,    71,    72,    73,    74,    75,    76,
    82,    85,    95,    96,    97,    98,    99,   100,   101,   102,
   103,   104,   105,   106,   107,   113,   116,   126,   127,   128,
   129,   136,   142,   148,   151,   154,   161,   167,   173,   181,
   187,   190,   197,   203,   206,   213,   219,   226,   229,   237,
   240,   243,   249,   252,   255,   261,   264,   267,   274,   280,
   287,   290,   297,   300,   307,   310,   317,   320,   328,   331,
   334,   337,   341,   344,   347,   350,   353,   356,   359,   363,
   366,   369,   373,   376,   379,   383,   386,   389,   392,   395,
   398,   401,   404,   407,   410,   416,   423,   426,   433,   436,
   443,   446,   453,   462,   468,   469,   470,   471
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
    68,    69,    70,    71,    71,    71,    72,    73,    74,    75,
    76,    76,    77,    78,    78,    79,    80,    81,    81,    82,
    82,    82,    83,    83,    83,    84,    84,    84,    85,    86,
    87,    87,    88,    88,    89,    89,    90,    90,    91,    91,
    91,    91,    92,    92,    92,    92,    92,    92,    92,    93,
    93,    93,    94,    94,    94,    95,    95,    95,    95,    95,
    95,    95,    95,    95,    95,    96,    97,    97,    98,    98,
    99,    99,   100,   101,   102,   102,   102,   102
};

static const short yyr2[] = {     0,
     0,     2,     2,     2,     1,     2,     1,     1,     2,     1,
     0,     2,     2,     2,     2,     2,     2,     2,     1,     1,
     1,     2,     2,     2,     1,     0,     2,     2,     2,     2,
     1,     2,     4,     3,     6,     1,     2,     7,     6,     9,
     0,     2,     7,     0,     4,     7,     9,     5,     7,     5,
     5,     5,     8,     8,     8,    10,    10,    10,     1,     1,
     2,     1,     0,     2,     0,     3,     2,     2,     3,     3,
     2,     1,     3,     3,     3,     3,     3,     3,     1,     3,
     3,     1,     3,     3,     1,     1,     1,     1,     1,     1,
     4,     4,     3,     2,     2,     2,     0,     3,     0,     2,
     0,     3,     1,     3,     1,     1,     1,     1
};

static const short yydefact[] = {     1,
   107,     0,   106,   105,    62,     0,    10,   108,     1,     0,
     0,     5,     0,     7,     8,     0,     0,     0,     0,    86,
    87,     0,     0,     0,    89,    97,    88,    61,    72,    79,
    82,    85,    90,     0,     0,     2,     3,     4,     6,     9,
     0,    37,     0,     0,    32,     0,    26,     0,    71,    94,
    95,     0,    96,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,    99,     0,     0,    63,     0,
    63,   104,     0,    63,     0,     0,    31,     0,    26,     0,
     0,     0,     0,     0,    93,    97,    70,    69,    77,    75,
    73,    78,    76,    74,    80,    81,    83,    84,   103,     0,
   101,     0,     0,     0,    65,     0,     0,     0,     0,     0,
     0,    26,     0,    48,    27,    28,    29,    30,    37,    32,
    98,    92,     0,   100,    91,    63,    52,     0,    64,    68,
    67,    63,    51,    63,    50,     0,    63,    63,    63,   101,
     0,    11,    65,     0,    11,     0,    11,    49,     0,     0,
     0,   102,     0,    59,    60,     0,     0,     0,    25,     0,
    11,     0,     0,     0,     0,     0,     0,    19,    20,    21,
     0,     0,     0,    36,    90,     0,     0,    66,     0,     0,
     0,     0,    52,    51,    50,    11,     0,     0,     0,    55,
    12,    13,    14,    15,    16,    17,    18,    22,    23,    24,
     0,     0,    37,    32,    11,    54,    11,    53,     0,     0,
     0,     0,     0,    34,     0,     0,     0,     0,     0,    58,
     0,     0,     0,    91,     0,     0,    33,    57,    56,     0,
    11,    11,     0,     0,     0,     0,     0,     0,    35,    39,
     0,    11,    41,    46,    38,     0,     0,    44,    41,    47,
     0,     0,    40,    42,     0,    11,     0,     0,    11,    45,
     0,    43,     0,     0,     0
};

static const short yydefgoto[] = {    36,
     9,   160,   161,    78,    79,   162,   163,   164,   165,   166,
   167,   168,   248,   249,   253,   169,   170,    12,    82,    14,
    15,   171,   172,   173,   104,   129,   105,   174,    29,    30,
    31,    32,    33,    53,   100,   124,   101,   176,   177
};

static const short yypact[] = {    18,
-32768,   -39,-32768,-32768,   148,    -2,-32768,-32768,    18,     9,
    32,-32768,    43,-32768,-32768,    50,    15,   -31,     8,-32768,
-32768,   148,   148,   -18,-32768,    20,-32768,-32768,   -34,    65,
    73,    68,    70,    31,    64,-32768,-32768,-32768,-32768,-32768,
    45,    85,    82,    74,    96,    77,    24,   106,-32768,-32768,
-32768,    80,-32768,   148,   148,   188,   188,   188,   188,   188,
   188,   188,   188,   188,   188,   148,   148,    84,    48,    88,
    48,-32768,    91,    48,   111,    95,-32768,   113,    24,   122,
   124,   125,   104,   -28,-32768,    20,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   137,
   134,   138,   142,   150,   154,   118,   -22,   155,   156,   163,
   164,    24,   170,-32768,-32768,-32768,-32768,-32768,   171,   172,
-32768,-32768,   148,-32768,-32768,    48,   173,    48,-32768,-32768,
-32768,    48,   174,    48,   175,   161,    48,    48,    48,   134,
   180,   162,   154,   194,   162,   195,   162,-32768,   196,   200,
   201,-32768,   202,-32768,-32768,   203,   205,   206,-32768,   207,
   162,   208,   209,   215,   216,   227,   228,-32768,-32768,-32768,
   229,   230,   231,-32768,    54,   181,    17,-32768,   236,   210,
   237,   214,-32768,-32768,-32768,   162,   213,   148,   148,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
   148,   211,   238,   239,   162,-32768,   162,-32768,   242,   259,
   248,   249,   246,-32768,   250,    48,   148,   252,   253,-32768,
   221,   251,   255,   254,   148,   256,-32768,-32768,-32768,   257,
   162,   162,   148,   260,   148,   262,   258,   263,-32768,-32768,
   264,   162,   280,-32768,-32768,   265,   267,   282,   280,-32768,
   148,   268,-32768,-32768,   270,   162,   271,   269,   162,-32768,
   272,-32768,   304,   306,-32768
};

static const short yypgoto[] = {   307,
-32768,  -134,-32768,   -75,-32768,    22,-32768,-32768,    35,-32768,
-32768,-32768,    59,-32768,-32768,-32768,-32768,-32768,    34,-32768,
-32768,-32768,-32768,    55,    25,   166,   182,    -5,-32768,   198,
    66,-32768,  -140,   225,-32768,   176,   189,    16,     1
};


#define	YYLAST		316


static const short yytable[] = {    28,
    18,   175,    43,   115,   175,    43,   175,    50,    51,    18,
   180,    43,   182,    54,    55,    17,    48,    49,    46,    19,
   175,    10,     1,     2,    17,     3,   191,    44,     1,    45,
    10,     3,   120,    13,    11,     4,   136,     5,   131,    47,
     6,     4,    13,    11,    37,   175,    76,    84,    87,    88,
    43,   209,     1,     7,    16,     3,    34,    52,    35,    77,
    99,   102,    83,    16,   175,     4,   175,    38,    80,   107,
   218,   107,   219,    41,   107,    42,     8,   204,    39,    84,
   230,    81,     8,    66,   106,    40,   106,   201,    68,   106,
   175,   175,   202,    69,    83,   109,   237,   238,   111,    66,
    80,   175,    70,    67,    56,    57,     8,   246,    58,    59,
    60,    61,    84,    81,    71,   175,    72,    99,   175,    64,
    65,   258,    62,    63,   261,    74,   107,    83,   107,    97,
    98,    73,   107,    80,   107,    75,    85,   107,   107,   107,
    86,   106,   112,   106,   103,   114,    81,   106,   108,   106,
   141,   110,   106,   106,   106,   113,   144,   116,   146,   117,
   118,   149,   150,   151,   119,   154,     1,   122,   155,     3,
   123,   126,   125,    20,    21,   156,   157,    22,   130,     4,
   127,     5,   211,   212,   132,   158,   133,    20,    21,    23,
   128,    22,   134,   148,   135,   213,   214,   159,    24,   137,
   138,   139,   215,    23,   142,   145,   147,    25,    26,    27,
   153,   227,    24,    20,    21,     1,   226,    22,     3,   234,
     8,    25,    26,    27,   179,   181,   183,   239,     4,   241,
   184,   185,   187,   186,   188,   189,    20,    21,    24,   190,
    22,   203,   206,   192,   193,   255,   208,    25,    26,    27,
   194,   195,    23,    89,    90,    91,    92,    93,    94,    95,
    96,    24,   196,   197,   198,   199,   200,   205,   207,     8,
    25,    26,    27,   210,   220,   221,   216,   217,   222,   223,
   224,    26,   231,   225,   228,   229,   232,   236,   247,   235,
   243,   252,   233,   242,   240,   244,   251,   250,   245,   256,
   257,   260,   259,   264,   262,   265,   263,   254,   178,   143,
   121,   140,     0,     0,     0,   152
};

static const short yycheck[] = {     5,
     0,   142,    34,    79,   145,    34,   147,    26,    27,     9,
   145,    34,   147,    48,    49,     0,    22,    23,    11,    59,
   161,     0,     5,     6,     9,     8,   161,    59,     5,    61,
     9,     8,    61,     0,     0,    18,   112,    20,    61,    32,
    23,    18,     9,     9,    36,   186,    23,    47,    54,    55,
    34,   186,     5,    36,     0,     8,    59,    38,    61,    36,
    66,    67,    47,     9,   205,    18,   207,    36,    47,    69,
   205,    71,   207,    59,    74,    61,    59,    61,    36,    79,
   221,    47,    59,    30,    69,    36,    71,    34,    58,    74,
   231,   232,    39,    30,    79,    71,   231,   232,    74,    30,
    79,   242,    58,    34,    40,    41,    59,   242,    44,    45,
    46,    47,   112,    79,    30,   256,    35,   123,   259,    52,
    53,   256,    50,    51,   259,    30,   126,   112,   128,    64,
    65,    58,   132,   112,   134,    59,    31,   137,   138,   139,
    61,   126,    32,   128,    61,    33,   112,   132,    61,   134,
   126,    61,   137,   138,   139,    61,   132,    36,   134,    36,
    36,   137,   138,   139,    61,     4,     5,    31,     7,     8,
    37,    30,    35,    26,    27,    14,    15,    30,    61,    18,
    31,    20,   188,   189,    30,    24,    31,    26,    27,    42,
    37,    30,    30,    33,    31,   201,   202,    36,    51,    30,
    30,    30,   202,    42,    32,    32,    32,    60,    61,    62,
    31,   217,    51,    26,    27,     5,   216,    30,     8,   225,
    59,    60,    61,    62,    31,    31,    31,   233,    18,   235,
    31,    31,    30,    32,    30,    30,    26,    27,    51,    33,
    30,    61,    33,    36,    36,   251,    33,    60,    61,    62,
    36,    36,    42,    56,    57,    58,    59,    60,    61,    62,
    63,    51,    36,    36,    36,    36,    36,    32,    32,    59,
    60,    61,    62,    61,    33,    17,    39,    39,    31,    31,
    35,    61,    32,    34,    33,    33,    32,    31,     9,    34,
    33,    10,    39,    32,    35,    33,    30,    33,    35,    32,
    31,    33,    32,     0,    33,     0,     0,   249,   143,   128,
    86,   123,    -1,    -1,    -1,   140
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
#line 181 "oa.y"
{
		yyval.node = createIf(yyvsp[-6].expression, yyvsp[-3].node, yyvsp[-1].node, yyvsp[0].node);
	;
    break;}
case 41:
#line 187 "oa.y"
{
		yyval.node = NULL;
	;
    break;}
case 42:
#line 190 "oa.y"
{
		yyvsp[-1].node->next = yyvsp[0].node;
		yyval.node = yyvsp[-1].node;
	;
    break;}
case 43:
#line 197 "oa.y"
{
		yyval.node = createElifPart(yyvsp[-4].expression, yyvsp[-1].node);
	;
    break;}
case 44:
#line 203 "oa.y"
{
		yyval.node = NULL;
	;
    break;}
case 45:
#line 206 "oa.y"
{
		yyval.node = createElsePart(yyvsp[-1].node);
	;
    break;}
case 46:
#line 213 "oa.y"
{
		yyval.node = createWhile(yyvsp[-4].expression, yyvsp[-1].node);
	;
    break;}
case 47:
#line 219 "oa.y"
{
		yyval.node = createForeach(yyvsp[-6].name, yyvsp[-4].leftValue, yyvsp[-1].node);
	;
    break;}
case 48:
#line 226 "oa.y"
{
		yyval.node = createClassDefine(yyvsp[-3].type, NULL, yyvsp[-1].node);
	;
    break;}
case 49:
#line 229 "oa.y"
{
		yyval.node = createClassDefine(yyvsp[-5].type, yyvsp[-3].type, yyvsp[-1].node);
	;
    break;}
case 50:
#line 237 "oa.y"
{
		yyval.node = createFunctionDeclare(yyvsp[-4].type, yyvsp[-3].name, yyvsp[-1].formParam);
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
		yyval.node = createFunctionDeclare(NULL, yyvsp[-3].name, yyvsp[-1].formParam);
	;
    break;}
case 53:
#line 249 "oa.y"
{
		yyval.node = createFunctionDefine(yyvsp[-7].type, yyvsp[-6].name, yyvsp[-4].formParam, yyvsp[-1].node);
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
		yyval.node = createFunctionDefine(NULL, yyvsp[-6].name, yyvsp[-4].formParam, yyvsp[-1].node);
	;
    break;}
case 56:
#line 261 "oa.y"
{
		yyval.node = createClassMethodDefine(yyvsp[-9].type, yyvsp[-6].name, yyvsp[-4].formParam, yyvsp[-1].node, yyvsp[-8].type);
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
		yyval.node = createClassMethodDefine(NULL, yyvsp[-6].name, yyvsp[-4].formParam, yyvsp[-1].node, yyvsp[-8].type);
	;
    break;}
case 59:
#line 274 "oa.y"
{
		yyval.node = createBreak();
	;
    break;}
case 60:
#line 280 "oa.y"
{
		yyval.node = createContinue();
	;
    break;}
case 61:
#line 287 "oa.y"
{
		yyval.node = createReturn(yyvsp[0].expression);
	;
    break;}
case 62:
#line 290 "oa.y"
{
		yyval.node = createReturn(NULL);
	;
    break;}
case 63:
#line 297 "oa.y"
{
		yyval.formParam = NULL;
	;
    break;}
case 64:
#line 300 "oa.y"
{
		yyvsp[-1].formParam->next = yyvsp[0].formParam;
		yyval.formParam = yyvsp[-1].formParam;
	;
    break;}
case 65:
#line 307 "oa.y"
{
		yyval.formParam = NULL;
	;
    break;}
case 66:
#line 310 "oa.y"
{
		yyvsp[-1].formParam->next = yyvsp[0].formParam;
		yyval.formParam = yyvsp[-1].formParam;
	;
    break;}
case 67:
#line 317 "oa.y"
{
		yyval.formParam = createFormParam(yyvsp[-1].type, yyvsp[0].name);
	;
    break;}
case 68:
#line 320 "oa.y"
{
		yyval.formParam = createFormParam(yyvsp[-1].type, yyvsp[0].name);
	;
    break;}
case 69:
#line 328 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_AND);
	;
    break;}
case 70:
#line 331 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_OR);
	;
    break;}
case 71:
#line 334 "oa.y"
{
		yyval.expression = createExpression(yyvsp[0].expression, NULL, OA_EXP_NOT);
	;
    break;}
case 73:
#line 341 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_EQ);
	;
    break;}
case 74:
#line 344 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_NE);
	;
    break;}
case 75:
#line 347 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_GT);
	;
    break;}
case 76:
#line 350 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_GE);
	;
    break;}
case 77:
#line 353 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_LT);
	;
    break;}
case 78:
#line 356 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_LE);
	;
    break;}
case 80:
#line 363 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_PLUS);
	;
    break;}
case 81:
#line 366 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_MINUS);
	;
    break;}
case 83:
#line 373 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_MULTIPLE);
	;
    break;}
case 84:
#line 376 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_DIVIDE);
	;
    break;}
case 86:
#line 383 "oa.y"
{
		yyval.expression = createExpressionIntLeaf(yyvsp[0].number_int, 1);
	;
    break;}
case 87:
#line 386 "oa.y"
{
		yyval.expression = createExpressionDoubleLeaf(yyvsp[0].number_double, 1);
	;
    break;}
case 88:
#line 389 "oa.y"
{
		yyval.expression = createExpressionCharLeaf(yyvsp[0].type_char);
	;
    break;}
case 89:
#line 392 "oa.y"
{
		yyval.expression = createExpressionStringLeaf(yyvsp[0].type_string);
	;
    break;}
case 90:
#line 395 "oa.y"
{
		yyval.expression = createExpressionLeftValueLeaf(yyvsp[0].leftValue);
	;
    break;}
case 91:
#line 398 "oa.y"
{
		yyval.expression = createExpressionArrayValue(yyvsp[-3].leftValue, yyvsp[-1].expression);
	;
    break;}
case 92:
#line 401 "oa.y"
{
		yyval.expression = createExpressionFunctionValue(yyvsp[-3].leftValue, yyvsp[-1].factParam);
	;
    break;}
case 93:
#line 404 "oa.y"
{
		yyval.expression = yyvsp[-1].expression;
	;
    break;}
case 94:
#line 407 "oa.y"
{
		yyval.expression = createExpressionIntLeaf(yyvsp[0].number_int, 0);
	;
    break;}
case 95:
#line 410 "oa.y"
{
		yyval.expression = createExpressionDoubleLeaf(yyvsp[0].number_double, 0);
	;
    break;}
case 96:
#line 416 "oa.y"
{
		yyval.leftValue = createLeftValue(yyvsp[-1].name);
		yyval.leftValue->next = yyvsp[0].leftValue;
	;
    break;}
case 97:
#line 423 "oa.y"
{
		yyval.leftValue = NULL;
	;
    break;}
case 98:
#line 426 "oa.y"
{
		yyval.leftValue = createLeftValue(yyvsp[-1].name);
		yyval.leftValue->next = yyvsp[0].leftValue;
	;
    break;}
case 99:
#line 433 "oa.y"
{
		yyval.factParam = NULL;
	;
    break;}
case 100:
#line 436 "oa.y"
{
		yyvsp[-1].factParam->next = yyvsp[0].factParam;
		yyval.factParam = yyvsp[-1].factParam;
	;
    break;}
case 101:
#line 443 "oa.y"
{
		yyval.factParam = NULL;
	;
    break;}
case 102:
#line 446 "oa.y"
{
		yyvsp[-1].factParam->next = yyvsp[0].factParam;
		yyval.factParam = yyvsp[-1].factParam;
	;
    break;}
case 103:
#line 453 "oa.y"
{
		yyval.factParam = createFactParam(yyvsp[0].expression);
	;
    break;}
case 104:
#line 462 "oa.y"
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
#line 475 "oa.y"

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