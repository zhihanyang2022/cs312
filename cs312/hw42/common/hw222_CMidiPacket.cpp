// hw222_CMidiPacket.cpp

#ifndef HW222_CMIDIPACKET_H_
#include "hw222_CMidiPacket.h"
#endif

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace CMP22;

// the C++ method of initializing constructors is to use a colon
// after the function declaration followed by a comma separated list
// of class data members using curly brace initialization
// the body of the constructor is often empty

// DO NOT CHANGE
// Default constructor
// Initializes a "do nothing" NOF message
CMidiPacket::CMidiPacket()
    : timestamp_{0}, status_{0x80}, data1_{0}, data2_{0}, length_{3}
{
  // empty body
}

// Default destructor
// Note placement of ~
// no need to do anything because there was no memory allocation in class
// Alternatively you could use ~CMidiPacket() = default in the header file
// and let the compiler implement the destructor.
CMidiPacket::~CMidiPacket()
{
  // empty body
}
// END DO NOT CHANGE

// ******************************************************
// FROM HERE TO END YOU HAVE TO IMPLEMENT THESE FUNCTIONS
// ******************************************************

// Constructor overload for one data byte message
// use colon initialization with parameters inside curly braces
CMidiPacket::CMidiPacket(uint32_t ts, uint8_t st, uint8_t d1)
    : timestamp_{ts}, status_{st}, data1_{d1}, length_{2}
{
}

// Constructor overload for two data bytes message
// use colon initialization with parameters inside curly braces
CMidiPacket::CMidiPacket(uint32_t ts, uint8_t st, uint8_t d1, uint8_t d2)
    : timestamp_{ts}, status_{st}, data1_{d1}, data2_{d2}, length_{3}
{
}

bool is_invalid(uint8_t status_)
{
  int bitmask = 0xF0;
  int result = bitmask & status_;
  if (result == bitmask)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool has_length_2(uint8_t status_)
{
  uint8_t bitmask = 0xF0;
  uint8_t result = bitmask & status_;
  if (result == 0xC0 || result == 0xD0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

// Constructor overload for string parameter
// Initialize the CMidiPacket data from a string parameter.
// The string is valid MIDIDisplay format.
// Remember status_ is hex without 0x prefix in the string.
// You'll need to find a parsing routine that will
// separate the string into tokens separated by whitespace
// any number of spaces or tabs
// assign the tokens to the data members
// ignore any status_ 0xFn
// remember status_ 0xCn and 0xDn are length_ 2 and do not use data2_
// all other status_ are length_ 3 and use both data1_ and data2_
// assign the length_ once you know the status_
CMidiPacket::CMidiPacket(const std::string &str)
{
  std::istringstream iss(str);
  
  std::string subs;
  std::vector<std::string> str_args;
  
  while (iss >> subs && !subs.empty()) {
    str_args.push_back(subs);
  }
  
  status_ = std::stoul(str_args[1], NULL, 16);
  if (is_invalid(status_))
  {
    length_ = 0;
  }
  else
  {
    timestamp_ = std::stoul(str_args[0]);
    data1_ = std::stoul(str_args[2]);
    
    if (has_length_2(status_))
    {
      length_ = 2;
    }
    else
    {
      data2_ = std::stoul(str_args[3]);
      length_ = 3;
    }
  }
}

// Convert the CMidiPacket data to a string.
// Separate numbers with a single tab char.
// Account for 1 data byte or 2 data byte messages.
// <timestamp_>TAB<status_(hex)>TAB<data1_>
// <timestamp_>TAB<status_-hex>TAB<data1_>TAB<data2_>
// Status is hex number without 0x prefix.
// Length should be set at the same time as status_.
// Length will never be displayed in a MIDIDisplay message.
// timestamp_, data1_, and data2_ (if used) are decimal numbers.
// send a not processed message if status_ is 0xFn
std::string CMidiPacket::to_string() const
{
  std::ostringstream oss;

  if (is_invalid(status_)) {
    oss << "# 0xFn status_ not processed";
  } 
  else
  {
    oss << std::dec << static_cast<int>(timestamp_) << "\t";
    oss << std::hex << static_cast<int>(status_) << "\t";
    oss << std::dec << static_cast<int>(data1_) << "\t";

    if (length_ == 3)
    {
      oss << std::dec << static_cast<int>(data2_);
    }
  }
  return oss.str();
}

// Do not change print()
// Send a MIDIDisplay string to std::cout using toString()
void CMidiPacket::print() const
{
  std::cout << to_string() << std::endl;
}
