#include "sphere.h"
#include <iostream>

Sphere::Sphere()
{
	// default sphere
	m_vCenter = Vector3(0,0,0);
	m_fRadius = 1;
}

Sphere::~Sphere()
{
}

void Sphere::RenderGL()
{
    float *m = MatToFloat(m_xTransform);
    glColor3f(1, 1, 1);
    glPushMatrix();
    glMultMatrixf(m);
    glTranslatef(m_vCenter.x, m_vCenter.y, m_vCenter.z);
    glutWireSphere(m_fRadius, 20, 20);
    glPopMatrix();

    // render bounding box
    //box.RenderGL();
}

bool Sphere::IntersectLocal (HitInfo& result, const Ray& ray,
                float tMin, float tMax)
{
    // TODO

    float a = ray.d^ray.d;
	float b = 2*(ray.d^ (ray.o-m_vCenter));
	float c = ((ray.o-m_vCenter)^(ray.o-m_vCenter))-(m_fRadius*m_fRadius);

	float det = b*b-4*a*c;

	if (det<0)
		return false;

	float t0 = (-b+sqrt(det))/(2*a);
	float t1 = (-b-sqrt(det))/(2*a);

	if (t0>t1){
		float temp = t0;
		t0 = t1;
		t1 = temp;
	}

	if (t0>tMax)
		return false;
	if (t1<tMin)
		return false;
	
	if (t0>tMin)
		result.t = t0;
	else
		result.t = t1;

	result.P = Vector3(ray.o+result.t*(ray.d));
	result.N = (result.P-m_vCenter).Normalize();
	result.material = this->m_material;
    return true;
}

// bounding box for a sphere
BoundingBox Sphere::getLocalBoundingBox()
{
	Vector3 min(m_vCenter.x-m_fRadius,m_vCenter.y-m_fRadius,m_vCenter.z-m_fRadius);
	Vector3 max(m_vCenter.x+m_fRadius,m_vCenter.y+m_fRadius,m_vCenter.z+m_fRadius);

	min = m_xTransform*Vector4(min,1);
	max = m_xTransform*Vector4(max,1);

	BoundingBox localBox(min,max);

	return localBox;
}
