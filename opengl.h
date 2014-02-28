
// use the following on Windows or GNU/Linux
#ifdef _WIN64
   //define something for Windows (64-bit)
	#include <GL/glut.h>
#elif _WIN32
   //define something for Windows (32-bit)
	#include <GL/glut.h>
#elif __APPLE__
	#include <GLUT/glut.h> 
#endif

// use this on Mac OSX
// #include <GLUT/glut.h>
