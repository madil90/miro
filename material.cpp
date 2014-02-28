#include "material.h"
#include "light.h"
#include "ray.h"
#include "scene.h"
#include <iostream>

Material::Material()
{
	mr= Vector3(0,0,0);
	mt= Vector3(0,0,0);
	me = Vector3(0,0,0);
	index = 1.0003;  // air
}

Material::~Material()
{
}

Vector3 Material::Shade (const Ray& ray, const HitInfo& hit, Scene& scene) 
{
    return Vector3(1,1,1);
}

Vector3 PhongMaterial::Shade(const Ray& ray, const HitInfo& hit, Scene& scene) 
{
	Vector3 color(0,0,0);
	
	// lights in the scene

	const LightList* lights = scene.GetLights();
	LightList::const_iterator l;

	if (ray.t != Ray::INDIRECT)
		color+= me;
	
	
	for (l=lights->begin();l!=lights->end();l++)
	{
		// get light info
		LightInfo lInfo = (*l)->GetLightInfo(hit.P);
		Vector3 lightDir = lInfo.lightRay.d;
		Vector3 lightColor = ((*l)->GetColor() * lInfo.attenuation).Bound(1.0f);

		// check for shadows
		if ( (hit.N^lightDir)> 0){
			HitInfo shadowHit;
			Ray shadowRay = lInfo.lightRay;
			scene.assignId(shadowRay);
			if (scene.Trace(shadowHit,shadowRay)){
				if (shadowHit.t < lInfo.dist){
					continue;
				}
			}
		}

		// Compute the diffuse term
		Vector3 diffuse = ArrayProd(lightColor,md)*std::max((float)0.0,hit.N^lightDir);
		
		// compute the specular term
		Vector3 h = (ray.o+lightDir);
		h.Normalize();
		Vector3 specular = ArrayProd(lightColor,ms)*std::max((float)0.0,(float)powl(h^hit.N,msp));
		
		color+= diffuse+specular;
	}
	return color;
}