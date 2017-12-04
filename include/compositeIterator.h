#ifndef COMPOSITEITERATOR_H
#define COMPOSITEITERATOR_H

#include "./iterator.h"
#include <stack>

using std::stack;
class CompositeIterator : public Iterator {
public:
    CompositeIterator(Iterator *it);
    bool isDone();
    void next();
    Component* currentItem();
private:
    stack<Iterator*> _stack;
};

#endif