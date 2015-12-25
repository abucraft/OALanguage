
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



#define	YYFINAL		269
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
     0,     1,     4,     7,    10,    13,    16,    18,    21,    23,
    25,    28,    30,    31,    34,    37,    40,    43,    46,    49,
    52,    54,    56,    58,    61,    64,    67,    69,    70,    73,
    76,    79,    82,    84,    87,    92,    96,   103,   105,   108,
   116,   123,   133,   134,   137,   145,   146,   151,   159,   169,
   175,   183,   189,   195,   201,   210,   219,   228,   239,   250,
   261,   263,   265,   268,   270,   271,   274,   275,   279,   282,
   285,   289,   293,   296,   298,   302,   306,   310,   314,   318,
   322,   324,   328,   332,   334,   338,   342,   344,   346,   348,
   350,   352,   354,   359,   364,   368,   371,   374,   377,   378,
   382,   383,   386,   387,   391,   393,   397,   399,   401,   403
};

static const short yyrhs[] = {    -1,
    64,    63,     0,    69,    36,     0,    70,    36,     0,    72,
    36,     0,    73,    36,     0,    81,     0,    82,    36,     0,
    83,     0,    84,     0,    87,    36,     0,    36,     0,     0,
    66,    65,     0,    69,    36,     0,    70,    36,     0,    71,
    36,     0,    72,    36,     0,    73,    36,     0,    74,    36,
     0,    75,     0,    79,     0,    80,     0,    85,    36,     0,
    86,    36,     0,    87,    36,     0,    36,     0,     0,    68,
    67,     0,    69,    36,     0,    72,    36,     0,    82,    36,
     0,    36,     0,   102,    61,     0,   102,    61,    39,    91,
     0,    96,    39,    91,     0,    96,    34,    91,    35,    39,
    91,     0,    91,     0,   101,    61,     0,   101,    61,    39,
   102,    34,    91,    35,     0,    96,    39,   102,    34,    91,
    35,     0,    15,    30,    91,    31,    32,    65,    33,    76,
    78,     0,     0,    77,    76,     0,     9,    30,    91,    31,
    32,    65,    33,     0,     0,    10,    32,    65,    33,     0,
    24,    30,    91,    31,    32,    65,    33,     0,    14,    30,
    61,    17,    96,    31,    32,    65,    33,     0,     6,    59,
    32,    67,    33,     0,     6,    59,    11,    59,    32,    67,
    33,     0,   102,    61,    30,    88,    31,     0,   101,    61,
    30,    88,    31,     0,    23,    61,    30,    88,    31,     0,
   102,    61,    30,    88,    31,    32,    65,    33,     0,   101,
    61,    30,    88,    31,    32,    65,    33,     0,    23,    61,
    30,    88,    31,    32,    65,    33,     0,   102,    59,    58,
    61,    30,    88,    31,    32,    65,    33,     0,   101,    59,
    58,    61,    30,    88,    31,    32,    65,    33,     0,    23,
    59,    58,    61,    30,    88,    31,    32,    65,    33,     0,
     4,     0,     7,     0,    20,    91,     0,    20,     0,     0,
    90,    89,     0,     0,    37,    90,    89,     0,   102,    61,
     0,   101,    61,     0,    92,    49,    91,     0,    92,    48,
    91,     0,    42,    91,     0,    92,     0,    93,    44,    93,
     0,    93,    47,    93,     0,    93,    41,    93,     0,    93,
    46,    93,     0,    93,    40,    93,     0,    93,    45,    93,
     0,    93,     0,    94,    50,    93,     0,    94,    51,    93,
     0,    94,     0,    95,    52,    94,     0,    95,    53,    94,
     0,    95,     0,    26,     0,    27,     0,    62,     0,    60,
     0,    96,     0,    96,    34,    91,    35,     0,    96,    30,
    98,    31,     0,    30,    91,    31,     0,    51,    26,     0,
    51,    27,     0,    61,    97,     0,     0,    38,    61,    97,
     0,     0,   100,    99,     0,     0,    37,   100,    99,     0,
    91,     0,   102,    34,    35,     0,    18,     0,     8,     0,
     5,     0,    59,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    52,    55,    69,    70,    71,    72,    73,    74,    75,    76,
    77,    78,    84,    87,    97,    98,    99,   100,   101,   102,
   103,   104,   105,   106,   107,   108,   109,   115,   118,   128,
   129,   130,   131,   138,   144,   150,   153,   156,   163,   169,
   175,   183,   189,   192,   199,   205,   208,   215,   221,   228,
   231,   239,   242,   245,   251,   254,   257,   263,   266,   269,
   276,   282,   289,   292,   299,   302,   309,   312,   319,   322,
   330,   333,   336,   339,   343,   346,   349,   352,   355,   358,
   361,   365,   368,   371,   375,   378,   381,   385,   388,   391,
   394,   397,   400,   403,   406,   409,   412,   418,   425,   428,
   435,   438,   445,   448,   455,   464,   470,   471,   472,   473
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
    64,    64,    65,    65,    66,    66,    66,    66,    66,    66,
    66,    66,    66,    66,    66,    66,    66,    67,    67,    68,
    68,    68,    68,    69,    70,    71,    71,    71,    72,    73,
    74,    75,    76,    76,    77,    78,    78,    79,    80,    81,
    81,    82,    82,    82,    83,    83,    83,    84,    84,    84,
    85,    86,    87,    87,    88,    88,    89,    89,    90,    90,
    91,    91,    91,    91,    92,    92,    92,    92,    92,    92,
    92,    93,    93,    93,    94,    94,    94,    95,    95,    95,
    95,    95,    95,    95,    95,    95,    95,    96,    97,    97,
    98,    98,    99,    99,   100,   101,   102,   102,   102,   102
};

static const short yyr2[] = {     0,
     0,     2,     2,     2,     2,     2,     1,     2,     1,     1,
     2,     1,     0,     2,     2,     2,     2,     2,     2,     2,
     1,     1,     1,     2,     2,     2,     1,     0,     2,     2,
     2,     2,     1,     2,     4,     3,     6,     1,     2,     7,
     6,     9,     0,     2,     7,     0,     4,     7,     9,     5,
     7,     5,     5,     5,     8,     8,     8,    10,    10,    10,
     1,     1,     2,     1,     0,     2,     0,     3,     2,     2,
     3,     3,     2,     1,     3,     3,     3,     3,     3,     3,
     1,     3,     3,     1,     3,     3,     1,     1,     1,     1,
     1,     1,     4,     4,     3,     2,     2,     2,     0,     3,
     0,     2,     0,     3,     1,     3,     1,     1,     1,     1
};

static const short yydefact[] = {     1,
   109,     0,   108,   107,    64,     0,    12,   110,     1,     0,
     0,     0,     0,     7,     0,     9,    10,     0,     0,     0,
     0,    88,    89,     0,     0,     0,    91,    99,    90,    63,
    74,    81,    84,    87,    92,     0,     0,     2,     3,     4,
     5,     6,     8,    11,     0,    39,     0,     0,    34,     0,
    28,     0,    73,    96,    97,     0,    98,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,   101,
     0,     0,    65,     0,    65,     0,   106,     0,    65,     0,
     0,     0,    33,     0,    28,     0,     0,     0,     0,     0,
    95,    99,    72,    71,    79,    77,    75,    80,    78,    76,
    82,    83,    85,    86,   105,     0,   103,     0,     0,     0,
    67,     0,     0,     0,     0,     0,     0,     0,    35,    28,
     0,    50,    29,    30,    31,    32,    39,    34,   100,    94,
     0,   102,    93,    65,    54,     0,    66,    70,    69,    65,
    53,     0,    65,    52,     0,    65,    65,    65,   103,     0,
    13,    67,     0,    13,     0,     0,    13,    51,     0,     0,
     0,   104,     0,    61,    62,     0,     0,     0,    27,     0,
    13,     0,     0,     0,     0,     0,     0,    21,    22,    23,
     0,     0,     0,    38,    92,     0,     0,    68,     0,     0,
    40,     0,     0,    54,    53,    52,    13,     0,     0,     0,
    57,    14,    15,    16,    17,    18,    19,    20,    24,    25,
    26,     0,     0,    39,    34,    13,    56,    13,    55,     0,
     0,     0,     0,     0,    36,     0,     0,     0,    60,     0,
     0,     0,    93,     0,    59,    58,     0,    13,    13,     0,
     0,     0,     0,     0,    37,    41,    13,    43,    48,     0,
     0,    46,    43,    49,     0,     0,    42,    44,     0,    13,
     0,     0,    13,    47,     0,    45,     0,     0,     0
};

static const short yydefgoto[] = {    38,
     9,   170,   171,    84,    85,   172,   173,   174,   175,   176,
   177,   178,   252,   253,   257,   179,   180,    14,    88,    16,
    17,   181,   182,   183,   110,   137,   111,   184,    31,    32,
    33,    34,    35,    57,   106,   132,   107,   186,   187
};

static const short yypact[] = {    23,
-32768,   -50,-32768,-32768,   256,     8,-32768,-32768,    23,   -11,
    11,    42,    48,-32768,    52,-32768,-32768,    57,    26,   -27,
    12,-32768,-32768,   256,   256,    47,-32768,    64,-32768,-32768,
    43,   146,    -1,    45,    34,    53,    73,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,    54,   -15,    70,    60,   -13,    22,
    40,    88,-32768,-32768,-32768,    66,-32768,   256,   256,   248,
   248,   248,   248,   248,   248,   248,   248,   248,   248,   256,
   256,    67,    -2,    68,    -2,    -2,-32768,    71,    -2,   256,
    90,    72,-32768,    98,    40,    87,    99,   100,    78,   -26,
-32768,    64,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,   111,   106,   110,   116,   117,
   112,    92,   -23,   124,   127,   125,   132,   134,-32768,    40,
   133,-32768,-32768,-32768,-32768,-32768,   136,   140,-32768,-32768,
   256,-32768,-32768,    -2,   139,    -2,-32768,-32768,-32768,    -2,
   141,   256,    -2,   142,   143,    -2,    -2,    -2,   106,   147,
   229,   112,   149,   229,   137,   151,   229,-32768,   152,   153,
   154,-32768,   156,-32768,-32768,   166,   169,   170,-32768,   171,
   229,   167,   173,   175,   176,   177,   178,-32768,-32768,-32768,
   179,   180,   182,-32768,   -12,   144,   -22,-32768,   188,   191,
-32768,   189,   192,-32768,-32768,-32768,   229,   184,   256,   256,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,   256,   234,   193,   199,   229,-32768,   229,-32768,   194,
   211,   200,   209,   195,-32768,   207,   213,   215,-32768,   190,
   222,   225,   219,   256,-32768,-32768,   231,   229,   229,   256,
   228,   235,   233,   236,-32768,-32768,   229,   261,-32768,   239,
   238,   263,   261,-32768,   256,   245,-32768,-32768,   250,   229,
   247,   251,   229,-32768,   254,-32768,   292,   297,-32768
};

static const short yypgoto[] = {   300,
-32768,   -37,-32768,   -83,-32768,     1,    33,-32768,     5,    51,
-32768,-32768,    49,-32768,-32768,-32768,-32768,-32768,    61,-32768,
-32768,-32768,-32768,    62,   -39,   159,   165,    -5,-32768,   259,
    46,-32768,   -41,   212,-32768,   157,   172,    21,     4
};


#define	YYLAST		326


static const short yytable[] = {    30,
    10,   123,     1,    20,    12,     3,    47,    47,    21,    10,
    47,    47,    20,    12,    75,     4,    79,    70,    52,    53,
    19,   212,    50,    76,    39,    80,   213,     1,     2,    19,
     3,    48,    11,    49,   128,   115,   145,   139,   215,   118,
     4,    11,     5,    51,     1,     6,    40,     3,    66,    67,
    13,    86,    93,    94,    90,    87,     8,     4,     7,    13,
    15,    18,    82,    70,   105,   108,    36,    71,    37,    15,
    18,    89,    54,    55,   119,    83,   113,    41,   113,   116,
    81,     8,   113,    42,    45,    86,    46,    43,    90,    87,
    58,    59,    44,   112,   150,   112,    68,    69,     8,   112,
   153,    56,    73,   156,    77,    89,   159,   160,   161,   185,
    72,    74,   185,   103,   104,   185,   190,    78,    91,   193,
    86,   120,   124,    90,    87,   105,    92,   109,   114,   185,
   122,   117,   121,   202,   125,   126,   155,   113,   127,   113,
    89,   130,   131,   113,   133,   134,   113,   135,   136,   113,
   113,   113,   138,   140,   112,   185,   112,   141,   142,   220,
   112,   143,   146,   112,   144,   147,   112,   112,   112,   148,
   151,   191,   154,   157,   185,   158,   185,   163,   227,   189,
   228,   192,   194,   195,   196,    60,    61,   197,   237,    62,
    63,    64,    65,   222,   223,   198,   185,   185,   199,   200,
   243,   244,   203,   201,   214,   185,   224,   225,   204,   250,
   205,   206,   207,   208,   209,   210,   226,   211,   185,   216,
   218,   185,   262,   217,   219,   265,   229,   230,   241,   233,
   231,    76,   164,     1,   245,   165,     3,    80,     1,   232,
   234,     3,   166,   167,   221,   235,     4,   236,     5,   259,
    28,     4,   168,   238,    22,    23,   239,   240,    24,    22,
    23,   242,   246,    24,   169,   248,   247,   255,   249,   251,
    25,   254,   256,    22,    23,    25,   260,    24,   263,    26,
   261,    22,    23,   264,    26,    24,   266,     8,    27,    28,
    29,   268,     8,    27,    28,    29,   269,    25,    26,   267,
   152,   258,   149,   129,     0,   162,    26,    27,    28,    29,
   188,     0,     0,     0,     0,    27,    28,    29,    95,    96,
    97,    98,    99,   100,   101,   102
};

static const short yycheck[] = {     5,
     0,    85,     5,     0,     0,     8,    34,    34,    59,     9,
    34,    34,     9,     9,    30,    18,    30,    30,    24,    25,
     0,    34,    11,    39,    36,    39,    39,     5,     6,     9,
     8,    59,     0,    61,    61,    75,   120,    61,    61,    79,
    18,     9,    20,    32,     5,    23,    36,     8,    50,    51,
     0,    51,    58,    59,    51,    51,    59,    18,    36,     9,
     0,     0,    23,    30,    70,    71,    59,    34,    61,     9,
     9,    51,    26,    27,    80,    36,    73,    36,    75,    76,
    59,    59,    79,    36,    59,    85,    61,    36,    85,    85,
    48,    49,    36,    73,   134,    75,    52,    53,    59,    79,
   140,    38,    30,   143,    35,    85,   146,   147,   148,   151,
    58,    58,   154,    68,    69,   157,   154,    58,    31,   157,
   120,    32,    36,   120,   120,   131,    61,    61,    61,   171,
    33,    61,    61,   171,    36,    36,   142,   134,    61,   136,
   120,    31,    37,   140,    35,    30,   143,    31,    37,   146,
   147,   148,    61,    30,   134,   197,   136,    31,    34,   197,
   140,    30,    30,   143,    31,    30,   146,   147,   148,    30,
    32,    35,    32,    32,   216,    33,   218,    31,   216,    31,
   218,    31,    31,    31,    31,    40,    41,    32,   230,    44,
    45,    46,    47,   199,   200,    30,   238,   239,    30,    30,
   238,   239,    36,    33,    61,   247,   212,   213,    36,   247,
    36,    36,    36,    36,    36,    36,   213,    36,   260,    32,
    32,   263,   260,    33,    33,   263,    33,    17,   234,    35,
    31,    39,     4,     5,   240,     7,     8,    39,     5,    31,
    34,     8,    14,    15,    61,    33,    18,    33,    20,   255,
    61,    18,    24,    32,    26,    27,    32,    39,    30,    26,
    27,    31,    35,    30,    36,    33,    32,    30,    33,     9,
    42,    33,    10,    26,    27,    42,    32,    30,    32,    51,
    31,    26,    27,    33,    51,    30,    33,    59,    60,    61,
    62,     0,    59,    60,    61,    62,     0,    42,    51,     0,
   136,   253,   131,    92,    -1,   149,    51,    60,    61,    62,
   152,    -1,    -1,    -1,    -1,    60,    61,    62,    60,    61,
    62,    63,    64,    65,    66,    67
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
case 12:
#line 78 "oa.y"
{
		yyval.node = NULL;
	;
    break;}
case 13:
#line 84 "oa.y"
{
		yyval.node = NULL;
	;
    break;}
case 14:
#line 87 "oa.y"
{
		if(yyvsp[-1].node){
			yyvsp[-1].node->next = yyvsp[0].node;
		}else{
			yyval.node = yyvsp[0].node;
		}
	;
    break;}
case 27:
#line 109 "oa.y"
{
		yyval.node = NULL;
	;
    break;}
case 28:
#line 115 "oa.y"
{
		yyval.node = NULL;
	;
    break;}
case 29:
#line 118 "oa.y"
{
		if(yyvsp[-1].node){
			yyvsp[-1].node->next = yyvsp[0].node;
		}else{
			yyval.node = yyvsp[0].node;
		}
	;
    break;}
case 33:
#line 131 "oa.y"
{
		yyval.node = NULL;
	;
    break;}
case 34:
#line 138 "oa.y"
{
		yyval.node = createVarDeclare(yyvsp[-1].type, yyvsp[0].name);
	;
    break;}
case 35:
#line 144 "oa.y"
{
		yyval.node = createVarDefine(yyvsp[-3].type, yyvsp[-2].name, yyvsp[0].expression);
	;
    break;}
case 36:
#line 150 "oa.y"
{
		yyval.node = createVarAssign(yyvsp[-2].leftValue, yyvsp[0].expression, NULL);
	;
    break;}
case 37:
#line 153 "oa.y"
{
		yyval.node = createVarAssign(yyvsp[-5].leftValue, yyvsp[0].expression, yyvsp[-3].expression);
	;
    break;}
case 38:
#line 156 "oa.y"
{
		yyval.node = createVarAssign(NULL, yyvsp[0].expression, NULL);
	;
    break;}
case 39:
#line 163 "oa.y"
{
		yyval.node = createArrayDeclare(yyvsp[-1].type, yyvsp[0].name);
	;
    break;}
case 40:
#line 169 "oa.y"
{
		yyval.node = createArrayDefine(yyvsp[-6].type, yyvsp[-5].name, yyvsp[-3].type, yyvsp[-1].expression);
	;
    break;}
case 41:
#line 175 "oa.y"
{
		yyval.node = createArrayAssign(yyvsp[-5].leftValue, yyvsp[-3].type, yyvsp[-1].expression);
	;
    break;}
case 42:
#line 183 "oa.y"
{
		yyval.node = createIf(yyvsp[-6].expression, yyvsp[-3].node, yyvsp[-1].node, yyvsp[0].node);
	;
    break;}
case 43:
#line 189 "oa.y"
{
		yyval.node = NULL;
	;
    break;}
case 44:
#line 192 "oa.y"
{
		yyvsp[-1].node->next = yyvsp[0].node;
		yyval.node = yyvsp[-1].node;
	;
    break;}
case 45:
#line 199 "oa.y"
{
		yyval.node = createElifPart(yyvsp[-4].expression, yyvsp[-1].node);
	;
    break;}
case 46:
#line 205 "oa.y"
{
		yyval.node = NULL;
	;
    break;}
case 47:
#line 208 "oa.y"
{
		yyval.node = createElsePart(yyvsp[-1].node);
	;
    break;}
case 48:
#line 215 "oa.y"
{
		yyval.node = createWhile(yyvsp[-4].expression, yyvsp[-1].node);
	;
    break;}
case 49:
#line 221 "oa.y"
{
		yyval.node = createForeach(yyvsp[-6].name, yyvsp[-4].leftValue, yyvsp[-1].node);
	;
    break;}
case 50:
#line 228 "oa.y"
{
		yyval.node = createClassDefine(yyvsp[-3].type, NULL, yyvsp[-1].node);
	;
    break;}
case 51:
#line 231 "oa.y"
{
		yyval.node = createClassDefine(yyvsp[-5].type, yyvsp[-3].type, yyvsp[-1].node);
	;
    break;}
case 52:
#line 239 "oa.y"
{
		yyval.node = createFunctionDeclare(yyvsp[-4].type, yyvsp[-3].name, yyvsp[-1].formParam);
	;
    break;}
case 53:
#line 242 "oa.y"
{
		yyval.node = createFunctionDeclare(yyvsp[-4].type, yyvsp[-3].name, yyvsp[-1].formParam);
	;
    break;}
case 54:
#line 245 "oa.y"
{
		yyval.node = createFunctionDeclare(NULL, yyvsp[-3].name, yyvsp[-1].formParam);
	;
    break;}
case 55:
#line 251 "oa.y"
{
		yyval.node = createFunctionDefine(yyvsp[-7].type, yyvsp[-6].name, yyvsp[-4].formParam, yyvsp[-1].node);
	;
    break;}
case 56:
#line 254 "oa.y"
{
		yyval.node = createFunctionDefine(yyvsp[-7].type, yyvsp[-6].name, yyvsp[-4].formParam, yyvsp[-1].node);
	;
    break;}
case 57:
#line 257 "oa.y"
{
		yyval.node = createFunctionDefine(NULL, yyvsp[-6].name, yyvsp[-4].formParam, yyvsp[-1].node);
	;
    break;}
case 58:
#line 263 "oa.y"
{
		yyval.node = createClassMethodDefine(yyvsp[-9].type, yyvsp[-6].name, yyvsp[-4].formParam, yyvsp[-1].node, yyvsp[-8].type);
	;
    break;}
case 59:
#line 266 "oa.y"
{
		yyval.node = createClassMethodDefine(yyvsp[-9].type, yyvsp[-6].name, yyvsp[-4].formParam, yyvsp[-1].node, yyvsp[-8].type);
	;
    break;}
case 60:
#line 269 "oa.y"
{
		yyval.node = createClassMethodDefine(NULL, yyvsp[-6].name, yyvsp[-4].formParam, yyvsp[-1].node, yyvsp[-8].type);
	;
    break;}
case 61:
#line 276 "oa.y"
{
		yyval.node = createBreak();
	;
    break;}
case 62:
#line 282 "oa.y"
{
		yyval.node = createContinue();
	;
    break;}
case 63:
#line 289 "oa.y"
{
		yyval.node = createReturn(yyvsp[0].expression);
	;
    break;}
case 64:
#line 292 "oa.y"
{
		yyval.node = createReturn(NULL);
	;
    break;}
case 65:
#line 299 "oa.y"
{
		yyval.formParam = NULL;
	;
    break;}
case 66:
#line 302 "oa.y"
{
		yyvsp[-1].formParam->next = yyvsp[0].formParam;
		yyval.formParam = yyvsp[-1].formParam;
	;
    break;}
case 67:
#line 309 "oa.y"
{
		yyval.formParam = NULL;
	;
    break;}
case 68:
#line 312 "oa.y"
{
		yyvsp[-1].formParam->next = yyvsp[0].formParam;
		yyval.formParam = yyvsp[-1].formParam;
	;
    break;}
case 69:
#line 319 "oa.y"
{
		yyval.formParam = createFormParam(yyvsp[-1].type, yyvsp[0].name);
	;
    break;}
case 70:
#line 322 "oa.y"
{
		yyval.formParam = createFormParam(yyvsp[-1].type, yyvsp[0].name);
	;
    break;}
case 71:
#line 330 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_AND);
	;
    break;}
case 72:
#line 333 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_OR);
	;
    break;}
case 73:
#line 336 "oa.y"
{
		yyval.expression = createExpression(yyvsp[0].expression, NULL, OA_EXP_NOT);
	;
    break;}
case 75:
#line 343 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_EQ);
	;
    break;}
case 76:
#line 346 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_NE);
	;
    break;}
case 77:
#line 349 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_GT);
	;
    break;}
case 78:
#line 352 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_GE);
	;
    break;}
case 79:
#line 355 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_LT);
	;
    break;}
case 80:
#line 358 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_LE);
	;
    break;}
case 82:
#line 365 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_PLUS);
	;
    break;}
case 83:
#line 368 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_MINUS);
	;
    break;}
case 85:
#line 375 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_MULTIPLE);
	;
    break;}
case 86:
#line 378 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_DIVIDE);
	;
    break;}
case 88:
#line 385 "oa.y"
{
		yyval.expression = createExpressionIntLeaf(yyvsp[0].number_int, 1);
	;
    break;}
case 89:
#line 388 "oa.y"
{
		yyval.expression = createExpressionDoubleLeaf(yyvsp[0].number_double, 1);
	;
    break;}
case 90:
#line 391 "oa.y"
{
		yyval.expression = createExpressionCharLeaf(yyvsp[0].type_char);
	;
    break;}
case 91:
#line 394 "oa.y"
{
		yyval.expression = createExpressionStringLeaf(yyvsp[0].type_string);
	;
    break;}
case 92:
#line 397 "oa.y"
{
		yyval.expression = createExpressionLeftValueLeaf(yyvsp[0].leftValue);
	;
    break;}
case 93:
#line 400 "oa.y"
{
		yyval.expression = createExpressionArrayValue(yyvsp[-3].leftValue, yyvsp[-1].expression);
	;
    break;}
case 94:
#line 403 "oa.y"
{
		yyval.expression = createExpressionFunctionValue(yyvsp[-3].leftValue, yyvsp[-1].factParam);
	;
    break;}
case 95:
#line 406 "oa.y"
{
		yyval.expression = yyvsp[-1].expression;
	;
    break;}
case 96:
#line 409 "oa.y"
{
		yyval.expression = createExpressionIntLeaf(yyvsp[0].number_int, 0);
	;
    break;}
case 97:
#line 412 "oa.y"
{
		yyval.expression = createExpressionDoubleLeaf(yyvsp[0].number_double, 0);
	;
    break;}
case 98:
#line 418 "oa.y"
{
		yyval.leftValue = createLeftValue(yyvsp[-1].name);
		yyval.leftValue->next = yyvsp[0].leftValue;
	;
    break;}
case 99:
#line 425 "oa.y"
{
		yyval.leftValue = NULL;
	;
    break;}
case 100:
#line 428 "oa.y"
{
		yyval.leftValue = createLeftValue(yyvsp[-1].name);
		yyval.leftValue->next = yyvsp[0].leftValue;
	;
    break;}
case 101:
#line 435 "oa.y"
{
		yyval.factParam = NULL;
	;
    break;}
case 102:
#line 438 "oa.y"
{
		yyvsp[-1].factParam->next = yyvsp[0].factParam;
		yyval.factParam = yyvsp[-1].factParam;
	;
    break;}
case 103:
#line 445 "oa.y"
{
		yyval.factParam = NULL;
	;
    break;}
case 104:
#line 448 "oa.y"
{
		yyvsp[-1].factParam->next = yyvsp[0].factParam;
		yyval.factParam = yyvsp[-1].factParam;
	;
    break;}
case 105:
#line 455 "oa.y"
{
		yyval.factParam = createFactParam(yyvsp[0].expression);
	;
    break;}
case 106:
#line 464 "oa.y"
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
#line 477 "oa.y"

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