#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>

int x = 800;
int y = 600;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f);

    // Move origin to the center of the window
    glTranslatef(150, 150, 0);

    // Rotate 45 degrees
    glRotatef(45, 0, 0, 1);

    glTranslatef(-150, -150, 0);


    // Draw square around the origin
    glBegin(GL_POLYGON);

    glVertex2i(100, 100);
    glVertex2i(200, 100);
    glVertex2i(200, 200);
    glVertex2i(100, 200);

    glEnd();

    glFlush();
}

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, x, 0, y);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(x, y);

    glutCreateWindow("Rotation Example");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}