#ifndef RESOURCE_PATH_HPP
#define RESOURCE_PATH_HPP

#include <string>

namespace v0id {

#ifdef MACOS

#ifdef __cplusplus
extern "C"
{
#endif

#include "CoreFoundation/CoreFoundation.h"

#ifdef __cplusplus
}
#endif

#endif

/**
 * @brief Stores the location of the Resources directory
 *
 */
class ResourcePath
{
public:
  /**
   * @brief Construct a new Resource Path object
   *
   */
  ResourcePath();

  /**
   * @brief Construct a new Resource Path object
   *
   * @param path The path of the resources directory
   */
  ResourcePath(std::string path);

  ~ResourcePath();

  /**
   * @brief Get the relative path of the Resources directory
   *
   * @return The path
   */
  inline const std::string& get() { return path; }

private:
  std::string path;
};
}

#endif