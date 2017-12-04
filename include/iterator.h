#ifndef ITERATOR_H
#define ITERATOR_H


class Component;
class Iterator {
public:
    virtual bool isDone() = 0;
    virtual void next() = 0;
    virtual Component* currentItem() = 0;
private:
};

#endif