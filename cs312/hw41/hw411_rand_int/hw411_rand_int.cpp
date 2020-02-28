/******************************************************
hw411_rand_int.cpp
Copyright (c) Carleton College CS312 free open source
Assignment: hw411
Zhihan Yang yangz2@carleton.edu
DATE: 2020-02-02
TIME: 20-25-21
******************************************************/

#include <random>

int get_rand_int(int start, int end) {
    std::random_device rd;
    std::default_random_engine dre{rd()};
    std::uniform_int_distribution<int> dist{start, end};
    return dist(dre);
}