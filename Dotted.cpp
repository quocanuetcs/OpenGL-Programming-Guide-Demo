//
// Created by Quoc An on 11/29/2020.
//

#include "Dotted.h"
#include <GL/glut.h>

void Dotted::draw() {
    glOrtho(0.0, 200.0, 0.0, 200.0, -1.0, 1.0);
    glShadeModel (GL_FLAT);
    glColor3f (1.0, 1.0, 1.0);
    glEnable (GL_LINE_STIPPLE);
    glLineStipple (1, 0x0101); /* dotted line */
    glBegin(GL_LINES);
    glVertex2f (50.0,125.0);
    glVertex2f (150.0,125.0);
    glEnd();
}
