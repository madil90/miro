// image.h: interface for the Image class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __IMAGE_H__
#define __IMAGE_H__

#include "Vector.h"

class Image
{
public:
    typedef struct _TAGPixel
    {
        unsigned char r, g, b;
        _TAGPixel(unsigned char ir, unsigned char ig, unsigned char ib) { Set(ir, ig, ib); }
        _TAGPixel(){ r = 0; g = 0; b = 0; }
        void Set(unsigned char ir, unsigned char ig, unsigned char ib) { r = ir; g = ig; b = ib; }
    } Pixel;

    Image();
    virtual ~Image();

    void Resize(int width, int height);
    void SetPixel(int x, int y, const Vector3& p);
    void SetPixel(int x, int y, const Pixel& p);

    void Draw();
    void DrawScanline(int y);
    void Clear(const Vector3& c);
    void WritePPM(char* pcFile); // write data to a ppm image file
    void WritePPM(char *pcName, unsigned char *data, int width, int height);
    void WriteBMP(char* pcFile);   // write data to a bitmap file
    void WriteBMP(char* pcName, unsigned char *data, int width, int height);

    inline unsigned char* GetCharPixels() { return (unsigned char*)m_pPixels; }
    inline int Width() { return m_iWidth; }
    inline int Height() { return m_iHeight; }

private:
    Pixel* m_pPixels;
    int m_iWidth;
    int m_iHeight;
};

#endif
