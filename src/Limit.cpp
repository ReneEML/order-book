//
// Created by Rene on 2023-02-06.
//

#include "Limit.h"

Limit::Limit(int limitPrice) {
    this->limitPrice = limitPrice;
    this->totalVolume = 0;
}

size_t Limit::getSize() const {
    return this->orders.size();
}

std::list<Order*>::iterator Limit::addOrder(Order * order) {
    this->orders.push_back(order);
    return --this->orders.end();
}

Order *Limit::peekFront() {
    return this->orders.front();
}

Order *Limit::popFront() {
    Order * front = this->orders.front();
    this->orders.pop_front();
    return front;
}

void Limit::removeOrder(std::list<Order*>::iterator order) {
    this->orders.erase(order);
}


