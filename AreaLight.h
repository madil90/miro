#ifndef _AREA_LIGHT_H_
#define _AREA_LIGHT_H_

#include "light.h"
#include "square.h"

class AreaLight : public Light
{
public:
	AreaLight() {intensity = 0;}
	~AreaLight() {
		delete [] square;
	}

	// setters
	void SetObject(Square* square) ;
	void SetIntensity(float intensity) {this->intensity = intensity;}

	// getters
	virtual Vector3 GetColor() ;
    virtual Vector3 GetDirection(const Vector3& pos) ;
    LightInfo GetLightInfo(const Vector3 &pos) ;

    // utility functions
    virtual void PreCalc() {}
    virtual void RenderGL() {}

protected:
	Vector3 m_center;
	float intensity;
	Square* square;

	float area;
	Vector3 m_normal;
};

#endif