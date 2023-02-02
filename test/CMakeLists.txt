cmake_minimum_required(VERSION 3.9)
project(v0idengine-example
  DESCRIPTION "A game used to test v0idengine"  
  LANGUAGES CXX
  )
include(GNUInstallDirs)
add_executable(v0idengine-example
  Main.cpp
  src/CarMovement.cpp
  src/Game.cpp
  src/SceneLevel.cpp
  src/SceneSplashScreen.cpp
  )
target_include_directories(v0idengine-example
  PRIVATE 
    "src"  
    "include"
  PUBLIC
    "${CMAKE_INSTALL_LIBDIR}/v0idengine"
  )
set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} ${CMAKE_INSTALL_LIBDIR})
target_link_libraries(v0idengine-example
  v0idengine
  sfml-graphics
  sfml-window
  sfml-system
  )