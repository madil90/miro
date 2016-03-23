#include <math.h>
#include "miro.h"
#include "scene.h"
#include "camera.h"
#include "image.h"
#include "console.h"

#define OPTIONS_STRING ":s:" // a colon after an option means it takes an argument
// e.g. -s <file name> should be "s:" since the file name is an argument to the option
// the first : is to prevent getopt from printing errors.  we can do that ourselves.

// main variables
Camera* g_pCamera;
Scene* g_pScene;
Image* g_pImage;

// other variables
int noOfRays;

void Usage(char* pName)
{
    fprintf(stderr, "\nUsage: %s [options]\n", pName);
    fprintf(stderr, "  Where options is one of:\n");
    fprintf(stderr, "  <file>              : Load a script file (you probably want this):\n");
    // add more usage info here!
}

int main(int argc, char*argv[])
{
    glutInit(&argc, argv);

    if (argc < 2)
    { // if there arent any options we cant do much...
        Warning("No options specified!\n");
        Usage(argv[0]);
        return 0;
    }

    g_pCamera = new Camera;
    g_pScene = new Scene;
    g_pImage = new Image;
    
    FILE* fp = fopen(argv[1], "r");
    if (fp)
    {
        ParseFile(fp); // defined in parse.y
        fclose(fp);
    }
    else
    {
        Warning("Could not open script file %s!\n", argv[1]);
        return 0;
    }

    // let objects do pre-calculations if needed
    g_pScene->PreCalc();

    InitOpenGL(); // init drawing window and glut

    glutMainLoop();

    return 0; // never executed
}

