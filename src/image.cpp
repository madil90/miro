// Image.cpp: implementation of the Image class.
//
//////////////////////////////////////////////////////////////////////

#include "miro.h"
#include "image.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "bitmap.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Image::Image()
{
    m_pPixels = 0;
    m_iWidth = 1;
    m_iHeight = 1;
}

Image::~Image()
{
    if (m_pPixels)
        delete [] m_pPixels;
}

void Image::Resize(int width, int height)
{
    if (m_pPixels)
        delete [] m_pPixels;
    m_pPixels = 0;
    m_pPixels = new Pixel[width*height];
    memset(m_pPixels, 0, width*height*sizeof(Pixel));
    m_iWidth = width;
    m_iHeight = height;
}

void Image::Clear(const Vector3& c)
{
    // should be bg color
    for (int y=0; y<m_iHeight; y++)
        for (int x=0; x<m_iWidth; x++)
            SetPixel(x, y, c);
}

// map floating point values to byte values for pixels
unsigned char Map(float r)
{
    float rMap = 255*r;
    unsigned char c = rMap>255?255:(unsigned char)rMap;
    return c;
}

void Image::SetPixel(int x, int y, const Vector3& p)
{
    // do some tone mapping
    if (x >= 0 && x < m_iWidth && y < m_iHeight && y >= 0)
    {
        m_pPixels[y*m_iWidth+x].r = Map(p.x);
        m_pPixels[y*m_iWidth+x].g = Map(p.y);
        m_pPixels[y*m_iWidth+x].b = Map(p.z);
    }
}

void Image::SetPixel(int x, int y, const Pixel& p)
{
    // do some tone mapping
    if (x >= 0 && x < m_iWidth && y < m_iHeight && y >= 0)
    {
        m_pPixels[y*m_iWidth+x]= p;
    }
}

void Image::DrawScanline(int y)
{
    glRasterPos2f(-1, -1 + 2*y / (float)m_iHeight);
    glDrawPixels(m_iWidth, 1, GL_RGB, GL_UNSIGNED_BYTE, &m_pPixels[y*m_iWidth]);
}

void Image::Draw()
{
    //glRasterPos2f(-.1, -.1);
    //glDrawPixels(m_iWidth, m_iHeight, GL_RGB, GL_UNSIGNED_BYTE, m_pPixels);
    for (int i=0; i<m_iHeight; i++)
        DrawScanline(i);
}

void Image::WritePPM(char* pcFile)
{
    WritePPM(pcFile, (unsigned char*)m_pPixels, m_iWidth, m_iHeight);
    //WriteBMP(pcFile);
}

void Image::WritePPM(char *pcFile, unsigned char *data, int width, int height)
{
    FILE *fp = fopen(pcFile, "wb");
    if (!fp)
        fprintf(stderr, "Couldn't open PPM file %s for writing\n", pcFile);
    else
    {
        fprintf(fp, "P6\n");
        fprintf(fp, "%d %d\n", width, height );
        fprintf(fp, "255\n" );

        // invert image
        int stride = width*3;
        for (int i=height-1; i>=0; i--)
            fwrite(&data[stride*i], stride, 1, fp);
        fclose(fp);
    }
	printf("Image Saved %s \n", pcFile);
}

// write data to a bitmap file
void Image::WriteBMP(char* pcFile)   
{
    WriteBMP(pcFile, (unsigned char*)m_pPixels, m_iWidth, m_iHeight);
}

void Image::WriteBMP(char* pcName, unsigned char *data, int width, int height)
{
    writeBMP(pcName, width, height, data);
}
