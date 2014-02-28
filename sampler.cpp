#include "Sampler.h"
#include <iostream>

Sample* Sampler::generateStratifiedSamples(int noX, int noY)
{
	Sample* samples = new Sample[noX*noY];

	for (int i=0;i<noX;i++){
		for (int j=0;j<noY;j++){
			float width = 1.0/noX;
			float height = 1.0/noY;
			samples[j + i*noX] = Sample( width*i + Sampler::rand01()*width, height*j+ Sampler::rand01()*height);
			//samples[j + i*noX] = Sample( width*i + 0.5*width, height*j+ 0.5*height);
			//std::cout<<"one sample at"<<i<<","<<j<<" and "<<j+noX*i<<" is "<<samples[j+i*j].x<<","<<samples[j+i*j].y<<std::endl;
		}
	}
	return samples;
}