#ifndef ENUM_HASH_HPP
#define ENUM_HASH_HPP

#include <cstddef>

namespace v0id {

struct EnumHash
{
  template<typename T>
  std::size_t operator()(T t) const
  {
    return static_cast<std::size_t>(t);
  }
};

}

#endif