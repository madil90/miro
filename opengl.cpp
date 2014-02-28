#include "miro.h"
#include "camera.h"
#include "image.h"
#include "scene.h"
#include <stdlib.h>

// some of the code may look familiar if you've taken Mike Bailey's CSE167
#define ANGFACT		1.0
#define LEFT		4
#define MIDDLE		2
#define RIGHT		1

float g_rScaleFact = 0.1f;
int   g_iActiveButton;
int   g_iXmouse, g_iYmouse;
int   g_iMainWindow;
int   g_iRenderWindow=0;


void Display()
{
    g_pCamera->Click(g_pScene, g_pImage); // take a snapshot of the scene

    glFinish(); // flush the OpenGL pipeline
}

void Idle()
{
    // post rendering message here
    glutPostRedisplay();
}

void Motion(int x, int y)
{
    int dx, dy;		// change in mouse coordinates

    dx = x - g_iXmouse;		// change in mouse coords
    dy = y - g_iYmouse;

    if (g_iActiveButton & LEFT)
    {
        float xfact = -ANGFACT*dy;
        float yfact = -ANGFACT*dx;
        // construct a coordinate system from up and viewdir
        Vector3 vRight = g_pCamera->GetViewDir()*g_pCamera->GetUp();
        // now rotate everything
        g_pCamera->GetViewDir().Rotate(xfact*PI/180., vRight);
        g_pCamera->GetViewDir().Rotate(yfact*PI/180., g_pCamera->GetUp());
        //g_pCamera->GetUp().Rotate(-xfact*PI/180., vRight);
    }

    g_iXmouse = x;			// new current position
    g_iYmouse = y;

    glutPostRedisplay();
}

void Mouse(int button, int state, int x, int y)
{
    int b; // LEFT, MIDDLE, or RIGHT

    switch(button)
    {
    case GLUT_LEFT_BUTTON:
        b = LEFT;		break;
    case GLUT_MIDDLE_BUTTON:
        b = MIDDLE;		break;
    case GLUT_RIGHT_BUTTON:
        b = RIGHT;		break;
    default:
        b = 0;
    }

    if(state == GLUT_DOWN)
    {
        g_iXmouse = x;
        g_iYmouse = y;
        g_iActiveButton |= b;		/* set the proper bit	*/
    }
    else
        g_iActiveButton &= ~b;		/* clear the proper bit	*/
}

void Keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
        break;

    case 'i':
    case 'I':
        {
            char str[256];
            sprintf(str, "miro_%04d.bmp", g_pScene->getShotNo());
            if (g_pCamera->IsOpenGL())
            {
                unsigned char* buf = new unsigned char[g_pImage->Width()*g_pImage->Height()*3];
                glReadPixels(0, 0, g_pImage->Width(), g_pImage->Height(),
                             GL_RGB, GL_UNSIGNED_BYTE, buf);
                g_pImage->WriteBMP(str, buf, g_pImage->Width(), g_pImage->Height());
            }
            else
            {
                g_pImage->WriteBMP(str);
            }
            break;
        }

    case 'r':
    case 'R':
        g_pCamera->setTraced(false);
        g_pCamera->SetRenderer(Camera::RENDER_RAYTRACE);
        break;

    case 'g':
    case 'G':
        g_pCamera->SetRenderer(Camera::RENDER_OPENGL);
        break;

    case '+':
        g_rScaleFact *= 1.5;
        break;

    case '-':
        g_rScaleFact /= 1.5;
        break;

    case 'w':
    case 'W':
        g_pCamera->SetEye(g_pCamera->GetEye() + g_rScaleFact*g_pCamera->GetViewDir());
        break;

    case 's':
    case 'S':
        g_pCamera->SetEye(g_pCamera->GetEye() - g_rScaleFact*g_pCamera->GetViewDir());
        break;

    case 'q':
    case 'Q':
        g_pCamera->SetEye(g_pCamera->GetEye() + g_rScaleFact*g_pCamera->GetUp());
        break;

    case 'z':
    case 'Z':
        g_pCamera->SetEye(g_pCamera->GetEye() - g_rScaleFact*g_pCamera->GetUp());
        break;

    case 'a':
    case 'A':
        {
            Vector3 vRight = g_pCamera->GetViewDir()*g_pCamera->GetUp();
            g_pCamera->SetEye(g_pCamera->GetEye() - g_rScaleFact*vRight);
            break;
        }

    case 'p':
    case 'P':
        {
            bool bRender = g_pScene->isRenderTree();
            g_pScene->setRenderTree(!bRender);
            break;
        }

    case 'd':
    case 'D':
        {
            Vector3 vRight = g_pCamera->GetViewDir()*g_pCamera->GetUp();
            g_pCamera->SetEye(g_pCamera->GetEye() + g_rScaleFact*vRight);
            break;
        }
        break;

    default:
        break;
    }
    glutPostRedisplay();
}

void Reshape(int w, int h)
{
    g_pImage->Resize(w, h);
    glViewport(0, 0, w, h);
    glutPostRedisplay();
}

void Visibility(int state)
{
    glClear(GL_COLOR_BUFFER_BIT);
    if (state == GLUT_HIDDEN)
        glutIdleFunc(0); // dont update if window is minimized
    else
        glutIdleFunc(Idle);
}

void InitOpenGL()
{
    glutInitWindowSize(g_pImage->Width(), g_pImage->Height());
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(200, 200);
    g_iMainWindow = glutCreateWindow("miro");

    glutIdleFunc(Idle);
    glutDisplayFunc(Display);
    glutKeyboardFunc(Keyboard);
    glutReshapeFunc(Reshape);
    glutWindowStatusFunc(Visibility);
    glutMouseFunc(Mouse);
    glutMotionFunc(Motion);

    // use the user defined clear color (defaults to black)
    glClearColor(g_pCamera->GetBGColor().x, g_pCamera->GetBGColor().y, g_pCamera->GetBGColor().z, 1);

    // we'll be coding in our own lighting and texturing!
    glDisable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
    glShadeModel(GL_SMOOTH);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // draw outlines only
}

