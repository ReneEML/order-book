//
// Created by Rene on 2023-02-06.
//

#ifndef ORDER_BOOK_BOOK_H
#define ORDER_BOOK_BOOK_H


#include <map>
#include <unordered_map>
#include "Limit.h"



class Book {
public:
    void addOrder(int id_number, Order::OrderType orderType, int shares, int limit, int eventTime);
    std::map<int, Limit*> buyTree;
    std::map<int, Limit*> sellTree;
    std::map<int, Limit*>::iterator lowestSell;
    std::map<int, Limit*>::iterator highestBuy;

    std::unordered_map<int, std::list<Order*>::iterator> orders;
    std::unordered_map<int, std::map<int, Limit*>::iterator> limits;

    Limit *getLimit(int limit);
    Limit *createLimit(int limit, Order::OrderType orderType);
};


#endif //ORDER_BOOK_BOOK_H
