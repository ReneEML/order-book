//
// Created by Rene on 2023-02-06.
//

#ifndef ORDER_BOOK_ORDER_H
#define ORDER_BOOK_ORDER_H


#include <map>
#include <corecrt.h>

class Order {
public:
    Order(int idNumber, bool buyOrSell, int shares, int limit, int eventTime);
    int idNumber;
    bool buyOrSell;
    int shares;
    int limit;
    time_t entryTime;
    time_t eventTime;
    int parentLimit;
};


#endif //ORDER_BOOK_ORDER_H
