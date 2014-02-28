#include "object.h"
#include "ray.h"
#include "scene.h"
#include <iostream>

Object::Object()
{
	m_xTransform.SetIdentity();
	m_xTransformInv = m_xTransform;
	m_xTransformInv.Invert();
}

void Object::PreCalc()
{
	box = getLocalBoundingBox();
}

void Object::SetTransformation (Matrix4x4 m_transform)
{
	m_xTransform = m_transform; 
	m_xTransformInv = m_transform; 
	m_xTransformInv.Invert();
}

bool Object::Intersect (HitInfo& result, const Ray& ray,
	                        float tMin, float tMax)
{
	//std::cout<<"Checking intersection"<<std::endl;

	// handle motion
	Vector3 motion = g_pScene->getCurrentTime()*m_velocity;

	if (motion.isZero()){
		return Intersect(result,ray,m_xTransform,m_xTransformInv,tMin,tMax);
	} else{
		Matrix4x4 transform;
	    transform.SetIdentity();
	    transform.SetColumn4(Vector4(motion, 1));
	    transform = m_xTransform*transform;
	    Matrix4x4 transformInv = transform;
	    transformInv.Invert();

	    return Intersect(result,ray,transform,transformInv,tMin,tMax);
	}
}

// intersect function after motion
bool Object::Intersect (HitInfo& result, const Ray& ray,
						Matrix4x4 transform, Matrix4x4 transformInv,
	                        float tMin, float tMax)
{
	Ray transform_ray = Transform_Ray(ray,transformInv);
	
	if (!IntersectLocal(result,transform_ray)){
		return false;
	}
	else{
		TransformHitInfo(result,transform);
		return true;
	}
}

// default local intersection for all objects
bool Object::IntersectLocal (HitInfo& result, const Ray& ray,
	                        float tMin, float tMax)
{
	return false;
}

// object tagging
void Object::clearTAG()
{
	rayId = -std::numeric_limits<float>::max();
}

void Object::setTAG(int tag){
	if (tag>=0)
		rayId = tag;
}

int Object::getTAG(){
	return rayId;
}