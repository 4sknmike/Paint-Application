#include "Rectangle.h"
#include <GL/freeglut.h>

Rectangle::Rectangle() {
    x = 0.0;
    y = 0.0;
    width = 0.2;
    width = 0.2;
    r = 0.0;
    g = 0.0;
    b = 0.0;
}

Rectangle::Rectangle(float x, float y, float width, float height, float r, float g, float b) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->r = r;
    this->g = g;
    this->b = b;
}

void Rectangle::draw() const {
    glColor3f(r, g, b);
    
    glBegin(GL_POLYGON);
        glVertex2f(x - width/2, y + height/2);
        glVertex2f(x + width/2, y + height/2);
        glVertex2f(x + width/2, y - height/2);
        glVertex2f(x - width/2, y - height/2);
    glEnd();
}

bool Rectangle::contains(float mx, float my) const {
    return (
        mx >= x - width / 2 && mx <= x + width / 2 &&
        my >= y - height / 2 && my <= y + height / 2
    );
}

void Rectangle::resize(float factor) {
    width *= factor;
    height *= factor;
}

void Rectangle::move(float dx, float dy) {
    x += dx;
    y += dy;
}