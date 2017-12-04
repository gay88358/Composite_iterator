#ifndef UTCOMPOSITE_H
#define UTCOMPOSITE_H

//#include "./include/component.h"
#include "./include/leaf.h"
#include "./include/composite.h"
TEST(Leaf, symbol) {
    Leaf l("leaf");
    ASSERT_EQ("leaf", l.symbol());
}

TEST(Composite, symbol) {
    Leaf l("leaf1");
    Leaf l2("leaf2");
    Leaf l3("leaf3");

    Composite c({ &l, &l2, &l3});
    ASSERT_EQ("[leaf1, leaf2, leaf3]", c.symbol());

    Composite c2({ &c, &l2 });
    ASSERT_EQ("[[leaf1, leaf2, leaf3], leaf2]", c2.symbol());
}


#endif