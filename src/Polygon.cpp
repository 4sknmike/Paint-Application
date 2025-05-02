#include "Polygon.h"
#include <GL/freeglut.h>
#include <cmath>

Polygon::Polygon() {
    x = 0.0;
    y = 0.0;
    radius = 0.1;
    r = 0.0;
    g = 0.0;
    b = 0.0;
}
Polygon::Polygon(float x, float y, float radius, float r, float g, float b) {
    this->x = x;
    this->y = y;
    this->radius = radius;
    this->r = r;
    this->g = g;
    this->b = b;
}
void Polygon::draw() const {
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    int sides = 5;
    for (int i = 0; i < sides; i++) {
        float angle = 2 * 3.1415926f * i / sides + 3.1415926f / 2.0f;
        float dx = radius * cos(angle);
        float dy = radius * sin(angle);
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}

bool Polygon::contains(float mx, float my) const {
    float dx = mx - x;
    float dy = my - y;
    return dx * dx + dy * dy;
}

void Polygon::resize(float factor) {
    radius *= factor;
}

void Polygon::move(float dx, float dy) {
    x += dx;
    y += dy;
}
