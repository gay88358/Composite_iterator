#ifndef LISTITERATOR_H
#define LISTITERATOR_H

#include "./iterator.h"
#include "./composite.h"

class ListIterator : public Iterator {
public:
    ListIterator(Composite *);
    bool isDone();
    void next();
    Component* currentItem();
private:
    Composite *_composite;
    int _index;
};

#endif