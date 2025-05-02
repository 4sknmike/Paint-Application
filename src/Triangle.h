#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Drawable.h"

class Triangle : public Drawable {
    float x;
    float y;
    float size;
    float r;
    float g;
    float b;

public:
    Triangle();
    Triangle(float x, float y, float size, float r, float g, float b);

    void draw() const override;
    bool contains(float x, float y) const override;
    void resize(float factor) override;
    void move(float dx, float dy) override;
};

#endif