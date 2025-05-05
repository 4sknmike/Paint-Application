#include "Circle.h"
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <cmath>

Circle::Circle() {
    x = 0.0;
    y = 0.0;
    radius = 0.1;
    r = 0.0;
    g = 0.0;
    b = 0.0;
}

Circle::Circle(float x, float y, float radius, float r, float g, float b) {
    this->x = x;
    this->y = y;
    this->radius = radius;
    this->r = r;
    this->g = g;
    this->b = b;
}

void Circle::draw() const {
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    int segments = 50;
    for (int i = 0; i < segments; i++) {
        float theta = 2.0f * 3.1415926 * float(i) / float(segments);
        float dx = radius * cosf(theta);
        float dy = radius * sinf(theta);
        glVertex2f(x + dx, y  + dy);
    }
    glEnd();
}

bool Circle::contains(float mx, float my) const {
    float dx = mx - x;
    float dy = my - y;
    return dx * dx + dy * dy <= radius * radius;
}

void Circle::resize(float factor) {
    radius *= factor;
}

void Circle::move(float dx, float dy) {
    x += dx;
    y += dy;
}
void Canvas::eraseAt(float x, float y, float radius) {
    for (Drawable* d : drawables) {
        Scribble* scribble = dynamic_cast<Scribble*>(d);
        if (scribble) {
            scribble->eraseNear(x, y, radius);
        }
    }
}
