#ifndef SCRIBBLE_H
#define SCRIBBLE_H

#include "Drawable.h"
#include "Point.h"
#include <vector>

class Scribble : public Drawable {
    std::vector<Point*> points;

public:
    Scribble();
    ~Scribble();

    void addPoint(float x, float y, float r, float g, float b, int size);

    void draw() const override;
    bool contains(float x, float y) const override;
    void resize(float factor) override;
    void move(float dx, float dy) override;
    void eraseNear(float x, float y, float radius);
};

#endif