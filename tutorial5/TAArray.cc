#include "TAArray.h"

TAArray::TAArray() : size(0) {}

TAArray::~TAArray() {
    for (int i = 0; i < size; ++i) {
        delete elements[i];
    }
}

bool TAArray::add(TextArea* ta) {
    if (size >= MAX_COMPONENTS) return false;
    elements[size++] = ta;
    return true;
}

bool TAArray::add(TextArea* ta, int index) {
    if (size >= MAX_COMPONENTS || index < 0 || index > size) return false;
    for (int i = size; i > index; --i) {
        elements[i] = elements[i - 1];
    }
    elements[index] = ta;
    ++size;
    return true;
}

TextArea* TAArray::get(int index) const {
    if (index < 0 || index >= size) return nullptr;
    return elements[index];
}

TextArea* TAArray::get(const std::string& id) const {
    for (int i = 0; i < size; ++i) {
        if (elements[i]->getId() == id) {
            return elements[i];
        }
    }
    return nullptr;
}

TextArea* TAArray::remove(int index) {
    if (index < 0 || index >= size) return nullptr;
    TextArea* removed = elements[index];
    for (int i = index; i < size - 1; ++i) {
        elements[i] = elements[i + 1];
    }
    --size;
    return removed;
}

TextArea* TAArray::remove(const std::string& id) {
    for (int i = 0; i < size; ++i) {
        if (elements[i]->getId() == id) {
            TextArea* removed = elements[i];
            for (int j = i; j < size - 1; ++j) {
                elements[j] = elements[j + 1];
            }
            --size;
            return removed;
        }
    }
    return nullptr;
}

int TAArray::getSize() const { return size; }
