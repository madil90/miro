#include "material.h"
#include "light.h"
#include "ray.h"
#include "scene.h"
#include "console.h"

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
		// default color contribution
		Vector3 lColor(0,0,0);
		int nSamples = (*l)->GetSamples();

		// no of samples per light
		for (int i=0;i<nSamples;i++){

			// get light info
			LightInfo lInfo = (*l)->GetLightInfo(hit.P);
			Vector3 lightDir = lInfo.lightRay.d;
			Vector3 lightColor = ((*l)->GetColor() * lInfo.attenuation);

			// Debug("attenuation is %f \n",lInfo.attenuation);
			// Debug("hit normal is %f,%f,%f \n",hit.N.x,hit.N.y,hit.N.z);
			// Debug("light dir is %f,%f,%f \n",lightDir.x,lightDir.y,lightDir.z);
			// Debug("dot product is %f \n",hit.N^lightDir);

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
			}else{
				continue;
			}

			// Debug("light color is %f,%f,%f \n",lightColor.x,lightColor.y,lightColor.z);

			// Compute the diffuse term
			Vector3 diffuse = ArrayProd(lightColor,md/PI)*std::max((float)0.0,hit.N^lightDir);
			
			// compute the specular term
			Vector3 h = (ray.o+lightDir);
			h.Normalize();
			Vector3 specular = ArrayProd(lightColor,ms/PI)*std::max((float)0.0,(float)powl(h^hit.N,msp));
			
			lColor+= diffuse+specular;
		}

		// add contribution to final color
		color += lColor/(float)nSamples;
	}
	return color;
}