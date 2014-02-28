/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 62 "../parse.y"
{
    float real;
    int integer;
    char* str;
}
/* Line 1529 of yacc.c.  */
#line 213 "../parse.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

