#ifndef LINEAR_R3_H
#define LINEAR_R3_H

#include <math.h>
#include <float.h>

#ifdef WIN32
#pragma warning(disable:4305) // disable useless warnings
#pragma warning(disable:4244)
#endif

const float PI = 3.1415926535897932384626433832795028841972;

class Vector3;
class Vector4;
class Matrix4x4;



class Vector3
{

public:
    float x, y, z;		// The x & y & z coordinates.

public:
    Vector3( ) : x(0.0), y(0.0), z(0.0) {}
	Vector3(const Vector4& v);
    Vector3( float xVal, float yVal, float zVal )
            : x(xVal), y(yVal), z(zVal) {}
	

    Vector3& Set( float xx, float yy, float zz )
    { x=xx; y=yy; z=zz; return *this; }
    Vector3& SetZero() { x=0.0; y=0.0; z=0.0;  return *this;}
    inline bool isZero(){ 
        if (x>0.0 || y>0.0 || z>0.0) return false; return true;
    }
    inline float* p() { return &x; }

    inline float& operator[]( int i ) const;

    Vector3& operator= ( const Vector3& v )
    { x=v.x; y=v.y; z=v.z; return(*this);}
    Vector3& operator+= ( const Vector3& v )
    { x+=v.x; y+=v.y; z+=v.z; return(*this); }
    Vector3& operator-= ( const Vector3& v )
    { x-=v.x; y-=v.y; z-=v.z; return(*this); }
    Vector3& operator*= ( float m )
    { x*=m; y*=m; z*=m; return(*this); }
    Vector3& operator/= ( float m )
    {
        register float mInv = 1.0/m;
        x*=mInv; y*=mInv; z*=mInv;
        return(*this);
    }
    Vector3 operator- () const { return ( Vector3(-x, -y, -z) ); }
    Vector3& operator*= (const Vector3& v);	// Cross Product
    Vector3& ArrayProd(const Vector3&);		// Component-wise product

    float Norm() const { return ( (float)sqrt( x*x + y*y + z*z ) ); }
    float NormSq() const { return ( x*x + y*y + z*z ); }
    Vector3& Negate() { x = -x; y = -y; z = -z; return *this;}
    Vector3& Normalize () { *this /= Norm(); return *this;}	// No error checking
    inline Vector3& Rotate( float theta, const Vector3& w) ;
	inline Vector3& Bound(float bound);
};

class Vector4
{

public:
    float x, y, z, w;		// The x & y & z & w coordinates.

public:
    Vector4( ) : x(0.0), y(0.0), z(0.0), w(0.0) {}
    Vector4( float xVal, float yVal, float zVal, float wVal )
            : x(xVal), y(yVal), z(zVal), w(wVal) {}

    Vector4( const Vector3& v )
    { x=v.x; y=v.y; z=v.z; w = 1; }
	Vector4( const Vector3& v, float wVal)
	{ x=v.x; y=v.y; z=v.z; w=wVal;}
    Vector4& SetZero() { x=0.0; y=0.0; z=0.0; w=0.0; return *this;}
    Vector4& Set( float xx, float yy, float zz, float ww )
    { x=xx; y=yy; z=zz; w=ww; return *this;}

    Vector4& operator= ( const Vector3& v )
    { x=v.x; y=v.y; z=v.z; w = 1; return(*this);}
    Vector4& operator= ( const Vector4& v )
    { x=v.x; y=v.y; z=v.z; w = v.w; return(*this);}
    Vector4& operator+= ( const Vector4& v )
    { x+=v.x; y+=v.y; z+=v.z; w+=v.w;  return(*this); }
    Vector4& operator-= ( const Vector4& v )
    { x-=v.x; y-=v.y; z-=v.z; w-=v.w;  return(*this); }
    Vector4& operator*= ( float m )
    { x*=m; y*=m; z*=m; w*=m;  return(*this); }
    Vector4& operator/= ( float m )
    {
        register float mInv = 1.0/m;
        x*=mInv; y*=mInv; z*=mInv; w*=mInv;
        return(*this);
    }
    Vector4 operator- () const { return ( Vector4(-x, -y, -z, -w) ); }
    Vector4& ArrayProd(const Vector4&);		// Component-wise product

    float Norm() const { return ( (float)sqrt( x*x + y*y + z*z +w*w) ); }
    float NormSq() const { return ( x*x + y*y + z*z + w*w ); }
    Vector4& Normalize () { *this /= Norm(); return *this; }	// No error checking
};

inline Vector4 operator+( const Vector4& u, const Vector4& v );
inline Vector4 operator-( const Vector4& u, const Vector4& v );
inline Vector4 operator*( const Vector4& u, float m);
inline Vector4 operator*( float m, const Vector4& u);
inline Vector4 operator/( const Vector4& u, float m);
inline int operator==( const Vector4& u, const Vector4& v );

inline float operator^ (const Vector4& u, const Vector4& v ); // Dot Product
inline Vector4 ArrayProd(const Vector4& u, const Vector4& v );

// ********************************************************************
// Matrix4x4     - base class for 4x4 matrices                        *
// * * * * * * * * * * * * * * * * * * * * * **************************

class Matrix4x4
{

public:
    float m11, m12, m13, m14, m21, m22, m23, m24,
    m31, m32, m33, m34, m41, m42, m43, m44;

    // Implements a 4x4 matrix: m_i_j - row-i and column-j entry

public:

    Matrix4x4();
    Matrix4x4( const Vector4&, const Vector4&,
               const Vector4&, const Vector4& );	// Sets by columns!
    Matrix4x4( float, float, float, float,
               float, float, float, float,
               float, float, float, float,
               float, float, float, float );	// Sets by columns

    inline void SetIdentity ();		// Set to the identity map
    inline void SetZero ();			// Set to the zero map
    inline void Set ( const Matrix4x4& );	// Set to the matrix.
    inline void Set( const Vector4&, const Vector4&,
                     const Vector4&, const Vector4& );
    inline void Set( float, float, float, float,
                     float, float, float, float,
                     float, float, float, float,
                     float, float, float, float );
    inline void SetColumn1 ( float, float, float, float );
    inline void SetColumn2 ( float, float, float, float );
    inline void SetColumn3 ( float, float, float, float );
    inline void SetColumn4 ( float, float, float, float );
    inline void SetColumn1 ( const Vector4& );
    inline void SetColumn2 ( const Vector4& );
    inline void SetColumn3 ( const Vector4& );
    inline void SetColumn4 ( const Vector4& );
    inline Vector4 Column1() const;
    inline Vector4 Column2() const;
    inline Vector4 Column3() const;
    inline Vector4 Column4() const;

    /********************** begin - New for Assignment 2 **********************/
    inline Matrix4x4& Invert();
    /********************** end - New for Assignment 2 **********************/

    inline void MakeTranspose();					// Transposes it.
    inline Matrix4x4& operator+= (const Matrix4x4& );
    inline Matrix4x4& operator-= (const Matrix4x4& );
    inline Matrix4x4& operator*= (float);
    inline Matrix4x4& operator/= (float);
    inline Matrix4x4& operator*= (const Matrix4x4& );	// Matrix product
};

// binary operators
inline Matrix4x4 operator+ (const Matrix4x4&, const Matrix4x4&);
inline Matrix4x4 operator- (const Matrix4x4&);
inline Matrix4x4 operator- (const Matrix4x4&, const Matrix4x4&);
inline Matrix4x4 operator* ( const Matrix4x4&, float);
inline Matrix4x4 operator* ( float, const Matrix4x4& );
inline Matrix4x4 operator/ ( const Matrix4x4&, float );
inline Matrix4x4 operator* ( const Matrix4x4&, const Matrix4x4& );

inline Vector3 operator+( const Vector3& u, const Vector3& v );
inline Vector3 operator-( const Vector3& u, const Vector3& v );
inline Vector3 operator*( const Vector3& u, float m);
inline Vector3 operator*( float m, const Vector3& u);
inline Vector3 operator/( const Vector3& u, float m);
inline Vector3 operator/( float m, const Vector3& u);
inline int operator==( const Vector3& u, const Vector3& v );

inline float operator^ (const Vector3& u, const Vector3& v ); // Dot Product
inline Vector3 operator* (const Vector3& u, const Vector3& v);	 // Cross Product
inline Vector3 ArrayProd ( const Vector3& u, const Vector3& v );

inline Vector4 operator* ( const Matrix4x4&, const Vector4& );
inline Vector3 operator* ( const Matrix4x4&, const Vector3& );

// *****************************************************
// * Vector3 class - inlined functions				   *
// * * * * * * * * * * * * * * * * * * * * * * * * * * *

inline Vector3::Vector3(const Vector4& v)
{
	if (v.w!=0)
	{x=v.x/v.w;y=v.y/v.w;z=v.z/v.w;}
	else
	{x=v.x;y=v.y;z=v.z;}
}

inline float& Vector3::operator[]( int i ) const
{
    return ((float*)&x)[i];
}

inline Vector3 operator+( const Vector3& u, const Vector3& v )
{
    return Vector3(u.x+v.x, u.y+v.y, u.z+v.z);
}
inline Vector3 operator-( const Vector3& u, const Vector3& v )
{
    return Vector3(u.x-v.x, u.y-v.y, u.z-v.z);
}
inline Vector3 operator*( const Vector3& u, register float m)
{
    return Vector3( u.x*m, u.y*m, u.z*m);
}
inline Vector3 operator*( register float m, const Vector3& u)
{
    return Vector3( u.x*m, u.y*m, u.z*m);
}
inline Vector3 operator/( const Vector3& u, float m)
{
    register float mInv = 1.0/m;
    return Vector3( u.x*mInv, u.y*mInv, u.z*mInv);
}
inline Vector3 operator/( register float m, const Vector3& u)
{
    return Vector3( m/u.x, m/u.y, m/u.z);
}

inline int operator==( const Vector3& u, const Vector3& v )
{
    return ( u.x==v.x && u.y==v.y && u.z==v.z );
}

inline float operator^ ( const Vector3& u, const Vector3& v ) // Dot Product
{
    return ( u.x*v.x + u.y*v.y + u.z*v.z );
}

inline Vector3 operator* (const Vector3& u, const Vector3& v)	// Cross Product
{
    return (Vector3(	u.y*v.z - u.z*v.y,
                     u.z*v.x - u.x*v.z,
                     u.x*v.y - u.y*v.x  ) );
}

inline Vector3 ArrayProd ( const Vector3& u, const Vector3& v )
{
    return ( Vector3( u.x*v.x, u.y*v.y, u.z*v.z ) );
}

inline Vector3& Vector3::operator*= (const Vector3& v)		// Cross Product
{
    float tx=x, ty=y;
    x =  y*v.z -  z*v.y;
    y =  z*v.x - tx*v.z;
    z = tx*v.y - ty*v.x;
    return ( *this );
}

inline Vector3& Vector3::ArrayProd (const Vector3& v)		// Component-wise Product
{
    x *= v.x;
    y *= v.y;
    z *= v.z;
    return ( *this );
}

inline Vector3& Vector3::Rotate( float theta, const Vector3& w)
{
    float c = cos(theta);
    float s = sin(theta);
    float dotw = (x*w.x + y*w.y + z*w.z);
    float v0x = dotw*w.x;
    float v0y = dotw*w.y;		// v0 = provjection onto w
    float v0z = dotw*w.z;
    float v1x = x-v0x;
    float v1y = y-v0y;			// v1 = projection onto plane normal to w
    float v1z = z-v0z;
    float v2x = w.y*v1z - w.z*v1y;
    float v2y = w.z*v1x - w.x*v1z;	// v2 = w * v1 (cross product)
    float v2z = w.x*v1y - w.y*v1x;

    x = v0x + c*v1x + s*v2x;
    y = v0y + c*v1y + s*v2y;
    z = v0z	+ c*v1z + s*v2z;

    Normalize();
    return ( *this );
}

inline Vector3& Vector3::Bound(float bound)
{
	if (x>bound) x = bound;
	if (y>bound) y = bound;
	if (z>bound) z = bound;
	return *this;
}

// *****************************************************
// * Vector4 class - inlined functions				   *
// * * * * * * * * * * * * * * * * * * * * * * * * * * *

inline Vector4 operator+( const Vector4& u, const Vector4& v )
{
    return Vector4(u.x+v.x, u.y+v.y, u.z+v.z, u.w+v.w );
}
inline Vector4 operator-( const Vector4& u, const Vector4& v )
{
    return Vector4(u.x-v.x, u.y-v.y, u.z-v.z, u.w-v.w);
}
inline Vector4 operator*( const Vector4& u, register float m)
{
    return Vector4( u.x*m, u.y*m, u.z*m, u.w*m );
}
inline Vector4 operator*( register float m, const Vector4& u)
{
    return Vector4( u.x*m, u.y*m, u.z*m, u.w*m );
}
inline Vector4 operator/( const Vector4& u, float m)
{
    register float mInv = 1.0/m;
    return Vector4( u.x*mInv, u.y*mInv, u.z*mInv, u.w*mInv );
}

inline int operator==( const Vector4& u, const Vector4& v )
{
    return ( u.x==v.x && u.y==v.y && u.z==v.z && u.w==v.w );
}

inline float operator^ ( const Vector4& u, const Vector4& v ) // Dot Product
{
    return ( u.x*v.x + u.y*v.y + u.z*v.z + u.w*v.w );
}

inline Vector4 ArrayProd ( const Vector4& u, const Vector4& v )
{
    return ( Vector4( u.x*v.x, u.y*v.y, u.z*v.z, u.w*v.w ) );
}

inline Vector4& Vector4::ArrayProd (const Vector4& v)		// Component-wise Product
{
    x *= v.x;
    y *= v.y;
    z *= v.z;
    w *= v.w;
    return ( *this );
}



// *********************************************************
// * Matrix4x4 class - inlined functions				   *
// * * * * * * * * * * * * * * * * * * * * * * * * * * *****

inline Matrix4x4::Matrix4x4() {}

inline Matrix4x4::Matrix4x4( const Vector4& u, const Vector4& v,
                             const Vector4& s, const Vector4& t)
{
    m11 = u.x;		// Column 1
    m21 = u.y;
    m31 = u.z;
    m41 = u.w;
    m12 = v.x;		// Column 2
    m22 = v.y;
    m32 = v.z;
    m42 = v.w;
    m13 = s.x;		// Column 3
    m23 = s.y;
    m33 = s.z;
    m43 = s.w;
    m14 = t.x;		// Column 4
    m24 = t.y;
    m34 = t.z;
    m44 = t.w;
}

inline Matrix4x4::Matrix4x4( float a11, float a12, float a13, float a14,
                             float a21, float a22, float a23, float a24,
                             float a31, float a32, float a33, float a34,
                             float a41, float a42, float a43, float a44)
// Values specified in row order!!!
{
    m11 = a11;		// Row 1
    m12 = a12;
    m13 = a13;
    m14 = a14;
    m21 = a21;		// Row 2
    m22 = a22;
    m23 = a23;
    m24 = a24;
    m31 = a31;		// Row 3
    m32 = a32;
    m33 = a33;
    m34 = a34;
    m41 = a41;		// Row 4
    m42 = a42;
    m43 = a43;
    m44 = a44;
}

inline void Matrix4x4::SetIdentity ( )
{
    m11 = m22 = m33 = m44 = 1.0;
    m12 = m13 = m14 = m21 = m23 = m24 = m31 = m32 = m34 = m41= m42 = m43 = 0.0;
}

inline void Matrix4x4::Set( const Vector4& u, const Vector4& v,
                            const Vector4& s, const Vector4& t )
{
    m11 = u.x;		// Column 1
    m21 = u.y;
    m31 = u.z;
    m41 = u.w;
    m12 = v.x;		// Column 2
    m22 = v.y;
    m32 = v.z;
    m42 = v.w;
    m13 = s.x;		// Column 3
    m23 = s.y;
    m33 = s.z;
    m43 = s.w;
    m14 = t.x;		// Column 4
    m24 = t.y;
    m34 = t.z;
    m44 = t.w;
}

inline void Matrix4x4::Set( float a11, float a12, float a13, float a14,
                            float a21, float a22, float a23, float a24,
                            float a31, float a32, float a33, float a34,
                            float a41, float a42, float a43, float a44)
// Values specified in row order!!!
{
    m11 = a11;		// Row 1
    m12 = a12;
    m13 = a13;
    m14 = a14;
    m21 = a21;		// Row 2
    m22 = a22;
    m23 = a23;
    m24 = a24;
    m31 = a31;		// Row 3
    m32 = a32;
    m33 = a33;
    m34 = a34;
    m41 = a41;		// Row 4
    m42 = a42;
    m43 = a43;
    m44 = a44;
}

inline void Matrix4x4::Set ( const Matrix4x4& M )	// Set to the matrix.
{
    m11 = M.m11;
    m12 = M.m12;
    m13 = M.m13;
    m14 = M.m14;
    m21 = M.m21;
    m22 = M.m22;
    m23 = M.m23;
    m24 = M.m24;
    m31 = M.m31;
    m32 = M.m32;
    m33 = M.m33;
    m34 = M.m34;
    m41 = M.m41;
    m42 = M.m42;
    m43 = M.m43;
    m44 = M.m44;
}

inline void Matrix4x4::SetZero( )
{
    m11 = m12 = m13 = m14 = m21 = m22 = m23 = m24
                                        = m31 = m32 = m33 = m34 = m41 = m42 = m43 = m44 = 0.0;
}

inline void Matrix4x4::SetColumn1 ( float x, float y, float z, float w)
{
    m11 = x; m21 = y; m31= z; m41 = w;
}

inline void Matrix4x4::SetColumn2 ( float x, float y, float z, float w)
{
    m12 = x; m22 = y; m32= z; m42 = w;
}

inline void Matrix4x4::SetColumn3 ( float x, float y, float z, float w)
{
    m13 = x; m23 = y; m33= z; m43 = w;
}

inline void Matrix4x4::SetColumn4 ( float x, float y, float z, float w)
{
    m14 = x; m24 = y; m34= z; m44 = w;
}

inline void Matrix4x4::SetColumn1 ( const Vector4& u )
{
    m11 = u.x; m21 = u.y; m31 = u.z; m41 = u.w;
}

inline void Matrix4x4::SetColumn2 ( const Vector4& u )
{
    m12 = u.x; m22 = u.y; m32 = u.z; m42 = u.w;
}

inline void Matrix4x4::SetColumn3 ( const Vector4& u )
{
    m13 = u.x; m23 = u.y; m33 = u.z; m43 = u.w;
}

inline void Matrix4x4::SetColumn4 ( const Vector4& u )
{
    m14 = u.x; m24 = u.y; m34 = u.z; m44 = u.w;
}

Vector4 Matrix4x4::Column1() const
{
    return ( Vector4(m11, m21, m31, m41) );
}

Vector4 Matrix4x4::Column2() const
{
    return ( Vector4(m12, m22, m32, m42) );
}

Vector4 Matrix4x4::Column3() const
{
    return ( Vector4(m13, m23, m33, m43) );
}

Vector4 Matrix4x4::Column4() const
{
    return ( Vector4(m14, m24, m34, m44) );
}

inline void Matrix4x4::MakeTranspose()	// Transposes it.
{
    register float temp;
    temp = m12;
    m12 = m21;
    m21=temp;
    temp = m13;
    m13 = m31;
    m31 = temp;
    temp = m14;
    m14 = m41;
    m41 = temp;
    temp = m23;
    m23 = m32;
    m32 = temp;
    temp = m24;
    m24 = m42;
    m42 = temp;
    temp = m34;
    m34 = m43;
    m43 = temp;
}

/********************** begin - New for Assignment 2 **********************/
Matrix4x4& Matrix4x4::Invert() 			// Converts into inverse.
{
    float Tbt34C12 = m31*m42-m32*m41;		// 2x2 subdeterminants
    float Tbt34C13 = m31*m43-m33*m41;
    float Tbt34C14 = m31*m44-m34*m41;
    float Tbt34C23 = m32*m43-m33*m42;
    float Tbt34C24 = m32*m44-m34*m42;
    float Tbt34C34 = m33*m44-m34*m43;
    float Tbt24C12 = m21*m42-m22*m41;		// 2x2 subdeterminants
    float Tbt24C13 = m21*m43-m23*m41;
    float Tbt24C14 = m21*m44-m24*m41;
    float Tbt24C23 = m22*m43-m23*m42;
    float Tbt24C24 = m22*m44-m24*m42;
    float Tbt24C34 = m23*m44-m24*m43;
    float Tbt23C12 = m21*m32-m22*m31;		// 2x2 subdeterminants
    float Tbt23C13 = m21*m33-m23*m31;
    float Tbt23C14 = m21*m34-m24*m31;
    float Tbt23C23 = m22*m33-m23*m32;
    float Tbt23C24 = m22*m34-m24*m32;
    float Tbt23C34 = m23*m34-m24*m33;

    float sd11 = m22*Tbt34C34 - m23*Tbt34C24 + m24*Tbt34C23;	// 3x3 subdeterminants
    float sd12 = m21*Tbt34C34 - m23*Tbt34C14 + m24*Tbt34C13;
    float sd13 = m21*Tbt34C24 - m22*Tbt34C14 + m24*Tbt34C12;
    float sd14 = m21*Tbt34C23 - m22*Tbt34C13 + m23*Tbt34C12;
    float sd21 = m12*Tbt34C34 - m13*Tbt34C24 + m14*Tbt34C23;	// 3x3 subdeterminants
    float sd22 = m11*Tbt34C34 - m13*Tbt34C14 + m14*Tbt34C13;
    float sd23 = m11*Tbt34C24 - m12*Tbt34C14 + m14*Tbt34C12;
    float sd24 = m11*Tbt34C23 - m12*Tbt34C13 + m13*Tbt34C12;
    float sd31 = m12*Tbt24C34 - m13*Tbt24C24 + m14*Tbt24C23;	// 3x3 subdeterminants
    float sd32 = m11*Tbt24C34 - m13*Tbt24C14 + m14*Tbt24C13;
    float sd33 = m11*Tbt24C24 - m12*Tbt24C14 + m14*Tbt24C12;
    float sd34 = m11*Tbt24C23 - m12*Tbt24C13 + m13*Tbt24C12;
    float sd41 = m12*Tbt23C34 - m13*Tbt23C24 + m14*Tbt23C23;	// 3x3 subdeterminants
    float sd42 = m11*Tbt23C34 - m13*Tbt23C14 + m14*Tbt23C13;
    float sd43 = m11*Tbt23C24 - m12*Tbt23C14 + m14*Tbt23C12;
    float sd44 = m11*Tbt23C23 - m12*Tbt23C13 + m13*Tbt23C12;

    register float detInv = 1.0/(m11*sd11 - m12*sd12 + m13*sd13 - m14*sd14);

    m11 = sd11*detInv;
    m12 = -sd21*detInv;
    m13 = sd31*detInv;
    m14 = -sd41*detInv;
    m21 = -sd12*detInv;
    m22 = sd22*detInv;
    m23 = -sd32*detInv;
    m24 = sd42*detInv;
    m31 = sd13*detInv;
    m32 = -sd23*detInv;
    m33 = sd33*detInv;
    m34 = -sd43*detInv;
    m41 = -sd14*detInv;
    m42 = sd24*detInv;
    m43 = -sd34*detInv;
    m44 = sd44*detInv;

    return ( *this );
}
/********************** end - New for Assignment 2 **********************/

inline Matrix4x4& Matrix4x4::operator+= (const Matrix4x4& B)
{
    m11 += B.m11;
    m12 += B.m12;
    m13 += B.m13;
    m14 += B.m14;
    m21 += B.m21;
    m22 += B.m22;
    m23 += B.m23;
    m24 += B.m24;
    m31 += B.m31;
    m32 += B.m32;
    m33 += B.m33;
    m34 += B.m34;
    m41 += B.m41;
    m42 += B.m42;
    m43 += B.m43;
    m44 += B.m44;
    return ( *this );
}

inline Matrix4x4& Matrix4x4::operator-= (const Matrix4x4& B)
{
    m11 -= B.m11;
    m12 -= B.m12;
    m13 -= B.m13;
    m14 -= B.m14;
    m21 -= B.m21;
    m22 -= B.m22;
    m23 -= B.m23;
    m24 -= B.m24;
    m31 -= B.m31;
    m32 -= B.m32;
    m33 -= B.m33;
    m34 -= B.m34;
    m41 -= B.m41;
    m42 -= B.m42;
    m43 -= B.m43;
    m44 -= B.m44;
    return( *this );
}

inline Matrix4x4 operator+ (const Matrix4x4& A, const Matrix4x4& B)
{
    return( Matrix4x4( A.m11+B.m11, A.m21+B.m21, A.m31+B.m31, A.m41+B.m41,
                       A.m12+B.m12, A.m22+B.m22, A.m32+B.m32, A.m42+B.m42,
                       A.m13+B.m13, A.m23+B.m23, A.m33+B.m33, A.m43+B.m43,
                       A.m14+B.m14, A.m24+B.m24, A.m34+B.m34, A.m44+B.m44) );
}

inline Matrix4x4 operator- (const Matrix4x4& A)
{
    return( Matrix4x4( -A.m11, -A.m21, -A.m31, -A.m41,
                       -A.m12, -A.m22, -A.m32, -A.m42,
                       -A.m13, -A.m23, -A.m33, -A.m43,
                       -A.m14, -A.m24, -A.m34, -A.m44 ) );
}

inline Matrix4x4 operator- (const Matrix4x4& A, const Matrix4x4& B)
{
    return( Matrix4x4( A.m11-B.m11, A.m21-B.m21, A.m31-B.m31, A.m41-B.m41,
                       A.m12-B.m12, A.m22-B.m22, A.m32-B.m32, A.m42-B.m42,
                       A.m13-B.m13, A.m23-B.m23, A.m33-B.m33, A.m43-B.m43,
                       A.m14-B.m14, A.m24-B.m24, A.m34-B.m34, A.m44-B.m44 ) );
}

inline Matrix4x4& Matrix4x4::operator*= (register float b)
{
    m11 *= b;
    m12 *= b;
    m13 *= b;
    m14 *= b;
    m21 *= b;
    m22 *= b;
    m23 *= b;
    m24 *= b;
    m31 *= b;
    m32 *= b;
    m33 *= b;
    m34 *= b;
    m41 *= b;
    m42 *= b;
    m43 *= b;
    m44 *= b;
    return ( *this);
}

inline Matrix4x4& Matrix4x4::operator*= (const Matrix4x4& B)	// Matrix product
{
    float t1, t2, t3;		// temporary values
    t1 =  m11*B.m11 + m12*B.m21 + m13*B.m31 + m14*B.m41;
    t2 =  m11*B.m12 + m12*B.m22 + m13*B.m32 + m14*B.m42;
    t3 =  m11*B.m13 + m12*B.m23 + m13*B.m33 + m14*B.m43;
    m14 = m11*B.m14 + m12*B.m24 + m13*B.m34 + m14*B.m44;
    m11 = t1;
    m12 = t2;
    m13 = t3;

    t1 =  m21*B.m11 + m22*B.m21 + m23*B.m31 + m24*B.m41;
    t2 =  m21*B.m12 + m22*B.m22 + m23*B.m32 + m24*B.m42;
    t3 =  m21*B.m13 + m22*B.m23 + m23*B.m33 + m24*B.m43;
    m24 = m21*B.m14 + m22*B.m24 + m23*B.m34 + m24*B.m44;
    m21 = t1;
    m22 = t2;
    m23 = t3;

    t1 =  m31*B.m11 + m32*B.m21 + m33*B.m31 + m34*B.m41;
    t2 =  m31*B.m12 + m32*B.m22 + m33*B.m32 + m34*B.m42;
    t3 =  m31*B.m13 + m32*B.m23 + m33*B.m33 + m34*B.m43;
    m34 = m31*B.m14 + m32*B.m24 + m33*B.m34 + m34*B.m44;
    m31 = t1;
    m32 = t2;
    m33 = t3;

    t1 =  m41*B.m11 + m42*B.m21 + m43*B.m31 + m44*B.m41;
    t2 =  m41*B.m12 + m42*B.m22 + m43*B.m32 + m44*B.m42;
    t3 =  m41*B.m13 + m42*B.m23 + m43*B.m33 + m44*B.m43;
    m44 = m41*B.m14 + m42*B.m24 + m43*B.m34 + m44*B.m44;
    m41 = t1;
    m42 = t2;
    m43 = t3;
    return *this;
}

inline Matrix4x4 operator* (const Matrix4x4& A, const Matrix4x4& B)	// Matrix product
{
    Matrix4x4 R;
    float t1, t2, t3;		// temporary values
    t1 =  A.m11*B.m11 + A.m12*B.m21 + A.m13*B.m31 + A.m14*B.m41;
    t2 =  A.m11*B.m12 + A.m12*B.m22 + A.m13*B.m32 + A.m14*B.m42;
    t3 =  A.m11*B.m13 + A.m12*B.m23 + A.m13*B.m33 + A.m14*B.m43;
    R.m14 = A.m11*B.m14 + A.m12*B.m24 + A.m13*B.m34 + A.m14*B.m44;
    R.m11 = t1;
    R.m12 = t2;
    R.m13 = t3;

    t1 =  A.m21*B.m11 + A.m22*B.m21 + A.m23*B.m31 + A.m24*B.m41;
    t2 =  A.m21*B.m12 + A.m22*B.m22 + A.m23*B.m32 + A.m24*B.m42;
    t3 =  A.m21*B.m13 + A.m22*B.m23 + A.m23*B.m33 + A.m24*B.m43;
    R.m24 = A.m21*B.m14 + A.m22*B.m24 + A.m23*B.m34 + A.m24*B.m44;
    R.m21 = t1;
    R.m22 = t2;
    R.m23 = t3;

    t1 =  A.m31*B.m11 + A.m32*B.m21 + A.m33*B.m31 + A.m34*B.m41;
    t2 =  A.m31*B.m12 + A.m32*B.m22 + A.m33*B.m32 + A.m34*B.m42;
    t3 =  A.m31*B.m13 + A.m32*B.m23 + A.m33*B.m33 + A.m34*B.m43;
    R.m34 = A.m31*B.m14 + A.m32*B.m24 + A.m33*B.m34 + A.m34*B.m44;
    R.m31 = t1;
    R.m32 = t2;
    R.m33 = t3;

    t1 =  A.m41*B.m11 + A.m42*B.m21 + A.m43*B.m31 + A.m44*B.m41;
    t2 =  A.m41*B.m12 + A.m42*B.m22 + A.m43*B.m32 + A.m44*B.m42;
    t3 =  A.m41*B.m13 + A.m42*B.m23 + A.m43*B.m33 + A.m44*B.m43;
    R.m44 = A.m41*B.m14 + A.m42*B.m24 + A.m43*B.m34 + A.m44*B.m44;
    R.m41 = t1;
    R.m42 = t2;
    R.m43 = t3;
    return R;
}

inline Matrix4x4 operator* ( const Matrix4x4& A, register float b)
{
    return( Matrix4x4( A.m11*b, A.m21*b, A.m31*b, A.m41*b,
                       A.m12*b, A.m22*b, A.m32*b, A.m42*b,
                       A.m13*b, A.m23*b, A.m33*b, A.m43*b,
                       A.m14*b, A.m24*b, A.m34*b, A.m44*b) );
}

inline Matrix4x4 operator* ( register float b, const Matrix4x4& A)
{
    return( Matrix4x4( A.m11*b, A.m21*b, A.m31*b, A.m41*b,
                       A.m12*b, A.m22*b, A.m32*b, A.m42*b,
                       A.m13*b, A.m23*b, A.m33*b, A.m43*b,
                       A.m14*b, A.m24*b, A.m34*b, A.m44*b ) );
}

inline Matrix4x4 operator/ ( const Matrix4x4& A, float b)
{
    register float bInv = 1.0/b;
    return ( A*bInv );
}

inline Matrix4x4& Matrix4x4::operator/= (register float b)
{
    register float bInv = 1.0/b;
    return ( *this *= bInv );
}

inline Vector4 operator* ( const Matrix4x4& A, const Vector4& u)
{
    return(Vector4 ( A.m11*u.x + A.m12*u.y + A.m13*u.z + A.m14*u.w,
                     A.m21*u.x + A.m22*u.y + A.m23*u.z + A.m24*u.w,
                     A.m31*u.x + A.m32*u.y + A.m33*u.z + A.m34*u.w,
                     A.m41*u.x + A.m42*u.y + A.m43*u.z + A.m44*u.w ) );
}

inline Vector3 operator* ( const Matrix4x4& A, const Vector3& u)
{
    return(Vector3 ( A.m11*u.x + A.m12*u.y + A.m13*u.z + A.m14,
                     A.m21*u.x + A.m22*u.y + A.m23*u.z + A.m24,
                     A.m31*u.x + A.m32*u.y + A.m33*u.z + A.m34 ) );
    // note that this ignores the fourth row in the matrix!
}

inline float* MatToFloat(Matrix4x4 m_xform)
{
	float *m = new float[16];
	m[0] = m_xform.m11;
	m[1] = m_xform.m21;
	m[2] = m_xform.m31;
	m[3] = m_xform.m41;
	m[4] = m_xform.m12;
	m[5] = m_xform.m22;
	m[6] = m_xform.m32;
	m[7] = m_xform.m42;
	m[8] = m_xform.m13;
	m[9] = m_xform.m23;
	m[10] = m_xform.m33;
	m[11] = m_xform.m43;
	m[12] = m_xform.m14;
	m[13] = m_xform.m24;
	m[14] = m_xform.m34;
	m[15] = m_xform.m44;
	
	return m;
}

#endif
