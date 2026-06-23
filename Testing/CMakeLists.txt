list(APPEND TEST_FILES
#   ADD TEST FILES HERE
    test_common.cpp
    test_piece.cpp
    test_move.cpp
    test_board.cpp
    test_engine.cpp
)

foreach(TEST_FILE ${TEST_FILES})
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)
    add_executable(${TEST_NAME} ${TEST_FILE})
    target_link_libraries(${TEST_NAME} PRIVATE chessdex)
    target_include_directories(${TEST_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/src)
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()