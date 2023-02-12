#include <gtest/gtest.h>
#include "../src/Limit.h"

TEST(LimitTest, TestInitialization) {
    Limit testLimit(69);
    assert(testLimit.getSize() == 0);
    assert(testLimit.limitPrice == 69);
    assert(testLimit.totalVolume == 0);
}


TEST(LimitTest, TestSize) {
    Order order(69, true, 69, 69, 69);
    Limit testLimit(69);
    testLimit.addOrder(&order);
    testLimit.addOrder(&order);
    assert(testLimit.getSize() == 2);
}

TEST(LimitTest, TestPeekFront) {
    Order order(69, true, 69, 69, 69);
    Order order2(69, true, 69, 69, 69);
    Limit testLimit(69);
    testLimit.addOrder(&order);
    testLimit.addOrder(&order2);
    Order * front = testLimit.peekFront();
    assert(front == &order);
}

TEST(LimitTest, TestPopFront) {
    Order order(69, true, 69, 69, 69);
    Order order2(69, true, 69, 69, 69);
    Limit testLimit(69);
    testLimit.addOrder(&order);
    testLimit.addOrder(&order2);
    Order * front = testLimit.popFront();
    Order * front2 = testLimit.peekFront();
    assert(front == &order);
    assert(front2 == &order2);
}

TEST(LimitTest, TestRemoveOrder) {
    Order order(69, true, 69, 69, 69);
    Order order2(68, true, 69, 69, 69);
    Order order3(67, true, 69, 69, 69);
    Limit testLimit(69);
    auto it = testLimit.addOrder(&order);
    auto it2 = testLimit.addOrder(&order2);
    auto it3 = testLimit.addOrder(&order3);
    testLimit.removeOrder(it2);
    assert(testLimit.getSize() == 2);
    assert(testLimit.peekFront() == &order);
    testLimit.removeOrder(it);
    assert(testLimit.getSize() == 1);
    assert(testLimit.peekFront() == &order3);
    testLimit.removeOrder(it3);
    assert(testLimit.getSize() == 0);
}