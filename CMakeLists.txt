cmake_minimum_required(VERSION 3.24)
project(order_book)

set(CMAKE_CXX_STANDARD 17)

add_executable(order_book main.cpp Book.cpp Book.h Limit.cpp Limit.h Order.cpp Order.h)
