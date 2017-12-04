#include "../include/compositeIterator.h"
#include "../include/composite.h"
#include <iostream>
using std::cout;
using std::endl;
CompositeIterator::CompositeIterator(Iterator *it) {
    this->_stack.push(it);
}

bool CompositeIterator::isDone() {
    if (this->_stack.empty())
        return true;
    Iterator *it = this->_stack.top();
    if (it->isDone()) {
        this->_stack.pop();
        return this->isDone();
    } else {
        return false;
    }
}

void CompositeIterator::next() {
    if (!this->isDone()) {
        Iterator *it = this->_stack.top();
        Composite * p = dynamic_cast<Composite*>(it->currentItem());
        if (p) {
            this->_stack.push(p->createIterator());
        }
        it->next();
    } 
}

Component* CompositeIterator::currentItem() {
    return this->_stack.top()->currentItem();
}