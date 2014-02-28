#include "AreaLight.h"
#include <random>
#include <iostream>
#include "miro.h"

Vector3 AreaLight::GetColor() 
{
	return square->getMaterial()->getEmissive();
}

Vector3 AreaLight::GetDirection(const Vector3& pos)
{
	return Vector3(0,0,0);
}

float rand01()
{
	return ((float)std::rand()/RAND_MAX);
}

void AreaLight::SetObject(Square* square)
{
	this->square = square;
	Matrix4x4 mat = square->getTransformation();

	m_center = mat*Vector4(0,0,0,1);

	// find the area
	Vector3 p1 = mat*Vector4(0.0,0.5,0,1);
	Vector3 p2 = mat*Vector4(0.5,0.0,0,1);
	area = (2*(p1-m_center).Norm())*(2*(p2-m_center).Norm());

	// get normal vector
	Vector4 normal = mat*Vector4(0,0,1.0,0);
	m_normal = Vector3(normal.x,normal.y,normal.z);
	m_normal.Normalize();

	// multiply material emmisivity with intensity
	Material* material = square->getMaterial();
	Vector3 me_modified = intensity*material->getEmissive();
	material->SetEmissive(me_modified);
}

LightInfo AreaLight::GetLightInfo(const Vector3& pos)
{
	Matrix4x4 mat = square->getTransformation();
	
	// generate random position
	float x = rand01()-0.5;
	float y = rand01()-0.5;
	Vector3 center = mat*Vector4(x,y,0.0,1.0);
	
	// calculate direction and distance
	Vector3 dir = (center-pos);
	float dist = dir.Norm() - MIRO_TMIN;
	dir = dir.Normalize();

	// calculate angle b/w light and light normal
	Vector3 lDir = (pos-m_center).Normalize();
	float lightAngle = std::max((float)0.0,lDir^m_normal);

	// calculate attenuation
	float distCtr = (m_center-pos).Norm();
	float attenuation = (area)*(1.0/(distCtr*distCtr));

	return LightInfo(Ray(pos,dir,Ray::SHADOW),dist, attenuation );
}
