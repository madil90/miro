#include "photonManager.h"
#include "console.h"
#include "scene.h"
#include "light.h"
#include "sampler.h"

PhotonManager::PhotonManager()
{
	no_caustic_photons = 10000;
    no_indirect_photons = 10000;
    no_photons_in_estimate = 50;
    no_photons_in_estimate_caustics = 50;

    max_distance = 0.8;

    render_maps = false;

    final_gather_rays = 0;
    final_gather = false;

    caustic_trace = false;
}

PhotonManager::~PhotonManager()
{
	if (causticMap)
		delete causticMap;
	if (indirectMap)
		delete indirectMap;
}

// set final gather
void PhotonManager::setFinalGatherRays(int nRays) 
{
	final_gather_rays = nRays;
	if (nRays > 0)
		final_gather = true;
}

// define gldraw for a photon map here
void Photon_map::glDraw() const
{
	glBegin(GL_POINTS);
	for( int i = 1; i <= stored_photons; ++i )
	{
		glVertex3f( photons[i].pos[0],photons[i].pos[1],photons[i].pos[2] );
	}
	glEnd();
	
}

// render the opengl maps
void PhotonManager::RenderMaps()
{
	// indirect photon map
	if (render_maps){
		glColor3f(0.0, 1.0, 0.0);
		indirectMap->glDraw();
		glColor3f(1.0, 0.0, 0.0);
		causticMap->glDraw();
	}
}

// local function for converting vectors to array
void vecToarray(Vector3 vector,float *arr)
{
	arr[0] = vector[0];
	arr[1] = vector[1];
	arr[2] = vector[2];
}

void PhotonManager::addPhoton(Photon_map* map,Vector3 power,Vector3 pos,Vector3 dir)
{
	float powerArr[3],posArr[3],dirArr[3];
	vecToarray(power,powerArr);
	vecToarray(pos,posArr);
	vecToarray(dir,dirArr);
	map->store(powerArr,posArr,dirArr);
}

void PhotonManager::ShootPhotons(Scene& scene)
{
	// reset photon maps
	causticMap = new Photon_map(no_caustic_photons);
	indirectMap = new Photon_map(no_indirect_photons);

	TraceIndirectPhotons(scene);
	TraceCausticPhotons(scene);

	indirectMap->scale_photon_power(1.0f/(float)no_indirect_photons);
	causticMap->scale_photon_power(1.0f/(float)(no_caustic_photons+no_indirect_photons));

	causticMap->balance();
	indirectMap->balance();

    Debug("Caustic map size is %d \n",causticMap->numberStored());
}

void PhotonManager::TraceCausticPhotons(Scene& scene)
{
	// start tracing caustic photons
	Debug("Tracing %d photons \n",no_caustic_photons);

	// set caustic trace to true
	caustic_trace = true;

	// get all the lights
	const LightList* lights = scene.GetLights();
	LightList::const_iterator l;

	// find photons per light
	int photons_per_light = no_caustic_photons/(float)lights->size();

	// modify the number of indirect photons to account for floating point errors
	no_caustic_photons = photons_per_light * lights->size();

	// go over all the lights
    for (l=lights->begin();l!=lights->end();l++)
	{
        Light* pLight = *l;

        // shoot photons
        for (int i=0;i<photons_per_light;i++){

        	// get photon direction and light power
        	Ray pDir = pLight->EmitPhoton();
        	scene.assignId(pDir);
        	Vector3 lPower = pLight->GetPower();

        	// construct the photon
        	PhotonRay pRay(pDir,lPower,PhotonRay::INDIRECT);

        	// trace this photon into the scene
        	TracePhoton(scene,pRay,0);
        }
    }
}

void PhotonManager::TraceIndirectPhotons(Scene& scene)
{
	// start tracing photons
	Debug("Tracing %d photons \n",no_indirect_photons);

	// set caustic trace to false
	caustic_trace = false;
	
	// get all the lights
	const LightList* lights = scene.GetLights();
	LightList::const_iterator l;

	// find photons per light
	int photons_per_light = no_indirect_photons/(float)lights->size();

	// modify the number of indirect photons to account for floating point errors
	no_indirect_photons = photons_per_light * lights->size();

	// go over all the lights
    for (l=lights->begin();l!=lights->end();l++)
	{
        Light* pLight = *l;

        // shoot photons
        for (int i=0;i<photons_per_light;i++){

        	// get photon direction and light power
        	Ray pDir = pLight->EmitPhoton();
        	scene.assignId(pDir);
        	Vector3 lPower = pLight->GetPower();

        	// construct the photon
        	PhotonRay pRay(pDir,lPower,PhotonRay::INDIRECT);

        	// trace this photon into the scene
        	TracePhoton(scene,pRay,0);
        }
    }

	
}

void PhotonManager::TracePhoton(Scene& scene,PhotonRay pRay, int depth)
{
	// start tracing the photon
	HitInfo minHit;

	// check depth
    if (depth>DEPTH_MAX)
        return;

	// trace the photon ray
	if (scene.Trace(minHit,pRay.p_dir)){

		// get average material properties
		Vector3 md = minHit.material->getDiffuse();
		Vector3 mr = minHit.material->getReflectance();
		Vector3 mt = minHit.material->getTransmittance();
		float md_avg = md.Average();
		float mr_avg = mr.Average();
		float mt_avg = mt.Average();

		// store photon if diffuse surface
		if (!(minHit.material->getDiffuse().isZero())){

			if (!caustic_trace){
				if (pRay.p_type == PhotonRay::INDIRECT){
					if (!final_gather){
						if (depth != 0 )
							addPhoton(indirectMap,pRay.power,minHit.P,pRay.p_dir.d);
					}else{
						addPhoton(indirectMap,pRay.power,minHit.P,pRay.p_dir.d);
					}
				} else if (pRay.p_type == PhotonRay::CAUSTIC){
					addPhoton(causticMap,pRay.power,minHit.P,pRay.p_dir.d);
					if (final_gather)
						addPhoton(indirectMap,pRay.power,minHit.P,pRay.p_dir.d);
				}
			}else{
				if (pRay.p_type == PhotonRay::CAUSTIC){
					addPhoton(causticMap,pRay.power,minHit.P,pRay.p_dir.d);
					return;
				}else{
					// no need to continue
					return;
				}
			}
		}

		// generate random
		float random = Sampler::rand01();

		// russian roulette
		if (random < md_avg){

			// diffuse scattering
			Vector3 ind_dir = scene.getScatterDirection(minHit.N);
			Ray indirectRay(minHit.P, ind_dir, Ray::PHOTON);
            scene.assignId(indirectRay);

            
            // create scatter photon
			PhotonRay scatterPhoton(indirectRay,
									pRay.power,
									PhotonRay::INDIRECT);

			// scale power to account for specteral reflectance 
			scatterPhoton.power = ArrayProd(pRay.power,md/md_avg);

			// keep tracing
			TracePhoton(scene,scatterPhoton,depth+1);

		}else if (random < md_avg + mr_avg){

			// determine type
			PhotonRay::Type type = pRay.p_type;
			if (depth == 0)
				type = PhotonRay::CAUSTIC;

			if ((minHit.N^pRay.p_dir.d) < 0.0){
				// trace reflected ray
	            Vector3 refDir = pRay.p_dir.d - 2 * minHit.N * (pRay.p_dir.d^minHit.N) ;
	            Ray refRay(minHit.P, refDir.Normalize(), Ray::PHOTON);
	            scene.assignId(refRay);

	            // new photon
	            PhotonRay reflectedPhoton(refRay,
	            						 pRay.power
	            						 	,type);

	            // scale power
	            reflectedPhoton.power = ArrayProd(pRay.power,mr/mr_avg);

	      		// trace photon
	      		TracePhoton(scene,reflectedPhoton,depth+1);
	        }

		}else if (random < md_avg + mr_avg + mt_avg){

			// determine type
			PhotonRay::Type type = pRay.p_type;
			if (depth == 0)
				type = PhotonRay::CAUSTIC;

			// refractive caustics handled 
			// trace refracted ray
            Ray refRay;
            if (scene.getRefractedRay(minHit,pRay.p_dir,refRay)){

                // assign ray id
                scene.assignId(refRay);
                refRay.t = Ray::PHOTON;

                // new photon
                PhotonRay transmitPhoton(refRay,
                						pRay.power
                						,type);

                // scale power
                transmitPhoton.power = ArrayProd(pRay.power,mt/mt_avg);

                // keep tracing
                TracePhoton(scene,transmitPhoton,depth+1);
            }

		}else{

			// absporption
		}
	}
}

// ---------------------------------------------------------------------
// Gather radiance
// ---------------------------------------------------------------------
Vector3 PhotonManager::radiance(HitInfo& minHit, Scene& scene)
{
	// // get the caustics estimate 
	Vector3 irrColor(0,0,0);

	// send the vector back after multiplying by the diffuse brdf
	irrColor += ArrayProd(minHit.material->getDiffuse()/PI,irradiance(causticMap,minHit,PhotonRay::CAUSTIC));

	// add final gather contribution
	if (final_gather)
		irrColor += finalGather(minHit,scene);
	else
		irrColor += ArrayProd(minHit.material->getDiffuse()/PI,irradiance(indirectMap,minHit,PhotonRay::INDIRECT));

	return irrColor;
}

// ---------------------------------------------------------------------
// Final Gather
// ---------------------------------------------------------------------
Vector3 PhotonManager::finalGather(HitInfo& minHit, Scene& scene)
{
	Vector3 indColor(0,0,0);

	// Debug("Doing final gather \n ");

	// trace final gather rays
	for (int i=0;i<final_gather_rays;i++){
		
		// get direction for gather ray
		Vector3 gatherDir = scene.getScatterDirection(minHit.N);
		Ray gatherRay(minHit.P,gatherDir,Ray::GATHER);
		scene.assignId(gatherRay);

		Vector3 gatherColor = scene.TraceRay(gatherRay,g_pCamera,0);
		indColor += ArrayProd(minHit.material->getDiffuse()
												,gatherColor);
	}

	return indColor/((float)final_gather_rays);
}

// ---------------------------------------------------------------------
// Irradiance
// ---------------------------------------------------------------------
Vector3 PhotonManager::irradiance(Photon_map* map,HitInfo& minHit,PhotonRay::Type type)
{
	float irr[3],pos[3],normal[3],photons_in_estimate;
	vecToarray(minHit.P,pos);
	vecToarray(minHit.N,normal);

	// get no photons in estimate
	if (type== PhotonRay::CAUSTIC)
		photons_in_estimate = no_photons_in_estimate_caustics;
	else if (type == PhotonRay::INDIRECT)
		photons_in_estimate = no_photons_in_estimate;

	// get the caustic estimate
	map->irradiance_estimate(irr,pos,normal,max_distance,photons_in_estimate);

	// send the vector back after multiplying by the diffuse brdf
	Vector3 irrColor(irr[0],irr[1],irr[2]);

	return irrColor;
}

// ---------------------------------------------------------------------
// Indirect Illumination
// ---------------------------------------------------------------------
Vector3 PhotonManager::indirectIllum(HitInfo& minHit,Scene& scene)
{
	// returns the indirect illumination from indirect photon map
	return irradiance(indirectMap,minHit,PhotonRay::INDIRECT);
}






