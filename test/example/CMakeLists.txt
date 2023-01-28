cmake_minimum_required(VERSION 3.9)
project(v0idengine-example
  DESCRIPTION "A game used to test v0idengine"  
  LANGUAGE CXX
  )
add_executable(v0idengine-example Main.cpp)
target_include_directories(v0idengine-example PRIVATE src)