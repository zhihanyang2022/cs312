/******************************************************
hw322_CMP32friends.cpp
Copyright (c) Carleton College CS312 free open source
Assignment: hw322
Zhihan Yang yangz2@carleton.edu
DATE: 2020-01-28
TIME: 15-22-01
******************************************************/

#ifndef hw322_CMIDIPACKET_H_
#include "hw322_CMidiPacket.h"
#endif

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace CMP32;

std::vector<CMidiPacket> v_ordered;

void create_ordered_vector()
{
    // arranged in chronological order by timestamps
    CMidiPacket mp;
    v_ordered.push_back(mp = {100, 0xE0, 10, 64});
    v_ordered.push_back(mp = {100, 0xD0, 60, 100});
    v_ordered.push_back(mp = {100, 0xB0, 10, 127});
    v_ordered.push_back(mp = {100, 0xA0, 11, 100});
    v_ordered.push_back(mp = {100, 0x90, 60, 100});
    v_ordered.push_back(mp = {100, 0x80, 0, 0}); // no harm NOF
    v_ordered.push_back(mp = {100, 0xC0, 14});   // Tubular Bells
    v_ordered.push_back(mp = {1100, 0xD0, 60});
    v_ordered.push_back(mp = {1100, 0xE0, 10, 64});
    v_ordered.push_back(mp = {1100, 0xB0, 10, 127});
    v_ordered.push_back(mp = {1100, 0xA0, 11, 100});
    v_ordered.push_back(mp = {1100, 0x90, 64, 100}); // new NON
    v_ordered.push_back(mp = {1100, 0x80, 60, 0});   // old NOF
    v_ordered.push_back(mp = {1100, 0xC0, 19});      // Organ
    v_ordered.push_back(mp = {2100, 0xE0, 10, 64});
    v_ordered.push_back(mp = {2100, 0xD0, 60});
    v_ordered.push_back(mp = {2100, 0xB0, 10, 127});
    v_ordered.push_back(mp = {2100, 0xA0, 11, 100});
    v_ordered.push_back(mp = {2100, 0x90, 67, 100}); // new NON
    v_ordered.push_back(mp = {2100, 0x80, 64, 0});   // old NOF
    v_ordered.push_back(mp = {2100, 0xC0, 91});      // Choir}
    v_ordered.push_back(mp = {4100, 0xE0, 10, 64});
    v_ordered.push_back(mp = {4100, 0xD0, 60});
    v_ordered.push_back(mp = {4100, 0xB0, 10, 127});
    v_ordered.push_back(mp = {4100, 0xA0, 11, 100});
    v_ordered.push_back(mp = {4100, 0x90, 72, 100}); // new NON
    v_ordered.push_back(mp = {4100, 0x80, 67, 0});   // old NOF
    v_ordered.push_back(mp = {4100, 0xC0, 124});     // Telephone
    v_ordered.push_back(mp = {5100, 0x80, 72, 0});   // old NOF
}

std::vector<CMidiPacket> mixup_packets(const std::vector<CMidiPacket> &vec)
{
    std::vector<CMidiPacket> v;
    // push back randomly to shuffle timestamps
    // while testing the sort() algorithms
    v.push_back(vec.at(1));
    v.push_back(vec.at(12));
    v.push_back(vec.at(2));
    v.push_back(vec.at(8));
    v.push_back(vec.at(3));
    v.push_back(vec.at(11));
    v.push_back(vec.at(9));
    v.push_back(vec.at(4));
    v.push_back(vec.at(10));
    v.push_back(vec.at(6));
    v.push_back(vec.at(27));
    v.push_back(vec.at(7));
    v.push_back(vec.at(5));
    v.push_back(vec.at(21));
    v.push_back(vec.at(17));
    v.push_back(vec.at(14));
    v.push_back(vec.at(26));
    v.push_back(vec.at(15));
    v.push_back(vec.at(20));
    v.push_back(vec.at(25));
    v.push_back(vec.at(18));
    v.push_back(vec.at(19));
    v.push_back(vec.at(16));
    v.push_back(vec.at(28));
    v.push_back(vec.at(24));
    v.push_back(vec.at(0));
    v.push_back(vec.at(13));
    v.push_back(vec.at(22));
    v.push_back(vec.at(23));
    return v;
}

void print_ts_order()
{
    for (auto itr : v_ordered)
        std::cout << itr;
    std::cout << "\n";
}

int main(int argc, char const *argv[])
{
    create_ordered_vector();
    std::cout << "# v_ordered\n";
    print_ts_order();

    std::cout << "# mixedup_order followed by sort\n";
    std::vector<CMidiPacket> v_mixed = mixup_packets(v_ordered);
    sort(v_mixed.begin(), v_mixed.end());
    for (auto itr : v_mixed)
        std::cout << itr;
    std::cout << "\n";
}
