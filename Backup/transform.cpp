#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>

int x = 800;
int y = 600;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // =========================
    // Element 1
    // Translate + Rotate + Scale
    // =========================

    glColor3f(1.0f, 0.0f, 0.0f);

    glPushMatrix();

    // Move
    glTranslatef(200, 300, 0);

    // Rotate
    glRotatef(45, 0, 0, 1);

    // Scale
    glScalef(1.5f, 1.5f, 1.0f);

    // Draw square around origin
    glBegin(GL_POLYGON);
    glVertex2i(-50, -50);
    glVertex2i(50, -50);
    glVertex2i(50, 50);
    glVertex2i(-50, 50);
    glEnd();

    glPopMatrix();


    // =========================
    // Element 2
    // Normal square
    // =========================

    glColor3f(0.0f, 0.0f, 1.0f);

    glBegin(GL_POLYGON);
    glVertex2i(500, 250);
    glVertex2i(600, 250);
    glVertex2i(600, 350);
    glVertex2i(500, 350);
    glEnd();

    glFlush();
}

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, x, 0, y);

    // Use ModelView for transformations
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(x, y);

    glutCreateWindow("Transformations");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}

// ============================================================
// OPENGL 2D TRANSFORMATIONS - QUICK NOTES
// ============================================================

// 1. TRANSLATION = MOVE
// ---------------------
// glTranslatef(x, y, z);
//
// x = move left/right
// y = move up/down
// z = depth (usually 0 in 2D)
//
// Examples:
// glTranslatef(100, 0, 0);    // Move right
// glTranslatef(-100, 0, 0);   // Move left
// glTranslatef(0, 100, 0);    // Move up
// glTranslatef(0, -100, 0);   // Move down


// 2. ROTATION = TURN
// ------------------
// glRotatef(angle, x, y, z);
//
// angle = how many degrees to rotate
// x, y, z = rotation axis
//
// For 2D, rotate around the Z axis:
// glRotatef(45, 0, 0, 1);      // Rotate 45 degrees
//
// 0, 0, 1 means:
// X axis = 0
// Y axis = 0
// Z axis = 1
//
// Positive angle = counterclockwise
// Negative angle = clockwise


// 3. SCALING = CHANGE SIZE
// ------------------------
// glScalef(x, y, z);
//
// x = change width
// y = change height
// z = change depth
//
// Examples:
// glScalef(2, 2, 1);           // 2x bigger
// glScalef(0.5, 0.5, 1);       // Half size
// glScalef(2, 1, 1);            // 2x wider
// glScalef(1, 2, 1);            // 2x taller


// 4. PUSH MATRIX = SAVE
// ---------------------
// glPushMatrix();
//
// Saves the current transformation.
// Useful when we want to transform only ONE element.
//
// Example:
// glPushMatrix();
// glTranslatef(100, 100, 0);
// // Draw element
// glPopMatrix();


// 5. POP MATRIX = RESTORE
// -----------------------
// glPopMatrix();
//
// Restores the transformation that was saved
// by glPushMatrix().
//
// This prevents the transformation from affecting
// other elements.


/*
    BASIC PATTERN:

    glPushMatrix();

        glTranslatef(...);     // Move
        glRotatef(...);        // Rotate
        glScalef(...);         // Scale

        // Draw element here

    glPopMatrix();


    IMPORTANT:
    Push -> Transform -> Draw -> Pop

    This allows us to transform one element
    without affecting other elements.
*/


// ============================================================
// 2D PARAMETER SUMMARY
// ============================================================

// Translation:
// glTranslatef(x, y, 0);
//
// Rotation:
// glRotatef(angle, 0, 0, 1);
//
// Scaling:
// glScalef(x, y, 1);
//
// Save:
// glPushMatrix();
//
// Restore:
// glPopMatrix();
// ============================================================