#ifndef BITMASK_HPP
#define BITMASK_HPP

#include <stdint.h>

namespace v0id {

class Bitmask
{
public:
  Bitmask();
  ~Bitmask();

  void setMask(Bitmask& other);
  uint32_t getMask() const;

  bool getBit(int pos) const;
  void setBit(int pos, bool on);
  void setBit(int pos);
  void clearBit(int pos);
  void clear();

private:
  uint32_t bits;
};

}

#endif