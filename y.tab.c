
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



#define	YYFINAL		211
#define	YYFLAG		-32768
#define	YYNTBASE	62

#define YYTRANSLATE(x) ((unsigned)(x) <= 315 ? yytranslate[x] : 99)

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
     0,     1,     5,     7,     9,    11,    13,    15,    17,    19,
    21,    23,    25,    27,    29,    31,    32,    36,    38,    40,
    42,    44,    46,    48,    49,    53,    55,    57,    59,    61,
    63,    65,    67,    69,    71,    74,    79,    83,    86,    94,
   101,   111,   112,   115,   123,   128,   136,   146,   152,   160,
   166,   172,   181,   190,   201,   212,   213,   216,   217,   221,
   224,   227,   231,   235,   238,   240,   244,   248,   252,   256,
   260,   264,   266,   270,   274,   276,   280,   284,   286,   288,
   290,   292,   294,   299,   304,   308,   311,   312,   316,   317,
   320,   321,   325,   327,   331,   333,   335,   337
};

static const short yyrhs[] = {    -1,
    63,    36,    62,     0,    68,     0,    69,     0,    70,     0,
    71,     0,    72,     0,    73,     0,    74,     0,    78,     0,
    79,     0,    80,     0,    81,     0,    82,     0,    83,     0,
     0,    65,    36,    64,     0,    68,     0,    69,     0,    71,
     0,    72,     0,    81,     0,    82,     0,     0,    67,    36,
    66,     0,    68,     0,    69,     0,    70,     0,    71,     0,
    72,     0,    73,     0,    74,     0,    78,     0,    79,     0,
    98,    60,     0,    98,    60,    39,    87,     0,    92,    39,
    87,     0,    97,    60,     0,    97,    60,    39,    98,    34,
    87,    35,     0,    92,    39,    98,    34,    87,    35,     0,
    15,    30,    87,    31,    32,    62,    33,    75,    77,     0,
     0,    76,    75,     0,     9,    30,    87,    31,    32,    62,
    33,     0,    10,    32,    62,    33,     0,    24,    30,    87,
    31,    32,    62,    33,     0,    14,    30,    60,    17,    60,
    31,    32,    62,    33,     0,     6,    59,    32,    64,    33,
     0,     6,    59,    11,    59,    32,    64,    33,     0,    98,
    60,    30,    84,    31,     0,    97,    60,    30,    84,    31,
     0,    98,    60,    30,    84,    31,    32,    66,    33,     0,
    97,    60,    30,    84,    31,    32,    66,    33,     0,    98,
    59,    58,    60,    30,    84,    31,    32,    66,    33,     0,
    97,    59,    58,    60,    30,    84,    31,    32,    66,    33,
     0,     0,    86,    85,     0,     0,    37,    86,    85,     0,
    98,    60,     0,    97,    60,     0,    88,    49,    87,     0,
    88,    48,    87,     0,    42,    87,     0,    88,     0,    89,
    44,    89,     0,    89,    47,    89,     0,    89,    41,    89,
     0,    89,    46,    89,     0,    89,    40,    89,     0,    89,
    45,    89,     0,    89,     0,    90,    50,    89,     0,    90,
    51,    89,     0,    90,     0,    91,    52,    90,     0,    91,
    53,    90,     0,    91,     0,    26,     0,    27,     0,    61,
     0,    92,     0,    92,    34,    87,    35,     0,    92,    30,
    94,    31,     0,    30,    87,    31,     0,    60,    93,     0,
     0,    38,    60,    93,     0,     0,    96,    95,     0,     0,
    37,    96,    95,     0,    87,     0,    98,    34,    35,     0,
    18,     0,     8,     0,     5,     0,    59,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    49,    52,    59,    60,    61,    62,    63,    64,    65,    66,
    67,    68,    69,    70,    71,    75,    78,    84,    85,    86,
    87,    88,    89,    93,    96,   102,   103,   104,   105,   106,
   107,   108,   109,   110,   115,   121,   127,   134,   140,   146,
   154,   160,   163,   169,   175,   182,   188,   195,   198,   206,
   209,   215,   218,   223,   226,   233,   236,   243,   246,   253,
   256,   264,   267,   270,   273,   279,   282,   285,   288,   291,
   294,   297,   303,   306,   309,   315,   318,   321,   327,   330,
   333,   336,   339,   342,   345,   351,   358,   361,   368,   371,
   378,   381,   388,   397,   403,   406,   409,   412
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
"CLASS_IDENTIFIER","IDENTIFIER","CHAR_LITERAL","statements","statement","classStatements",
"classStatement","functionStatements","functionStatement","varDeclareStatement",
"varDefineStatement","varAssignStatement","arrayDeclareStatement","arrayDefineStatement",
"arrayAssignStatement","ifStatement","elifParts","elifPart","elsePart","whileStatement",
"forEachStatement","classDefineStatement","functionDeclareStatement","functionDefineStatement",
"classMethodDefineStatement","formParams","formParamSet","formParam","expression",
"compareExpression","mathExpression","term","factor","leftValue","leftValueSet",
"factParams","factParamSet","factParam","arrayType","type", NULL
};
#endif

static const short yyr1[] = {     0,
    62,    62,    63,    63,    63,    63,    63,    63,    63,    63,
    63,    63,    63,    63,    63,    64,    64,    65,    65,    65,
    65,    65,    65,    66,    66,    67,    67,    67,    67,    67,
    67,    67,    67,    67,    68,    69,    70,    71,    72,    73,
    74,    75,    75,    76,    77,    78,    79,    80,    80,    81,
    81,    82,    82,    83,    83,    84,    84,    85,    85,    86,
    86,    87,    87,    87,    87,    88,    88,    88,    88,    88,
    88,    88,    89,    89,    89,    90,    90,    90,    91,    91,
    91,    91,    91,    91,    91,    92,    93,    93,    94,    94,
    95,    95,    96,    97,    98,    98,    98,    98
};

static const short yyr2[] = {     0,
     0,     3,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     0,     3,     1,     1,     1,
     1,     1,     1,     0,     3,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     2,     4,     3,     2,     7,     6,
     9,     0,     2,     7,     4,     7,     9,     5,     7,     5,
     5,     8,     8,    10,    10,     0,     2,     0,     3,     2,
     2,     3,     3,     2,     1,     3,     3,     3,     3,     3,
     3,     1,     3,     3,     1,     3,     3,     1,     1,     1,
     1,     1,     4,     4,     3,     2,     0,     3,     0,     2,
     0,     3,     1,     3,     1,     1,     1,     1
};

static const short yydefact[] = {     1,
    97,     0,    96,     0,     0,    95,     0,    98,    87,     0,
     3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
    13,    14,    15,     0,     0,     0,     0,     0,     0,     0,
     0,    86,     1,     0,     0,    38,     0,     0,    35,     0,
    16,     0,    79,    80,     0,     0,    81,     0,    65,    72,
    75,    78,    82,     0,    87,     2,    37,     0,     0,    56,
     0,    94,     0,    56,     0,     0,     0,     0,    18,    19,
    20,    21,    22,    23,     0,     0,     0,     0,    64,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    89,     0,     0,    88,     0,     0,     0,    58,
     0,     0,     0,     0,     0,    36,    16,    48,    16,     0,
    85,     1,    63,    62,    70,    68,    66,    71,    69,    67,
    73,    74,    76,    77,    93,     0,    91,     0,     1,     0,
    56,    51,     0,    57,    61,    60,     0,    56,    50,     0,
    17,     0,     0,    84,     0,    90,    83,     0,    40,     0,
    24,    58,     0,     0,    24,    49,     1,    42,    91,    46,
     0,     0,     0,    26,    27,    28,    29,    30,    31,    32,
    33,    34,     0,     0,    59,    39,     0,     0,     0,     0,
     0,    42,    92,    24,    53,    24,    38,    35,    24,    52,
    47,     0,     0,    41,    43,     0,    25,     0,     0,     1,
    55,    54,     0,     0,     1,    45,     0,    44,     0,     0,
     0
};

static const short yydefgoto[] = {    56,
    10,    67,    68,   162,   163,    11,    12,    13,    14,    15,
    16,    17,   181,   182,   194,    18,    19,    20,    21,    22,
    23,    99,   134,   100,   125,    49,    50,    51,    52,    53,
    32,   126,   146,   127,    25,    26
};

static const short yypact[] = {    34,
-32768,   -18,-32768,    14,    31,-32768,    58,-32768,    54,    55,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,    57,   -46,   -14,     5,    46,   204,   204,
    62,-32768,    34,   191,    66,    60,    85,    68,    77,    64,
     7,   110,-32768,-32768,   204,   204,-32768,    97,    16,   222,
    33,    65,    17,   101,    54,-32768,-32768,    99,    78,     7,
     7,-32768,    79,     7,   204,   105,   107,   108,-32768,-32768,
-32768,-32768,-32768,-32768,    83,   -25,    92,   129,-32768,   130,
   204,   204,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
    -4,    -4,   204,   204,   131,-32768,   204,   137,   139,   124,
   111,   -17,   134,   142,   150,-32768,     7,-32768,     7,   152,
-32768,    34,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,   154,   136,   153,    34,   157,
     7,   155,     7,-32768,-32768,-32768,   204,     7,   161,   164,
-32768,   166,   169,-32768,   204,-32768,-32768,   179,-32768,   184,
    45,   124,   185,   188,    45,-32768,    34,   213,   136,-32768,
   195,   199,   208,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,   175,     2,-32768,-32768,   215,   207,   216,   231,
   260,   213,-32768,    45,-32768,    45,   232,   233,    45,-32768,
-32768,   204,   241,-32768,-32768,   242,-32768,   243,   246,    34,
-32768,-32768,   247,   245,    34,-32768,   248,-32768,   274,   280,
-32768
};

static const short yypgoto[] = {     1,
-32768,   -80,-32768,   -75,-32768,   -20,    -9,   -10,    27,    40,
    39,    52,   100,-32768,-32768,    53,    59,-32768,   -35,   -31,
-32768,   -56,   132,   156,   -27,-32768,   170,    -6,-32768,     0,
   228,-32768,   126,   141,   -36,   -30
};


#define	YYLAST		289


static const short yytable[] = {    24,
   209,    48,    54,    58,    75,    73,    57,   105,    37,    74,
    76,     1,    35,    36,     3,    40,    37,    78,    79,    37,
    69,    43,    44,   101,     6,    45,   140,   101,   141,   102,
   103,    70,    24,   102,    39,    37,    41,   106,     1,     2,
    27,     3,   136,    28,    38,    39,    93,     4,     5,     1,
    94,     6,     3,   113,   114,     9,    47,     7,     4,     5,
    29,   188,     6,    81,    82,     8,   128,    71,     7,   130,
    75,    73,    75,    73,   150,    74,    76,    74,    76,   178,
    72,   154,    89,    90,   123,   124,    69,    30,    69,    60,
    33,    31,     8,     9,   101,    34,   101,    70,    61,    70,
   102,   101,   102,     8,     9,    42,    64,   102,   196,   153,
   197,    24,   143,   198,   173,    65,    91,    92,   173,    62,
   174,    55,    66,    59,   174,    63,    77,    80,    24,   148,
   164,    95,    97,    71,   164,    71,   107,    98,   104,   108,
   166,   165,    36,   109,   166,   165,    72,   173,    72,   173,
    24,   110,   173,   174,    24,   174,    24,   179,   174,   111,
   133,   112,   129,   164,   199,   164,   131,   137,   164,   132,
   135,   138,   145,   166,   165,   166,   165,   167,   166,   165,
   139,   167,   142,    24,   144,    24,   151,   147,    24,   169,
   168,   149,   155,   169,   168,     1,   156,   157,     3,    24,
   204,   158,   170,   171,    24,   207,   170,   171,     6,   172,
   167,   160,   167,   172,   161,   167,    43,    44,   177,   176,
    45,   180,   169,   168,   169,   168,   184,   169,   168,    43,
    44,   185,    46,    45,   187,   170,   171,   170,   171,   190,
   170,   171,   172,   186,   172,    46,   189,   172,   191,     8,
     9,    47,   115,   116,   117,   118,   119,   120,   121,   122,
   192,    83,    84,     9,    47,    85,    86,    87,    88,   193,
    61,    65,   200,   210,   201,   202,   203,   206,   205,   211,
   208,   195,    96,   175,   183,   159,     0,     0,   152
};

static const short yycheck[] = {     0,
     0,    29,    30,    34,    41,    41,    34,    64,    34,    41,
    41,     5,    59,    60,     8,    11,    34,    45,    46,    34,
    41,    26,    27,    60,    18,    30,   107,    64,   109,    60,
    61,    41,    33,    64,    60,    34,    32,    65,     5,     6,
    59,     8,    60,    30,    59,    60,    30,    14,    15,     5,
    34,    18,     8,    81,    82,    60,    61,    24,    14,    15,
    30,    60,    18,    48,    49,    59,    94,    41,    24,    97,
   107,   107,   109,   109,   131,   107,   107,   109,   109,   155,
    41,   138,    50,    51,    91,    92,   107,    30,   109,    30,
    36,    38,    59,    60,   131,    39,   133,   107,    39,   109,
   131,   138,   133,    59,    60,    60,    30,   138,   184,   137,
   186,   112,   112,   189,   151,    39,    52,    53,   155,    35,
   151,    60,    59,    58,   155,    58,    17,    31,   129,   129,
   151,    31,    34,   107,   155,   109,    32,    60,    60,    33,
   151,   151,    60,    36,   155,   155,   107,   184,   109,   186,
   151,    60,   189,   184,   155,   186,   157,   157,   189,    31,
    37,    32,    32,   184,   192,   186,    30,    34,   189,    31,
    60,    30,    37,   184,   184,   186,   186,   151,   189,   189,
    31,   155,    31,   184,    31,   186,    32,    35,   189,   151,
   151,    35,    32,   155,   155,     5,    33,    32,     8,   200,
   200,    33,   151,   151,   205,   205,   155,   155,    18,   151,
   184,    33,   186,   155,    31,   189,    26,    27,    31,    35,
    30,     9,   184,   184,   186,   186,    32,   189,   189,    26,
    27,    33,    42,    30,    60,   184,   184,   186,   186,    33,
   189,   189,   184,    36,   186,    42,    32,   189,    33,    59,
    60,    61,    83,    84,    85,    86,    87,    88,    89,    90,
    30,    40,    41,    60,    61,    44,    45,    46,    47,    10,
    39,    39,    32,     0,    33,    33,    31,    33,    32,     0,
    33,   182,    55,   152,   159,   145,    -1,    -1,   133
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
#line 49 "oa.y"
{
		yyval.node = NULL;
	;
    break;}
case 2:
#line 52 "oa.y"
{
		yyvsp[-2].node->next = yyvsp[0].node;
		parseTree->root = yyvsp[-2].node;
	;
    break;}
case 16:
#line 75 "oa.y"
{
		yyval.node = NULL;
	;
    break;}
case 17:
#line 78 "oa.y"
{
		yyvsp[-2].node->next = yyvsp[0].node;
	;
    break;}
case 24:
#line 93 "oa.y"
{
		yyval.node = NULL;
	;
    break;}
case 25:
#line 96 "oa.y"
{
		yyvsp[-2].node->next = yyvsp[0].node;
	;
    break;}
case 35:
#line 115 "oa.y"
{
		yyval.node = createVarDeclare(yyvsp[-1].type, yyvsp[0].name);
	;
    break;}
case 36:
#line 121 "oa.y"
{
		yyval.node = createVarDefine(yyvsp[-3].type, yyvsp[-2].name, yyvsp[0].expression);
	;
    break;}
case 37:
#line 127 "oa.y"
{
		yyval.node = createVarAssign(yyvsp[-2].leftValue, yyvsp[0].expression);
	;
    break;}
case 38:
#line 134 "oa.y"
{
		yyval.node = createArrayDeclare(yyvsp[-1].type, yyvsp[0].name);
	;
    break;}
case 39:
#line 140 "oa.y"
{
		yyval.node = createArrayDefine(yyvsp[-6].type, yyvsp[-5].name, yyvsp[-3].type, yyvsp[-1].expression);
	;
    break;}
case 40:
#line 146 "oa.y"
{
		yyval.node = createArrayAssign(yyvsp[-5].leftValue, yyvsp[-3].type, yyvsp[-1].expression);
	;
    break;}
case 41:
#line 154 "oa.y"
{
		yyval.node = createIf(yyvsp[-6].expression, yyvsp[-3].node, yyvsp[-1].node, yyvsp[0].node);
	;
    break;}
case 42:
#line 160 "oa.y"
{
		yyval.node = NULL;
	;
    break;}
case 43:
#line 163 "oa.y"
{
		yyval.node->next = yyvsp[-1].node;
	;
    break;}
case 44:
#line 169 "oa.y"
{
		yyval.node = createElifPart(yyvsp[-4].expression, yyvsp[-1].node);
	;
    break;}
case 45:
#line 175 "oa.y"
{
		yyval.node = createElsePart(yyvsp[-1].node);
	;
    break;}
case 46:
#line 182 "oa.y"
{
		yyval.node = createWhile(yyvsp[-4].expression, yyvsp[-1].node);
	;
    break;}
case 47:
#line 188 "oa.y"
{
		yyval.node = createForeach(yyvsp[-6].name, yyvsp[-4].name, yyvsp[-1].node);
	;
    break;}
case 48:
#line 195 "oa.y"
{
		yyval.node = createClassDefine(yyvsp[-3].type, NULL, yyvsp[-1].node);
	;
    break;}
case 49:
#line 198 "oa.y"
{
		yyval.node = createClassDefine(yyvsp[-5].type, yyvsp[-3].type, yyvsp[-1].node);
	;
    break;}
case 50:
#line 206 "oa.y"
{
		yyval.node = createFunctionDeclare(yyvsp[-4].type, yyvsp[-3].name, yyvsp[-1].formParam);
	;
    break;}
case 51:
#line 209 "oa.y"
{
		yyval.node = createFunctionDeclare(yyvsp[-4].type, yyvsp[-3].name, yyvsp[-1].formParam);
	;
    break;}
case 52:
#line 215 "oa.y"
{
		yyval.node = createFunctionDefine(yyvsp[-7].type, yyvsp[-6].name, yyvsp[-4].formParam, yyvsp[-1].node);
	;
    break;}
case 53:
#line 218 "oa.y"
{
		yyval.node = createFunctionDefine(yyvsp[-7].type, yyvsp[-6].name, yyvsp[-4].formParam, yyvsp[-1].node);
	;
    break;}
case 54:
#line 223 "oa.y"
{
		yyval.node = createClassMethodDefine(yyvsp[-9].type, yyvsp[-6].name, yyvsp[-4].formParam, yyvsp[-1].node, yyvsp[-8].type);
	;
    break;}
case 55:
#line 226 "oa.y"
{
		yyval.node = createClassMethodDefine(yyvsp[-9].type, yyvsp[-6].name, yyvsp[-4].formParam, yyvsp[-1].node, yyvsp[-8].type);
	;
    break;}
case 56:
#line 233 "oa.y"
{
		yyval.formParam = NULL;
	;
    break;}
case 57:
#line 236 "oa.y"
{
		yyvsp[-1].formParam->next = yyvsp[0].formParam;
		yyval.formParam = yyvsp[-1].formParam;
	;
    break;}
case 58:
#line 243 "oa.y"
{
		yyval.formParam = NULL;
	;
    break;}
case 59:
#line 246 "oa.y"
{
		yyvsp[-1].formParam->next = yyvsp[0].formParam;
		yyval.formParam = yyvsp[-1].formParam;
	;
    break;}
case 60:
#line 253 "oa.y"
{
		yyval.formParam = createFormParam(yyvsp[-1].type, yyvsp[0].name);
	;
    break;}
case 61:
#line 256 "oa.y"
{
		yyval.formParam = createFormParam(yyvsp[-1].type, yyvsp[0].name);
	;
    break;}
case 62:
#line 264 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_AND);
	;
    break;}
case 63:
#line 267 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_OR);
	;
    break;}
case 64:
#line 270 "oa.y"
{
		yyval.expression = createExpression(yyvsp[0].expression, NULL, OA_EXP_NOT);
	;
    break;}
case 65:
#line 273 "oa.y"
{
		yyval.expression = yyvsp[0].expression;
	;
    break;}
case 66:
#line 279 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_EQ);
	;
    break;}
case 67:
#line 282 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_NE);
	;
    break;}
case 68:
#line 285 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_GT);
	;
    break;}
case 69:
#line 288 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_GE);
	;
    break;}
case 70:
#line 291 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_LT);
	;
    break;}
case 71:
#line 294 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_LE);
	;
    break;}
case 72:
#line 297 "oa.y"
{
		yyval.expression = yyvsp[0].expression;
	;
    break;}
case 73:
#line 303 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_PLUS);
	;
    break;}
case 74:
#line 306 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_MINUS);
	;
    break;}
case 75:
#line 309 "oa.y"
{
		yyval.expression = yyvsp[0].expression;
	;
    break;}
case 76:
#line 315 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_MULTIPLE);
	;
    break;}
case 77:
#line 318 "oa.y"
{
		yyval.expression = createExpression(yyvsp[-2].expression, yyvsp[0].expression, OA_EXP_DIVIDE);
	;
    break;}
case 78:
#line 321 "oa.y"
{
		yyval.expression = yyvsp[0].expression;
	;
    break;}
case 79:
#line 327 "oa.y"
{
		yyval.expression = createExpressionIntLeaf(yyvsp[0].number_int);
	;
    break;}
case 80:
#line 330 "oa.y"
{
		yyval.expression = createExpressionDoubleLeaf(yyvsp[0].number_double);
	;
    break;}
case 81:
#line 333 "oa.y"
{
		yyval.expression = createExpressionCharLeaf(yyvsp[0].type_char);
	;
    break;}
case 82:
#line 336 "oa.y"
{
		yyval.expression = createExpressionLeftValueLeaf(yyvsp[0].leftValue);
	;
    break;}
case 83:
#line 339 "oa.y"
{
		yyval.expression = createExpressionArrayValue(yyvsp[-3].leftValue, yyvsp[-1].expression);
	;
    break;}
case 84:
#line 342 "oa.y"
{
		yyval.expression = createExpressionFunctionValue(yyvsp[-3].leftValue, yyvsp[-1].factParam);
	;
    break;}
case 85:
#line 345 "oa.y"
{
		yyval.expression = yyvsp[-1].expression;
	;
    break;}
case 86:
#line 351 "oa.y"
{
		yyval.leftValue = createLeftValue(yyvsp[-1].name);
		yyval.leftValue->next = yyvsp[0].leftValue;
	;
    break;}
case 87:
#line 358 "oa.y"
{
		yyval.leftValue = NULL;
	;
    break;}
case 88:
#line 361 "oa.y"
{
		yyval.leftValue = createLeftValue(yyvsp[-1].name);
		yyval.leftValue->next = yyvsp[0].leftValue;
	;
    break;}
case 89:
#line 368 "oa.y"
{
		yyval.factParam = NULL;
	;
    break;}
case 90:
#line 371 "oa.y"
{
		yyvsp[-1].factParam->next = yyvsp[0].factParam;
		yyval.factParam = yyvsp[-1].factParam;
	;
    break;}
case 91:
#line 378 "oa.y"
{
		yyval.factParam = NULL;
	;
    break;}
case 92:
#line 381 "oa.y"
{
		yyvsp[-1].factParam->next = yyvsp[0].factParam;
		yyval.factParam = yyvsp[-1].factParam;
	;
    break;}
case 93:
#line 388 "oa.y"
{
		yyval.factParam = createFactParam(yyvsp[0].expression);
	;
    break;}
case 94:
#line 397 "oa.y"
{
		yyval.type = createArrayType(yyvsp[-2].type);
	;
    break;}
case 95:
#line 403 "oa.y"
{
		yyval.type = yyvsp[0].type;
	;
    break;}
case 96:
#line 406 "oa.y"
{
		yyval.type = yyvsp[0].type;
	;
    break;}
case 97:
#line 409 "oa.y"
{
		yyval.type = yyvsp[0].type;
	;
    break;}
case 98:
#line 412 "oa.y"
{
		yyval.type = yyvsp[0].type;
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
#line 418 "oa.y"

int
yyerror(char const *str)
{
    extern char *yytext;
    fprintf(stderr, "Parser error near %s\n", yytext);
    return 0;
}

int execute(const char* filename)
{
    extern int yyparse(void);
    extern FILE *yyin;
    FILE* fp = NULL;
    fp = fopen(filename,"r");
    if(fp == NULL){
      return;
    }
	parseTree = (struct ParseTree*)malloc(sizeof(struct ParseTree));
    yyin = fp;
    int result = yyparse();
    fclose(fp);
    return;
    if (yyparse()) {
        fprintf(stderr, "Error\n");
    }
    
	printJason(parseTree->root);
}