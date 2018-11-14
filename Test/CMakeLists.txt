cmake_minimum_required(VERSION 3.9.2)
 
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# MESSAGE(${CMAKE_CURRENT_SOURCE_DIR}/*.cc)
file(GLOB_RECURSE TEST_SOURCE_LIST *.cc)
# MESSAGE(${TEST_SOURCE_LIST})

add_executable(LifeGameTest ${TEST_SOURCE_LIST})
target_link_libraries(LifeGameTest ${GTEST_LIBRARIES} pthread)