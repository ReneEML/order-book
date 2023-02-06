//
// Created by Rene on 2023-02-06.
//

#ifndef ORDER_BOOK_BOOK_H
#define ORDER_BOOK_BOOK_H


#include <map>
#include <unordered_map>
#include "Limit.h"

class Book {

private:
    std::map<int, Limit> buyTree;
    std::map<int, Limit> sellTree;
    std::map<int, Limit>::iterator lowestSell;
    std::map<int, Limit>::iterator highestBuy;

    std::unordered_map<int, Order> orders;
    std::unordered_map<int, Limit> limits;
};


#endif //ORDER_BOOK_BOOK_H
