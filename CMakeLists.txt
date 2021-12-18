cmake_minimum_required(VERSION 3.20)
project(kr)

set(CMAKE_CXX_STANDARD 20)

add_executable(kr main.cpp structures/arrQueue.h structures/Deque.h structures/DequeOnArray.h structures/Forward_listOnNodes.h structures/ForwardListOnArray.h structures/ListOnArray.h structures/ListOnNodes.h structures/QueueOnNodes.h structures/StackOnArray.h structures/StackOnNodes.h)
