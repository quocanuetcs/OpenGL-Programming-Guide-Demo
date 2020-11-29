#include "Dash.h"
#include <GL/glut.h>

void Dash::draw() {
    glColor3f(1.0, 1.0, 1.0);
    glEnable(GL_LINE_STIPPLE);
    glOrtho(0.0, 300.0, 0.0, 300.0, -1.0, 1.0);
    glLineStipple(1, 0x00FF);
    glBegin(GL_LINES);
    glVertex2f(50, 125);
    glVertex2f(250, 125);
    glEnd();
}