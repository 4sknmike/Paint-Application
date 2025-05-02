#ifndef CIRCLE_H
#define CIRCLE_H

#include "Drawable.h"

class Circle : public Drawable {
    float x;
    float y;
    float radius;
    float r;
    float g;
    float b;

public:
    Circle();
    Circle(float x, float y, float radius, float r, float g, float b);

    void draw() const override;
    bool contains(float x, float y) const override;
    void resize(float factor) override;
    void move(float dx, float dy) override;
};

#endif