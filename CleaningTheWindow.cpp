//
// Created by Quoc An on 11/25/2020.
//

#include "CleaningTheWindow.h"
#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;

void CleaningTheWindow::Cleaning(std::string color) {
    if (color.compare("yellow")){
        glClearColor(1.0,0.0,0.0,0.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
    if (color.compare("red")){
        glClearColor(1.0,1.0,0.0,0.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

}