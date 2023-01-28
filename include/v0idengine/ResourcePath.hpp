#ifndef RESOURCE_PATH_HPP
#define RESOURCE_PATH_HPP

#include <string>

namespace v0id {

#ifdef MACOS
#include "CoreFoundation/CoreFoundation.h"
#endif

/// @brief Stores the location of the Resources directory
class ResourcePath
{
public:
  /// @brief Create a new ResourcePath
  ResourcePath();
  ~ResourcePath();

  /// @brief Get the relative path of the Resources directory
  /// @return The path
  inline const std::string& get() { return path; }

private:
  std::string path;
};

}

#endif