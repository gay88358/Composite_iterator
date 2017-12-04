#ifndef LEAF_H
#define LEAF_H

#include <string>
#include "./component.h"
using std::string;

class Leaf : public Component {
public:
    Leaf(string symbol);
    string symbol();
    Component* getChild(int i);
    Iterator* createIterator();
private:
    string _symbol;
};

#endif