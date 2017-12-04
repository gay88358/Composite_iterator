#include "../include/composite.h"
#include "../include/listIterator.h"
#include "../include/compositeIterator.h"
Composite::Composite(vector<Component*> args): _args(args) {

}

int Composite::size() const {
    return this->_args.size();
}

Iterator* Composite::createIterator() {
    return new CompositeIterator(new ListIterator(this));
}

string Composite::symbol() {
    string symbol = "[";
    for (int i = 0; i < this->_args.size() - 1; i++) {
        symbol += this->_args[i]->symbol() + ", ";
    }
    symbol += this->_args[this->_args.size() - 1]->symbol() + "]";
    return symbol;
}

Component* Composite::getChild(int i) {
    return this->_args[i];
}
