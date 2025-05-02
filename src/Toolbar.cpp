#include "Toolbar.h"
#include "Enums.h"
#include <FL/Enumerations.H>
#include <bobcat_ui/image.h>
using namespace bobcat;

void Toolbar::deselectAllTools() const {
    pencilButton->color(FL_BACKGROUND_COLOR);
    eraserButton->color(FL_BACKGROUND_COLOR);
    circleButton->color(FL_BACKGROUND_COLOR);
    triangleButton->color(FL_BACKGROUND_COLOR);
    rectangleButton->color(FL_BACKGROUND_COLOR);
    polygonButton->color(FL_BACKGROUND_COLOR);
    mouseButton->color(FL_BACKGROUND_COLOR);
    plusButton->color(FL_BACKGROUND_COLOR);
    minusButton->color(FL_BACKGROUND_COLOR);
    frontButton->color(FL_BACKGROUND_COLOR);
    backButton->color(FL_BACKGROUND_COLOR);
    clearButton->color(FL_BACKGROUND_COLOR);
}

void Toolbar::visualizeSelectedTool() const {
    if (tool == PENCIL) {
        pencilButton->color(FL_WHITE);
    }
    else if (tool == ERASER) {
        eraserButton->color(FL_WHITE);
    }
    else if (tool == CIRCLE) {
        circleButton->color(FL_WHITE);
    }
    else if (tool == TRIANGLE) {
        triangleButton->color(FL_WHITE);
    }
    else if (tool == RECTANGLE) {
        rectangleButton->color(FL_WHITE);
    }
    else if (tool == POLYGON) {
        polygonButton->color(FL_WHITE);
    }
    else if (tool == MOUSE) {
        mouseButton->color(FL_WHITE);
    }
    else if (tool == PLUS) {
        plusButton->color(FL_WHITE);
    }
    else if (tool == MINUS) {
        minusButton->color(FL_WHITE);
    }
    else if (tool == FRONT) {
        frontButton->color(FL_WHITE);
    }
    else if (tool == BACK) {
        backButton->color(FL_WHITE);
    }
    else if (tool == CLEAR) {
        clearButton->color(FL_WHITE);
    }
}

void Toolbar::onClick(bobcat::Widget* sender) {
    deselectAllTools();

    if (sender == pencilButton) {
        std::cout << "Pencil was clicked" << std::endl;
        tool = PENCIL;
    }
    else if (sender == eraserButton) {
        std::cout << "Eraser was clicked" << std::endl;
        tool = ERASER;
    }
    else if (sender == circleButton) {
        std::cout << "Circle was clicked" << std::endl;
        tool = CIRCLE;
    }
    else if (sender == triangleButton) {
        std::cout << "Triangle was clicked" << std::endl;
        tool = TRIANGLE;
    }
    else if (sender == rectangleButton) {
        std::cout << "Rectangle was clicked" << std::endl;
        tool = RECTANGLE;
    }
    else if (sender == polygonButton) {
        std::cout << "Polygon was clicked" << std::endl;
        tool = POLYGON;
    }
    else if (sender == mouseButton) {
        std::cout << "Mouse button was clicked" << std::endl;
        tool = MOUSE;
    }
    else if (sender == plusButton) {
        std::cout << "Plus button was clicked" << std::endl;
        tool = PLUS;
    }
    else if (sender == minusButton) {
        std::cout << "Minus button was clicked" << std::endl;
        tool = MINUS;
    }
    else if (sender == frontButton) {
        std::cout << "Front button was clicked" << std::endl;
        tool = FRONT;
    }
    else if (sender == backButton) {
        std::cout << "Back button was clicked" << std::endl;
        tool = BACK;
    }
    else if (sender == clearButton) {
        std::cout << "Clear button was clicked" << std::endl;
        tool = CLEAR;
    }

    visualizeSelectedTool();
    redraw();
}

TOOL Toolbar::getTool() const {
    return tool;
}

Toolbar::Toolbar(int x, int y, int w, int h) : Group(x, y, w, h) {
    pencilButton = new Image(x, y, 50, 50, "./assets/pencil.png");
    eraserButton = new Image(x, y + 50, 50, 50, "./assets/eraser.png");
    circleButton = new Image(x, y + 100, 50, 50, "./assets/circle.png");
    triangleButton = new Image(x, y + 150, 50, 50, "./assets/triangle.png");
    rectangleButton = new Image(x, y + 200, 50, 50, "./assets/rectangle.png");
    polygonButton = new Image(x, y + 250, 50, 50, "./assets/polygon.png");
    mouseButton = new Image(x, y + 300, 50, 50, "./assets/mouse.png");
    plusButton = new Image(x, y + 350, 50, 50, "./assets/plus.png");
    minusButton = new Image(x, y + 400, 50, 50, "./assets/minus.png");
    frontButton = new Image(x, y + 450, 50, 50, "./assets/bring-to-front.png");
    backButton = new Image (x, y + 500, 50, 50, "./assets/send-to-back.png");
    clearButton = new Image(x, y + 550, 50, 50, "./assets/clear.png");

    tool = PENCIL;

    pencilButton->box(FL_BORDER_BOX);
    eraserButton->box(FL_BORDER_BOX);
    circleButton->box(FL_BORDER_BOX);
    triangleButton->box(FL_BORDER_BOX);
    rectangleButton->box(FL_BORDER_BOX);
    polygonButton->box(FL_BORDER_BOX);
    mouseButton->box(FL_BORDER_BOX);
    plusButton->box(FL_BORDER_BOX);
    minusButton->box(FL_BORDER_BOX);
    frontButton->box(FL_BORDER_BOX);
    backButton->box(FL_BORDER_BOX);
    clearButton->box(FL_BORDER_BOX);

    visualizeSelectedTool();

    ON_CLICK(pencilButton, Toolbar::onClick);
    ON_CLICK(eraserButton, Toolbar::onClick);
    ON_CLICK(circleButton, Toolbar::onClick);
    ON_CLICK(triangleButton, Toolbar::onClick);
    ON_CLICK(rectangleButton, Toolbar::onClick);
    ON_CLICK(polygonButton, Toolbar::onClick);
    ON_CLICK(mouseButton, Toolbar::onClick);
    ON_CLICK(plusButton, Toolbar::onClick);
    ON_CLICK(minusButton, Toolbar::onClick);
    ON_CLICK(frontButton, Toolbar::onClick);
    ON_CLICK(backButton, Toolbar::onClick);
    ON_CLICK(clearButton, Toolbar::onClick);
}