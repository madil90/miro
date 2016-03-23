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
		}
	}
	return samples;
}

Vector3 Sampler::cosineWeightedHemisphereSample()
{
	float r1 = rand01();
	float r2 = rand01();

	//float theta = acos(sqrt(r1));
	float phi = 2*PI*r2;

	// float xd = sinf(theta)*cosf(phi);
	// float yd = sinf(theta)*sinf(phi);
	float xd = sqrt(r1)*cosf(phi);
	float yd = sqrt(r1)*sinf(phi);
	float zd = sqrt(1-r1);

	return Vector3(xd,yd,zd);
}