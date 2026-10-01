#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <cmath>

int x = 800;
int y = 600;

int posX = 100;
int posY = 100;

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f);


    // Draw square
    glBegin(GL_POLYGON);
    glVertex2i(posX, posY);
    glVertex2i(posX + 100, posY);
    glVertex2i(posX + 100, posY + 100);
    glVertex2i(posX, posY + 100);
    glEnd();


    glFlush();
}

void keyboard(unsigned char key, int x, int y){
    if (key == 'w')
        posY += 10;

    if (key == 's')
        posY -= 10;

    if (key == 'a')
        posX -= 10;

    if (key == 'd')
        posX += 10;

    glutPostRedisplay();
}

void init(){
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, x, 0, y);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(x, y);
    glutCreateWindow("My First GLUT Program");
    init();

    glutDisplayFunc(display);

    // Set the keyboard callback function
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}