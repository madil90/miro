#ifndef __MIRO_H__
#define __MIRO_H__

const float MIRO_TMAX = 1e12f;
const float MIRO_TMIN = 1e-3f;

const int DEPTH_MAX = 5;
const int DEPTH_MIN = 2;

#include "opengl.h"
#include <stdio.h>

class Ray;
class HitInfo;

class Object;
class Sphere;
class Triangle;
class TriangleMesh;
class Instance;

class PointLight;

class Camera;
class Image;
class Scene;
class Material;

extern void ParseFile(FILE* fp);
extern void InitOpenGL();
extern Camera* g_pCamera;
extern Scene* g_pScene;
extern Image* g_pImage;

#endif
