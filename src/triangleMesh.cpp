#include "triangleMesh.h"
#include "triangle.h"
#include "scene.h"

void TriangleMesh::RenderGL()
{
    glColor3f(1, 1, 1);

    float *m = MatToFloat(m_xTransform);
    glPushMatrix();
    glMultMatrixf(m);
    
    // use vertex buffers
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, m_pVertices);
    glDrawElements(GL_TRIANGLES, 3*m_iNumTris, GL_UNSIGNED_INT, m_pVertexIndices);
    glDisableClientState(GL_VERTEX_ARRAY);
	glPopMatrix();
}

TriangleMesh::TriangleMesh()
{
    m_pNormals = 0;
    m_pVertices = 0;
    m_pTexCoords = 0;
    m_pNormalIndices = 0;
    m_pVertexIndices = 0;
    m_pTexCoordIndices = 0;
}

TriangleMesh::~TriangleMesh()
{
    delete [] m_pNormals;
    delete [] m_pVertices;
    delete [] m_pTexCoords;
    delete [] m_pNormalIndices;
    delete [] m_pVertexIndices;
    delete [] m_pTexCoordIndices;
}

/*
    The TriangleMesh class is only used to stored shared data for triangles.
    It does not itself perform the ray intersection calculation. Each individual
    mesh triangle does that.
*/
bool TriangleMesh::Intersect (HitInfo& result, const Ray& ray,
                float tMin, float tMax)
{
    return false;
}

/*
    Refine will create an instance of a Triangle class for each triangle in the
    mesh and add it to the list of objects
*/
bool TriangleMesh::Refine(ObjectList& objects)
{
	// for single triangle
	if (m_iNumTris == 1){
		Vector3 n = m_pNormals[0];
		if (n.x == 0 && n.y == 0 && n.z == 0 )
			ComputeNormals();
	}

    for (size_t i = 0; i < m_iNumTris; ++i)
    {
        Triangle* t = new Triangle;
        t->SetIndex (i);
        t->SetMesh (this);
        t->SetMaterial(this->m_material);
        t->SetTransformation(m_xTransform);
        objects.push_back (t);
    }
    
    return m_iNumTris > 0;
}
