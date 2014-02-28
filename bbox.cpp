#include "bbox.h"
#include "ray.h"
#include "triangle.h"
#include "math.h"

BoundingBox::BoundingBox(Vector3 min, Vector3 max)
{
	minimum = min;
	maximum = max;
}

Vector3 BoundingBox::Max()
{
	return maximum;
}

Vector3 BoundingBox::Min()
{
	return minimum;
}

float BoundingBox::Area()
{
	return fabs(maximum.x-minimum.x)*fabs(maximum.y-minimum.y)*fabs(maximum.z-minimum.z);
}

void BoundingBox::RenderGL()
{
	Vector3 bounds[8];
	bounds[0] = Vector3(maximum.x, maximum.y, minimum.z);
    bounds[1] = Vector3(minimum.x, maximum.y, minimum.z);
    bounds[2] = Vector3(minimum.x, minimum.y, minimum.z);
    bounds[3] = Vector3(maximum.x, minimum.y, minimum.z);
    bounds[4] = Vector3(maximum.x, minimum.y, maximum.z);
    bounds[5] = Vector3(maximum.x, maximum.y, maximum.z);
    bounds[6] = Vector3(minimum.x, maximum.y, maximum.z);
    bounds[7] = Vector3(minimum.x, minimum.y, maximum.z);

	glColor3f(0.0f, 1.0f, 0.0f);

    glBegin(GL_LINE_LOOP);
        glVertex3f(bounds[0].x, bounds[0].y, bounds[0].z);
        glVertex3f(bounds[1].x, bounds[1].y, bounds[1].z);
        glVertex3f(bounds[2].x, bounds[2].y, bounds[2].z);
        glVertex3f(bounds[3].x, bounds[3].y, bounds[3].z);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex3f(bounds[4].x, bounds[4].y, bounds[4].z);
        glVertex3f(bounds[5].x, bounds[5].y, bounds[5].z);
        glVertex3f(bounds[6].x, bounds[6].y, bounds[6].z);
        glVertex3f(bounds[7].x, bounds[7].y, bounds[7].z);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex3f(bounds[0].x, bounds[0].y, bounds[0].z);
        glVertex3f(bounds[5].x, bounds[5].y, bounds[5].z);
        glVertex3f(bounds[6].x, bounds[6].y, bounds[6].z);
        glVertex3f(bounds[1].x, bounds[1].y, bounds[1].z);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex3f(bounds[4].x, bounds[4].y, bounds[4].z);
        glVertex3f(bounds[7].x, bounds[7].y, bounds[7].z);
        glVertex3f(bounds[2].x, bounds[2].y, bounds[2].z);
        glVertex3f(bounds[3].x, bounds[3].y, bounds[3].z);
    glEnd();


}



bool BoundingBox::intersect(const Ray& ray,float &tmin,float &tmax,float t0,float t1)
{
	Vector3 inv_d;
	int sign_[3];

	for( unsigned int i = 0; i < 3; ++i )
	{
		inv_d[i] = 1. / ray.d[i];
		sign_[i] = (inv_d[i] < 0);
	}

	tmin = ((parameter(sign_[0])).x - ray.o.x) * inv_d.x;
	tmax = ((parameter(1-sign_[0])).x - ray.o.x) * inv_d.x;
	
	float tymin = ((parameter(sign_[1])).y - ray.o.y) * inv_d.y;
	float tymax = ((parameter(1-sign_[1])).y - ray.o.y) * inv_d.y;
	 
	if ( (tmin > tymax) || (tymin > tmax) ) 
		return false;
	if (tymin > tmin)
		tmin = tymin;
	if (tymax < tmax)
		tmax = tymax;

	float tzmin = ((parameter(sign_[2])).z - ray.o.z) * inv_d.z;
	float tzmax = ((parameter(1-sign_[2])).z - ray.o.z) * inv_d.z;
	
	if ( (tmin > tzmax) || (tzmin > tmax) ) 
		return false;
	if (tzmin > tmin)
		tmin = tzmin;
	if (tzmax < tmax)
		tmax = tzmax;

	  return ( (tmin < t1) && (tmax > t0) );
}

bool BoundingBox::intersects(const BoundingBox &target) const
{
	return (((target.minimum)[0] - MIRO_TMIN <= (maximum)[0]) && ((target.maximum)[0] + MIRO_TMIN >= (minimum)[0]) &&
			((target.minimum)[1] - MIRO_TMIN <= (maximum)[1]) && ((target.maximum)[1] + MIRO_TMIN >= (minimum)[1]) &&
			((target.minimum)[2] - MIRO_TMIN <= (maximum)[2]) && ((target.maximum)[2] + MIRO_TMIN >= (minimum)[2]));
}

void BoundingBox::expand(BoundingBox box)
{
	Vector3 boxMin = box.Min();
	Vector3 boxMax = box.Max();

	minimum.x = std::min(boxMin.x,minimum.x);
	minimum.y = std::min(boxMin.y,minimum.y);
	minimum.z = std::min(boxMin.z,minimum.z);
	
	maximum.x = std::max(boxMax.x,maximum.x);
	maximum.y = std::max(boxMax.y,maximum.y);
	maximum.z = std::max(boxMax.z,maximum.z);
}

void BoundingBox::expand(Vector3& point)
{
	minimum[0] = std::min(minimum[0],point[0]);
	minimum[1] = std::min(minimum[1],point[1]);
	minimum[2] = std::min(minimum[2],point[2]);

	maximum[0] = std::max(maximum[0],point[0]);
	maximum[1] = std::max(maximum[1],point[1]);
	maximum[2] = std::max(maximum[2],point[2]);
}

void BoundingBox::transformBox(Matrix4x4& mat)
{

	for (int i=0; i<2; i++){
		for (int j=0; j<2; j++){
			for (int k=0; k<2; k++){
				Vector3 point = mat*Vector4(
					i==0 ? minimum[0] : maximum[0],
					j==0 ? minimum[1] : maximum[1],
					k==0 ? minimum[2] : maximum[2] , 1);
				expand(point);
			}
		}
	}
}