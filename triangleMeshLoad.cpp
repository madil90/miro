#include "triangleMesh.h"
#include "console.h"
#include <stdlib.h>
#include <iostream>

#ifndef max
#define max(a,b) ((a>b)?a:b)
#endif

void TriangleMesh::ComputeNormals()
{
	// get vertices
	Vector3 a = m_pVertices[0];
	Vector3 b = m_pVertices[1];
	Vector3 c = m_pVertices[2];

    // calculate normals
    Vector3 nu = m_pVertices[1]-m_pVertices[0];
    Vector3 nv = m_pVertices[2]-m_pVertices[1];

    // take cross product
    Vector3 normal = nu*nv;
    Vector3 n = normal.Normalize();

    // set normal
    m_pNormals[0] = n;
    m_pNormals[1] = n;
    m_pNormals[2] = n; 
}

void TriangleMesh::CreateSingleTriangle ()
{
    m_pNormals = new Vector3[3];
    m_pVertices = new Vector3[3];
    m_pTexCoords = new VectorR2[3];

    m_pTexCoords[0].x = 0.0f;
    m_pTexCoords[0].y = 0.0f;
    m_pTexCoords[1].x = 1.0f;
    m_pTexCoords[1].y = 0.0f;
    m_pTexCoords[2].x = 0.0f;
    m_pTexCoords[2].y = 1.0f;

    m_pNormalIndices = new TupleI3[1];
    m_pVertexIndices = new TupleI3[1];
    m_pTexCoordIndices = new TupleI3[1];

    m_pVertexIndices[0].x = 0;
    m_pVertexIndices[0].y = 1;
    m_pVertexIndices[0].z = 2;

    m_pNormalIndices[0].x = 0;
    m_pNormalIndices[0].y = 1;
    m_pNormalIndices[0].z = 2;

    m_pTexCoordIndices[0].x = 0;
    m_pTexCoordIndices[0].y = 1;
    m_pTexCoordIndices[0].z = 2;

    m_iNumTris = 1;
}


//************************************************************************
// Part of the parser was written by myself and 
// part by the original author
//************************************************************************

bool TriangleMesh::Load(char* file, char* group)
{
    FILE *fp = fopen( file, "rb" );
    if (!fp)
    {
        Error("Cannot open \"%s\" for reading\n",file);
        return false;
    }
    Debug("Loading \"%s\"...\n", file);

    LoadObj(fp, group);
    Debug("Loaded \"%s\" with %d triangles\n",file,m_iNumTris);
    fclose(fp);

    return true;
}

void get_indices(char *word, int *vindex, int *tindex, int *nindex)
{
    char *null = " ";
    char *ptr;
    char *tp;
    char *np;

    /* by default, the texture and normal pointers are set to the null string */

    tp = null;
    np = null;

    /* replace slashes with null characters and cause tp and np to point */
    /* to character immediately following the first or second slash */

    for (ptr = word; *ptr != '\0'; ptr++)
    {
        if (*ptr == '/')
        {
            if (tp == null)
                tp = ptr + 1;
            else
                np = ptr + 1;

            *ptr = '\0';
        }
    }

    *vindex = atoi (word);
    *tindex = atoi (tp);
    *nindex = atoi (np);
}


void TriangleMesh::LoadObj(FILE* fp, char* group)
{
    int nv=0, nt=0, nn=0, nf=0;
    char line[81];
    while ( fgets( line, 80, fp ) != NULL )
    {
        if (line[0] == 'v')
        {
            if (line[1] == 'n')
                nn++;
            else if (line[1] == 't')
                nt++;
            else
                nv++;
        }
        else if (line[0] == 'f')
        {
            nf++;
        }
    }
    fseek(fp, 0, 0);

    char* currentgroup = "default";
    char* groupall = "all";
    m_pNormals = new Vector3[max(nv,nf)];
    m_pVertices = new Vector3[nv];

    if (nt)
    { // got texture coordinates
        std::cout<<"This model has texture coordinates"<<std::endl;

        m_pTexCoords = new VectorR2[nt];
        m_pTexCoordIndices = new TupleI3[nf];
    }
    m_pNormalIndices = new TupleI3[nf]; // always make normals
    m_pVertexIndices = new TupleI3[nf]; // always have vertices

    m_iNumTris = 0;
    int nvertices = 0;
    int nnormals = 0;
    int ntextures = 0;

    while ( fgets( line, 80, fp ) != NULL )
    {
        if (line[0] == 'v')
        {
            if (line[1] == 'n')
            {
                float x, y, z;
                sscanf( &line[2], "%f %f %f\n", &x, &y, &z);
                Vector3 n(x, y, z);
                m_pNormals[nnormals] = n;
                m_pNormals[nnormals].Normalize();
                nnormals++;
            }
            else if (line[1] == 't')
            {
                float x, y;
                sscanf( &line[2], "%f %f\n", &x, &y);
                m_pTexCoords[ntextures].x = x;
                m_pTexCoords[ntextures].y = y;
                ntextures++;
            }
            else
            {
                float x, y, z;
                sscanf( &line[1], "%f %f %f\n", &x, &y, &z);
                Vector3 v(x, y, z);
                m_pVertices[nvertices] = v;
                nvertices++;
            }
        }
        else if (line[0] == 'f')
        {
            if (strcmp(currentgroup,group)!=0 && strcmp(group,groupall)!=0)
                continue;

            char s1[32], s2[32], s3[32];
            int v, t, n;
            sscanf( &line[1], "%s %s %s\n", s1, s2, s3);

            get_indices(s1, &v, &t, &n);
            m_pVertexIndices[m_iNumTris].x = v-1;
            if (n)
                m_pNormalIndices[m_iNumTris].x = n-1;
            if (t)
                m_pTexCoordIndices[m_iNumTris].x = t-1;
            get_indices(s2, &v, &t, &n);
            m_pVertexIndices[m_iNumTris].y = v-1;
            if (n)
                m_pNormalIndices[m_iNumTris].y = n-1;
            if (t)
                m_pTexCoordIndices[m_iNumTris].y = t-1;
            get_indices(s3, &v, &t, &n);
            m_pVertexIndices[m_iNumTris].z = v-1;
            if (n)
                m_pNormalIndices[m_iNumTris].z = n-1;
            if (t)
                m_pTexCoordIndices[m_iNumTris].z = t-1;

            if (!n)
            {   // if no normal was supplied
                Vector3 e1 = m_pVertices[m_pVertexIndices[m_iNumTris].y] -
                             m_pVertices[m_pVertexIndices[m_iNumTris].x];
                Vector3 e2 = m_pVertices[m_pVertexIndices[m_iNumTris].z] -
                             m_pVertices[m_pVertexIndices[m_iNumTris].x];

                m_pNormals[nn] = e1*e2;
                m_pNormalIndices[nn].x = nn;
                m_pNormalIndices[nn].y = nn;
                m_pNormalIndices[nn].z = nn;
                nn++;
            }

            m_iNumTris++;
        } else if (line[0]=='g')
        {
            char s1[128];
            sscanf(&line[2],"%s",s1);
            currentgroup=s1;
        }
        
        //  else ignore line
    }
}

