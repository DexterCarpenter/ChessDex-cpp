add_executable(default_test test.cpp)
target_include_directories(default_test PRIVATE ${PROJECT_SOURCE_DIR}/src)
add_test(NAME DefaultTest COMMAND default_test)