#include "Scribble.h"
#include <cmath>

Scribble::Scribble() {}

Scribble::~Scribble() {
    for (Point* p : points) delete p;
}

void Scribble::addPoint(float x, float y, float r, float g, float b, int size) {
    points.push_back(new Point(x, y, r, g, b, size));
}

void Scribble::draw() const {
    for (Point* p : points) {
        p->draw();
    }
}

bool Scribble::contains(float x, float y) const {
    for (Point* p : points) {
        float dx = x - p->getX();
        float dy = y - p->getY();
        if (dx * dx + dy * dy < 0.01f) {
            return true;
        }
    }
    return false;
}

void Scribble::resize(float factor) {
    for (Point* p : points) {
        float dx = p->getX() - points[0]->getX();
        float dy = p->getY() - points[0]->getY();
        float newX = points[0]->getX() + dx * factor;
        float newY = points[0]->getY() + dy * factor;
        *p = Point(newX, newY, p->getR(), p->getG(), p->getB(), p->getSize());
    }
}

void Scribble::move(float dx, float dy) {
    for (Point* p : points) {
        float newX = p->getX() + dx;
        float newY = p->getY() + dy;
        *p = Point(newX, newY, p->getR(), p->getG(), p->getB(), p->getSize());
    }
}