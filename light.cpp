#include "light.h"
#include "ray.h"
#include "scene.h"



void PointLight::RenderGL(){
    glColor3f(1, 1, 0);
    glPushMatrix();
        glTranslatef(m_vPos.x, m_vPos.y, m_vPos.z);
		glutWireSphere(0.1,10,10);
    glPopMatrix();
}

Vector3 PointLight::GetColor(){
	return m_vColor;
}

Vector3 PointLight::GetDirection(const Vector3 &pos){
	return (m_vPos-pos).Normalize();
}

LightInfo PointLight::GetLightInfo(const Vector3 &pos)
{
	float dist = (m_vPos-pos).Norm();
	Vector3 dir = (m_vPos-pos).Normalize();
	float att = m_fWattage/((dist*dist));  // not using the 4 pi factor
	return LightInfo( Ray(pos, dir,Ray::SHADOW), dist, att );
}

Vector3 DirectionalLight::GetColor(){
	return m_vColor;
}

Vector3 DirectionalLight::GetDirection(const Vector3 &pos){
	return -m_vDir;
}

LightInfo DirectionalLight::GetLightInfo(const Vector3 &pos){
	float dist = std::numeric_limits<float>::max();
	Vector3 dir = -m_vDir;
	return LightInfo( Ray(pos,dir,Ray::SHADOW) , dist, 1);
}

void DirectionalLight::RenderGL()
{
	// get maximum point
	glColor3f(1,1,0);
	Vector3 start = Vector3(0,0,0)+100*m_vDir;

	glLineWidth(3);
	glBegin(GL_LINES);
		glVertex3f(start.x,start.y,start.z);
		glVertex3f(-start.x,-start.y,-start.z);
	glEnd();
	glLineWidth(1);
}