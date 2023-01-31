#ifndef ResourceAllocator_hpp
#define ResourceAllocator_hpp

#include <map>
#include <memory>

namespace v0id {

/**
 * @brief Handles the instantiation, allocation, and retrieval of resources
 * @note Resources can be sprites, fonts, or audio clips, etc.
 *
 * @tparam T The type of resource this ResourceAllocator will store
 */
template<typename T>
class ResourceAllocator
{
public:
  /**
   * @brief Load a resource and add it to the ResourceAllocator
   *
   * @param filePath The path of the resource
   * @return The ID of the resource
   */
  int add(const std::string& filePath)
  {
    auto it = resources.find(filePath);
    if (it != resources.end()) {
      return it->second.first;
    }

    std::shared_ptr<T> resource = std::make_shared<T>();
    if (!resource->loadFromFile(filePath)) {
      return -1;
    }

    resources.insert(
      std::make_pair(filePath, std::make_pair(currentId, resource)));

    return currentId++;
  }

  /**
   * @brief Remove a resource from the ResourceAllocator
   *
   * @param id The ID of the resource
   */
  void remove(int id)
  {
    for (auto it = resources.begin(); it != resources.end(); ++it) {
      if (it->second.first == id) {
        resources.erase(it->first);
      }
    }
  }

  /**
   * @brief Retrieve a resource from the ResourceAllocator
   *
   * @param id The ID of the resource
   * @return A shared pointer to the resource if found, else nullptr
   */
  std::shared_ptr<T> get(int id)
  {
    for (auto it = resources.begin(); it != resources.end(); ++it) {
      if (it->second.first == id) {
        return it->second.second;
      }
    }

    return nullptr;
  }

  /**
   * @brief Determine whether the ResourceAllocator contains a resource
   *
   * @param id The ID of the resource
   * @return True if the ResourceAllocator contains the resource with the ID
   */
  bool has(int id) { return (get(id) != nullptr); }

private:
  int currentId;
  std::map<std::string, std::pair<int, std::shared_ptr<T>>> resources;
};

}

#endif /* ResourceAllocator_hpp */