%option noyywrap 
%option never-interactive 
%option stack 

%{
#include <stdio.h>
#include <string.h>
#include "miro.h"
#include "parse.cpp.h"

int yyline=1;
%}


COMMENT "#".* 
SPACE [ ]+
WS [ \t]*

SIGN    [+-]
DIGIT   [0-9]
FLOATARGS [eE][+-]
INT {DIGIT}+
REAL {DIGIT}*("."{DIGIT}*)?({FLOATARGS}{DIGIT}+)?
ID  ([_a-zA-Z][_a-zA-Z0-9]*[\ \t\n])+
STRING  \"[_a-zA-Z"."][_a-zA-Z0-9"."/\\: ]*\"

%x global
%x camera
%x triangle
%x mesh
%x instance
%x light
%x pointlight
%x dirlight
%x areaLight
%x sphere
%x square
%x material_phong
%%

<*>enable{WS} { return ENABLE; }
<*>disable{WS} { return DISABLE; }
<*>cos{WS} { return MATH_COS; }
<*>sin{WS} { return MATH_SIN; }
<*>tan{WS} { return MATH_TAN; }
<*>acos{WS} { return MATH_ACOS; }
<*>asin{WS} { return MATH_ASIN; }
<*>atan{WS} { return MATH_ATAN; }
<*>atan2{WS} { return MATH_ATAN2; }
<*>ln{WS} { return MATH_LN; }
<*>log{WS} { return MATH_LOG; }
<*>exp{WS} { return MATH_EXP; }
<*>sqrt{WS} { return MATH_SQRT; }
<*>e{WS} { return MATH_E; }
<*>pi{WS} { return MATH_PI; }

<INITIAL>global{WS} { yy_push_state(global); return GLOBAL; }
<global>width{WS}	{ return WIDTH; }
<global>height{WS}	{ return HEIGHT; }
<global>background{WS}color{WS} { return BGCOLOR; }
<global>samplesX{WS} {return SAMPLESX;}
<global>samplesY{WS} {return SAMPLESY;}
<global>shutter{WS}time{WS} {return SHUTTERTIME;}
<global>path{WS}trace{WS} {return PATHTRACE;}

<INITIAL>camera{WS} { yy_push_state(camera); return CAMERA; }
<camera>pos{WS} { return POS; }
<camera>dir{WS} { return DIR; }
<camera>look{WS}at{WS} { return LOOKAT; }
<camera>up{WS} { return UP; }
<camera>fov{WS} { return FOV; }
<camera>focal{WS}length{WS} {return FOCALLENGTH;}
<camera>aperture{WS}size{WS} {return APERTURESIZE;}
<camera>focal{WS}point{WS} {return FOCALPOINT;}

<INITIAL>triangle{WS} { yy_push_state(triangle); return TRIANGLE; }
<triangle>v1{WS} { return V1; }
<triangle>v2{WS} { return V2; }
<triangle>v3{WS} { return V3; }
<triangle>n1{WS} { return N1; }
<triangle>n2{WS} { return N2; }
<triangle>n3{WS} { return N3; }

<INITIAL>square{WS} { yy_push_state(square); return SQUARE;}
<square>center{WS} { return CENTER; }

<INITIAL>mesh{WS} { yy_push_state(mesh); return MESH; }
<mesh>load{WS} { return LOAD; }
<mesh>group{WS} { return GROUP; }

<INITIAL>instance{WS} { yy_push_state(instance); return INSTANCE; }
<instance>geometry{WS} { return GEOMETRY; }

<INITIAL>material_phong{WS} {yy_push_state(material_phong); return MATERIAL_PHONG;}
<material_phong>me{WS} {return ME;}
<material_phong>ma{WS} {return MA;}
<material_phong>md{WS} {return MD;}
<material_phong>ms{WS} {return MS;}
<material_phong>msp{WS} {return MSP;}
<material_phong>mr{WS} {return MR;}
<material_phong>mt{WS} {return MT;}
<material_phong>index{WS} {return INDEX;}

<INITIAL>push{WS}matrix{WS} { return PUSHMATRIX; }
<INITIAL>pop{WS}matrix{WS} { return POPMATRIX; }
<INITIAL>rotate{WS} { return ROTATE; }
<INITIAL>translate{WS} { return TRANSLATE; }
<INITIAL>scale{WS} { return SCALE; }
<INITIAL>vel{WS} { return VELOCITY;}

<INITIAL>light{WS} { yy_push_state(light); return LIGHT; }
<light>point{WS} { yy_pop_state(); yy_push_state(pointlight); return POINTLIGHT; }
<pointlight>color{WS} { return COLOR; }
<pointlight>pos{WS} { return POS; }
<pointlight>wattage{WS} { return WATTAGE; }

<light>directional{WS} { yy_pop_state(); yy_push_state(dirlight); return DIRLIGHT; }
<dirlight>color{WS} { return COLOR;}
<dirlight>dir{WS} { return DIR;}

<light>area{WS} { yy_pop_state(); yy_push_state(areaLight); return AREALIGHT;}
<areaLight>intensity{WS} {return INTENSITY;}

<INITIAL>sphere{WS} { yy_push_state(sphere); return SPHERE; }
<sphere>center{WS} { return CENTER; }
<sphere>radius{WS} { return RADIUS; }

<*>{INT} {
  yylval.integer = atoi(yytext);
  return PARSE_INT;
}

<*>{REAL} {
  yylval.real = atof(yytext);
  return REAL;
}

<*>{STRING} {
  yylval.str = strdup(yytext);
  return STRING;
}

<*>"/*" { // C style comments
  register int c;
  for ( ; ; ) {
    while ((c = yyinput()) != '*' && c != EOF ) if (c == '\n') yyline++;
    if ( c == '*' ) {
      while ( (c = yyinput()) == '*' ) if (c == '\n') yyline++;
	  if ( c == '/' )
	    break;    /* found the end */
      if ( c == EOF ) {
	    fprintf(stderr, "EOF in comment");
	    printf("Press Enter to continue...");
	  }
	}
  }
}


<*>[!{,=\-+\\/*()]{WS} {
  return yytext[0];
}

<*>"}" {
  yy_pop_state();
  return yytext[0];
}

<*>{COMMENT}       // eat up comments 

<*>[ ,\t\r]+          // eat up whitespace

<*>"\n" { yyline++; }

.          { 
  printf("\nParse error line %d near: %s\n", yyline, yytext); 
  printf("Press Enter to continue...");
}

%%
