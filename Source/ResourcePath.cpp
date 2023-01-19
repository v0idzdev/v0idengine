#include "ResourcePath.hpp"

ResourcePath::ResourcePath()
{
  path = "./Resources/";

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

ResourcePath::~ResourcePath() {}