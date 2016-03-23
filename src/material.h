#ifndef __MATERIAL_H__
#define __MATERIAL_H__

#include <list>
#include <string>
#include "miro.h"
#include "Vector.h"

class Material
{
public:
    Material();
    virtual ~Material();

    virtual void PreCalc() {}
    
    virtual Vector3 Shade (const Ray& ray, const HitInfo& hit,
                           Scene& scene) ;

    void SetReflectence(Vector3& v) {mr = v;}
	
	void SetTransmittance(Vector3& v) {mt = v;}

	void SetIndex(float ind) {index = ind;}

	void SetEmissive(Vector3& v) {me = v;}

	float getIndex() const {return index;}

	Vector3 getReflectance() const {return mr;} 

	Vector3 getTransmittance() const {return mt;}

	Vector3 getEmissive() const {return me;}

	virtual Vector3 getDiffuse() const {return Vector3(0,0,0);}

	// material properties for reflectance
	// and transmittance
	Vector3 mr,mt;
	Vector3 me;
	float index;
};

class PhongMaterial : public Material
{
public:
	PhongMaterial() : Material() {
		ma = Vector3(0,0,0);
		ms= Vector3(0,0,0);
		md = Vector3(0,0,0);
		msp = 10;
	}
	
	void SetAmbient(Vector3& v) {ma = v;}
	
	void SetDiffuse(Vector3& v) {md = v;} 
	
	void SetSpecular(Vector3& v) {ms = v;}
	
	void SetMetalness(float& v) {msp = v;}

	virtual Vector3 getDiffuse() const {return md;}
	
	
	
	void PreCalc() {}
    
    Vector3 Shade (const Ray& ray, const HitInfo& hit,
                           Scene& scene) ;
	
protected:
	// Material Properties in the following order
	// ma = Ambient
	// md = Diffuse
	// ms = Specular
	// msp = MetalNess
	// mr = Reflectence
	// mt = Transmittance
	Vector3 ma,md,ms;
	float msp;
};

#endif
