#ifndef NULLITERATOR_H
#define NULLITERATOR_H

#include <string>
#include "./iterator.h"

using std::string;
class NullIterator : public Iterator {
public:
    NullIterator(Component *);
    bool isDone();
    void next();
    Component* currentItem();
private:
    Component* _component;
};

#endif