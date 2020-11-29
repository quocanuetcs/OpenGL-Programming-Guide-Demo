#include "DrawRectangle.h"
#include <GL/glut.h>

using namespace std;

void DrawRectangle::drawDefault() {
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(0.25, 0.25, 0.0);
    glVertex3f(0.75, 0.25, 0.0);
    glVertex3f(0.75, 0.75, 0.0);
    glVertex3f(0.25, 0.75, 0.0);
    glEnd();
}

void DrawRectangle::drawAuto() {
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
    glColor3f(1.0, 0.0f, 0.0f);
    glRectf(0.25f, 0.75f, 0.75f, 0.25f);
    glutSwapBuffers();
}

