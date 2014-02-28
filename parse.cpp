/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

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
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     REAL = 258,
     PARSE_INT = 259,
     STRING = 260,
     PARSE_TRUE = 261,
     PARSE_FALSE = 262,
     ENABLE = 263,
     DISABLE = 264,
     MATH_COS = 265,
     MATH_SIN = 266,
     MATH_TAN = 267,
     MATH_ACOS = 268,
     MATH_ASIN = 269,
     MATH_ATAN = 270,
     MATH_ATAN2 = 271,
     MATH_LN = 272,
     MATH_LOG = 273,
     MATH_EXP = 274,
     MATH_SQRT = 275,
     MATH_E = 276,
     MATH_PI = 277,
     GLOBAL = 278,
     WIDTH = 279,
     HEIGHT = 280,
     BGCOLOR = 281,
     SAMPLESX = 282,
     SAMPLESY = 283,
     SHUTTERTIME = 284,
     PATHTRACE = 285,
     CAMERA = 286,
     POS = 287,
     DIR = 288,
     LOOKAT = 289,
     UP = 290,
     FOV = 291,
     APERTURESIZE = 292,
     FOCALLENGTH = 293,
     FOCALPOINT = 294,
     TRIANGLE = 295,
     V1 = 296,
     V2 = 297,
     V3 = 298,
     N1 = 299,
     N2 = 300,
     N3 = 301,
     MESH = 302,
     LOAD = 303,
     GROUP = 304,
     INSTANCE = 305,
     GEOMETRY = 306,
     MATERIAL_PHONG = 307,
     ME = 308,
     MA = 309,
     MD = 310,
     MS = 311,
     MR = 312,
     MT = 313,
     MSP = 314,
     INDEX = 315,
     PUSHMATRIX = 316,
     POPMATRIX = 317,
     ROTATE = 318,
     TRANSLATE = 319,
     SCALE = 320,
     VELOCITY = 321,
     LIGHT = 322,
     POINTLIGHT = 323,
     WATTAGE = 324,
     COLOR = 325,
     DIRLIGHT = 326,
     AREALIGHT = 327,
     INTENSITY = 328,
     SPHERE = 329,
     CENTER = 330,
     RADIUS = 331,
     SQUARE = 332,
     NORMAL = 333,
     NEG = 334
   };
#endif
/* Tokens.  */
#define REAL 258
#define PARSE_INT 259
#define STRING 260
#define PARSE_TRUE 261
#define PARSE_FALSE 262
#define ENABLE 263
#define DISABLE 264
#define MATH_COS 265
#define MATH_SIN 266
#define MATH_TAN 267
#define MATH_ACOS 268
#define MATH_ASIN 269
#define MATH_ATAN 270
#define MATH_ATAN2 271
#define MATH_LN 272
#define MATH_LOG 273
#define MATH_EXP 274
#define MATH_SQRT 275
#define MATH_E 276
#define MATH_PI 277
#define GLOBAL 278
#define WIDTH 279
#define HEIGHT 280
#define BGCOLOR 281
#define SAMPLESX 282
#define SAMPLESY 283
#define SHUTTERTIME 284
#define PATHTRACE 285
#define CAMERA 286
#define POS 287
#define DIR 288
#define LOOKAT 289
#define UP 290
#define FOV 291
#define APERTURESIZE 292
#define FOCALLENGTH 293
#define FOCALPOINT 294
#define TRIANGLE 295
#define V1 296
#define V2 297
#define V3 298
#define N1 299
#define N2 300
#define N3 301
#define MESH 302
#define LOAD 303
#define GROUP 304
#define INSTANCE 305
#define GEOMETRY 306
#define MATERIAL_PHONG 307
#define ME 308
#define MA 309
#define MD 310
#define MS 311
#define MR 312
#define MT 313
#define MSP 314
#define INDEX 315
#define PUSHMATRIX 316
#define POPMATRIX 317
#define ROTATE 318
#define TRANSLATE 319
#define SCALE 320
#define VELOCITY 321
#define LIGHT 322
#define POINTLIGHT 323
#define WATTAGE 324
#define COLOR 325
#define DIRLIGHT 326
#define AREALIGHT 327
#define INTENSITY 328
#define SPHERE 329
#define CENTER 330
#define RADIUS 331
#define SQUARE 332
#define NORMAL 333
#define NEG 334




/* Copy the first part of user declarations.  */
#line 1 "../parse.y"

#ifdef WIN32
#pragma warning(disable:4786)
#endif

#include <stdlib.h>
#include <math.h>
#include <stack>
#include <map>
#include <string>
#include <iostream>
#include "miro.h"
#include "object.h"
#include "bspTree.h"
#include "scene.h"
#include "instance.h"
#include "triangle.h"
#include "triangleMesh.h"
#include "sphere.h"
#include "camera.h"
#include "material.h"
#include "image.h"
#include "console.h"
#include "square.h"
#include "AreaLight.h"

//#define YYDEBUG 1
#define yyerror(x) Fatal("Parser error on line %d: %s\n", yyline, x); 

extern int yylex();
extern int yyline;
extern FILE *yyin, *yyout;

// variables for adding objects, keeping track of variables
Object* pObj=0;
BSPTree* pBSP=0;
std::map<std::string, Object*> g_objectMap;
Material* pMat=new Material;
char* g = 0;
// add more here

Vector3 __parse_temp_vector;
std::stack<Matrix4x4> g_kMatrixStack;
Vector3 g_Vel;
Light* pLight=0;

Vector3& Vertex3(const float& x, const float& y, const float& z);
Vector3& Vertex3(const Vector3& v);
Vector3& Color3(const float& x, const float& y, const float& z);
void Translate(const float& x, const float& y, const float& z);
void Rotate(const float& angle, float x, float y, float z); // angle is in degrees
void Scale(const float& x, const float& y, const float& z);
Matrix4x4& GetCTM();
void PushMatrix();
void PopMatrix();



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 62 "../parse.y"
{
    float real;
    int integer;
    char* str;
}
/* Line 193 of yacc.c.  */
#line 318 "../parse.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 331 "../parse.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1040

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  91
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  143
/* YYNRULES -- Number of states.  */
#define YYNSTATES  436

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   334

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      89,    90,    82,    81,    88,    80,     2,    83,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    79,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    85,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    86,     2,    87,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    84
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,    12,    17,    19,    21,    25,
      27,    28,    34,    35,    42,    43,    49,    50,    57,    58,
      64,    65,    72,    73,    79,    80,    87,    88,    94,    95,
     102,   103,   111,   119,   127,   135,   143,   151,   152,   160,
     164,   165,   173,   174,   178,   180,   182,   191,   198,   205,
     212,   213,   218,   219,   224,   225,   230,   231,   239,   243,
     251,   252,   260,   268,   271,   272,   275,   276,   281,   282,
     286,   290,   298,   302,   306,   310,   314,   315,   321,   322,
     329,   330,   339,   340,   349,   350,   359,   360,   365,   366,
     375,   376,   385,   386,   391,   392,   400,   408,   416,   424,
     428,   432,   436,   444,   446,   448,   450,   454,   458,   462,
     466,   470,   474,   478,   482,   486,   490,   494,   498,   502,
     506,   510,   513,   517,   519,   524,   529,   534,   539,   544,
     549,   554,   559,   564,   569,   571,   573,   575,   579,   583,
     587,   591,   594,   598
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      92,     0,    -1,    -1,    92,    93,    -1,    23,    86,   119,
      87,    -1,    31,    86,   130,    87,    -1,    94,    -1,   120,
      -1,    67,   110,    87,    -1,   109,    -1,    -1,    40,    86,
      95,   105,    87,    -1,    -1,    40,     5,    86,    96,   105,
      87,    -1,    -1,    47,    86,    97,   117,    87,    -1,    -1,
      47,     5,    86,    98,   117,    87,    -1,    -1,    74,    86,
      99,   106,    87,    -1,    -1,    74,     5,    86,   100,   106,
      87,    -1,    -1,    77,    86,   101,   107,    87,    -1,    -1,
      77,     5,    86,   102,   107,    87,    -1,    -1,    50,    86,
     103,   108,    87,    -1,    -1,    50,     5,    86,   104,   108,
      87,    -1,    -1,    41,   131,    88,   131,    88,   131,   105,
      -1,    42,   131,    88,   131,    88,   131,   105,    -1,    43,
     131,    88,   131,    88,   131,   105,    -1,    44,   131,    88,
     131,    88,   131,   105,    -1,    45,   131,    88,   131,    88,
     131,   105,    -1,    46,   131,    88,   131,    88,   131,   105,
      -1,    -1,    75,   131,    88,   131,    88,   131,   106,    -1,
      76,   131,   106,    -1,    -1,    75,   131,    88,   131,    88,
     131,   107,    -1,    -1,    51,     5,   106,    -1,    61,    -1,
      62,    -1,    63,   131,    88,   131,    88,   131,    88,   131,
      -1,    64,   131,    88,   131,    88,   131,    -1,    65,   131,
      88,   131,    88,   131,    -1,    66,   131,    88,   131,    88,
     131,    -1,    -1,    68,    86,   111,   114,    -1,    -1,    71,
      86,   112,   115,    -1,    -1,    72,    86,   113,   116,    -1,
      -1,    32,   131,    88,   131,    88,   131,   114,    -1,    69,
     131,   114,    -1,    70,   131,    88,   131,    88,   131,   114,
      -1,    -1,    33,   131,    88,   131,    88,   131,   115,    -1,
      70,   131,    88,   131,    88,   131,   115,    -1,    73,   131,
      -1,    -1,    48,     5,    -1,    -1,    49,     5,   118,   117,
      -1,    -1,    25,   134,   119,    -1,    24,   134,   119,    -1,
      26,   131,    88,   131,    88,   131,   119,    -1,    27,   131,
     119,    -1,    28,   131,   119,    -1,    29,   131,   119,    -1,
      30,   131,   119,    -1,    -1,    52,    86,   121,   122,    87,
      -1,    -1,    53,   131,    88,   131,    88,   131,    -1,    -1,
      54,   131,    88,   131,    88,   131,   123,   122,    -1,    -1,
      55,   131,    88,   131,    88,   131,   124,   122,    -1,    -1,
      56,   131,    88,   131,    88,   131,   125,   122,    -1,    -1,
      59,   131,   126,   122,    -1,    -1,    57,   131,    88,   131,
      88,   131,   127,   122,    -1,    -1,    58,   131,    88,   131,
      88,   131,   128,   122,    -1,    -1,    60,   131,   129,   122,
      -1,    -1,    32,   131,    88,   131,    88,   131,   130,    -1,
      33,   131,    88,   131,    88,   131,   130,    -1,    34,   131,
      88,   131,    88,   131,   130,    -1,    35,   131,    88,   131,
      88,   131,   130,    -1,    36,   131,   130,    -1,    37,   131,
     130,    -1,    38,   131,   130,    -1,    39,   131,    88,   131,
      88,   131,   130,    -1,     3,    -1,   134,    -1,   132,    -1,
     131,    81,   131,    -1,   134,    81,   131,    -1,   131,    81,
     134,    -1,   131,    80,   131,    -1,   134,    80,   131,    -1,
     131,    80,   134,    -1,   131,    82,   131,    -1,   134,    82,
     131,    -1,   131,    82,   134,    -1,   131,    83,   131,    -1,
     134,    83,   131,    -1,   131,    83,   134,    -1,   131,    85,
     131,    -1,   134,    85,   131,    -1,   131,    85,   134,    -1,
      80,   131,    -1,    89,   131,    90,    -1,   133,    -1,    11,
      89,   131,    90,    -1,    10,    89,   131,    90,    -1,    12,
      89,   131,    90,    -1,    14,    89,   131,    90,    -1,    13,
      89,   131,    90,    -1,    15,    89,   131,    90,    -1,    17,
      89,   131,    90,    -1,    18,    89,   131,    90,    -1,    19,
      89,   131,    90,    -1,    20,    89,   131,    90,    -1,    21,
      -1,    22,    -1,     4,    -1,   134,    81,   134,    -1,   134,
      80,   134,    -1,   134,    82,   134,    -1,   134,    83,   134,
      -1,    80,   134,    -1,   134,    85,   134,    -1,    89,   134,
      90,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   173,   173,   174,   177,   178,   179,   180,   181,   182,
     187,   186,   202,   201,   226,   225,   240,   239,   263,   262,
     277,   276,   292,   291,   304,   303,   319,   318,   332,   331,
     346,   347,   349,   351,   353,   355,   357,   361,   362,   364,
     368,   369,   372,   373,   383,   384,   386,   388,   390,   392,
     396,   396,   397,   397,   398,   398,   401,   402,   404,   406,
     410,   411,   413,   417,   432,   433,   448,   447,   455,   456,
     458,   460,   462,   464,   466,   468,   479,   478,   485,   486,
     489,   488,   492,   491,   495,   494,   498,   497,   501,   500,
     504,   503,   507,   506,   511,   512,   514,   516,   518,   520,
     522,   524,   526,   530,   531,   532,   534,   535,   536,   538,
     539,   540,   542,   543,   544,   546,   547,   548,   550,   551,
     552,   554,   555,   556,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   572,   573,   576,   577,   578,   579,
     580,   581,   582,   583
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "REAL", "PARSE_INT", "STRING",
  "PARSE_TRUE", "PARSE_FALSE", "ENABLE", "DISABLE", "MATH_COS", "MATH_SIN",
  "MATH_TAN", "MATH_ACOS", "MATH_ASIN", "MATH_ATAN", "MATH_ATAN2",
  "MATH_LN", "MATH_LOG", "MATH_EXP", "MATH_SQRT", "MATH_E", "MATH_PI",
  "GLOBAL", "WIDTH", "HEIGHT", "BGCOLOR", "SAMPLESX", "SAMPLESY",
  "SHUTTERTIME", "PATHTRACE", "CAMERA", "POS", "DIR", "LOOKAT", "UP",
  "FOV", "APERTURESIZE", "FOCALLENGTH", "FOCALPOINT", "TRIANGLE", "V1",
  "V2", "V3", "N1", "N2", "N3", "MESH", "LOAD", "GROUP", "INSTANCE",
  "GEOMETRY", "MATERIAL_PHONG", "ME", "MA", "MD", "MS", "MR", "MT", "MSP",
  "INDEX", "PUSHMATRIX", "POPMATRIX", "ROTATE", "TRANSLATE", "SCALE",
  "VELOCITY", "LIGHT", "POINTLIGHT", "WATTAGE", "COLOR", "DIRLIGHT",
  "AREALIGHT", "INTENSITY", "SPHERE", "CENTER", "RADIUS", "SQUARE",
  "NORMAL", "'='", "'-'", "'+'", "'*'", "'/'", "NEG", "'^'", "'{'", "'}'",
  "','", "'('", "')'", "$accept", "input", "block", "objectTypes", "@1",
  "@2", "@3", "@4", "@5", "@6", "@7", "@8", "@9", "@10", "triangleOptions",
  "sphereOptions", "squareOptions", "instanceOptions", "transform",
  "lightTypes", "@11", "@12", "@13", "pointLightOptions",
  "dirLightOptions", "areaLightOptions", "meshOptions", "@14",
  "globalOptions", "materialTypes", "@15", "materialPhongOptions", "@16",
  "@17", "@18", "@19", "@20", "@21", "@22", "cameraOptions", "rExp",
  "fExp", "constantExp", "iExp", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,    61,
      45,    43,    42,    47,   334,    94,   123,   125,    44,    40,
      41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    91,    92,    92,    93,    93,    93,    93,    93,    93,
      95,    94,    96,    94,    97,    94,    98,    94,    99,    94,
     100,    94,   101,    94,   102,    94,   103,    94,   104,    94,
     105,   105,   105,   105,   105,   105,   105,   106,   106,   106,
     107,   107,   108,   108,   109,   109,   109,   109,   109,   109,
     111,   110,   112,   110,   113,   110,   114,   114,   114,   114,
     115,   115,   115,   116,   117,   117,   118,   117,   119,   119,
     119,   119,   119,   119,   119,   119,   121,   120,   122,   122,
     123,   122,   124,   122,   125,   122,   126,   122,   127,   122,
     128,   122,   129,   122,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   133,   133,   134,   134,   134,   134,
     134,   134,   134,   134
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     4,     4,     1,     1,     3,     1,
       0,     5,     0,     6,     0,     5,     0,     6,     0,     5,
       0,     6,     0,     5,     0,     6,     0,     5,     0,     6,
       0,     7,     7,     7,     7,     7,     7,     0,     7,     3,
       0,     7,     0,     3,     1,     1,     8,     6,     6,     6,
       0,     4,     0,     4,     0,     4,     0,     7,     3,     7,
       0,     7,     7,     2,     0,     2,     0,     4,     0,     3,
       3,     7,     3,     3,     3,     3,     0,     5,     0,     6,
       0,     8,     0,     8,     0,     8,     0,     4,     0,     8,
       0,     8,     0,     4,     0,     7,     7,     7,     7,     3,
       3,     3,     7,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     3,     1,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     1,     1,     1,     3,     3,     3,
       3,     2,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,    44,
      45,     0,     0,     0,     0,     0,     0,     0,     3,     6,
       9,     7,    68,    94,     0,    10,     0,    14,     0,    26,
      76,   103,   136,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   134,   135,     0,     0,     0,   105,   123,
     104,     0,     0,     0,     0,     0,     0,     0,     0,    18,
       0,    22,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    12,
      30,    16,    64,    28,    42,    78,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,   104,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    50,    52,    54,     8,    20,    37,
      24,    40,     0,     0,    68,    68,     0,    68,    68,    68,
      68,     4,     0,     0,     0,     0,    94,    94,    94,     0,
       5,    30,     0,     0,     0,     0,     0,     0,     0,    64,
       0,     0,     0,    42,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   122,   143,   109,   104,   106,
     104,   112,   104,   115,   104,   118,   104,     0,   110,   104,
     107,   104,   113,   104,   116,   104,   119,   104,     0,     0,
       0,    56,    60,     0,    37,     0,     0,     0,    40,     0,
       0,   141,     0,     0,     0,     0,     0,     0,    70,    69,
       0,    72,    73,    74,    75,     0,     0,     0,     0,    99,
     100,   101,     0,     0,     0,     0,     0,     0,     0,     0,
      11,     0,    65,    66,    15,     0,    37,    27,     0,     0,
       0,     0,     0,     0,    86,    92,    77,   125,   124,   126,
     128,   127,   129,   130,   131,   132,   133,     0,     0,     0,
       0,     0,     0,     0,    51,     0,     0,    53,     0,    55,
       0,     0,    37,    19,     0,     0,    23,   138,   137,   139,
     140,   142,     0,     0,     0,     0,     0,     0,    13,     0,
       0,     0,     0,     0,     0,    17,    64,    29,    43,     0,
       0,     0,     0,     0,     0,    78,    78,     0,    47,    48,
      49,     0,    56,     0,     0,     0,    63,    21,     0,    39,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    67,     0,     0,     0,     0,     0,
       0,    87,    93,     0,     0,    58,     0,     0,     0,     0,
       0,    68,    94,    94,    94,    94,    94,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    46,
       0,     0,     0,     0,     0,     0,    71,    95,    96,    97,
      98,   102,    30,    30,    30,    30,    30,    30,    79,    80,
      82,    84,    88,    90,     0,     0,     0,     0,    37,    40,
      31,    32,    33,    34,    35,    36,    78,    78,    78,    78,
      78,    56,    56,    60,    60,    38,    41,    81,    83,    85,
      89,    91,    57,    59,    61,    62
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    18,    19,    80,   141,    82,   149,   119,   204,
     121,   208,    84,   153,   148,   207,   210,   155,    20,    57,
     201,   202,   203,   274,   277,   279,   152,   306,    69,    21,
      85,   164,   416,   417,   418,   315,   419,   420,   316,    78,
      47,    48,    49,    50
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -340
static const yytype_int16 yypact[] =
{
    -340,   351,  -340,   -74,   -71,    17,    18,    23,   -65,  -340,
    -340,    27,    27,    27,    27,    -1,    24,    38,  -340,  -340,
    -340,  -340,  1010,   986,   -59,  -340,   -50,  -340,   -29,  -340,
    -340,  -340,  -340,   -16,    -3,    -2,    29,    32,    40,    69,
      76,    83,    91,  -340,  -340,    27,    27,   230,  -340,  -340,
     156,   434,   443,   452,    41,    95,   102,   103,   109,  -340,
     110,  -340,    28,    28,    27,    27,    27,    27,    27,   111,
      27,    27,    27,    27,    27,    27,    27,    27,   112,  -340,
     240,  -340,   -23,  -340,   150,   973,    27,    27,    27,    27,
      27,    27,    27,    27,    27,    27,   115,   124,   253,   295,
      27,    27,    27,    27,    27,    27,    27,    27,    27,    27,
      27,    27,    27,    27,  -340,  -340,  -340,  -340,  -340,    -7,
    -340,   135,    28,    28,   149,   149,   461,   224,   224,   224,
     224,  -340,   470,   479,   488,   497,   104,   104,   104,   506,
    -340,   240,    27,    27,    27,    27,    27,    27,   125,   -23,
     206,   214,   134,   150,   221,   146,    27,    27,    27,    27,
      27,    27,    27,    27,   148,   339,   350,   369,   375,   381,
     387,   393,   399,   405,   411,  -340,  -340,    43,    70,    43,
      70,   115,   124,   115,   124,   115,   124,   515,    43,    70,
      43,    70,   115,   124,   115,   124,   115,   124,   524,   533,
     542,   -19,     2,   169,    -7,    27,    27,   175,   135,    27,
     178,   193,   417,    28,    28,    28,    28,    28,  -340,  -340,
      27,  -340,  -340,  -340,  -340,    27,    27,    27,    27,  -340,
    -340,  -340,    27,   192,   551,   560,   569,   578,   587,   596,
    -340,   207,  -340,  -340,  -340,   208,    -7,  -340,   605,   614,
     623,   632,   641,   650,   267,   267,  -340,  -340,  -340,  -340,
    -340,  -340,  -340,  -340,  -340,  -340,  -340,    27,    27,    27,
      27,    27,    27,    27,  -340,    27,    27,  -340,    27,  -340,
     209,   659,   142,  -340,   216,   668,  -340,    74,    74,   193,
     193,   193,   677,   686,   695,   704,   713,   722,  -340,    27,
      27,    27,    27,    27,    27,  -340,   -23,  -340,  -340,    27,
      27,    27,    27,    27,    27,   973,   973,   731,   267,   267,
     267,   740,   122,   749,   758,   767,   267,  -340,    27,  -340,
    -340,    27,    27,    27,    27,    27,    27,    27,   776,   785,
     794,   803,   812,   821,  -340,   830,   839,   848,   857,   866,
     875,  -340,  -340,    27,    27,  -340,    27,    27,    27,   884,
     893,   224,   104,   104,   104,   104,   104,    27,    27,    27,
      27,    27,    27,    27,    27,    27,    27,    27,    27,   267,
     902,   911,   920,   929,    27,    27,  -340,  -340,  -340,  -340,
    -340,  -340,   363,   363,   363,   363,   363,   363,   267,   267,
     267,   267,   267,   267,    27,    27,    27,    27,   142,   428,
    -340,  -340,  -340,  -340,  -340,  -340,   973,   973,   973,   973,
     973,   122,   122,   247,   247,  -340,  -340,  -340,  -340,  -340,
    -340,  -340,  -340,  -340,  -340,  -340
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -340,  -340,  -340,  -340,  -340,  -340,  -340,  -340,  -340,  -340,
    -340,  -340,  -340,  -340,  -125,  -180,  -203,   140,  -340,  -340,
    -340,  -340,  -340,  -302,  -339,  -340,  -135,  -340,  -121,  -340,
    -340,  -305,  -340,  -340,  -340,  -340,  -340,  -340,  -340,  -119,
     -12,  -340,  -340,    60
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      51,    52,    53,   218,   219,   284,   221,   222,   223,   224,
     351,   352,    22,   271,   241,    23,   233,   229,   230,   231,
     355,    30,    24,    26,   280,   150,   151,    79,    28,    58,
      31,    32,    32,    96,    98,   275,    81,    33,    34,    35,
      36,    37,    38,    60,    39,    40,    41,    42,    43,    44,
     272,   273,   126,   127,   128,   129,   130,    83,   132,   133,
     134,   135,   136,   137,   138,   139,   308,    54,   205,   206,
      55,    56,   276,    86,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   434,   435,    87,    88,   177,   179,
     181,   183,   185,   187,   188,   190,   192,   194,   196,   198,
     199,   200,   329,    25,    27,    97,    99,    45,   122,    29,
      59,   427,   428,   429,   430,   431,    46,   123,    89,   432,
     433,    90,   124,   125,    61,   102,   103,   114,   104,    91,
     234,   235,   236,   237,   238,   239,    70,    71,    72,    73,
      74,    75,    76,    77,   248,   249,   250,   251,   252,   253,
     254,   255,   108,   109,   271,   110,   215,   216,    92,   217,
     178,   180,   182,   184,   186,    93,   189,   191,   193,   195,
     197,   344,    94,    62,    63,    64,    65,    66,    67,    68,
      95,   115,   211,   212,   100,   101,   102,   103,   116,   104,
     117,   272,   273,   281,   282,   118,   120,   285,   131,   140,
     104,   154,   100,   101,   102,   103,   426,   104,   292,   110,
     209,   242,   240,   293,   294,   295,   296,   205,   206,   243,
     297,   244,   100,   101,   102,   103,   246,   104,   425,   213,
     214,   215,   216,   247,   217,   256,   106,   107,   108,   109,
     386,   110,   278,   387,   388,   389,   390,   391,    62,    63,
      64,    65,    66,    67,    68,   317,   318,   319,   320,   321,
     322,   323,   283,   324,   325,   286,   326,   410,   411,   412,
     413,   414,   415,   287,   288,   289,   290,   291,   217,   298,
     275,   142,   143,   144,   145,   146,   147,   338,   339,   340,
     341,   342,   343,   245,   305,   307,   327,   345,   346,   347,
     348,   349,   350,   330,   100,   101,   102,   103,     0,   104,
     100,   101,   102,   103,     0,   104,   359,   276,   105,   360,
     361,   362,   363,   364,   365,   366,     0,   100,   101,   102,
     103,     0,   104,   100,   101,   102,   103,     0,   104,     0,
       0,   379,   380,   175,   381,   382,   383,   100,   101,   102,
     103,     2,   104,     0,     0,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,   403,     0,     0,     0,
       0,     0,   408,   409,     3,   106,   107,   108,   109,     0,
     110,     0,     4,     0,     0,   176,     0,     0,     0,     0,
       0,     5,   421,   422,   423,   424,     0,     0,     6,     0,
       0,     7,     0,     8,   142,   143,   144,   145,   146,   147,
       0,     0,     9,    10,    11,    12,    13,    14,    15,   100,
     101,   102,   103,     0,   104,    16,     0,     0,    17,   257,
     100,   101,   102,   103,     0,   104,     0,     0,     0,     0,
     258,     0,     0,   100,   101,   102,   103,     0,   104,   100,
     101,   102,   103,     0,   104,   100,   101,   102,   103,   259,
     104,   100,   101,   102,   103,   260,   104,   100,   101,   102,
     103,   261,   104,   100,   101,   102,   103,   262,   104,   100,
     101,   102,   103,   263,   104,   100,   101,   102,   103,   264,
     104,   100,   101,   102,   103,   265,   104,   213,   214,   215,
     216,   266,   217,   209,     0,     0,     0,   176,   100,   101,
     102,   103,     0,   104,   100,   101,   102,   103,     0,   104,
       0,     0,   111,   100,   101,   102,   103,     0,   104,     0,
       0,   112,   100,   101,   102,   103,     0,   104,     0,     0,
     113,   100,   101,   102,   103,     0,   104,     0,     0,   220,
     100,   101,   102,   103,     0,   104,     0,     0,   225,   100,
     101,   102,   103,     0,   104,     0,     0,   226,   100,   101,
     102,   103,     0,   104,     0,     0,   227,   100,   101,   102,
     103,     0,   104,     0,     0,   228,   100,   101,   102,   103,
       0,   104,     0,     0,   232,   100,   101,   102,   103,     0,
     104,     0,     0,   267,   100,   101,   102,   103,     0,   104,
       0,     0,   268,   100,   101,   102,   103,     0,   104,     0,
       0,   269,   100,   101,   102,   103,     0,   104,     0,     0,
     270,   100,   101,   102,   103,     0,   104,     0,     0,   299,
     100,   101,   102,   103,     0,   104,     0,     0,   300,   100,
     101,   102,   103,     0,   104,     0,     0,   301,   100,   101,
     102,   103,     0,   104,     0,     0,   302,   100,   101,   102,
     103,     0,   104,     0,     0,   303,   100,   101,   102,   103,
       0,   104,     0,     0,   304,   100,   101,   102,   103,     0,
     104,     0,     0,   309,   100,   101,   102,   103,     0,   104,
       0,     0,   310,   100,   101,   102,   103,     0,   104,     0,
       0,   311,   100,   101,   102,   103,     0,   104,     0,     0,
     312,   100,   101,   102,   103,     0,   104,     0,     0,   313,
     100,   101,   102,   103,     0,   104,     0,     0,   314,   100,
     101,   102,   103,     0,   104,     0,     0,   328,   100,   101,
     102,   103,     0,   104,     0,     0,   331,   100,   101,   102,
     103,     0,   104,     0,     0,   332,   100,   101,   102,   103,
       0,   104,     0,     0,   333,   100,   101,   102,   103,     0,
     104,     0,     0,   334,   100,   101,   102,   103,     0,   104,
       0,     0,   335,   100,   101,   102,   103,     0,   104,     0,
       0,   336,   100,   101,   102,   103,     0,   104,     0,     0,
     337,   100,   101,   102,   103,     0,   104,     0,     0,   353,
     100,   101,   102,   103,     0,   104,     0,     0,   354,   100,
     101,   102,   103,     0,   104,     0,     0,   356,   100,   101,
     102,   103,     0,   104,     0,     0,   357,   100,   101,   102,
     103,     0,   104,     0,     0,   358,   100,   101,   102,   103,
       0,   104,     0,     0,   367,   100,   101,   102,   103,     0,
     104,     0,     0,   368,   100,   101,   102,   103,     0,   104,
       0,     0,   369,   100,   101,   102,   103,     0,   104,     0,
       0,   370,   100,   101,   102,   103,     0,   104,     0,     0,
     371,   100,   101,   102,   103,     0,   104,     0,     0,   372,
     100,   101,   102,   103,     0,   104,     0,     0,   373,   100,
     101,   102,   103,     0,   104,     0,     0,   374,   100,   101,
     102,   103,     0,   104,     0,     0,   375,   100,   101,   102,
     103,     0,   104,     0,     0,   376,   100,   101,   102,   103,
       0,   104,     0,     0,   377,   100,   101,   102,   103,     0,
     104,     0,     0,   378,   100,   101,   102,   103,     0,   104,
       0,     0,   384,   100,   101,   102,   103,     0,   104,     0,
       0,   385,   100,   101,   102,   103,     0,   104,     0,     0,
     404,   100,   101,   102,   103,     0,   104,     0,     0,   405,
     100,   101,   102,   103,     0,   104,     0,     0,   406,   100,
     101,   102,   103,     0,   104,     0,     0,   407,    70,    71,
      72,    73,    74,    75,    76,    77,   156,   157,   158,   159,
     160,   161,   162,   163,    62,    63,    64,    65,    66,    67,
      68
};

static const yytype_int16 yycheck[] =
{
      12,    13,    14,   124,   125,   208,   127,   128,   129,   130,
     315,   316,    86,    32,   149,    86,   141,   136,   137,   138,
     322,    86,     5,     5,   204,    48,    49,    86,     5,     5,
       3,     4,     4,    45,    46,    33,    86,    10,    11,    12,
      13,    14,    15,     5,    17,    18,    19,    20,    21,    22,
      69,    70,    64,    65,    66,    67,    68,    86,    70,    71,
      72,    73,    74,    75,    76,    77,   246,    68,    75,    76,
      71,    72,    70,    89,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,   423,   424,    89,    89,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   282,    86,    86,    45,    46,    80,    80,    86,
      86,   416,   417,   418,   419,   420,    89,    89,    89,   421,
     422,    89,    62,    63,    86,    82,    83,    86,    85,    89,
     142,   143,   144,   145,   146,   147,    32,    33,    34,    35,
      36,    37,    38,    39,   156,   157,   158,   159,   160,   161,
     162,   163,    82,    83,    32,    85,    82,    83,    89,    85,
     100,   101,   102,   103,   104,    89,   106,   107,   108,   109,
     110,   306,    89,    24,    25,    26,    27,    28,    29,    30,
      89,    86,   122,   123,    80,    81,    82,    83,    86,    85,
      87,    69,    70,   205,   206,    86,    86,   209,    87,    87,
      85,    51,    80,    81,    82,    83,   409,    85,   220,    85,
      75,     5,    87,   225,   226,   227,   228,    75,    76,     5,
     232,    87,    80,    81,    82,    83,     5,    85,   408,    80,
      81,    82,    83,    87,    85,    87,    80,    81,    82,    83,
     361,    85,    73,   362,   363,   364,   365,   366,    24,    25,
      26,    27,    28,    29,    30,   267,   268,   269,   270,   271,
     272,   273,    87,   275,   276,    87,   278,   392,   393,   394,
     395,   396,   397,   213,   214,   215,   216,   217,    85,    87,
      33,    41,    42,    43,    44,    45,    46,   299,   300,   301,
     302,   303,   304,   153,    87,    87,    87,   309,   310,   311,
     312,   313,   314,    87,    80,    81,    82,    83,    -1,    85,
      80,    81,    82,    83,    -1,    85,   328,    70,    88,   331,
     332,   333,   334,   335,   336,   337,    -1,    80,    81,    82,
      83,    -1,    85,    80,    81,    82,    83,    -1,    85,    -1,
      -1,   353,   354,    90,   356,   357,   358,    80,    81,    82,
      83,     0,    85,    -1,    -1,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,    -1,    -1,    -1,
      -1,    -1,   384,   385,    23,    80,    81,    82,    83,    -1,
      85,    -1,    31,    -1,    -1,    90,    -1,    -1,    -1,    -1,
      -1,    40,   404,   405,   406,   407,    -1,    -1,    47,    -1,
      -1,    50,    -1,    52,    41,    42,    43,    44,    45,    46,
      -1,    -1,    61,    62,    63,    64,    65,    66,    67,    80,
      81,    82,    83,    -1,    85,    74,    -1,    -1,    77,    90,
      80,    81,    82,    83,    -1,    85,    -1,    -1,    -1,    -1,
      90,    -1,    -1,    80,    81,    82,    83,    -1,    85,    80,
      81,    82,    83,    -1,    85,    80,    81,    82,    83,    90,
      85,    80,    81,    82,    83,    90,    85,    80,    81,    82,
      83,    90,    85,    80,    81,    82,    83,    90,    85,    80,
      81,    82,    83,    90,    85,    80,    81,    82,    83,    90,
      85,    80,    81,    82,    83,    90,    85,    80,    81,    82,
      83,    90,    85,    75,    -1,    -1,    -1,    90,    80,    81,
      82,    83,    -1,    85,    80,    81,    82,    83,    -1,    85,
      -1,    -1,    88,    80,    81,    82,    83,    -1,    85,    -1,
      -1,    88,    80,    81,    82,    83,    -1,    85,    -1,    -1,
      88,    80,    81,    82,    83,    -1,    85,    -1,    -1,    88,
      80,    81,    82,    83,    -1,    85,    -1,    -1,    88,    80,
      81,    82,    83,    -1,    85,    -1,    -1,    88,    80,    81,
      82,    83,    -1,    85,    -1,    -1,    88,    80,    81,    82,
      83,    -1,    85,    -1,    -1,    88,    80,    81,    82,    83,
      -1,    85,    -1,    -1,    88,    80,    81,    82,    83,    -1,
      85,    -1,    -1,    88,    80,    81,    82,    83,    -1,    85,
      -1,    -1,    88,    80,    81,    82,    83,    -1,    85,    -1,
      -1,    88,    80,    81,    82,    83,    -1,    85,    -1,    -1,
      88,    80,    81,    82,    83,    -1,    85,    -1,    -1,    88,
      80,    81,    82,    83,    -1,    85,    -1,    -1,    88,    80,
      81,    82,    83,    -1,    85,    -1,    -1,    88,    80,    81,
      82,    83,    -1,    85,    -1,    -1,    88,    80,    81,    82,
      83,    -1,    85,    -1,    -1,    88,    80,    81,    82,    83,
      -1,    85,    -1,    -1,    88,    80,    81,    82,    83,    -1,
      85,    -1,    -1,    88,    80,    81,    82,    83,    -1,    85,
      -1,    -1,    88,    80,    81,    82,    83,    -1,    85,    -1,
      -1,    88,    80,    81,    82,    83,    -1,    85,    -1,    -1,
      88,    80,    81,    82,    83,    -1,    85,    -1,    -1,    88,
      80,    81,    82,    83,    -1,    85,    -1,    -1,    88,    80,
      81,    82,    83,    -1,    85,    -1,    -1,    88,    80,    81,
      82,    83,    -1,    85,    -1,    -1,    88,    80,    81,    82,
      83,    -1,    85,    -1,    -1,    88,    80,    81,    82,    83,
      -1,    85,    -1,    -1,    88,    80,    81,    82,    83,    -1,
      85,    -1,    -1,    88,    80,    81,    82,    83,    -1,    85,
      -1,    -1,    88,    80,    81,    82,    83,    -1,    85,    -1,
      -1,    88,    80,    81,    82,    83,    -1,    85,    -1,    -1,
      88,    80,    81,    82,    83,    -1,    85,    -1,    -1,    88,
      80,    81,    82,    83,    -1,    85,    -1,    -1,    88,    80,
      81,    82,    83,    -1,    85,    -1,    -1,    88,    80,    81,
      82,    83,    -1,    85,    -1,    -1,    88,    80,    81,    82,
      83,    -1,    85,    -1,    -1,    88,    80,    81,    82,    83,
      -1,    85,    -1,    -1,    88,    80,    81,    82,    83,    -1,
      85,    -1,    -1,    88,    80,    81,    82,    83,    -1,    85,
      -1,    -1,    88,    80,    81,    82,    83,    -1,    85,    -1,
      -1,    88,    80,    81,    82,    83,    -1,    85,    -1,    -1,
      88,    80,    81,    82,    83,    -1,    85,    -1,    -1,    88,
      80,    81,    82,    83,    -1,    85,    -1,    -1,    88,    80,
      81,    82,    83,    -1,    85,    -1,    -1,    88,    80,    81,
      82,    83,    -1,    85,    -1,    -1,    88,    80,    81,    82,
      83,    -1,    85,    -1,    -1,    88,    80,    81,    82,    83,
      -1,    85,    -1,    -1,    88,    80,    81,    82,    83,    -1,
      85,    -1,    -1,    88,    80,    81,    82,    83,    -1,    85,
      -1,    -1,    88,    80,    81,    82,    83,    -1,    85,    -1,
      -1,    88,    80,    81,    82,    83,    -1,    85,    -1,    -1,
      88,    80,    81,    82,    83,    -1,    85,    -1,    -1,    88,
      80,    81,    82,    83,    -1,    85,    -1,    -1,    88,    80,
      81,    82,    83,    -1,    85,    -1,    -1,    88,    32,    33,
      34,    35,    36,    37,    38,    39,    53,    54,    55,    56,
      57,    58,    59,    60,    24,    25,    26,    27,    28,    29,
      30
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    92,     0,    23,    31,    40,    47,    50,    52,    61,
      62,    63,    64,    65,    66,    67,    74,    77,    93,    94,
     109,   120,    86,    86,     5,    86,     5,    86,     5,    86,
      86,     3,     4,    10,    11,    12,    13,    14,    15,    17,
      18,    19,    20,    21,    22,    80,    89,   131,   132,   133,
     134,   131,   131,   131,    68,    71,    72,   110,     5,    86,
       5,    86,    24,    25,    26,    27,    28,    29,    30,   119,
      32,    33,    34,    35,    36,    37,    38,    39,   130,    86,
      95,    86,    97,    86,   103,   121,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,   131,   134,   131,   134,
      80,    81,    82,    83,    85,    88,    80,    81,    82,    83,
      85,    88,    88,    88,    86,    86,    86,    87,    86,    99,
      86,   101,    80,    89,   134,   134,   131,   131,   131,   131,
     131,    87,   131,   131,   131,   131,   131,   131,   131,   131,
      87,    96,    41,    42,    43,    44,    45,    46,   105,    98,
      48,    49,   117,   104,    51,   108,    53,    54,    55,    56,
      57,    58,    59,    60,   122,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,    90,    90,   131,   134,   131,
     134,   131,   134,   131,   134,   131,   134,   131,   131,   134,
     131,   134,   131,   134,   131,   134,   131,   134,   131,   131,
     131,   111,   112,   113,   100,    75,    76,   106,   102,    75,
     107,   134,   134,    80,    81,    82,    83,    85,   119,   119,
      88,   119,   119,   119,   119,    88,    88,    88,    88,   130,
     130,   130,    88,   105,   131,   131,   131,   131,   131,   131,
      87,   117,     5,     5,    87,   108,     5,    87,   131,   131,
     131,   131,   131,   131,   131,   131,    87,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    88,    88,    88,
      88,    32,    69,    70,   114,    33,    70,   115,    73,   116,
     106,   131,   131,    87,   107,   131,    87,   134,   134,   134,
     134,   134,   131,   131,   131,   131,   131,   131,    87,    88,
      88,    88,    88,    88,    88,    87,   118,    87,   106,    88,
      88,    88,    88,    88,    88,   126,   129,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,    87,    88,   106,
      87,    88,    88,    88,    88,    88,    88,    88,   131,   131,
     131,   131,   131,   131,   117,   131,   131,   131,   131,   131,
     131,   122,   122,    88,    88,   114,    88,    88,    88,   131,
     131,   131,   131,   131,   131,   131,   131,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,   131,
     131,   131,   131,   131,    88,    88,   119,   130,   130,   130,
     130,   130,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,    88,    88,    88,    88,   131,   131,
     105,   105,   105,   105,   105,   105,   123,   124,   125,   127,
     128,   131,   131,   131,   131,   106,   107,   122,   122,   122,
     122,   122,   114,   114,   115,   115
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 8:
#line 181 "../parse.y"
    { g_pScene->AddLight(pLight); pLight = 0; ;}
    break;

  case 10:
#line 187 "../parse.y"
    {
                pObj = new TriangleMesh;
                pObj->SetMaterial (pMat);
                pObj->SetVelocity(g_Vel);
                pObj->SetTransformation(GetCTM());
                ((TriangleMesh*)pObj)->CreateSingleTriangle();
            ;}
    break;

  case 11:
#line 195 "../parse.y"
    {
                if (pObj)
                    g_pScene->AddObject(pObj);
                pObj = 0;
            ;}
    break;

  case 12:
#line 202 "../parse.y"
    {
                pBSP = new BSPTree;
                pBSP->SetMaterial (pMat);
                g_objectMap[(yyvsp[(2) - (3)].str)] = pBSP;

                pObj = new TriangleMesh;
                pObj->SetMaterial (pMat);
                pObj->SetVelocity(g_Vel);
                pObj->SetTransformation(GetCTM());
                ((TriangleMesh*)pObj)->CreateSingleTriangle();
            ;}
    break;

  case 13:
#line 214 "../parse.y"
    {
                if (pObj && pBSP)
                {
                    pBSP->AddObject (pObj);
                    g_pScene->AddObject(pBSP);
                }
                pObj = 0;
                pBSP = 0;
            ;}
    break;

  case 14:
#line 226 "../parse.y"
    {
                pObj = new TriangleMesh;
                pObj->SetMaterial (pMat);
                pObj->SetVelocity(g_Vel);
                pObj->SetTransformation(GetCTM());
            ;}
    break;

  case 15:
#line 233 "../parse.y"
    {
                if (pObj)
                    g_pScene->AddObject(pObj);
                pObj = 0;
            ;}
    break;

  case 16:
#line 240 "../parse.y"
    {
                pBSP = new BSPTree;
                pBSP->SetMaterial (pMat);
                g_objectMap[(yyvsp[(2) - (3)].str)] = pBSP;

                pObj = new TriangleMesh;
                pObj->SetMaterial (pMat);
                pObj->SetVelocity(g_Vel);
                pObj->SetTransformation(GetCTM());
            ;}
    break;

  case 17:
#line 251 "../parse.y"
    {
                if (pObj && pBSP)
                {
                    pBSP->AddObject (pObj);
                    g_pScene->AddObject(pBSP);
                }
                pObj = 0;
                pBSP = 0;
            ;}
    break;

  case 18:
#line 263 "../parse.y"
    {
                pObj = new Sphere;
                pObj->SetMaterial (pMat);
                pObj->SetVelocity(g_Vel);
                pObj->SetTransformation(GetCTM());
            ;}
    break;

  case 19:
#line 270 "../parse.y"
    {
                if (pObj)
                    g_pScene->AddObject(pObj);
                pObj = 0;
            ;}
    break;

  case 20:
#line 277 "../parse.y"
    {
                pObj = new Sphere;
                pObj->SetMaterial (pMat);
                pObj->SetVelocity(g_Vel);
                pObj->SetTransformation(GetCTM());
                g_objectMap[(yyvsp[(2) - (3)].str)] = pObj;
            ;}
    break;

  case 21:
#line 285 "../parse.y"
    {
                if (pObj)
                    g_pScene->AddObject(pObj);
                pObj = 0;
            ;}
    break;

  case 22:
#line 292 "../parse.y"
    {
                pObj = new Square;
                pObj->SetMaterial (pMat);
                pObj->SetVelocity(g_Vel);
                pObj->SetTransformation(GetCTM());
            ;}
    break;

  case 23:
#line 298 "../parse.y"
    {
                if (pObj)
                    g_pScene->AddObject(pObj);
                pObj = 0;
            ;}
    break;

  case 24:
#line 304 "../parse.y"
    {
                pObj = new Square;
                pObj->SetMaterial (pMat);
                pObj->SetVelocity(g_Vel);
                pObj->SetTransformation(GetCTM());
                g_objectMap[(yyvsp[(2) - (3)].str)] = pObj;
            ;}
    break;

  case 25:
#line 311 "../parse.y"
    {
                if (pObj)
                    g_pScene->AddObject(pObj);
                pObj = 0;
            ;}
    break;

  case 26:
#line 319 "../parse.y"
    {
                pObj = new Instance;
                pObj->SetMaterial (pMat);
                pObj->SetVelocity(g_Vel);
            ;}
    break;

  case 27:
#line 325 "../parse.y"
    {
                if (pObj)
                    g_pScene->AddObject(pObj);
                pObj = 0;
            ;}
    break;

  case 28:
#line 332 "../parse.y"
    {
                pObj = new Instance;
                pObj->SetMaterial (pMat);
                pObj->SetVelocity(g_Vel);
                g_objectMap[(yyvsp[(2) - (3)].str)] = pObj;
            ;}
    break;

  case 29:
#line 339 "../parse.y"
    {
                if (pObj)
                    g_pScene->AddObject(pObj);
                pObj = 0;
            ;}
    break;

  case 31:
#line 348 "../parse.y"
    {((TriangleMesh*)pObj)->SetV1(Vertex3((yyvsp[(2) - (7)].real), (yyvsp[(4) - (7)].real), (yyvsp[(6) - (7)].real)));;}
    break;

  case 32:
#line 350 "../parse.y"
    {((TriangleMesh*)pObj)->SetV2(Vertex3((yyvsp[(2) - (7)].real), (yyvsp[(4) - (7)].real), (yyvsp[(6) - (7)].real)));;}
    break;

  case 33:
#line 352 "../parse.y"
    {((TriangleMesh*)pObj)->SetV3(Vertex3((yyvsp[(2) - (7)].real), (yyvsp[(4) - (7)].real), (yyvsp[(6) - (7)].real)));;}
    break;

  case 34:
#line 354 "../parse.y"
    {((TriangleMesh*)pObj)->SetN1(Vertex3((yyvsp[(2) - (7)].real), (yyvsp[(4) - (7)].real), (yyvsp[(6) - (7)].real)));;}
    break;

  case 35:
#line 356 "../parse.y"
    {((TriangleMesh*)pObj)->SetN2(Vertex3((yyvsp[(2) - (7)].real), (yyvsp[(4) - (7)].real), (yyvsp[(6) - (7)].real)));;}
    break;

  case 36:
#line 358 "../parse.y"
    {((TriangleMesh*)pObj)->SetN3(Vertex3((yyvsp[(2) - (7)].real), (yyvsp[(4) - (7)].real), (yyvsp[(6) - (7)].real)));;}
    break;

  case 38:
#line 363 "../parse.y"
    {((Sphere*)pObj)->SetCenter(Vector3((yyvsp[(2) - (7)].real), (yyvsp[(4) - (7)].real), (yyvsp[(6) - (7)].real)));;}
    break;

  case 39:
#line 365 "../parse.y"
    {((Sphere*)pObj)->SetRadius((yyvsp[(2) - (3)].real));;}
    break;

  case 41:
#line 370 "../parse.y"
    { ( (Square*) pObj)->SetCenter(Vector3((yyvsp[(2) - (7)].real),(yyvsp[(4) - (7)].real),(yyvsp[(6) - (7)].real)));;}
    break;

  case 43:
#line 374 "../parse.y"
    {
                std::map<std::string, Object*>::const_iterator it = g_objectMap.find ((yyvsp[(2) - (3)].str));
                if (it != g_objectMap.end ())
                {
                    ((Instance*)pObj)->SetGeometry(it->second, GetCTM());
                }
            ;}
    break;

  case 44:
#line 383 "../parse.y"
    { PushMatrix(); ;}
    break;

  case 45:
#line 385 "../parse.y"
    {PopMatrix();;}
    break;

  case 46:
#line 387 "../parse.y"
    {Rotate((yyvsp[(2) - (8)].real), (yyvsp[(4) - (8)].real), (yyvsp[(6) - (8)].real), (yyvsp[(8) - (8)].real));;}
    break;

  case 47:
#line 389 "../parse.y"
    {Translate((yyvsp[(2) - (6)].real), (yyvsp[(4) - (6)].real), (yyvsp[(6) - (6)].real));;}
    break;

  case 48:
#line 391 "../parse.y"
    {Scale((yyvsp[(2) - (6)].real), (yyvsp[(4) - (6)].real), (yyvsp[(6) - (6)].real));;}
    break;

  case 49:
#line 393 "../parse.y"
    { g_Vel = Vector3((yyvsp[(2) - (6)].real),(yyvsp[(4) - (6)].real),(yyvsp[(6) - (6)].real)); ;}
    break;

  case 50:
#line 396 "../parse.y"
    {pLight = new PointLight;;}
    break;

  case 52:
#line 397 "../parse.y"
    {pLight = new DirectionalLight; ;}
    break;

  case 54:
#line 398 "../parse.y"
    { pLight = new AreaLight; ;}
    break;

  case 57:
#line 403 "../parse.y"
    { ((PointLight*)pLight)->SetPosition(Vertex3((yyvsp[(2) - (7)].real), (yyvsp[(4) - (7)].real), (yyvsp[(6) - (7)].real)));;}
    break;

  case 58:
#line 405 "../parse.y"
    { ((PointLight*)pLight)->SetWattage((yyvsp[(2) - (3)].real));;}
    break;

  case 59:
#line 407 "../parse.y"
    { ((PointLight*)pLight)->SetColor(Vector3((yyvsp[(2) - (7)].real), (yyvsp[(4) - (7)].real), (yyvsp[(6) - (7)].real)));;}
    break;

  case 61:
#line 412 "../parse.y"
    { ((DirectionalLight*)pLight)->SetDirection(Vector3((yyvsp[(2) - (7)].real), (yyvsp[(4) - (7)].real), (yyvsp[(6) - (7)].real))); ;}
    break;

  case 62:
#line 414 "../parse.y"
    { ((DirectionalLight*)pLight)->SetColor(Color3((yyvsp[(2) - (7)].real), (yyvsp[(4) - (7)].real), (yyvsp[(6) - (7)].real))); ;}
    break;

  case 63:
#line 418 "../parse.y"
    { 
                ((AreaLight*)pLight)->SetIntensity((yyvsp[(2) - (2)].real));
                
                pObj = new Square;
                pObj->SetMaterial (pMat);
                pObj->SetVelocity(g_Vel);
                pObj->SetTransformation(GetCTM());
                
                g_pScene->AddObject(pObj);
                ((AreaLight*)pLight)->SetObject((Square*)pObj);
            ;}
    break;

  case 65:
#line 434 "../parse.y"
    {
                (yyvsp[(2) - (2)].str)[strlen((yyvsp[(2) - (2)].str))-1]=0;
                char* s = &(yyvsp[(2) - (2)].str)[1];
                if (!g){
                    if (!((TriangleMesh*)pObj)->Load(s))
                        pObj = 0;
                }else{
                    if (!((TriangleMesh*)pObj)->Load(s,g))
                        pObj = 0;
                }
                g=0;
                delete [] (yyvsp[(2) - (2)].str);
            ;}
    break;

  case 66:
#line 448 "../parse.y"
    {
                (yyvsp[(2) - (2)].str)[strlen((yyvsp[(2) - (2)].str))-1]=0;
                char* s = &(yyvsp[(2) - (2)].str)[1];
                g = s;
            ;}
    break;

  case 69:
#line 457 "../parse.y"
    { g_pImage->Resize(g_pImage->Width(), (yyvsp[(2) - (3)].integer)); ;}
    break;

  case 70:
#line 459 "../parse.y"
    { g_pImage->Resize((yyvsp[(2) - (3)].integer), g_pImage->Height()); ;}
    break;

  case 71:
#line 461 "../parse.y"
    { g_pCamera->SetBGColor(Vector3((yyvsp[(2) - (7)].real), (yyvsp[(4) - (7)].real), (yyvsp[(6) - (7)].real))); ;}
    break;

  case 72:
#line 463 "../parse.y"
    { g_pScene->SetSamplesX((yyvsp[(2) - (3)].real));;}
    break;

  case 73:
#line 465 "../parse.y"
    {g_pScene->SetSamplesY((yyvsp[(2) - (3)].real));;}
    break;

  case 74:
#line 467 "../parse.y"
    { g_pScene->SetShutterTime((yyvsp[(2) - (3)].real));;}
    break;

  case 75:
#line 469 "../parse.y"
    {
                if ((yyvsp[(2) - (3)].real)==0)
                    g_pScene->SetPathTrace(false);
                else
                    g_pScene->SetPathTrace(true);
            ;}
    break;

  case 76:
#line 479 "../parse.y"
    {
            pMat = new PhongMaterial;
          ;}
    break;

  case 79:
#line 487 "../parse.y"
    { ( (PhongMaterial*) pMat)->SetEmissive(Color3((yyvsp[(2) - (6)].real),(yyvsp[(4) - (6)].real),(yyvsp[(6) - (6)].real)));;}
    break;

  case 80:
#line 489 "../parse.y"
    {((PhongMaterial*)pMat)->SetAmbient(Color3((yyvsp[(2) - (6)].real),(yyvsp[(4) - (6)].real),(yyvsp[(6) - (6)].real)));;}
    break;

  case 82:
#line 492 "../parse.y"
    {((PhongMaterial*)pMat)->SetDiffuse(Color3((yyvsp[(2) - (6)].real),(yyvsp[(4) - (6)].real),(yyvsp[(6) - (6)].real)));;}
    break;

  case 84:
#line 495 "../parse.y"
    {((PhongMaterial*)pMat)->SetSpecular(Color3((yyvsp[(2) - (6)].real),(yyvsp[(4) - (6)].real),(yyvsp[(6) - (6)].real)));;}
    break;

  case 86:
#line 498 "../parse.y"
    {((PhongMaterial*)pMat)->SetMetalness((yyvsp[(2) - (2)].real));;}
    break;

  case 88:
#line 501 "../parse.y"
    {((PhongMaterial*)pMat)->SetReflectence(Color3((yyvsp[(2) - (6)].real),(yyvsp[(4) - (6)].real),(yyvsp[(6) - (6)].real)));;}
    break;

  case 90:
#line 504 "../parse.y"
    {((PhongMaterial*)pMat)->SetTransmittance(Color3((yyvsp[(2) - (6)].real),(yyvsp[(4) - (6)].real),(yyvsp[(6) - (6)].real)));;}
    break;

  case 92:
#line 507 "../parse.y"
    { ((PhongMaterial*)pMat)->SetIndex((yyvsp[(2) - (2)].real));;}
    break;

  case 95:
#line 513 "../parse.y"
    {g_pCamera->SetEye(Vector3((yyvsp[(2) - (7)].real), (yyvsp[(4) - (7)].real), (yyvsp[(6) - (7)].real)));;}
    break;

  case 96:
#line 515 "../parse.y"
    {g_pCamera->SetViewDir(Vector3((yyvsp[(2) - (7)].real), (yyvsp[(4) - (7)].real), (yyvsp[(6) - (7)].real)));;}
    break;

  case 97:
#line 517 "../parse.y"
    {g_pCamera->SetLookAt(Vector3((yyvsp[(2) - (7)].real), (yyvsp[(4) - (7)].real), (yyvsp[(6) - (7)].real)));;}
    break;

  case 98:
#line 519 "../parse.y"
    {g_pCamera->SetUp(Vector3((yyvsp[(2) - (7)].real), (yyvsp[(4) - (7)].real), (yyvsp[(6) - (7)].real)));;}
    break;

  case 99:
#line 521 "../parse.y"
    {g_pCamera->SetFOV((yyvsp[(2) - (3)].real));;}
    break;

  case 100:
#line 523 "../parse.y"
    { g_pCamera->SetApertureSize((yyvsp[(2) - (3)].real));;}
    break;

  case 101:
#line 525 "../parse.y"
    { g_pCamera->SetFocalLength((yyvsp[(2) - (3)].real));;}
    break;

  case 102:
#line 527 "../parse.y"
    { g_pCamera->SetFocalPoint(Vector3((yyvsp[(2) - (7)].real),(yyvsp[(4) - (7)].real),(yyvsp[(6) - (7)].real)));;}
    break;

  case 103:
#line 530 "../parse.y"
    { (yyval.real) = (yyvsp[(1) - (1)].real);             ;}
    break;

  case 104:
#line 531 "../parse.y"
    { (yyval.real) = (yyvsp[(1) - (1)].integer);             ;}
    break;

  case 105:
#line 532 "../parse.y"
    { (yyval.real) = (yyvsp[(1) - (1)].real);             ;}
    break;

  case 106:
#line 534 "../parse.y"
    { (yyval.real) = (yyvsp[(1) - (3)].real) + (yyvsp[(3) - (3)].real);        ;}
    break;

  case 107:
#line 535 "../parse.y"
    { (yyval.real) = (yyvsp[(1) - (3)].integer) + (yyvsp[(3) - (3)].real);        ;}
    break;

  case 108:
#line 536 "../parse.y"
    { (yyval.real) = (yyvsp[(1) - (3)].real) + (yyvsp[(3) - (3)].integer);        ;}
    break;

  case 109:
#line 538 "../parse.y"
    { (yyval.real) = (yyvsp[(1) - (3)].real) - (yyvsp[(3) - (3)].real);        ;}
    break;

  case 110:
#line 539 "../parse.y"
    { (yyval.real) = (yyvsp[(1) - (3)].integer) - (yyvsp[(3) - (3)].real);        ;}
    break;

  case 111:
#line 540 "../parse.y"
    { (yyval.real) = (yyvsp[(1) - (3)].real) - (yyvsp[(3) - (3)].integer);        ;}
    break;

  case 112:
#line 542 "../parse.y"
    { (yyval.real) = (yyvsp[(1) - (3)].real) * (yyvsp[(3) - (3)].real);        ;}
    break;

  case 113:
#line 543 "../parse.y"
    { (yyval.real) = (yyvsp[(1) - (3)].integer) * (yyvsp[(3) - (3)].real);        ;}
    break;

  case 114:
#line 544 "../parse.y"
    { (yyval.real) = (yyvsp[(1) - (3)].real) * (yyvsp[(3) - (3)].integer);        ;}
    break;

  case 115:
#line 546 "../parse.y"
    { (yyval.real) = (yyvsp[(1) - (3)].real) / (yyvsp[(3) - (3)].real);        ;}
    break;

  case 116:
#line 547 "../parse.y"
    { (yyval.real) = (yyvsp[(1) - (3)].integer) / (yyvsp[(3) - (3)].real);        ;}
    break;

  case 117:
#line 548 "../parse.y"
    { (yyval.real) = (yyvsp[(1) - (3)].real) / (yyvsp[(3) - (3)].integer);        ;}
    break;

  case 118:
#line 550 "../parse.y"
    { (yyval.real) = pow (float ((yyvsp[(1) - (3)].real)), float ((yyvsp[(3) - (3)].real)));   ;}
    break;

  case 119:
#line 551 "../parse.y"
    { (yyval.real) = pow (float ((yyvsp[(1) - (3)].integer)), float ((yyvsp[(3) - (3)].real)));   ;}
    break;

  case 120:
#line 552 "../parse.y"
    { (yyval.real) = pow (float ((yyvsp[(1) - (3)].real)), float ((yyvsp[(3) - (3)].integer)));   ;}
    break;

  case 121:
#line 554 "../parse.y"
    { (yyval.real) = -(yyvsp[(2) - (2)].real);            ;}
    break;

  case 122:
#line 555 "../parse.y"
    { (yyval.real) = (yyvsp[(2) - (3)].real);             ;}
    break;

  case 124:
#line 559 "../parse.y"
    {(yyval.real) = sin((yyvsp[(3) - (4)].real)); ;}
    break;

  case 125:
#line 560 "../parse.y"
    {(yyval.real) = cos((yyvsp[(3) - (4)].real)); ;}
    break;

  case 126:
#line 561 "../parse.y"
    {(yyval.real) = tan((yyvsp[(3) - (4)].real)); ;}
    break;

  case 127:
#line 562 "../parse.y"
    {(yyval.real) = asin((yyvsp[(3) - (4)].real)); ;}
    break;

  case 128:
#line 563 "../parse.y"
    {(yyval.real) = acos((yyvsp[(3) - (4)].real)); ;}
    break;

  case 129:
#line 564 "../parse.y"
    {(yyval.real) = atan((yyvsp[(3) - (4)].real)); ;}
    break;

  case 130:
#line 565 "../parse.y"
    {(yyval.real) = log((yyvsp[(3) - (4)].real)); ;}
    break;

  case 131:
#line 566 "../parse.y"
    {(yyval.real) = log10((yyvsp[(3) - (4)].real)); ;}
    break;

  case 132:
#line 567 "../parse.y"
    {(yyval.real) = exp((yyvsp[(3) - (4)].real)); ;}
    break;

  case 133:
#line 568 "../parse.y"
    {(yyval.real) = sqrt((yyvsp[(3) - (4)].real)); ;}
    break;

  case 134:
#line 572 "../parse.y"
    { (yyval.real) = 2.718281828459; ;}
    break;

  case 135:
#line 573 "../parse.y"
    { (yyval.real) = PI; ;}
    break;

  case 136:
#line 576 "../parse.y"
    { (yyval.integer) = (yyvsp[(1) - (1)].integer);                         ;}
    break;

  case 137:
#line 577 "../parse.y"
    { (yyval.integer) = (yyvsp[(1) - (3)].integer) + (yyvsp[(3) - (3)].integer);                    ;}
    break;

  case 138:
#line 578 "../parse.y"
    { (yyval.integer) = (yyvsp[(1) - (3)].integer) - (yyvsp[(3) - (3)].integer);                    ;}
    break;

  case 139:
#line 579 "../parse.y"
    { (yyval.integer) = (yyvsp[(1) - (3)].integer) * (yyvsp[(3) - (3)].integer);                    ;}
    break;

  case 140:
#line 580 "../parse.y"
    { (yyval.integer) = (yyvsp[(1) - (3)].integer) / (yyvsp[(3) - (3)].integer);                    ;}
    break;

  case 141:
#line 581 "../parse.y"
    { (yyval.integer) = -(yyvsp[(2) - (2)].integer);                        ;}
    break;

  case 142:
#line 582 "../parse.y"
    { (yyval.integer) = (int)pow ( (double)(yyvsp[(1) - (3)].integer), (yyvsp[(3) - (3)].integer));          ;}
    break;

  case 143:
#line 583 "../parse.y"
    { (yyval.integer) = (yyvsp[(2) - (3)].integer);                         ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2715 "../parse.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 587 "../parse.y"

//Additional C code


Matrix4x4& GetCTM()
{
    return g_kMatrixStack.top();
}

void PushMatrix()
{
    g_kMatrixStack.push(g_kMatrixStack.top());
}

void PopMatrix()
{
    g_Vel = Vector3(0,0,0);
    if(g_kMatrixStack.size() == 1)
    {
        Warning("Matrix stack empty!  Too many pops!\n");
    }
    else
        g_kMatrixStack.pop();
}

void Translate(const float& x, const float& y, const float& z)
{
    Matrix4x4 m;
    m.SetIdentity();
    m.SetColumn4(Vector4(x, y, z, 1));

    Matrix4x4& ctm = GetCTM();
    ctm *= m;
}

void Scale(const float& x, const float& y, const float& z)
{
    Matrix4x4 m;
    m.SetIdentity();
    m.m11 = x;
    m.m22 = y;
    m.m33 = z;

    Matrix4x4& ctm = GetCTM();
    ctm *= m;
}

void Rotate(const float& angle, float x, float y, float z) // angle is in degrees
{

    float rad = angle*(PI/180.);

    float x2 = x*x;
    float y2 = y*y;
    float z2 = z*z;
    float c = cos(rad);
    float cinv = 1-c;
    float s = sin(rad);
    float xy = x*y;
    float xz = x*z;
    float yz = y*z;
    float xs = x*s;
    float ys = y*s;
    float zs = z*s;
    float xzcinv = xz*cinv;
    float xycinv = xy*cinv;
    float yzcinv = yz*cinv;

    Matrix4x4 m;
    m.SetIdentity();
    m.Set(x2 + c*(1-x2), xy*cinv+zs, xzcinv - ys, 0,
          xycinv - zs, y2 + c*(1-y2), yzcinv + xs, 0,
          xzcinv + ys, yzcinv - xs, z2 + c*(1-z2), 0,
          0, 0, 0, 1);

    g_kMatrixStack.top() *= m;
}

Vector3& Vertex3(const Vector3& v)
{
    __parse_temp_vector = v;
    __parse_temp_vector = g_kMatrixStack.top()*__parse_temp_vector; // do transformation

    return __parse_temp_vector;
}

Vector3& Vertex3(const float& x, const float& y, const float& z)
{
    __parse_temp_vector.Set(x, y, z);
    __parse_temp_vector = g_kMatrixStack.top()*__parse_temp_vector; // do transformation

    return __parse_temp_vector;
}

Vector3& Color3(const float& x, const float& y, const float& z)
{
    __parse_temp_vector.Set(x,y,z);
    
    return __parse_temp_vector;
}

void ParseFile(FILE* fp)
{
    g_Vel = Vector3(0,0,0);
    Matrix4x4 m;
    m.SetIdentity();
    g_kMatrixStack.push(m);

    yyin = fp;
    //yydebug = 1;
    yyparse();
    if (g_kMatrixStack.size() > 1)
        Warning("There were more matrix pushes than pops!\n");
}

