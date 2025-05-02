#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <bobcat_ui/all.h>
#include "Enums.h"

class Toolbar : public bobcat::Group {
    bobcat::Image* pencilButton;
    bobcat::Image* eraserButton;
    bobcat::Image* circleButton;
    bobcat::Image* triangleButton;
    bobcat::Image* rectangleButton;
    bobcat::Image* polygonButton;
    bobcat::Image* clearButton;
    bobcat::Image* mouseButton;
    bobcat::Image* plusButton;
    bobcat::Image* minusButton;
    bobcat::Image* frontButton;
    bobcat::Image* backButton;
    

    TOOL tool;

    void onClick(bobcat::Widget* sender);
    void deselectAllTools() const;
    void visualizeSelectedTool() const;

public:
    Toolbar(int x, int y, int w, int h);

    TOOL getTool() const;
};

#endif