//
// Created by Rene on 2023-02-06.
//

#ifndef ORDER_BOOK_LIMIT_H
#define ORDER_BOOK_LIMIT_H


#include <list>
#include "Order.h"

class Limit {
    int limitPrice;
    int size;
    int totalVolume;
    std::list<Order> orders;
};


#endif //ORDER_BOOK_LIMIT_H
