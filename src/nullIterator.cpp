#include "../include/nullIterator.h"

NullIterator::NullIterator(Component *component):_component(component) {

}

bool NullIterator::isDone() {
    return true;
}

void NullIterator::next() {
    throw string("nulliterator can not use next operation");
}

Component* NullIterator::currentItem() {
    return this->_component;
}
