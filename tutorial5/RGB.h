#ifndef RGB_H
#define RGB_H

#include "defs.h"
#include <iostream>

class RGB {
private:
    int red;
    int green;
    int blue;

public:
    RGB(int r = 255, int g = 255, int b = 255);

    CuColour getColour() const;
    void setColour(CuColour col);
    void print() const;

    static RGB WHITE();
    static RGB BLACK();
    static RGB RED();
    static RGB GREEN();
    static RGB BLUE();
};

#endif