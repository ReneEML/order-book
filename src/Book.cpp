//
// Created by Rene on 2023-02-06.
//

#include <iostream>
#include "Book.h"
void Book::addOrder(int idNumber, Order::OrderType orderType, int shares, int limit, int eventTime) {
    Limit * limitObj = getLimit(limit);
    if(!limitObj) {
        limitObj = createLimit(limit, orderType);
    }
    Order * orderObj = new Order(idNumber, orderType, shares, limit, eventTime);
    limitObj->totalVolume += shares;
    auto it = limitObj->addOrder(orderObj);
    orders.emplace(idNumber, it);
}

Limit * Book::getLimit(int limit) {
    auto limitEntry = limits.find(limit);
    return limitEntry == limits.end() ? nullptr : (limitEntry->second)->second;
}

Limit * Book::createLimit(int limit, Order::OrderType orderType) {
    Limit * result = new Limit(limit);
    if(orderType == Order::BUY) {
        auto pr = this->buyTree.emplace(limit, result);
        limits.emplace(limit, pr.first);
    }
    else {
        auto pr = this->sellTree.emplace(limit, result);
        limits.emplace(limit, pr.first);

    }
    return result;
}