#include "instance.h"

Instance::Instance() : m_geometry (0)
{
}

Instance::~Instance()
{
	if (m_geometry)
		delete m_geometry;
}

void Instance::SetGeometry(Object* g, const Matrix4x4& ctm)
{
    // set the geometry and the current transform matrix.
    // also compute the inverse transform for convenience
    m_geometry = g;
    m_xform = m_xformInv = ctm;
    m_xformInv.Invert ();
}

void Instance::RenderGL()
{
    // TODO
}

bool Instance::Intersect (HitInfo& result, const Ray& ray,
                float tMin, float tMax)
{
    // TODO
    
    return false;
}
