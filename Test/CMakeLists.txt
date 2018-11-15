cmake_minimum_required(VERSION 3.9.2)
 
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

file(GLOB_RECURSE ORIGIN_SOURCE_LIST ../Source/*.cc)
file(GLOB_RECURSE TEST_SOURCE_LIST *.cc)

# Avoid duplicate main function
# GET_FILENAME_COMPONENT(FULL_PATH_MAIN_CPP ${CMAKE_CURRENT_SOURCE_DIR}/../Source/main.cc)
list(REMOVE_ITEM ORIGIN_SOURCE_LIST ${CMAKE_CURRENT_SOURCE_DIR}/../Source/main.cc)

MESSAGE(${CMAKE_CURRENT_SOURCE_DIR}/../Source/main.cc)
# MESSAGE(${FULL_PATH_MAIN_CPP})

# Message(${ORIGIN_SOURCE_LIST})

include_directories(LifeGameTest
    ../Header
)

add_executable(LifeGameTest ${TEST_SOURCE_LIST} ${ORIGIN_SOURCE_LIST})
target_link_libraries(LifeGameTest ${GTEST_LIBRARIES} pthread)