cmake_minimum_required(VERSION 3.20)
project(kr)

set(CMAKE_CXX_STANDARD 20)

add_executable(kr main.cpp structures/arrQueue.h structures/Deque.h structures/DequeOnArray.h structures/Forward_listOnNodes.h structures/ForwardListOnArray.h structures/ListOnArray.h structures/ListOnNodes.h structures/QueueOnNodes.h structures/StackOnArray.h structures/StackOnNodes.h Author.cpp Author.h Book.cpp Book.h Shop.cpp Shop.h)

project(Google_tests)

add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run structures/arrQueue.h structures/Deque.h structures/DequeOnArray.h structures/Forward_listOnNodes.h structures/ForwardListOnArray.h structures/ListOnArray.h structures/ListOnNodes.h structures/QueueOnNodes.h structures/StackOnArray.h structures/StackOnNodes.h)
target_link_libraries(Google_Tests_run gtest gtest_main)