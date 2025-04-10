#ifndef TAARRAY_H
#define TAARRAY_H

#include "TextArea.h"
#include "defs.h"

class TAArray {
private:
    TextArea* elements[MAX_COMPONENTS];
    int size;

public:
    TAArray();
    ~TAArray();

    bool add(TextArea* ta);
    bool add(TextArea* ta, int index);
    TextArea* get(int index) const;
    TextArea* get(const std::string& id) const;
    TextArea* remove(int index);
    TextArea* remove(const std::string& id);
    int getSize() const;
};

#endif
