#include "miro.h"
#include "scene.h"
#include "camera.h"
#include "image.h"
#include <iostream>
#include <fstream>
#include "sampler.h"

using namespace std;

unsigned int numInt = 0;

Scene::Scene () :
    m_bsp (new BSPTree ()) ,
		g_iShotIdx(-1) , samplesX(1)
        , samplesY(1) , m_shutterTime(0),
        m_currentTime(0) ,
        path_trace(false)
{
    //ambient = Vector3(0,0,0);

    // set the file no to save
    char str[256];
    bool done = false;
    
    while (!done){
        sprintf(str, "miro_%04d.bmp", g_iShotIdx+1);
        std::ifstream file(str);
        if (file){
            g_iShotIdx++;
        }else{
            done = true;
        }
    }
    int  a = g_iShotIdx;
}

Scene::~Scene ()
{
	// delete the bsp tree
    delete m_bsp;
	
	// free up all the lights
	std::list<Light*>::iterator it;
	for (it=m_kLights.begin();it!=m_kLights.end();it++){
		delete *it;
	}
}

void Scene::SetPathTrace(bool pathtrace)
{
     path_trace = pathtrace;

     if (path_trace)
        std::cout<<"Path Tracing Enabled !!"<<std::endl;
}

int Scene::getShotNo()
{
	g_iShotIdx++;
	return g_iShotIdx;
}

void Scene::assignId(Ray& ray)
{
    ray.rayId = m_bsp->getCurrentId();
}

void Scene::OpenGL(Camera *cam)
{
    glDrawBuffer(GL_BACK);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // set up the screen with our camera parameters
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective(cam->GetFOV(), g_pImage->Width()/(float)g_pImage->Height(), .01, 10000);
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    Vector3 vCenter = cam->GetEye() + cam->GetViewDir();
    gluLookAt( cam->GetEye().x, cam->GetEye().y, cam->GetEye().z,
               vCenter.x, vCenter.y, vCenter.z,
               cam->GetUp().x, cam->GetUp().y, cam->GetUp().z);

    glEnable( GL_DEPTH_TEST );
    m_bsp->RenderGL();
    glDisable(GL_DEPTH_TEST);

    glutSwapBuffers();
}

void Scene::PreCalc()
{
    m_bsp->PreCalc ();

    LightList::iterator lit;
    for (lit = m_kLights.begin(); lit != m_kLights.end(); lit++)
    {
        Light* pLight = *lit;
        pLight->PreCalc();
    }
}

// get the refracted ray
bool getRefractedRay(HitInfo& hit, Ray& ray, Ray& refRay)
{
    float n1,n2;
    float NdotI = hit.N^ray.d;
    Vector3 normal = hit.N;

    if (NdotI < 0.0){ // if entering the material
        n1 = 1.0003; // air
        n2 = hit.material->getIndex();
    }else{   // if leaving the material
        n1 = hit.material->getIndex();
		n2 = 1.0003; // air
        normal = -normal;
    }

    float n_it = n1/n2;
    float Ci = -(normal^ray.d);
    float under_radical = 1.0 - n_it*n_it*(1 - Ci*Ci );

    // total internal reflection if negative
    if (under_radical >0){
        Vector3 refDir = ( n_it*ray.d ) + (n_it*Ci - sqrt(under_radical)) * normal;

        refRay = Ray(hit.P, refDir.Normalize(), Ray::REFRACTION);
        return true;
    }else{
        return false;
    }
}



void Scene::RaytraceImage(Camera *cam, Image *img)
{
    // TODO write ray tracing code here
    // Ray trace the entire image, i.e. trace a ray for every pixel in the image
    
    // initialize variables
    int imageWidth = img->Width();
    int imageHeight = img->Height();
    time_t begin,end;
    noOfRays = 0;

    // start time and clear tags
    time(&begin);
    m_bsp->clearTAG();

    // begining ray tracing here
    for (int y=0;y<imageHeight;y++){
        //int ray_hits = 0;
        for (int x=0;x<imageWidth;x++){

            // trace the current pixel
            img->SetPixel(x,y,TracePixel(x,y,imageWidth,imageHeight,cam));
        }
        
		std::cout<<"Done Line No : "<<y<<std::endl;
        //std::cout<<"Ray Hits : "<<ray_hits<<std::endl;
		//m_bsp->printStats();
    }
    time(&end);

    // print time taken
    double time_taken = difftime(end,begin);
    int minutes = time_taken/60;
    double seconds = (time_taken-minutes*60);
    std::cout<<"Time Taken : "<<minutes<<" mins "<<seconds<<" secs"<<std::endl;

    // print bsp tree stats
    m_bsp->printStats();
}

Vector3 Scene::TracePixel(int x, int y, int imageWidth, int imageHeight, Camera* cam)
{
    Vector3 color(0,0,0);
    HitInfo minHit;

    // sampling a pixel
    int total = samplesX * samplesY;
    
    // antialiasing and motion
    Sample* samples = Sampler::generateStratifiedSamples(samplesX,samplesY);

    for (int i=0;i<total;i++){

        // set scene time
        if (m_shutterTime>0)
            m_currentTime = Sampler::rand01()*m_shutterTime;

        // Constructing primary rays
        Ray ray = cam->EyeRay(x + samples[i].x,y + samples[i].y,imageWidth,imageHeight);

        // assign a ray id
        assignId(ray);

        // trace ray in scene
        color += TraceRay(ray,cam,0);
    }

    // delete the samples
    delete [] samples;
    
    // return the average
    return color/total;
}

// traces a ray and returns the color
Vector3 Scene::TraceRay(Ray& ray, Camera* cam, int depth)
{
	Vector3 color(0,0,0);
	HitInfo minHit;

    // check depth
    if (depth>DEPTH_MAX)
        return color;

    // Tracing a ray
    if (Trace(minHit,ray)){
        
		//std::cout<<"Came past trace"<<std::endl;

        color+= minHit.material->Shade(ray,minHit,*this);

        if ((! (minHit.material->getReflectance().isZero())) &&
                ( (minHit.N^ray.d) < 0.0) ){
            
            // trace reflected ray
            Vector3 refDir = ray.d - 2 * minHit.N * (ray.d^minHit.N) ;
            Ray refRay(minHit.P, refDir.Normalize(), Ray::REFLECTION);
            assignId(refRay);

            // get reflected color
            color += ArrayProd(minHit.material->getReflectance(),TraceRay(refRay,cam,depth+1));
        }
        
        // get ray out instead of boolean
        if (! (minHit.material->getTransmittance().isZero())){

            // trace refracted ray
            Ray refRay;
            if (getRefractedRay(minHit,ray,refRay)){

                // assign ray id
                assignId(refRay);

                // refractive color
                color += ArrayProd(minHit.material->getTransmittance(), TraceRay(refRay,cam,depth+1));
            }
        }

        // send indirect illumination ray
        if (path_trace){

            // russian roulette
            Vector3 diff_ref = minHit.material->getDiffuse();
            float p_cont;

            // check if min depth reached
            if (depth>=DEPTH_MIN)
                p_cont = std::max(diff_ref.x,std::max(diff_ref.y,diff_ref.z));
            else
                p_cont = 1.0f;

            if (Sampler::rand01() < p_cont){
                
				// generate ray in hemisphere
                Vector3 ind_dir = getScatterDirection(minHit.N);
                Ray indirectRay(minHit.P, ind_dir, Ray::INDIRECT);
                assignId(indirectRay);

                if ((ind_dir^minHit.N) < 0.0)
					std::cout<<"direction wrong "<<(ind_dir^minHit.N)<<std::endl;  

                // trace ray
                Vector3 ind_light = TraceRay(indirectRay, cam, depth+1);
				Vector3 ind_diff = ArrayProd(ind_light,diff_ref);
                Vector3 ind_color = (ind_diff ) * (1.0/p_cont);

                // add this to the color
                color += ind_color;
            }
        }
        
    }else{
		if (ray.t != Ray::INDIRECT)
			return cam->GetBGColor();
		else
			return Vector3(0,0,0);
    }
	return color;
}

Vector3 Scene::getScatterDirection(Vector3 N)
{
	Vector3 dir(0,0,0);

	bool done = false;
	while (!done){
		float r1 = Sampler::rand01();
		float r2 = Sampler::rand01();

		float theta = acos(sqrt(r1));
		float phi = 2*PI*r2;

		float xd = sinf(theta)*cosf(phi);
		float yd = sinf(theta)*sinf(phi);
		float zd = cosf(theta);

		Vector3 z = N;
		Vector3 axis(0,0,0);
		if (fabs(N.x) < fabs(N.y) && fabs(N.x) < fabs(N.z))
			axis = Vector3(1.0f,0.0f,0.0f);
		else if (fabs(N.y) < fabs(N.z))
			axis = Vector3(0.0f,1.0f,0.0f);
		else
			axis = Vector3(0.0f,0.0f,1.0f);

		Vector3 x = (N*axis).Normalize();
		Vector3 y = (N*x);   // todo : remove this and see if it works

		dir = x*xd + y*yd + z*zd;
		dir.Normalize();

		if ( (N^dir) < 0.0f)
			done = false;
		else
			done = true;
	}
	return dir;
}

bool Scene::Trace(HitInfo& minHit, const Ray& ray, float tMin, float tMax) const
{
    // TODO, write Trace function here.
    // Iterate over all objects in the scene and store the minimum hit value
    // within the interval in minHit. Return true iff an object was hit.
    bool did_intersect = m_bsp->Intersect(minHit,ray,tMin,tMax);
    return did_intersect;
}


