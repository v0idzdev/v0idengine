cmake_minimum_required(VERSION 3.9)
project(v0idengine
  VERSION 0.1.0
  DESCRIPTION "A minimal 2D game engine"
  LANGUAGE CXX
  )
include(GNUInstallDirs)
add_library(v0idengine SHARED
  src/Bitmask.cpp
  src/Input.cpp
  src/KeyboardMovement.cpp
  src/Object.cpp
  src/ResourcePath.cpp
  src/SceneStateMachine.cpp
  src/Sprite.cpp
  src/Transform.cpp
  src/Window.cpp
  )
set(PUBLIC_HEADERS
  "include/v0idengine/Input.hpp"
  "include/v0idengine/ResourcePath.hpp"
  "include/v0idengine/SceneManagement.hpp"
  "include/v0idengine/Window.hpp"
  "include/v0idengine/ECS.hpp"
  "include/v0idengine/ECS/Component.hpp"
  "include/v0idengine/ECS/KeyboardMovement.hpp"
  "include/v0idengine/ECS/Object.hpp"
  "include/v0idengine/ECS/Sprite.hpp"
  "include/v0idengine/ECS/Transform.hpp"
  "include/v0idengine/SceneManagement.hpp"
  "include/v0idengine/SceneManagement/Scene.hpp"
  "include/v0idengine/SceneManagement/SceneStateMachine.hpp"
  )
set_target_properties(v0idengine PROPERTIES
  VERSION ${PROJECT_VERSION}
  SOVERSION 1
  PUBLIC_HEADER ${PUBLIC_HEADERS}
  )
configure_file(v0idengine.pc.in v0idengine.pc @ONLY)
target_include_directories(v0idengine
  PRIVATE
    src
  PUBLIC
    include/v0idengine
    include/v0idengine/ECS
    include/v0idengine/SceneManagement
  )
if(MSVC) # Microsoft Visual C++ - Windows
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
else() # GCC, Clang - Linux
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
endif()
install(
  TARGETS v0idengine
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  )
install(
  FILES ${CMAKE_BINARY_DIR}/v0idengine.pc
  DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig
  )