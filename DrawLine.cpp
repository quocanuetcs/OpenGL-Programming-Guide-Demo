#include "DrawLine.h"
#include <GL/glut.h>

void DrawLine::draw() {
    glOrtho(0.0, 200.0, 0.0, 200.0, -1.0, 1.0);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    glVertex2f(50.0, 125.0);
    glVertex2f(150.0, 125.0);
    glEnd();
}