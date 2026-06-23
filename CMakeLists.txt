cmake_minimum_required(VERSION 3.10.0)
project(ChessDex-cpp VERSION 0.1.0 LANGUAGES C CXX)

add_executable(ChessDex-cpp
  src/main.cpp
  src/common.cpp
  src/board/board.cpp
  src/board/piece.cpp
  src/board/move.cpp
  src/engine/engine.cpp
)

include(CTest)
enable_testing()

add_subdirectory(Testing)