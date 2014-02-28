%{
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

%}
// BISON Declarations


%union
{
    float real;
    int integer;
    char* str;
}

        /* ----------------------- tokens ------------------------*/

%token <real>  REAL
%token <integer>  PARSE_INT 
%token <str>  STRING

%token PARSE_TRUE
%token PARSE_FALSE
%token ENABLE
%token DISABLE
%token MATH_COS
%token MATH_SIN
%token MATH_TAN
%token MATH_ACOS
%token MATH_ASIN
%token MATH_ATAN
%token MATH_ATAN2
%token MATH_LN
%token MATH_LOG
%token MATH_EXP
%token MATH_SQRT
%token MATH_E
%token MATH_PI

%token GLOBAL
%token WIDTH
%token HEIGHT
%token BGCOLOR
%token SAMPLESX
%token SAMPLESY
%token SHUTTERTIME
%token PATHTRACE

%token CAMERA
%token POS
%token DIR
%token LOOKAT
%token UP
%token FOV

%token APERTURESIZE
%token FOCALLENGTH
%token FOCALPOINT

%token TRIANGLE
%token V1
%token V2
%token V3
%token N1
%token N2
%token N3

%token MESH
%token LOAD
%token GROUP

%token INSTANCE
%token GEOMETRY

%token MATERIAL_PHONG
%token ME
%token MA
%token MD
%token MS
%token MR
%token MT
%token MSP
%token INDEX

%token PUSHMATRIX
%token POPMATRIX
%token ROTATE
%token TRANSLATE
%token SCALE
%token VELOCITY

%token LIGHT
%token POINTLIGHT
%token WATTAGE
%token COLOR
%token DIRLIGHT
%token AREALIGHT
%token INTENSITY


%token SPHERE
%token CENTER
%token RADIUS

%token SQUARE
%token POS
%token NORMAL

// add more tokens here!

%right '='
%left '-' '+'
%left '*' '/' // multiplication or cross product
%left NEG     // Negation--unary minus
%right '^'

%type <real> rExp fExp constantExp
%type <integer> iExp 

%%
input:  /* empty */
        | input block
;

block:    GLOBAL '{' globalOptions '}'
        | CAMERA '{' cameraOptions '}'
        | objectTypes 
        | materialTypes
        | LIGHT lightTypes '}' { g_pScene->AddLight(pLight); pLight = 0; }
        | transform
;

objectTypes:
          TRIANGLE '{'
            {
                pObj = new TriangleMesh;
                pObj->SetMaterial (pMat);
                pObj->SetVelocity(g_Vel);
                pObj->SetTransformation(GetCTM());
                ((TriangleMesh*)pObj)->CreateSingleTriangle();
            }
          triangleOptions '}'
            {
                if (pObj)
                    g_pScene->AddObject(pObj);
                pObj = 0;
            }

        | TRIANGLE STRING '{'
            {
                pBSP = new BSPTree;
                pBSP->SetMaterial (pMat);
                g_objectMap[$2] = pBSP;

                pObj = new TriangleMesh;
                pObj->SetMaterial (pMat);
                pObj->SetVelocity(g_Vel);
                pObj->SetTransformation(GetCTM());
                ((TriangleMesh*)pObj)->CreateSingleTriangle();
            }
          triangleOptions '}'
            {
                if (pObj && pBSP)
                {
                    pBSP->AddObject (pObj);
                    g_pScene->AddObject(pBSP);
                }
                pObj = 0;
                pBSP = 0;
            }

            
	| MESH '{'
            {
                pObj = new TriangleMesh;
                pObj->SetMaterial (pMat);
                pObj->SetVelocity(g_Vel);
                pObj->SetTransformation(GetCTM());
            }
          meshOptions '}'
            {
                if (pObj)
                    g_pScene->AddObject(pObj);
                pObj = 0;
            }
            
	| MESH STRING '{'
            {
                pBSP = new BSPTree;
                pBSP->SetMaterial (pMat);
                g_objectMap[$2] = pBSP;

                pObj = new TriangleMesh;
                pObj->SetMaterial (pMat);
                pObj->SetVelocity(g_Vel);
                pObj->SetTransformation(GetCTM());
            }
          meshOptions '}'
            {
                if (pObj && pBSP)
                {
                    pBSP->AddObject (pObj);
                    g_pScene->AddObject(pBSP);
                }
                pObj = 0;
                pBSP = 0;
            }
            

	| SPHERE '{'
            {
                pObj = new Sphere;
                pObj->SetMaterial (pMat);
                pObj->SetVelocity(g_Vel);
                pObj->SetTransformation(GetCTM());
            }
          sphereOptions '}'
            {
                if (pObj)
                    g_pScene->AddObject(pObj);
                pObj = 0;
            }
            
	| SPHERE STRING '{'
            {
                pObj = new Sphere;
                pObj->SetMaterial (pMat);
                pObj->SetVelocity(g_Vel);
                pObj->SetTransformation(GetCTM());
                g_objectMap[$2] = pObj;
            }
          sphereOptions '}'
            {
                if (pObj)
                    g_pScene->AddObject(pObj);
                pObj = 0;
            }

    | SQUARE '{'
            {
                pObj = new Square;
                pObj->SetMaterial (pMat);
                pObj->SetVelocity(g_Vel);
                pObj->SetTransformation(GetCTM());
            } squareOptions '}'
            {
                if (pObj)
                    g_pScene->AddObject(pObj);
                pObj = 0;
            }
    | SQUARE STRING '{'
            {
                pObj = new Square;
                pObj->SetMaterial (pMat);
                pObj->SetVelocity(g_Vel);
                pObj->SetTransformation(GetCTM());
                g_objectMap[$2] = pObj;
            } squareOptions '}'
            {
                if (pObj)
                    g_pScene->AddObject(pObj);
                pObj = 0;
            }
            

	| INSTANCE '{'
            {
                pObj = new Instance;
                pObj->SetMaterial (pMat);
                pObj->SetVelocity(g_Vel);
            }
          instanceOptions '}'
            {
                if (pObj)
                    g_pScene->AddObject(pObj);
                pObj = 0;
            }
            
	| INSTANCE STRING '{'
            {
                pObj = new Instance;
                pObj->SetMaterial (pMat);
                pObj->SetVelocity(g_Vel);
                g_objectMap[$2] = pObj;
            }
          instanceOptions '}'
            {
                if (pObj)
                    g_pScene->AddObject(pObj);
                pObj = 0;
            }
;

triangleOptions: /* empty */
        | V1 rExp ',' rExp ',' rExp triangleOptions
            {((TriangleMesh*)pObj)->SetV1(Vertex3($2, $4, $6));}
        | V2 rExp ',' rExp ',' rExp triangleOptions
            {((TriangleMesh*)pObj)->SetV2(Vertex3($2, $4, $6));}
        | V3 rExp ',' rExp ',' rExp triangleOptions
            {((TriangleMesh*)pObj)->SetV3(Vertex3($2, $4, $6));}
        | N1 rExp ',' rExp ',' rExp triangleOptions
            {((TriangleMesh*)pObj)->SetN1(Vertex3($2, $4, $6));}
        | N2 rExp ',' rExp ',' rExp triangleOptions
            {((TriangleMesh*)pObj)->SetN2(Vertex3($2, $4, $6));}
        | N3 rExp ',' rExp ',' rExp triangleOptions
            {((TriangleMesh*)pObj)->SetN3(Vertex3($2, $4, $6));}
;

sphereOptions: /* empty */
        | CENTER rExp ',' rExp ',' rExp sphereOptions
            {((Sphere*)pObj)->SetCenter(Vector3($2, $4, $6));}
        | RADIUS rExp sphereOptions
            {((Sphere*)pObj)->SetRadius($2);}
;

squareOptions: /* empty */
        | CENTER rExp ',' rExp ',' rExp squareOptions
            { ( (Square*) pObj)->SetCenter(Vector3($2,$4,$6));}

instanceOptions: /* empty */
        | GEOMETRY STRING sphereOptions
            {
                std::map<std::string, Object*>::const_iterator it = g_objectMap.find ($2);
                if (it != g_objectMap.end ())
                {
                    ((Instance*)pObj)->SetGeometry(it->second, GetCTM());
                }
            }
;

transform:  PUSHMATRIX { PushMatrix(); }
        | POPMATRIX
            {PopMatrix();}
        | ROTATE rExp ',' rExp ',' rExp ',' rExp
            {Rotate($2, $4, $6, $8);}
        | TRANSLATE rExp ',' rExp ',' rExp
            {Translate($2, $4, $6);}
        | SCALE rExp ',' rExp ',' rExp
            {Scale($2, $4, $6);}
        | VELOCITY rExp ',' rExp ',' rExp
            { g_Vel = Vector3($2,$4,$6); }
;

lightTypes: POINTLIGHT '{' {pLight = new PointLight;} pointLightOptions
        |   DIRLIGHT '{' {pLight = new DirectionalLight; } dirLightOptions
        |   AREALIGHT '{' { pLight = new AreaLight; } areaLightOptions
;

pointLightOptions: /* empty */ 
        | POS rExp ',' rExp ',' rExp pointLightOptions
            { ((PointLight*)pLight)->SetPosition(Vertex3($2, $4, $6));}
        | WATTAGE rExp pointLightOptions
            { ((PointLight*)pLight)->SetWattage($2);}
        | COLOR rExp ',' rExp ',' rExp pointLightOptions
            { ((PointLight*)pLight)->SetColor(Vector3($2, $4, $6));}
;

dirLightOptions: /* empty */
        | DIR rExp ',' rExp ',' rExp dirLightOptions
            { ((DirectionalLight*)pLight)->SetDirection(Vector3($2, $4, $6)); }
        | COLOR rExp ',' rExp ',' rExp dirLightOptions
            { ((DirectionalLight*)pLight)->SetColor(Color3($2, $4, $6)); }
;

areaLightOptions: INTENSITY rExp
            { 
                ((AreaLight*)pLight)->SetIntensity($2);
                
                pObj = new Square;
                pObj->SetMaterial (pMat);
                pObj->SetVelocity(g_Vel);
                pObj->SetTransformation(GetCTM());
                
                g_pScene->AddObject(pObj);
                ((AreaLight*)pLight)->SetObject((Square*)pObj);
            }
;


meshOptions: /* empty */
        | LOAD STRING
            {
                $2[strlen($2)-1]=0;
                char* s = &$2[1];
                if (!g){
                    if (!((TriangleMesh*)pObj)->Load(s))
                        pObj = 0;
                }else{
                    if (!((TriangleMesh*)pObj)->Load(s,g))
                        pObj = 0;
                }
                g=0;
                delete [] $2;
            }
        | GROUP STRING
            {
                $2[strlen($2)-1]=0;
                char* s = &$2[1];
                g = s;
            } meshOptions
;

globalOptions: /* empty */
        | HEIGHT iExp globalOptions
            { g_pImage->Resize(g_pImage->Width(), $2); }
        | WIDTH iExp globalOptions
            { g_pImage->Resize($2, g_pImage->Height()); }
        | BGCOLOR rExp ',' rExp ',' rExp globalOptions
            { g_pCamera->SetBGColor(Vector3($2, $4, $6)); }
        | SAMPLESX rExp globalOptions
            { g_pScene->SetSamplesX($2);}
        | SAMPLESY rExp globalOptions
            {g_pScene->SetSamplesY($2);}
        | SHUTTERTIME rExp globalOptions
            { g_pScene->SetShutterTime($2);}
        | PATHTRACE rExp globalOptions
            {
                if ($2==0)
                    g_pScene->SetPathTrace(false);
                else
                    g_pScene->SetPathTrace(true);
            }
;

materialTypes:
          MATERIAL_PHONG '{'
          {
            pMat = new PhongMaterial;
          }
          materialPhongOptions '}'
;

materialPhongOptions: /* empty */
        | ME rExp ',' rExp ',' rExp
            { ( (PhongMaterial*) pMat)->SetEmissive(Color3($2,$4,$6));}
        | MA rExp ',' rExp ',' rExp
            {((PhongMaterial*)pMat)->SetAmbient(Color3($2,$4,$6));} 
            materialPhongOptions
        | MD rExp ',' rExp ',' rExp 
            {((PhongMaterial*)pMat)->SetDiffuse(Color3($2,$4,$6));} 
            materialPhongOptions
        | MS rExp ',' rExp ',' rExp 
            {((PhongMaterial*)pMat)->SetSpecular(Color3($2,$4,$6));} 
            materialPhongOptions
        | MSP rExp
            {((PhongMaterial*)pMat)->SetMetalness($2);} 
            materialPhongOptions
        | MR rExp ',' rExp ',' rExp 
            {((PhongMaterial*)pMat)->SetReflectence(Color3($2,$4,$6));} 
            materialPhongOptions
        | MT rExp ',' rExp ',' rExp 
            {((PhongMaterial*)pMat)->SetTransmittance(Color3($2,$4,$6));} 
            materialPhongOptions
        | INDEX rExp
            { ((PhongMaterial*)pMat)->SetIndex($2);}
            materialPhongOptions
;

cameraOptions: /* empty */
        | POS rExp ',' rExp ',' rExp cameraOptions
            {g_pCamera->SetEye(Vector3($2, $4, $6));}
        | DIR rExp ',' rExp ',' rExp cameraOptions
            {g_pCamera->SetViewDir(Vector3($2, $4, $6));}
        | LOOKAT rExp ',' rExp ',' rExp cameraOptions
            {g_pCamera->SetLookAt(Vector3($2, $4, $6));}
        | UP rExp ',' rExp ',' rExp cameraOptions
            {g_pCamera->SetUp(Vector3($2, $4, $6));}
        | FOV rExp cameraOptions
            {g_pCamera->SetFOV($2);}
        | APERTURESIZE rExp cameraOptions
            { g_pCamera->SetApertureSize($2);}
        | FOCALLENGTH rExp cameraOptions
            { g_pCamera->SetFocalLength($2);}
        | FOCALPOINT rExp ',' rExp ',' rExp cameraOptions
            { g_pCamera->SetFocalPoint(Vector3($2,$4,$6));}
;

rExp:     REAL                 { $$ = $1;             }
        | iExp                 { $$ = $1;             }
        | fExp                 { $$ = $1;             }
        
        | rExp '+' rExp        { $$ = $1 + $3;        }
        | iExp '+' rExp        { $$ = $1 + $3;        }
        | rExp '+' iExp        { $$ = $1 + $3;        }
        
        | rExp '-' rExp        { $$ = $1 - $3;        }
        | iExp '-' rExp        { $$ = $1 - $3;        }
        | rExp '-' iExp        { $$ = $1 - $3;        }
        
        | rExp '*' rExp        { $$ = $1 * $3;        }
        | iExp '*' rExp        { $$ = $1 * $3;        }
        | rExp '*' iExp        { $$ = $1 * $3;        }
        
        | rExp '/' rExp        { $$ = $1 / $3;        }
        | iExp '/' rExp        { $$ = $1 / $3;        }
        | rExp '/' iExp        { $$ = $1 / $3;        }
        
        | rExp '^' rExp        { $$ = pow (float ($1), float ($3));   }
        | iExp '^' rExp        { $$ = pow (float ($1), float ($3));   }
        | rExp '^' iExp        { $$ = pow (float ($1), float ($3));   }
        
        | '-' rExp  %prec NEG  { $$ = -$2;            }
        | '(' rExp ')'         { $$ = $2;             }
        | constantExp
;

fExp:      MATH_SIN '(' rExp ')' {$$ = sin($3); }
        |  MATH_COS '(' rExp ')' {$$ = cos($3); }
        |  MATH_TAN '(' rExp ')' {$$ = tan($3); }
        |  MATH_ASIN '(' rExp ')' {$$ = asin($3); }
        |  MATH_ACOS '(' rExp ')' {$$ = acos($3); }
        |  MATH_ATAN '(' rExp ')' {$$ = atan($3); }
        |  MATH_LN '(' rExp ')' {$$ = log($3); }
        |  MATH_LOG '(' rExp ')' {$$ = log10($3); }
        |  MATH_EXP '(' rExp ')' {$$ = exp($3); }
        |  MATH_SQRT '(' rExp ')' {$$ = sqrt($3); }
;

constantExp:
           MATH_E { $$ = 2.718281828459; }
        |  MATH_PI { $$ = PI; }
;

iExp:     PARSE_INT             { $$ = $1;                         }
        | iExp '+' iExp         { $$ = $1 + $3;                    }
        | iExp '-' iExp         { $$ = $1 - $3;                    }
        | iExp '*' iExp         { $$ = $1 * $3;                    }
        | iExp '/' iExp         { $$ = $1 / $3;                    }
        | '-' iExp  %prec NEG   { $$ = -$2;                        }
        | iExp '^' iExp         { $$ = (int)pow ( (double)$1, $3);          }
        | '(' iExp ')'          { $$ = $2;                         }
;

// End of grammar
%%
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
