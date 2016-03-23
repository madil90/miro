#ifndef _PHOTON_MANAGER_H_
#define _PHOTON_MANAGER_H_

#include "photonmap.h"
#include "ray.h"

class Scene;

// the photon class
// called photon ray to differentiate from 
// photons used in the photon map
struct PhotonRay{
public:
	// defining enum for type of photons
	enum Type{
		INDIRECT,
		CAUSTIC
	};

	// constructor
	PhotonRay(Ray pDir,Vector3 pow,Type pType) :
				p_dir(pDir),power(pow),p_type(pType) {}

	// defining photon properties
	Ray p_dir;     	// photon ray
	Vector3 power;	// photon power
	Type p_type;	// photon type (to store in different maps)
};


// class for implement photon tracing etc
// creates and keeps the photon maps
class PhotonManager{
public:
	// photon maps
	PhotonManager();
	~PhotonManager();

	// render maps
	void RenderMaps();

	// set render variable
	void setRenderMaps(bool render) {render_maps = render;}
	bool getRenderMaps() {return render_maps;}

	// radiance at a point
	Vector3 radiance(HitInfo& minHit,Scene& scene);
	Vector3 irradiance(Photon_map* map,HitInfo& minHit,PhotonRay::Type type);
	Vector3 finalGather(HitInfo& minHit,Scene& scene);
	Vector3 indirectIllum(HitInfo& minHit,Scene& scene);

	// trace caustic photons
	void TraceCausticPhotons(Scene& scene);

	// trace indirect photons
	void TraceIndirectPhotons(Scene& scene);

	// trace photons
	void TracePhoton(Scene& scene,PhotonRay pRay, int depth);

	// shoot photons in the scene
	void ShootPhotons(Scene& scene);

	// add photon to a photon map
	void addPhoton(Photon_map* map,Vector3 power,Vector3 pos,Vector3 dir);

	// functions for options
	void setNoPhotonsInEstimate(int nPhotons){no_photons_in_estimate = nPhotons;}
	void setNoPhotonsInCausticEstimate(int nPhotons) {no_photons_in_estimate_caustics = nPhotons;}
	void setNoCausticPhotons(int nPhotons) { no_caustic_photons = nPhotons;}
	void setNoIndirectPhotons(int nPhotons) { no_indirect_photons = nPhotons;}
	void setFinalGatherRays(int nRays);

protected:
	Photon_map* causticMap;
	Photon_map* indirectMap;

	// photon mapping options
	int no_caustic_photons;
    int no_indirect_photons;
    int no_photons_in_estimate;
    int no_photons_in_estimate_caustics;
    float max_distance;
    int final_gather_rays;

    // other options
    bool render_maps;
    bool final_gather;

    // tracing caustics or indirect
    bool caustic_trace;
};

#endif