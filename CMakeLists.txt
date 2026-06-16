cmake_minimum_required(VERSION 3.10.0)
project(ChessDex-cpp VERSION 0.1.0 LANGUAGES C CXX)

add_executable(ChessDex-cpp
  src/main.cpp
  src/board/board.cpp
  src/engine/engine.cpp
)

include(CTest)
enable_testing()

