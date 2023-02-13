#include <gtest/gtest.h>
#include "../src/Book.h"

TEST(TestBook, TestAddOrder) {
    Book book;
    int idNumber = 42069;
    Order::OrderType orderType = Order::BUY;
    int shares = 69420;
    int limit = 420;
    int eventTime = 1234567;
    for(int i = 0; i < 5; i ++) {
        book.addOrder(++idNumber, orderType, shares, limit, eventTime);
        assert(book.buyTree.size() == 1);
        assert(book.buyTree.find(420)->second->getSize() == i + 1);
    }
    for(int i = 1; i < 6; i ++) {
        book.addOrder(++idNumber, orderType, shares, ++limit, eventTime);
        assert(book.buyTree.size() == i + 1);
        assert(book.buyTree.find(420)->second->getSize() == 5);
    }
    assert(book.orders.size() == 10);
}

TEST(TestBook, TestCancelOrder) {
    Book book;
    book.addOrder(1, Order::BUY, 69, 42, 1234);
    book.addOrder(2, Order::BUY, 69, 69, 1234);
    book.addOrder(3, Order::BUY, 69, 7, 1234);
    book.cancelOrder(2);
    assert(book.buyTree.size() == 2);
    assert(book.highestBuy->second->limitPrice == 42);
    book.cancelOrder(3);
    assert(book.buyTree.size() == 1);
    assert(book.highestBuy->second->limitPrice == 42);
    book.cancelOrder(1);
    assert(book.buyTree.size() == 0);
    assert(book.highestBuy == book.buyTree.end());
    assert(book.cancelOrder(69) == false);
}

