#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
using std::string;
class Iterator;

class Component {
public:
    virtual string symbol() = 0;
    virtual Component* getChild(int i) = 0;
    virtual Iterator* createIterator() = 0;
};

#endif