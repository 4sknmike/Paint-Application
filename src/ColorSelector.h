#ifndef COLOR_SELECTOR_H
#define COLOR_SELECTOR_H

#include <bobcat_ui/all.h>
#include "Color.h"
#include "Enums.h"

class ColorSelector : public bobcat::Group {
public:
    bobcat::Button* redButton;
    bobcat::Button* orangeButton;
    bobcat::Button* yellowButton;
    bobcat::Button* greenButton;
    bobcat::Button* blueButton;
    bobcat::Button* indigoButton;
    bobcat::Button* violetButton;

    ColorSelector(int x, int y, int w, int h);

    Color getColor() const;

private:

    Color selectedColor;

    void onRedClick(bobcat::Widget* sender);
    void onOrangeClick(bobcat::Widget* sender);
    void onYellowClick(bobcat::Widget* sender);
    void onGreenClick(bobcat::Widget* sender);
    void onBlueClick(bobcat::Widget* sender);
    void onIndigoClick(bobcat::Widget* sender);
    void onVioletClick(bobcat::Widget* sender);
};

#endif