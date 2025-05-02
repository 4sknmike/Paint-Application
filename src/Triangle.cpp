#include "Triangle.h"
#include <GL/freeglut.h>
#include <cmath>

Triangle::Triangle() {
    x = 0.0;
    y = 0.0;
    size = 0.1;
    r = 0.0;
    g = 0.0;
    b = 0.0;
}

Triangle::Triangle(float x, float y, float size, float r, float g, float b) {
    this->x = x;
    this->y = y;
    this->size = size;
    this->r = r;
    this->g = g;
    this->b = b;
}

void Triangle::draw() const {
    float halfSize = size / 2.0f;
    float height = size * sqrt(3.0) / 2.0f;

    glColor3f(r, g, b);
    glBegin(GL_TRIANGLES);
        glVertex2f(x, y + 2.0f / 3.0f * height);
        glVertex2f(x - halfSize, y - 1.0f / 3.0f * height);
        glVertex2f(x + halfSize, y - 1.0f / 3.0f * height);
    glEnd();
}

bool Triangle::contains(float mx, float my) const {
    return (
        mx >= x - size / 2 && mx <= x + size / 2 &&
        my >= y - size / 2 && my <= y + size / 2
    );
}

void Triangle::resize(float factor) {
    size *= factor;
}

void Triangle::move(float dx, float dy) {
    x += dx;
    y += dy;
}