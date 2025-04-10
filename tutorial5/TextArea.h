#ifndef TEXTAREA_H
#define TEXTAREA_H

#include <string>
#include "RGB.h"
#include "defs.h"

class TextArea {
private:
    std::string id;
    std::string text;
    Rectangle rect;
    RGB fill;
    RGB border;

public:
    TextArea(const std::string& id, const std::string& text, int x, int y, int width, int height, const RGB& fill = RGB::WHITE(), const RGB& border = RGB::BLACK());
    TextArea(const Rectangle& rect, const std::string& id, const std::string& text, const RGB& fill = RGB::WHITE(), const RGB& border = RGB::BLACK());
    TextArea(const TextArea& other);

    void print() const;

    const std::string& getId() const;
    const std::string& getText() const;
    const Rectangle& getRect() const;
    const RGB& getFill() const;
    const RGB& getBorder() const;

    void setText(const std::string& text);
    void setRect(const Rectangle& rect);

    bool overlaps(const TextArea& ta) const;
};

#endif