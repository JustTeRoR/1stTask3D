//
//  main.cpp
//  firstTask3D
//
//  Created by Сергей Павленок on 13.06.2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Spring.hpp"
#include <GLUT/glut.h>
#include <OpenGL/glu.h>
#include <OpenGL/gl.h>

#define PI 3.14159265358979323846

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("Task1");
    glutDisplayFunc(displaySpring);
    glutMainLoop();
    
    return 0;
}
