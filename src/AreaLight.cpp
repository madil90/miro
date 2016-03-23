#include "AreaLight.h"
#include <random>
#include <iostream>
#include "miro.h"
#include "scene.h"
#include "console.h"

AreaLight::AreaLight() : render_geometry(true) 
{
	intensity = 0;square=NULL;
}

Vector3 AreaLight::GetColor() 
{
	return square->getMaterial()->getEmissive();
}

Vector3 AreaLight::GetDirection(const Vector3& pos)
{
	return Vector3(0,0,0);
}

Vector3 AreaLight::GetPower()
{
	return GetColor()*area*PI;
}

void AreaLight::RenderGeometry(bool render)
{
	this->render_geometry = render;
}

float rand01()
{
	return ((float)std::rand()/RAND_MAX);
}

void AreaLight::SetObject(Square* square)
{
	this->square = square;
	Matrix4x4 mat = square->getTransformation();

	// add to scene
	if (render_geometry){
		g_pScene->AddObject(square);
	}

	m_center = mat*Vector4(0,0,0,1);

	// find the area
	Vector3 p1 = mat*Vector4(0.0,0.5,0,1);
	Vector3 p2 = mat*Vector4(0.5,0.0,0,1);
	area = (2*(p1-m_center).Norm())*(2*(p2-m_center).Norm());

	// get normal vector
	Vector4 normal = mat*Vector4(0,0,1.0,0);
	m_normal = Vector3(normal.x,normal.y,normal.z);
	m_normal.Normalize();

	// Debug("Normal is %f,%f,%f",m_normal.x,m_normal.y,m_normal.z);

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
	float dist = dir.Norm();
	dir = dir.Normalize();

	// light properties
	//Vector3 lDir = (pos-m_center).Normalize();
	Vector3 lDir = -dir;
	// float distCtr = (m_center-pos).Norm();
	float distCtr = dist;

	// Debug("light normal is %f,%f,%f \n",m_normal.x,m_normal.y,m_normal.z);
	// Debug("light dir is %f,%f,%f \n",lDir.x,lDir.y,lDir.z);
	// Debug("hit pos is %f,%f,%f \n",pos.x,pos.y,pos.z);
	// Debug("light pos is %f,%f,%f \n",center.x,center.y,center.z);

	// calculate angle b/w light and light normal
	float lightAngle = std::max((float)0.0,lDir^m_normal);

	// calculate attenuation
	float attenuation = (1.0/(distCtr*distCtr));

	// Debug("light angle is %f \n",lDir^m_normal);
	// Debug("attenuation inside is %f \n",attenuation);

	return LightInfo(Ray(pos,dir,Ray::SHADOW), dist-MIRO_TMIN, lightAngle*attenuation );
}

Ray AreaLight::EmitPhoton()
{
	Matrix4x4 mat = square->getTransformation();
	Matrix4x4 matN = square->getNormalTransformation();

	// generate random position
	float x = rand01()-0.5;
	float y = rand01()-0.5;
	Vector3 center = mat*Vector4(x,y,0.0,1.0);

	// generate direction and transform around normal
	Vector3 dir = g_pScene->getScatterDirection(m_normal);

	return Ray(center,dir,Ray::PHOTON);
}

