typedef union
{
    float real;
    int integer;
    char* str;
} YYSTYPE;
#define	REAL	258
#define	PARSE_INT	259
#define	STRING	260
#define	PARSE_TRUE	261
#define	PARSE_FALSE	262
#define	ENABLE	263
#define	DISABLE	264
#define	MATH_COS	265
#define	MATH_SIN	266
#define	MATH_TAN	267
#define	MATH_ACOS	268
#define	MATH_ASIN	269
#define	MATH_ATAN	270
#define	MATH_ATAN2	271
#define	MATH_LN	272
#define	MATH_LOG	273
#define	MATH_EXP	274
#define	MATH_SQRT	275
#define	MATH_E	276
#define	MATH_PI	277
#define	GLOBAL	278
#define	WIDTH	279
#define	HEIGHT	280
#define	BGCOLOR	281
#define	BSPSPLITS	282
#define	SAMPLESX	283
#define	SAMPLESY	284
#define	SHUTTERTIME	285
#define	PATHTRACE	286
#define	PHOTONMAP	287
#define	CAUSTICPHOTONS	288
#define	INDIRECTPHOTONS	289
#define	PHOTONSESTIMATE	290
#define	CAUSTICESTIMATE	291
#define	FINALGATHER	292
#define	CAMERA	293
#define	POS	294
#define	DIR	295
#define	LOOKAT	296
#define	UP	297
#define	FOV	298
#define	APERTURESIZE	299
#define	FOCALLENGTH	300
#define	FOCALPOINT	301
#define	TRIANGLE	302
#define	V1	303
#define	V2	304
#define	V3	305
#define	N1	306
#define	N2	307
#define	N3	308
#define	MESH	309
#define	LOAD	310
#define	GROUP	311
#define	INSTANCE	312
#define	GEOMETRY	313
#define	MATERIAL_PHONG	314
#define	ME	315
#define	MA	316
#define	MD	317
#define	MS	318
#define	MR	319
#define	MT	320
#define	MSP	321
#define	INDEX	322
#define	PUSHMATRIX	323
#define	POPMATRIX	324
#define	ROTATE	325
#define	TRANSLATE	326
#define	SCALE	327
#define	VELOCITY	328
#define	LIGHT	329
#define	POINTLIGHT	330
#define	WATTAGE	331
#define	COLOR	332
#define	DIRLIGHT	333
#define	AREALIGHT	334
#define	INTENSITY	335
#define	RENDERLIGHT	336
#define	SPHERE	337
#define	CENTER	338
#define	RADIUS	339
#define	SQUARE	340
#define	NORMAL	341
#define	SAMPLES	342
#define	NEG	343


extern YYSTYPE yylval;
