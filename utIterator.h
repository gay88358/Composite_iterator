#ifndef UTITERATOR_H
#define UTITERATOR_H

#include "./include/nullIterator.h"
#include "./include/listIterator.h"
#include "./include/compositeIterator.h"
#include "./include/leaf.h"
#include "./include/composite.h"
#include <iostream>

using std::cout;
using std::endl;

TEST(NullIterator, next) {
    Leaf l("222");
    Iterator* it = l.createIterator();
    ASSERT_TRUE(it->isDone());
    ASSERT_EQ("222", it->currentItem()->symbol());
}

TEST(ListIterator, next) {
    Leaf l1("tom");
    Leaf l2("jem");
    Composite c({ &l1, &l2 });
    Iterator* it = c.createIterator();
    ASSERT_FALSE(it->isDone());
    ASSERT_EQ("tom", it->currentItem()->symbol());
    it->next();
    ASSERT_FALSE(it->isDone());
    ASSERT_EQ("jem", it->currentItem()->symbol());
    it->next();
    ASSERT_TRUE(it->isDone());
}

TEST(CompositeIterator, complex_iterator) {
    // [paul, [tom, jem], [jem, michael]]
    Leaf l1("tom");
    Leaf l2("jem");
    Leaf l3("michael");
    Leaf l4("paul");
    Composite c({ &l1, &l2 });
    Composite c1({ &l2, &l3 });
    Composite c2({ &l4, &c , &c1});
   // CompositeIterator it(c2.createIterator());
    Iterator *it = c2.createIterator();
    ASSERT_FALSE(it->isDone());
    ASSERT_EQ("paul", it->currentItem()->symbol());
    it->next();

    ASSERT_FALSE(it->isDone());
    ASSERT_EQ("[tom, jem]", it->currentItem()->symbol());
    it->next();
    
    ASSERT_FALSE(it->isDone());
    ASSERT_EQ("tom", it->currentItem()->symbol());
    it->next();

    ASSERT_FALSE(it->isDone());
    ASSERT_EQ("jem", it->currentItem()->symbol());
    it->next();

    ASSERT_FALSE(it->isDone());
    ASSERT_EQ("[jem, michael]", it->currentItem()->symbol());
    it->next();
    
    ASSERT_FALSE(it->isDone());
    ASSERT_EQ("jem", it->currentItem()->symbol());
    it->next();

    ASSERT_FALSE(it->isDone());
    ASSERT_EQ("michael", it->currentItem()->symbol());
    it->next();


    ASSERT_TRUE(it->isDone());
    
    
}
#endif