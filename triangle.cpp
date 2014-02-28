#include "triangle.h"


double AreaTriangle(Vector3 A,Vector3 B,Vector3 C){
	return 0.5*(((B-A)*(C-A)).Norm());
}

void Triangle::RenderGL()
{
	//box.RenderGL();
}

bool Triangle::IntersectLocal (HitInfo& result, const Ray& ray,
                float tMin, float tMax)
{
    // triangle ray intersection
    TriangleMesh::TupleI3 m_VIndices =  m_mesh->GetVIndices()[m_index];
	Vector3 verta = m_mesh->GetVertices()[m_VIndices.x];
	Vector3 vertb = m_mesh->GetVertices()[m_VIndices.y];
	Vector3 vertc = m_mesh->GetVertices()[m_VIndices.z];
	
	double a = verta.x-vertb.x;
	double b = verta.y-vertb.y;
	double c = verta.z-vertb.z;
	double d = verta.x-vertc.x;
	double e = verta.y-vertc.y;
	double f = verta.z-vertc.z;
	double g = ray.d.x;
	double h = ray.d.y;
	double i = ray.d.z;
	double j = verta.x-ray.o.x;
	double k = verta.y-ray.o.y;
	double l = verta.z-ray.o.z;

	double Beta,Gamma,t,M;

	M = a*(e*i-h*f)+b*(g*f-d*i)+c*(d*h-e*g);

	t = -(f*(a*k-j*b)+e*(j*c-a*l)+d*(b*l-k*c))/M;

	if ((t<tMin) || (t>tMax))
		return false;

	Gamma = (i*(a*k-j*b)+h*(j*c-a*l)+g*(b*l-k*c))/M;
	if (Gamma<0 || Gamma>1)
		return false;

	Beta = (j*(e*i-h*f)+k*(g*f-d*i)+l*(d*h-e*g))/M;
	if (Beta<0 ||  (Beta>(1-Gamma)))
		return false;

	

	result.t = t;

	result.P = ray.o+t*ray.d;

	TriangleMesh::TupleI3 m_NIndices =  m_mesh->GetNIndices()[m_index];
	Vector3 norma = m_mesh->GetNormals()[m_NIndices.x];
	Vector3 normb = m_mesh->GetNormals()[m_NIndices.y];
	Vector3 normc = m_mesh->GetNormals()[m_NIndices.z];
	
	
	double AreaABC = AreaTriangle(verta,vertb,vertc);
	double baryalpha =  AreaTriangle(result.P,vertb,vertc)/AreaABC;
	double barybeta = AreaTriangle(verta,result.P,vertc)/AreaABC;
	double barygamma = AreaTriangle(verta,vertb,result.P)/AreaABC;

	result.N = (baryalpha*norma+barybeta*normb+barygamma*normc).Normalize();
	result.material = this->m_material;

    return true;
}

BoundingBox Triangle::getLocalBoundingBox()
{
	TriangleMesh::TupleI3 m_VIndices =  m_mesh->GetVIndices()[m_index];
	Vector3 verta = m_mesh->GetVertices()[m_VIndices.x];
	Vector3 vertb = m_mesh->GetVertices()[m_VIndices.y];
	Vector3 vertc = m_mesh->GetVertices()[m_VIndices.z];

	verta = m_xTransform*Vector4(verta,1);
	vertb = m_xTransform*Vector4(vertb,1);
	vertc = m_xTransform*Vector4(vertc,1);

	Vector3 min(std::min(verta.x,std::min(vertb.x,vertc.x)),
		std::min(verta.y,std::min(vertb.y,vertc.y)),
		std::min(verta.z,std::min(vertb.z,vertc.z)));
	Vector3 max(std::max(verta.x,std::max(vertb.x,vertc.x)),
		std::max(verta.y,std::max(vertb.y,vertc.y)),
		std::max(verta.z,std::max(vertb.z,vertc.z)));

	return BoundingBox(min,max);
}