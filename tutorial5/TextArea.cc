#include "TextArea.h"
#include <iostream>

TextArea::TextArea(const std::string& id, const std::string& text, int x, int y, int width, int height, const RGB& fill, const RGB& border)
    : id(id), text(text), rect{x, y, width, height}, fill(fill), border(border) {}

TextArea::TextArea(const Rectangle& rect, const std::string& id, const std::string& text, const RGB& fill, const RGB& border)
    : id(id), text(text), rect(rect), fill(fill), border(border) {}

TextArea::TextArea(const TextArea& other)
    : id(other.id), text("DUPLICATE"), rect(other.rect), fill(other.fill), border(other.border) {}

void TextArea::print() const {
    std::cout << "TextArea id: " << id << "\n";
    std::cout << "Preferred location: " << rect.x << ", " << rect.y << "\n";
    std::cout << "Size: " << rect.width << ", " << rect.height << "\n";
    std::cout << "Text: " << text << "\n";
}

const std::string& TextArea::getId() const { return id; }
const std::string& TextArea::getText() const { return text; }
const Rectangle& TextArea::getRect() const { return rect; }
const RGB& TextArea::getFill() const { return fill; }
const RGB& TextArea::getBorder() const { return border; }

void TextArea::setText(const std::string& newText) { text = newText; }
void TextArea::setRect(const Rectangle& newRect) { rect = newRect; }

bool TextArea::overlaps(const TextArea& ta) const {
    return rect.overlaps(ta.getRect());
}