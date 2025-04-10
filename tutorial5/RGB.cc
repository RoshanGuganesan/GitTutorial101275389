#include "RGB.h"

RGB::RGB(int r, int g, int b) : red(r), green(g), blue(b) {}

CuColour RGB::getColour() const {
    return (red << 16) | (green << 8) | blue;
}

void RGB::setColour(CuColour col) {
    red = (col >> 16) & 0xFF;
    green = (col >> 8) & 0xFF;
    blue = col & 0xFF;
}

void RGB::print() const {
    std::cout << "RGB(" << red << ", " << green << ", " << blue << ")" << std::endl;
}

RGB RGB::WHITE() { return RGB(255, 255, 255); }
RGB RGB::BLACK() { return RGB(0, 0, 0); }
RGB RGB::RED() { return RGB(255, 0, 0); }
RGB RGB::GREEN() { return RGB(0, 255, 0); }
RGB RGB::BLUE() { return RGB(0, 0, 255); }