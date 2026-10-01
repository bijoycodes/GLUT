#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <cmath>

int x = 800;
int y = 600;

// Function to draw a circle using line loop
// cx, cy: center coordinates of the circle
// r: radius of the circle
void drawCircle(float cx, float cy, float r){
    glBegin(GL_LINE_LOOP);

    for (int i = 0; i < 360; i++){
        float angle = i * 3.14159f / 180.0f;
        float x = cx + r * cos(angle);
        float y = cy + r * sin(angle);
        glVertex2f(x, y);
    }

    glEnd();
}

// Function to draw a filled circle using polygon
// cx, cy: center coordinates of the circle
// r: radius of the circle
void drawFilledCircle(float cx, float cy, float r){
    glBegin(GL_POLYGON);

    for (int i = 0; i < 360; i++){
        float angle = i * 3.14159f / 180.0f;

        float x = cx + r * cos(angle);
        float y = cy + r * sin(angle);

        glVertex2f(x, y);
    }

    glEnd();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f);
    glLineWidth(5.0f);

    // -------------Draw Point-------------------
    glBegin(GL_POINTS);
    glVertex2i(100, 100);
    glEnd();

    // -------------Draw Line-------------------
    glBegin(GL_LINES);
    glVertex2i(200, 200);
    glVertex2i(800, 200);
    glEnd();

    //------------Draw Line Strip (draw a connected sequence of lines)-------------------
    glBegin(GL_LINE_STRIP);
    glVertex2i(100, 100);
    glVertex2i(200, 200);
    glVertex2i(300, 100);
    glVertex2i(400, 200);
    glEnd();

    //-------------Draw Line Loop (Draw Any closed shape)-------------------
    glBegin(GL_LINE_LOOP);
    glVertex2i(100, 100);
    glVertex2i(300, 100);
    glVertex2i(300, 300);
    glVertex2i(100, 300);
    glEnd();

    //-------------Draw Polygon (draw any shape filled)-------------------
    glBegin(GL_POLYGON);
    glVertex2i(100, 100);
    glVertex2i(300, 100);
    glVertex2i(350, 200);
    glVertex2i(200, 300);
    glVertex2i(50, 200);
    glEnd();

    // ------------Draw Circle-------------------
    drawCircle(400, 300, 100);

    // ------------Draw Filled Circle-------------------
    drawFilledCircle(600, 300, 50);

    glFlush();
}

void init(){
    // Set the clear color to white and value renge is from 0.0 to 1.0
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    // Set up coordinate system to match pixel dimensions (0 to X, 0 to Y)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, x, 0, y); // (left, right, bottom, top)
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Set the initial window Size (width, height)
    glutInitWindowSize(x, y);
    glutCreateWindow("My First GLUT Program");
    init();

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}