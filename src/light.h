#ifndef __LIGHT_H__
#define __LIGHT_H__

#include <list>
#include "Vector.h"
#include "miro.h"
#include "ray.h"

class Scene;

struct LightInfo{

    LightInfo(const Ray& r, const float t, const float att)
        : lightRay(r) , dist(t) , attenuation(att) {}

    Ray lightRay;
    float dist;
    float attenuation;
};

class Light{
public:
    Light()  {nSamples = 1;}
    virtual ~Light(){}

    virtual LightInfo GetLightInfo(const Vector3 &pos) = 0;

    virtual Vector3 GetColor() {return Vector3(0,0,0);};
    virtual Vector3 GetDirection(const Vector3& pos){return Vector3(0,0,0);}
    virtual Vector3 GetPower() {return Vector3(0,0,0);}
    virtual int GetSamples() {return nSamples;}
    virtual void SetSamples(int samples) {nSamples = samples;}
    virtual Ray EmitPhoton() {return Ray(Vector3(0,0,0),Vector3(0,0,0),Ray::PHOTON);}
    virtual void PreCalc()=0;
    virtual void RenderGL() {}

protected:
    int nSamples;
};

class PointLight : public Light
{
public:
    PointLight():Light(){}
    void SetPosition(const Vector3& v) { m_vPos = v; }
    void SetColor(const Vector3& v) { m_vColor = v; }
    Vector3 GetPower() ;
    void SetWattage(float f) { m_intensity = f; }
    inline float GetWattage() { return m_intensity; }
    Vector3 GetColor() ;
    Vector3 GetDirection(const Vector3& pos) ;
    
    LightInfo GetLightInfo(const Vector3 &pos);

    void PreCalc() {} // use this if you need to
    virtual void RenderGL();
protected:
    Vector3 m_vPos;
    Vector3 m_vColor;
    float m_intensity;
};

class DirectionalLight: public Light
{
public:
    DirectionalLight():Light(){ m_vDir = m_vColor = Vector3(0,0,0);}
    void SetDirection(const Vector3& v) {m_vDir = v;m_vDir.Normalize();}
    void SetColor(const Vector3& v){m_vColor = v;}
    Vector3 GetPower();
    Vector3 GetColor();
    Vector3 GetDirection(const Vector3& pos);
    
    LightInfo GetLightInfo(const Vector3 &pos);

    void PreCalc(){} // use this if u need to
    virtual void RenderGL();

protected:
    Vector3 m_vDir;
    Vector3 m_vColor;
};

typedef std::list<Light*> LightList;

#endif
