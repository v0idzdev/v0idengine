#ifndef RESOURCEPATH_HPP
#define RESOURCEPATH_HPP

#include <string>

namespace v0id {

#ifdef MACOS
#include "CoreFoundation/CoreFoundation.h"
#endif

class ResourcePath
{
public:
  ResourcePath();
  ~ResourcePath();

  inline const std::string& get() { return path; }

private:
  std::string path;
};

}

#endif