#include "CleaningTheWindow.h"
#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;

void CleaningTheWindow::cleaningRed() {
    glClearColor(1.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
}

void CleaningTheWindow::cleaningMagenta() {
        glClearColor(1.0,0.0,1.0,0.0);
        glClear(GL_COLOR_BUFFER_BIT);
}