#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "Vector.h"
#include "miro.h"
#include "ray.h"

class Camera
{
public:
    Camera();
    virtual ~Camera();

    enum {
        RENDER_OPENGL = 0,
        RENDER_RAYTRACE
    };

    void Click(Scene* pScene, Image* pImage);

    inline bool IsOpenGL() const { return m_iRenderer == RENDER_OPENGL; }
    inline void SetRenderer(int i) { m_iRenderer = i; }

    inline void SetEye(float x, float y, float z);
    inline void SetEye(const Vector3& eye);
    inline void SetUp(float x, float y, float z);
    inline void SetUp(const Vector3& up);
    inline void SetViewDir(float x, float y, float z);
    inline void SetViewDir(const Vector3& vd);
    inline void SetLookAt(float x, float y, float z);
    inline void SetLookAt(const Vector3& look);
    inline void SetBGColor(float x, float y, float z);
    inline void SetBGColor(const Vector3& color);
    inline void SetFOV(float fov) { m_rFOV = fov; }
    inline void SetFocalPoint(Vector3 focalPoint) {m_focalPoint = focalPoint;}
    inline void SetFocalLength(float focalLength) {m_focalLength = focalLength;}
    inline void SetApertureSize(float apertureSize) {m_apertureSize = apertureSize;}

    inline float& GetFOV() { return m_rFOV; }
    inline Vector3& GetViewDir() { return m_vViewDir; }
    inline Vector3& GetLookAt() { return m_vLookAt; }
    inline Vector3& GetUp() { return m_vUp; }
    inline Vector3& GetEye() { return m_vEye; }
    inline Vector3& GetBGColor() { return m_vBGColor; }


    Ray EyeRay(float x, float y, int imageWidth, int imageHeight);
    Ray LensRay(Ray eyeRay, Matrix4x4 m);

    inline void setTraced(bool traced) {isTraced = traced;}

private:

    void CalcLookAt();

    Vector3 m_vBGColor;
    int m_iRenderer;

    bool isTraced;
    Image* tracedImage;

    // main screen params
    Vector3 m_vEye;
    Vector3 m_vUp;
    Vector3 m_vViewDir;
    Vector3 m_vLookAt;
    float m_rFOV;

    // thin lens model parameters
    float m_apertureSize;    /// default 0
    float m_focalLength;     // default -1 , means not set
    Vector3 m_focalPoint;    
};

//--------------------------------------------------------

inline void Camera::SetEye(float x, float y, float z)
{
    m_vEye.Set(x, y, z);
}

inline void Camera::SetEye(const Vector3& eye)
{
    SetEye(eye.x, eye.y, eye.z);
}

inline void Camera::SetUp(float x, float y, float z)
{
    m_vUp.Set(x, y, z);
    m_vUp.Normalize();
}

inline void Camera::SetUp(const Vector3& up)
{
    SetUp(up.x, up.y, up.z);
}

inline void Camera::SetViewDir(float x, float y, float z)
{
    m_vViewDir.Set(x, y, z);
    m_vViewDir.Normalize();
}

inline void Camera::SetViewDir(const Vector3& vd)
{
    SetViewDir(vd.x, vd.y, vd.z);
}

inline void Camera::SetLookAt(float x, float y, float z)
{
    Vector3 dir = Vector3(x, y, z) - m_vEye;
    SetViewDir(dir);
}

inline void Camera::SetLookAt(const Vector3& vd)
{
    SetLookAt(vd.x, vd.y, vd.z);
}

inline void Camera::SetBGColor(float x, float y, float z)
{
    m_vBGColor.Set(x, y, z);
}

inline void Camera::SetBGColor(const Vector3& vd)
{
    SetBGColor(vd.x, vd.y, vd.z);
}

#endif
