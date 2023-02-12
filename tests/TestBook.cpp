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