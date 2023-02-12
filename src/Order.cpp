//
// Created by Rene on 2023-02-06.
//

#include <ctime>
#include "Order.h"

Order::Order(int idNumber, bool buyOrSell, int shares, int limit, int eventTime) {
    idNumber = idNumber;
    buyOrSell = buyOrSell;
    shares = shares;
    limit = limit;
    eventTime = eventTime;
    entryTime = std::time(0);
}
