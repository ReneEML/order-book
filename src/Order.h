//
// Created by Rene on 2023-02-06.
//

#ifndef ORDER_BOOK_ORDER_H
#define ORDER_BOOK_ORDER_H


#include <map>
#include <corecrt.h>
#include <ctime>



class Order {
public:
    enum OrderType : bool {
        BUY = true,
        SELL = false
    };
    Order(int idNumber, OrderType orderType, int shares, int limit, int eventTime);
    int idNumber;
    OrderType orderType;
    int shares;
    int limit;
    time_t entryTime;
    time_t eventTime;
};


#endif //ORDER_BOOK_ORDER_H
