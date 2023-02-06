//
// Created by Rene on 2023-02-06.
//

#ifndef ORDER_BOOK_ORDER_H
#define ORDER_BOOK_ORDER_H


#include <map>
#include "Limit.h"

class Order {
private:
    int idNumber;
    bool buyOrSell;
    int shares;
    int limit;
    int entryTime;
    int eventTime;
    int parentLimit;
};


#endif //ORDER_BOOK_ORDER_H
