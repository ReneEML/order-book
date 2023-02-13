//
// Created by Rene on 2023-02-06.
//

#include "Order.h"

Order::Order(int idNumber, OrderType orderType, int shares, int limit, int eventTime) {
    this->idNumber = idNumber;
    this->orderType = orderType;
    this->shares = shares;
    this->limit = limit;
    this->eventTime = eventTime;
    this->entryTime = std::time(nullptr);
}
