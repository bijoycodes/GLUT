#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>

int x = 800;
int y = 600;

float posX = 100;
float posY = 100;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f);

    glPushMatrix();

    glTranslatef(posX, posY, 0);

    // Draw square
    glBegin(GL_POLYGON);
    glVertex2f(-50, -50);
    glVertex2f(50, -50);
    glVertex2f(50, 50);
    glVertex2f(-50, 50);
    glEnd();

    glPopMatrix();

    glFlush();
}

void animate(){
    // Move the square
    posX += 0.1f;

    // If it reaches the right side,
    // start again from the left
    if (posX > 800)
        posX = 0;

    // Tell GLUT to redraw
    glutPostRedisplay();
}

void init(){
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, x, 0, y);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(x, y);

    glutCreateWindow("Animation");

    init();

    glutDisplayFunc(display);

    // Continuously call animate()
    glutIdleFunc(animate);

    glutMainLoop();

    return 0;
}