#include "Canvas.h"
#include "Drawable.h"
#include <GL/freeglut.h>
#include <bobcat_ui/bobcat_ui.h>

Canvas::Canvas(int x, int y, int w, int h) : Canvas_(x, y, w, h) {
    //
}
void Canvas::startScribble() {
    currentScribble = new Scribble();
}
void Canvas::addPointToScribble(float x, float y, float r, float g, float b, int size) {
    if (currentScribble) {
        currentScribble->addPoint(x, y, r, g, b, size);
    }
}
void Canvas::endScribble() {
    if (currentScribble) {
        drawables.push_back(currentScribble);
        currentScribble = nullptr;
    }
}
void Canvas::addCircle(float x, float y, float radius, float r, float g, float b) {
    drawables.push_back(new Circle(x, y, radius, r, g, b));
}
void Canvas::addTriangle(float x, float y, float size, float r, float g, float b) {
    drawables.push_back(new Triangle(x, y, size, r, g, b));
}
void Canvas::addRectangle(float x, float y, float width, float height, float r, float g, float b) {
    drawables.push_back(new Rectangle(x, y, width, height, r, g, b));
}
void Canvas::addPolygon(float x, float y, float radius, float r, float g, float b) {
    drawables.push_back(new Polygon(x, y, radius, r, g, b));
}
Drawable* Canvas::getSelected() const {
    return selected;
}
void Canvas::selectShape(float x, float y) {
    for (int i = drawables.size() - 1; i >= 0; i--) {
        if (drawables[i]->contains(x, y)) {
            selected = drawables[i];
            return;
        }
    }
    selected = nullptr;
}
void Canvas::bringToFront() {
    if (!selected) return;

    for (unsigned int i = 0; i < drawables.size(); i++) {
        if (drawables[i] == selected) {
            drawables.erase(drawables.begin() + i);
            drawables.push_back(selected);
            break;
        }
    }
}
void Canvas::sendToBack() {
    if (!selected) return;

    for (unsigned int i = 0; i < drawables.size(); i++) {
        if (drawables[i] == selected) {
            drawables.erase(drawables.begin() + i);
            drawables.insert(drawables.begin(), selected);
            break;
        }
    }
}
void Canvas::clearAll() {
    for (Drawable* d : drawables) {
        delete d;
    }
    drawables.clear();

    if (currentScribble) {
        delete currentScribble;
        currentScribble = nullptr;
    }
    
    selected = nullptr;
}
void Canvas::render() {
    for (Drawable* d : drawables) {
        d->draw();
    }
    if (currentScribble) {
        currentScribble->draw();
    }
}