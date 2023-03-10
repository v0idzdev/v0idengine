#include "ResourcePath.hpp"

namespace v0id {

ResourcePath::ResourcePath()
{
  path = "./resources/";

#ifdef MACOS
  CFBundleRef mainBundle = CFBundleGetMainBundle();
  CFURLRef resourcesURL = CFBundleCopyResourcesDirectoryURL(mainBundle);
  char path[PATH_MAX];

  if (CFURLGetFileSystemRepresentation(
        resourcesURL, TRUE, (UInt8*)path, PATH_MAX)) {
    CFRelease(resourcesURL);
    chdir(path);
  }

  // TODO: Test on MacOS. Attempt to mirror Windows or Linux usage
#endif
}

ResourcePath::ResourcePath(std::string path)
  : ResourcePath()
{
  this->path = path;
}

ResourcePath::~ResourcePath() {}
}