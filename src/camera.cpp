#include <stdio.h>
#include "miro.h"
#include "camera.h"
#include "image.h"
#include "scene.h"
#include "Sampler.h"

Camera::Camera()
{
    // set lens model parameters
    m_apertureSize = 0;
    m_focalLength = -1;
    m_focalPoint = Vector3(0,0,0);

    // default to at origin looking in -z (OpenGL style)
    m_vEye.Set(0, 0, 0);
    m_vViewDir.Set(0, 0, -1);
    m_vUp.Set(0, 1, 0); // y axis is up
    m_rFOV = (45.)*(PI/180.); // 45 degrees in radians
    m_vLookAt.Set(FLT_MAX, FLT_MAX, FLT_MAX);
    CalcLookAt();
    m_iRenderer = RENDER_OPENGL;
    isTraced = false;
}

Camera::~Camera()
{}

void Camera::Click(Scene* pScene, Image* pImage)
{
    CalcLookAt();
    if (m_iRenderer == RENDER_OPENGL)
    {
        glDrawBuffer(GL_BACK); // for double buffering
        pScene->OpenGL(this);
    }
    else if (m_iRenderer == RENDER_RAYTRACE)
    {
        glMatrixMode( GL_PROJECTION );
        glLoadIdentity();
        glMatrixMode( GL_MODELVIEW );
        glLoadIdentity();
        glDrawBuffer(GL_FRONT);
        if (!isTraced){
            pImage->Clear(GetBGColor());
            pScene->RaytraceImage(this, g_pImage);
            g_pImage->WriteBMP("default.bmp");
            isTraced = true;
        }
        g_pImage->Draw();
    }
}

void Camera::CalcLookAt()
{
    // this is true when a "lookat" is not used in the config file
    if (m_vLookAt.x != FLT_MAX)
    {
        SetLookAt(m_vLookAt);
        m_vLookAt.Set(FLT_MAX, FLT_MAX, FLT_MAX);
    }
}

Ray Camera::EyeRay(float x, float y, int imageWidth, int imageHeight)
{
    // TODO, calculate the camera transformation and return an
    // eye ray for the designated pixel
    

    // setting the canonical transform
    Vector3 w = (-m_vViewDir).Normalize();
    Vector3 u = (m_vUp*w).Normalize();
    Vector3 v = (w*u).Normalize();

    // setting the viewing plane
    float t = tan((m_rFOV/2)*(PI/180));
    float r = t*(float(imageWidth)/float(imageHeight));

    float uij = -r+((2*r)*(x/imageWidth));
    float vij = -t+((2*t)*(y/imageHeight));

    // primary ray in camera co-ordinates
    Vector4 s(uij,vij,-1,1);

    Matrix4x4 m;
    m.SetColumn1(Vector4(u,0));
    m.SetColumn2(Vector4(v,0));
    m.SetColumn3(Vector4(w,0));
    m.SetColumn4(m_vEye);

    Vector4 canEye = m*Vector4(0,0,0,1);
    Vector4 canDir = m*s-canEye;

    return LensRay(Ray(Vector3(canEye),Vector3(canDir),Ray::DIRECT), m);
}

Ray Camera::LensRay(Ray eyeRay, Matrix4x4 m)
{
    Vector3 canEye = eyeRay.o;
    Vector3 canDir = eyeRay.d;

    if (m_apertureSize > 0.0)
    {
        // set focal length and aperturesize
        if (m_focalLength < 0.0)
            m_focalLength = (m_focalPoint - canEye).Norm();
        //float m_focalLength = (Vector3(4.03,1,3.88)-Vector3(canEye)).Norm();
        
        // calculating point of focus
        Vector3 focusPoint = Vector3(canEye) + m_focalLength * Vector3(canDir);

        // pick points on a disk
        float randR = sqrt(Sampler::rand01());
        float randTheta = 2*PI*Sampler::rand01();
        float randX = randR*cos(randTheta);
        float randY = randR*sin(randTheta);

        // make new random eye
        Vector4 lensEye(randX*m_apertureSize,randY*m_apertureSize,0,1 );
        Vector3 lensPos = m*lensEye;

        // calculate direction
        Vector3 lensDir = (focusPoint - lensPos).Normalize();

        return Ray(lensPos, lensDir,Ray::DIRECT);
    }else{
        return eyeRay;
    }
}
