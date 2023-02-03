cmake_minimum_required(VERSION 3.25)
project(test
  VERSION 0.1.0
  DESCRIPTION "A game used to test v0idengine"  
  LANGUAGES CXX
  )
include(GNUInstallDirs)
add_executable(${PROJECT_NAME}
  Main.cpp
  src/CarMovement.cpp
  src/Game.cpp
  src/SceneLevel.cpp
  src/SceneSplashScreen.cpp
  )
find_library(V0IDENGINE_LIB
  NAMES libv0idengine v0idengine
  HINTS "${CMAKE_INSTALL_LIBDIR}"
  )
find_package(SFML 2.5 COMPONENTS graphics audio network REQUIRED)
target_include_directories(test
  PRIVATE 
    "src"  
    "include"
  )
target_link_libraries (${PROJECT_NAME}
  PUBLIC
    ${V0IDENGINE_LIB}
    sfml-system
    sfml-graphics
    sfml-audio
    sfml-network
  )
# add_executable(v0idengine-example
#   Main.cpp
#   src/CarMovement.cpp
#   src/Game.cpp
#   src/SceneLevel.cpp
#   src/SceneSplashScreen.cpp
#   )
# target_link_libraries(v0idengine-example
#   PUBLIC
#     v0idengine
#     sfml-graphics
#     sfml-window
#     sfml-system
#   )