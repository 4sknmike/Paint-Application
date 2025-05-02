#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Drawable.h"

class Rectangle : public Drawable {
    float x;
    float y;
    float width;
    float height;
    float r;
    float g;
    float b;

public:
    Rectangle();
    Rectangle(float x, float y, float width, float height, float r, float g, float b);

    void draw() const override;
    bool contains(float x, float y) const override;
    void resize(float factor) override;
    void move(float dx, float dy) override;
};

#endif