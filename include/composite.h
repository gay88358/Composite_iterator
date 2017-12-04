#ifndef COMPOSITE_H
#define COMPOSITE_H

#include <string>
#include <vector>
#include "./component.h"
using std::string;
using std::vector;
class Composite : public Component {
public:
    Composite(vector<Component*>);
    string symbol();
    Component* getChild(int i);
    int size() const;
    Iterator* createIterator();

protected:
    vector<Component*> _args;
};

#endif