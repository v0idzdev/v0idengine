#ifndef BITMASK_HPP
#define BITMASK_HPP

#include <stdint.h>

namespace v0id {

/**
 * @brief Used to store and operate on an array of bits
 *
 */
class Bitmask
{
public:
  /**
   * @brief Construct a new Bitmask object
   *
   */
  Bitmask();
  ~Bitmask();

  /**
   * @brief Change the bits stored by the Bitmask to those of another
   *
   * @param other The other Bitmask
   */
  void setMask(Bitmask& other);

  /**
   * @brief Get the bits stored by the Bitmask
   *
   * @return The bits
   */
  uint32_t getMask() const;

  /**
   * @brief Get a single bit at the specified position
   *
   * @param pos The position
   * @return The value of the bit
   */
  bool getBit(int pos) const;

  /**
   * @brief Set a single bit at the specified position
   *
   * @param pos The position
   * @param on The value to assign to the bit
   */
  void setBit(int pos, bool on);

  /**
   * @brief Set a single bit at the specified position to 1
   *
   * @param pos The position
   */
  void setBit(int pos);

  /**
   * @brief Set a single bit at the specified position to 0
   *
   * @param pos The position
   */
  void clearBit(int pos);

  /**
   * @brief Set every bit to 0
   *
   */
  void clear();

private:
  uint32_t bits;
};

}

#endif