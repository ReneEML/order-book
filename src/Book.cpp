//
// Created by Rene on 2023-02-06.
//

#include <iostream>
#include "Book.h"

bool Book::cancelOrder(int idNumber) {
    auto got_order = orders.find(idNumber);
    if(got_order == orders.end()) return false;

    auto order_it = got_order->second;
    Order * order = *order_it;
    auto limit_it = limits.find(order->limit)->second;
    Limit * limit = limit_it->second;

    if(limit->getSize() == 1) {
        removeFromTree(limit_it, order->orderType);
        delete limit;
    }
    else {
        limit->orders.erase(order_it);
    }
    delete order;
    return true;
}

void Book::removeFromTree(std::map<int, Limit*>::iterator it, Order::OrderType orderType) {
    switch (orderType) {
        case Order::BUY:
            removeFromBuyTree(it);
            break;
        case Order::SELL:
            removeFromSellTree(it);
        default:
            break;
    }
}

void Book::removeFromBuyTree(std::map<int, Limit*>::iterator it) {
    if(buyTree.size() > 1 && it == highestBuy) {
        buyTree.erase(highestBuy --);
    }
    else {
        buyTree.erase(it);
    }
    if(buyTree.empty()) {
        highestBuy = buyTree.end();
    }
}

void Book::removeFromSellTree(std::map<int, Limit*>::iterator it) {
    if(sellTree.size() > 1 && it == lowestSell) {
        sellTree.erase(lowestSell ++);
    }
    else {
        sellTree.erase(it);
    }
    if(sellTree.empty()) {
        highestBuy = buyTree.end();
    }
}

void Book::addOrder(int idNumber, Order::OrderType orderType, int shares, int limit, int eventTime) {
    Limit * limitObj = getLimit(limit);
    if(!limitObj) {
        limitObj = new Limit(limit);
        if(orderType == Order::BUY) {
            createBuyLimit(limit, limitObj);
        }
        else {
            createSellLimit(limit, limitObj);
        }
    }
    auto orderObj = new Order(idNumber, orderType, shares, limit, eventTime);
    limitObj->totalVolume += shares;
    auto it = limitObj->addOrder(orderObj);
    orders.emplace(idNumber, it);
}

Limit * Book::getLimit(int limit) {
    auto limitEntry = limits.find(limit);
    return limitEntry == limits.end() ? nullptr : (limitEntry->second)->second;
}

void Book::createBuyLimit(int limit, Limit * limitObj) {
    auto it = this->buyTree.emplace(limit, limitObj).first;
    if(highestBuy == buyTree.end() || limit > highestBuy->second->limitPrice) {
        highestBuy = it;
    }
    limits.emplace(limit, it);
}

void Book::createSellLimit(int limit, Limit * limitObj) {
    auto it = this->sellTree.emplace(limit, limitObj).first;
    if(lowestSell == sellTree.end() || limit < lowestSell->second->limitPrice) {
        lowestSell = it;
    }
    limits.emplace(limit, it);
}