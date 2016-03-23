#ifndef __SCENE_H__
#define __SCENE_H__

#include "miro.h"
#include "object.h"
#include "bspTree.h"
#include "light.h"
#include <time.h>


class Camera;
class Image;
class PhotonManager;

extern int noOfRays;

class Scene
{
public:
    Scene ();
    ~Scene ();

    void AddObject(Object* pObj) {m_bsp->AddObject(pObj);}

    void AddLight(Light* pObj) {m_kLights.push_back(pObj);}
    const LightList* GetLights() const {return &m_kLights;}

    void SetSamplesX(int nSamples) {samplesX = nSamples;}
    void SetSamplesY(int nSamples) {samplesY = nSamples;}
    void SetShutterTime(float shutterTime) {m_shutterTime = shutterTime;}
    void SetPathTrace(bool pathtrace);
    float getCurrentTime() {return m_currentTime;}
    Vector3 getScatterDirection(Vector3 N);
    void setRenderTree(bool render) {m_bsp->setRenderTree(render);}
    bool isRenderTree() {return m_bsp->isRenderTree();}

    void PreCalc();
    void OpenGL(Camera *cam);

    // tracing functions
    void RaytraceImage(Camera *cam, Image *img);
    bool Trace(HitInfo& minHit, const Ray& ray,
               float tMin = MIRO_TMIN, float tMax = MIRO_TMAX) const;
	Vector3 TracePixel(int x, int y, int imageWidth, int imageHeight, Camera* cam);
    Vector3 TraceRay(Ray& ray, Camera* cam, int depth);

	int getShotNo();

    // tagging rays
    void assignId(Ray& ray);

    // get different rays
    bool getRefractedRay(HitInfo& hit, Ray& ray, Ray& refRay);

    // get bsp tree
    BSPTree* getBSPTree() {return m_bsp;}

    // get photon manager
    PhotonManager* getPhotonManager() {return pManager;}
    void EnablePhotonMapping(bool p_map) {photon_map = p_map;}

    // debug variable
    bool debug_print;

protected:
    BSPTree* m_bsp;
    LightList m_kLights;

    // no of samples per pixel
    int samplesX,samplesY;

    // shutter time
    float m_shutterTime;
    float m_currentTime;

	// current shot no
	int g_iShotIdx;

    // path trace enable
    bool path_trace;

    // photon mapping options
    bool photon_map;

    // photon mapping
    PhotonManager* pManager;


};

#endif
