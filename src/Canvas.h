#ifndef CANVAS_H
#define CANVAS_H

#include <bobcat_ui/all.h>
#include <bobcat_ui/canvas.h>
#include <vector>
#include "Point.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "Polygon.h"
#include "Drawable.h"
#include "Scribble.h"

class Canvas : public bobcat::Canvas_ {
    std::vector<Drawable*> drawables;
    Drawable* selected = nullptr;
    Scribble* currentScribble = nullptr;

public:
    Canvas(int x, int y, int w, int h);

    Drawable* getSelected() const;

    void startScribble();
    void addPointToScribble(float x, float y, float r, float g, float b, int size);
    void endScribble();
    void selectShape(float x, float y);


    void addCircle(float x, float y, float radius, float r, float g, float b);
    void addTriangle(float x, float y, float size, float r, float g, float b);
    void addRectangle(float x, float y, float width, float height, float r, float g, float b);
    void addPolygon(float x, float y, float radius, float r, float g, float b);

    void clearAll();
    void render();
};
#endif