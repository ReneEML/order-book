//
// Created by Rene on 2023-02-06.
//

#ifndef ORDER_BOOK_LIMIT_H
#define ORDER_BOOK_LIMIT_H


#include <list>
#include "Order.h"

class Limit {
public:

    Limit(int limitPrice);

    int getSize();

    int limitPrice;
    int totalVolume;
    std::list<Order *> orders;

    std::list<Order*>::iterator addOrder(Order * order);
    Order * peekFront();
    Order * popFront();
    void removeOrder(std::list<Order*>::iterator);
};


#endif //ORDER_BOOK_LIMIT_H
