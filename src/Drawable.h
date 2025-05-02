#ifndef DRAWABLE_H
#define DRAWABLE_H

class Drawable {
public:
    virtual void draw() const = 0;
    virtual bool contains(float x, float y) const = 0;
    virtual void resize(float factor) = 0;
    virtual void move(float dx, float dy) = 0;
    virtual ~Drawable() {}
};

#endif