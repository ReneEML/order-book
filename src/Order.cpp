//
// Created by Rene on 2023-02-06.
//

#include "Order.h"

Order::Order(int idNumber, OrderType orderType, int shares, int limit, int eventTime) {
    idNumber = idNumber;
    orderType = orderType;
    shares = shares;
    limit = limit;
    eventTime = eventTime;
    entryTime = std::time(0);
}
