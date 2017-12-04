#include "../include/leaf.h"
#include "../include/nullIterator.h"

Leaf::Leaf(string symbol):_symbol(symbol) {

}

string Leaf::symbol() {
    return this->_symbol;
}

Component* Leaf::getChild(int i) {
    return NULL;
}

Iterator* Leaf::createIterator() {
    return new NullIterator(this);
}
