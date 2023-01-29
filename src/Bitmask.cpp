#include "Bitmask.hpp"

namespace v0id {

Bitmask::Bitmask()
  : bits(0)
{
}

Bitmask::~Bitmask() {}

void
Bitmask::setMask(Bitmask& other)
{
  bits = other.getMask();
}

uint32_t
Bitmask::getMask() const
{
  return bits;
}

bool
Bitmask::getBit(int pos) const
{
  // Move 1 pos toward right + and w/ bits
  // If bit is also 1 then result of & is 1, so ret. 0. Else do opposite
  return (bits & (1 << pos)) != 0;
}

void
Bitmask::setBit(int pos, bool on)
{
  // Setting to 1: setBit to set to 1
  // Setting to 0: clearBit to set to 0
  on ? setBit(pos) : clearBit(pos);
}

void
Bitmask::setBit(int pos)
{
  // Move 1 pos toward right
  // Or w/ bits. Will always be true, a.k.a. 1
  bits = bits | 1 << pos;
}

void
Bitmask::clearBit(int pos)
{
  // Move 1 pos toward right + invert
  // And w/ bits. Will always be false, a.k.a. 0
  bits = bits & ~(1 << pos);
}

void
Bitmask::clear()
{
  bits = 0;
}

}