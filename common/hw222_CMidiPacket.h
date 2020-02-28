// hw221_CMidiPacket.h

#ifndef HW221_CMIDIPACKET_H_
#define HW221_CMIDIPACKET_H_

#include <iostream>
#include <string>

namespace CMP22
{
class CMidiPacket
{
private: // not really needed because they're private by default
  // MidiPacket2 data
  uint32_t timestamp_;
  uint8_t status_;
  uint8_t data1_;
  uint8_t data2_;
  uint8_t length_;

public:
  // from class snippet
  CMidiPacket();                                         // constructor
  ~CMidiPacket();                                        // destructor
  CMidiPacket(const CMidiPacket &) = default;            // copy constructor
  CMidiPacket(CMidiPacket &&) = default;                 // move constructor
  CMidiPacket &operator=(const CMidiPacket &) = default; // assignment
  CMidiPacket &operator=(CMidiPacket &&) = default;      // move assignment

  // three overlaoded constructors
  // construct a CMidiPacket for a one data byte message
  CMidiPacket(uint32_t ts, uint8_t st, uint8_t d1);

  // construct a CMidiPacket for a two data byte message
  CMidiPacket(uint32_t ts, uint8_t st, uint8_t d1, uint8_t d2);

  // construct a CMidiPacket from a valid MIDIDisplay string
  CMidiPacket(const std::string &str);

  // return a string from this CMidiPacket data
  std::string to_string() const;

  // print this CMidiPacket data to std::cout
  // in MIDIDisplay format accounting for message lengths of 2 or 3
  void print() const;

  // getters
  uint32_t get_timestamp() const {
    return timestamp_;
  }
  uint8_t get_status() const {
    return status_;
  }
  uint8_t get_data1() const {
    return data1_;
  }
  uint8_t get_data2() const {
    return data2_;
  }
  uint8_t get_length() const {
    return length_;
  }
  uint8_t get_midi_channel() const {
    uint8_t bitmask = 0x0F;
    return bitmask & status_;
  }

  // setters
  void set_timestamp(const uint32_t &ts) {
    timestamp_ = ts;
  }

  void set_status(const uint8_t &st) {
    status_ = st;
  }
  
  void set_status_length(){
    int bitmask = 0xF0;
    int result = bitmask & status_;
    if (result == 0xC0 || result == 0xD0)
    {
      length_ = 2;
    }
    else
    {
      length_ = 3;
    }
  }

  void set_data1(const uint8_t &d1)
  {
    data1_ = d1;
  }

  void set_data2(const uint8_t &d2)
  {
    data2_ = d2;
  }

  void set_midi_channel(const uint8_t &chan)
  {
    data2_ = get_status_not_channel() + chan;
  }

  uint8_t get_status_not_channel() const {
    uint8_t result = 0xF0 & status_;
    return result; 
  }

  // Utility functions
  bool is_status_8n() const {
    return get_status_not_channel() == 0x80;
  }
  bool is_status_9n() const {
    return get_status_not_channel() == 0x90;
  }
  bool is_status_An() const {
    return get_status_not_channel() == 0xA0;
  }
  bool is_status_Bn() const {
    return get_status_not_channel() == 0xB0;
  }
  bool is_status_Cn() const {
    return get_status_not_channel() == 0xC0;
  }
  bool is_status_Dn() const {
    return get_status_not_channel() == 0xD0;
  }
  bool is_status_En() const {
    return get_status_not_channel() == 0xE0;
  }
  bool is_status_Fn() const {
    std::cout << "# 0xFn status_ not processed" << std::endl;
    return get_status_not_channel() == 0xF0;
  }
  bool is_note_off() const {
    return is_status_8n() || (data2_ == 0);
  }
  bool is_note_on() const {
    return is_status_9n() && (data2_ > 0);
  }
};
} // namespace CMP22
#endif // HW221_CMIDIPACKET_H