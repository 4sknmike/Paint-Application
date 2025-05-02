#include "ColorSelector.h"
#include "Color.h"
#include <FL/Enumerations.H>
#include <bobcat_ui/all.h>
#include <bobcat_ui/bobcat_ui.h>
#include <bobcat_ui/button.h>
using namespace bobcat;

ColorSelector::ColorSelector(int x, int y, int w, int h) : Group(x, y, w, h) {
    redButton = new Button(x, y, 50, 50);
    redButton->color(fl_rgb_color(255, 0, 0));

    orangeButton = new Button(x + 50, y, 50, 50);
    orangeButton->color(fl_rgb_color(255, 127, 0));

    yellowButton = new Button(x + 100, y, 50, 50);
    yellowButton->color(fl_rgb_color(255, 255, 0));

    greenButton = new Button(x + 150, y, 50, 50),
    greenButton->color(fl_rgb_color(0, 255, 0));

    blueButton = new Button(x + 200, y, 50, 50);
    blueButton->color(fl_rgb_color(0, 0, 255));

    indigoButton = new Button(x + 250, y, 50, 50);
    indigoButton->color(fl_rgb_color(75, 0, 130));

    violetButton = new Button(x + 300, y, 50, 50);
    violetButton->color(fl_rgb_color(148, 0, 211));

    redButton->box(FL_BORDER_BOX);
    orangeButton->box(FL_BORDER_BOX);
    yellowButton->box(FL_BORDER_BOX);
    greenButton->box(FL_BORDER_BOX);
    blueButton->box(FL_BORDER_BOX);
    indigoButton->box(FL_BORDER_BOX);
    violetButton->box(FL_BORDER_BOX);

    selectedColor = Color(1.0, 0.0, 0.0);

    ON_CLICK(redButton, ColorSelector::onRedClick);
    ON_CLICK(orangeButton, ColorSelector::onOrangeClick);
    ON_CLICK(yellowButton, ColorSelector::onYellowClick);
    ON_CLICK(greenButton, ColorSelector::onGreenClick);
    ON_CLICK(blueButton, ColorSelector::onBlueClick);
    ON_CLICK(indigoButton, ColorSelector::onIndigoClick);
    ON_CLICK(violetButton, ColorSelector::onVioletClick);
    
}

Color ColorSelector::getColor() const {
    return selectedColor;
}

void ColorSelector::onRedClick(bobcat::Widget* sender) {
    selectedColor = Color(1.0, 0.0, 0.0);
}
void ColorSelector::onOrangeClick(bobcat::Widget* sender) {
    selectedColor = Color(1.0, 0.498, 0.0);
}
void ColorSelector::onYellowClick(bobcat::Widget* sender) {
    selectedColor = Color(1.0, 1.0, 0.0);
}
void ColorSelector::onGreenClick(bobcat::Widget* sender) {
    selectedColor = Color(0.0, 1.0, 0.0);
}
void ColorSelector::onBlueClick(bobcat::Widget* sender) {
    selectedColor = Color(0.0, 0.0, 1.0);
}
void ColorSelector::onIndigoClick(bobcat::Widget* sender) {
    selectedColor = Color(0.294, 0.0, 0.51);
}
void ColorSelector::onVioletClick(bobcat::Widget* sender) {
    selectedColor = Color(0.58, 0.0, 0.827);
}