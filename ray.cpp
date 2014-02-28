#include "ray.h"

Ray Transform_Ray(const Ray& ray, Matrix4x4& mat)
{
	Ray transform_ray;
	transform_ray.d = mat*Vector4(ray.d,0);
	transform_ray.o = mat*Vector4(ray.o,1);
	transform_ray.t = ray.t;
	transform_ray.rayId = ray.rayId;
	return transform_ray;
}

void TransformHitInfo(HitInfo& result,Matrix4x4 mat)
{
	result.P = mat*Vector4(result.P,1);
	Matrix4x4 matN = mat.Invert();
	matN.MakeTranspose();
	Vector4 cNormal = (matN*Vector4(result.N,0));  // this is the converted normal
	Vector3 normal(cNormal.x,cNormal.y,cNormal.z);    // through the w
	result.N = normal.Normalize();
}