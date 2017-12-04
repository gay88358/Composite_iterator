#include "../include/listIterator.h"

ListIterator::ListIterator(Composite *composite):_composite(composite), _index(0) {

}

bool ListIterator::isDone() {
    return this->_index >= this->_composite->size();
}

void ListIterator::next() {
    this->_index++;
}

Component* ListIterator::currentItem() {
    return this->_composite->getChild(this->_index);
}
