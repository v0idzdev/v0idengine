cmake_minimum_required(VERSION 3.9)
project(v0idengine
  VERSION 0.1.0
  DESCRIPTION "A minimal 2D game engine"
  LANGUAGES CXX
  )
include(GNUInstallDirs)
add_library(v0idengine
  SHARED
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
  "include/v0idengine/v0idengine.hpp"
  "include/v0idengine/Core.hpp"
  "include/v0idengine/Core/Input.hpp"
  "include/v0idengine/Core/ResourcePath.hpp"
  "include/v0idengine/Core/Window.hpp"
  "include/v0idengine/ECS.hpp"
  "include/v0idengine/ECS/Component.hpp"
  "include/v0idengine/ECS/KeyboardMovement.hpp"
  "include/v0idengine/ECS/Object.hpp"
  "include/v0idengine/ECS/Sprite.hpp"
  "include/v0idengine/ECS/Transform.hpp"
  "include/v0idengine/Scenes.hpp"
  "include/v0idengine/Scenes/Scene.hpp"
  "include/v0idengine/Scenes/SceneStateMachine.hpp"
  )
set(PRIVATE_HEADERS
  "include/Bitmask.hpp"
  "include/EnumHash.hpp"
  )
set_target_properties(v0idengine PROPERTIES
  VERSION ${PROJECT_VERSION}
  SOVERSION 1
  PUBLIC_HEADER "${PUBLIC_HEADERS}"
  PRIVATE_HEADER "${PRIVATE_HEADERS}"
  )
configure_file(v0idengine.pc.in v0idengine.pc @ONLY)
target_include_directories(v0idengine
  PRIVATE
    "src"
    "include"
  PUBLIC
    "include/v0idengine"
    "include/v0idengine/Core"
    "include/v0idengine/ECS"
    "include/v0idengine/Scenes"
  )

# Set C++17
if(MSVC)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
else()
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
endif()

# Install v0idengine
install(
  TARGETS v0idengine
  LIBRARY
    DESTINATION ${CMAKE_INSTALL_LIBDIR}
  PUBLIC_HEADER
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/v0idengine
  PRIVATE_HEADER
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  )
install(
  FILES ${CMAKE_BINARY_DIR}/v0idengine.pc
  DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig
  )