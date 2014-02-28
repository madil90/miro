#ifndef _SAMPLER_H_
#define _SAMPLER_H_

#include <random>

struct Sample
{
public:
	Sample() : x(0),y(0) {}
	Sample(float _x, float _y) : x(_x) , y(_y) {}
	float x,y;
};

class Sampler
{
public:
	static inline float rand01() {return ( (float)std::rand() / (float)RAND_MAX);}
	static Sample* generateStratifiedSamples(int noX, int noY);
};

#endif