#include "Application.h"


using namespace bobcat;
using namespace std;

static float lastX = 0.0f;
static float lastY = 0.0f;

void Application::onCanvasMouseUp(bobcat::Widget* sender, float mx, float my) {
    TOOL tool = toolbar->getTool();
    if (tool == PENCIL || tool == ERASER) {
        canvas->endScribble();
    }

    if (tool == PENCIL) {
        canvas->startScribble();
        canvas->addPointToScribble(mx, my, color.getR(), color.getG(), color.getB(), 7);
        canvas->redraw();
    }
    else if (tool == ERASER) {
        canvas->eraseAt(mx, my, 0.01f); // adjust radius for precision
        canvas->redraw();
    }    

    }
    else if (tool == CIRCLE) {
        canvas->addCircle(mx, my, 0.1, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if (tool == TRIANGLE) {
        canvas->addTriangle(mx, my, 0.2, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if(tool == RECTANGLE) {
        canvas->addRectangle(mx, my, 0.2, 0.2, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if (tool == POLYGON) {
        canvas->addPolygon(mx, my, 0.15, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if (tool == MOUSE) {
        lastX = mx;
        lastY = my;
        canvas->selectShape(mx, my);
        canvas->redraw();
    }
    else if (tool == PLUS) {
        Drawable* selected = canvas->getSelected();
        if (selected) {
            selected->resize(1.25f);
            canvas->redraw();
        }
    }
    else if (tool == MINUS) {
        Drawable* selected = canvas->getSelected();
        if (selected) {
            selected->resize(0.8f);
            canvas->redraw();
        }
    }
    else if (tool == FRONT) {
        canvas->selectShape(mx, my);
        canvas->bringToFront();
        canvas->redraw();
    }
    else if (tool == BACK) {
        canvas->selectShape(mx, my);
        canvas->sendToBack();
        canvas->redraw();
    }
    else if (tool == CLEAR) {
        canvas->clearAll();
    }
}

void Application::onCanvasDrag(bobcat::Widget* sender, float mx, float my) {
    TOOL tool = toolbar->getTool();
    Color color = colorSelector->getColor();

    if (tool == PENCIL) {
        canvas->addPointToScribble(mx, my, color.getR(), color.getG(), color.getB(), 7);
        canvas->redraw();
    }
    else if (tool == ERASER) {
        canvas->eraseAt(mx, my, 0.01f); // match same radius
        canvas->redraw();
    }    
    }
    else if (tool == MOUSE) {
        float dx = mx - lastX;
        float dy = my - lastY;

        Drawable* selected = canvas->getSelected();
        if (selected) {
            selected->move(dx, dy);
            canvas->redraw();
       }

       lastX = mx;
       lastY = my;
    
    }
}

Application::Application() {
    window = new Window(25, 75, 700, 700, "Paint Application");

    toolbar = new Toolbar(0, 0, 50, 650);
    canvas = new Canvas(50, 0, 600, 600);
    colorSelector = new ColorSelector(50, 600, 350, 50);

    window->add(toolbar);
    window->add(canvas);
    window->add(colorSelector);

    ON_MOUSE_DOWN(canvas, Application::onCanvasMouseDown);
    ON_DRAG(canvas, Application::onCanvasDrag);

    window->show();
}