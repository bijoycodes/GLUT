#define GL_SILENCE_DEPRECATION

#include <GLUT/glut.h>

int windowWidth = 800;
int windowHeight = 600;

int posX = 100;
int posY = 250;

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    // Red color
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

void animate(int value){
    // Move square 5 pixels to the right
    posX += 5;

    // If square goes outside the window, start again
    if (posX > windowWidth)
    {
        posX = 0;
    }

    // Tell GLUT to redraw the screen
    glutPostRedisplay();

    // Call animate() again after 50 milliseconds
    glutTimerFunc(50, animate, 0);
}

void init(){
    // Background color: white
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    // Set projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Coordinate system: 0-800 horizontally, 0-600 vertically
    gluOrtho2D(0, windowWidth, 0, windowHeight);

    // Switch back to ModelView for object transformations
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv){
    // Initialize GLUT
    glutInit(&argc, argv);

    // Display mode
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Window size
    glutInitWindowSize(windowWidth, windowHeight);

    // Create window
    glutCreateWindow("GLUT Animation");

    // Initialize OpenGL
    init();

    // Register display function
    glutDisplayFunc(display);

    // Start animation
    glutTimerFunc(50, animate, 0);

    // Start GLUT
    glutMainLoop();

    return 0;
}