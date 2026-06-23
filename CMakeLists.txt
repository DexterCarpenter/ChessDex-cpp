cmake_minimum_required(VERSION 3.10.0)
project(ChessDex-cpp VERSION 0.1.0 LANGUAGES C CXX)

add_library(chessdex STATIC
  src/common.cpp
  src/board/board.cpp
  src/board/piece.cpp
  src/board/move.cpp
  src/engine/engine.cpp
)

target_include_directories(chessdex PUBLIC ${PROJECT_SOURCE_DIR}/src)

add_executable(ChessDex-cpp src/main.cpp)
target_link_libraries(ChessDex-cpp PRIVATE chessdex)

include(CTest)
enable_testing()

add_subdirectory(Testing)