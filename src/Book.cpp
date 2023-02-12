//
// Created by Rene on 2023-02-06.
//

#include "Book.h"
void Book::addOrder(int idNumber, bool buyOrSell, int shares, int limit, int eventTime) {
    auto limitEntry = this->limits.find(limit);
    Limit * limitObj = limitEntry->second;
    if(limitEntry == this->limits.end()) {
        limitObj = new Limit(limit);
        this->limits.emplace(limit, limitObj);
    }
    Order * orderObj = new Order(idNumber, buyOrSell, shares, limit, eventTime);
    limitObj->totalVolume += shares;
    limitObj->orders.push_back(orderObj);
}

