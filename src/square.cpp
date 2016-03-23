#include "square.h"

Square::Square()
	: m_vCenter(0,0,0)
{

}

// renderGL function
void Square::RenderGL()
{
	bool isLight = !m_material->getEmissive().isZero();
	if (!isLight)
		glColor3f(1,1,1);
	else 
		glColor3f(1,1,0);
		
	float* m = MatToFloat(m_xTransform);
	glPushMatrix();
	glMultMatrixf(m);
	glTranslatef(m_vCenter.x,m_vCenter.y,m_vCenter.z);
	glBegin(GL_QUADS);
		glVertex3f(-0.5,0.5,0.0f);
		glVertex3f(0.5,0.5,0.0f);
		glVertex3f(0.5,-0.5,0.0f);
		glVertex3f(-0.5,-0.5,0.0f);
	glEnd();

	if (isLight){
		glLineWidth(2);
		glBegin(GL_LINES);
			glVertex3f(0,0,0);
			glVertex3f(0,0,1);
		glEnd();
		glLineWidth(1);
	}

	glPopMatrix();

}


bool Square::IntersectLocal (HitInfo& result, const Ray& ray,
                            float tMin, float tMax)
{
	Vector3 p = ray.o;
	Vector3 d = ray.d;


	if ( d[2] == 0.0)
		return false;

	float t = - p[2]/d[2];

	if ( t <= tMin)
		return false;

	Vector3 P = ray.o + t*ray.d;

	if ( P[0] < -.5 || P[0] > 0.5)
		return false;

	if ( P[1] < -0.5 || P[1] > 0.5)
		return false;

	result.P = ray.o + t* ray.d;

	if ( d[2] > 0.0)
		result.N = Vector3(0,0,-1);
	else
		result.N = Vector3(0,0,1);

	result.N.Normalize();
	result.material = this->m_material;
	result.t = t;

	return true;
}

BoundingBox Square::getLocalBoundingBox()
{
	// get four sides
	Vector3 a = m_xTransform*Vector4(0.5,0.5,0,1);
	Vector3 b = m_xTransform*Vector4(-0.5,0.5,0,1);
	Vector3 c = m_xTransform*Vector4(-0.5,-0.5,0,1);
	Vector3 d = m_xTransform*Vector4(0.5,-0.5,0,1);

	// get minimum and maximum
	Vector3 min( std::min(a.x,std::min(b.x,std::min(c.x,d.x))) 
				,std::min(a.y,std::min(b.y,std::min(c.y,d.y))) 
				,std::min(a.z,std::min(b.z,std::min(c.z,d.z))) );
	Vector3 max( std::max(a.x,std::max(b.x,std::max(c.x,d.x))) 
				,std::max(a.y,std::max(b.y,std::max(c.y,d.y))) 
				,std::max(a.z,std::max(b.z,std::max(c.z,d.z))) );

	BoundingBox mBox(min,max);
	return mBox;
}