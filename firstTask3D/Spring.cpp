//
//  Spring.cpp
//  firstTask3D
//
//  Created by Сергей Павленок on 13.06.2022.
//

#include "Spring.hpp"


void createSpring(
    GLfloat rounds, GLfloat height, GLfloat thickness, GLfloat radius,
    std::vector<GLfloat> &vertices, std::vector<GLuint> &indices)
{
    const int slices = 32;
    const int step = 5;
    for (int i = -slices; i <= rounds * 360 + step; i += step)
    {
        for (int j = 0; j < slices; j ++)
        {
            GLfloat t = (GLfloat)i / 360 + (GLfloat)j / slices * step / 360;
            t = std::max(0.0f, std::min(rounds, t));
            GLfloat a1 = t * M_PI * 2;
            GLfloat a2 = (GLfloat)j / slices * M_PI * 2;
            GLfloat d = radius + thickness * cos(a2);
            vertices.push_back(d * cos(a1));
            vertices.push_back(d * sin(a1));
            vertices.push_back(thickness * sin(a2) + height * t / rounds);
        }
    }
    for (GLuint i = 0; i < (GLuint)vertices.size() / 3 - slices; ++i)
    {
        indices.push_back(i);
        indices.push_back(i + slices);
    }
}

void drawSpring(
    const std::vector<GLfloat>& vertices, const std::vector<GLuint>& indices)
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // just to see the mesh (delete later)

    glColor4f(1, 1, 1, 1);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices.data());
    glDrawElements(GL_TRIANGLE_STRIP, indices.size(), GL_UNSIGNED_INT, indices.data());
    glDisableClientState(GL_VERTEX_ARRAY);
}

std::vector<GLfloat> springVertices;
std::vector<GLuint> springIndices;

void initSpring()
{
    createSpring(1.5, 0.25, 0.03, 0.1, springVertices, springIndices);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(20.0, 1.0f, 0.1f, 1000);
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(0, -1, 0.125, 0, 0.0, 0.125, 0, 0, 1);

    glEnable(GL_DEPTH_TEST);
}

void displaySpring()
{
    initSpring();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawSpring(springVertices, springIndices);
    glutSwapBuffers();
}
