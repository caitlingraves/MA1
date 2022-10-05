cmake_minimum_required(VERSION 3.0.0)
project(MA1 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(MA1 main.cpp testQueue.cpp queue.h testQueue.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_CXX_STANDARD 11) 
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall") 
set(CMAKE_BUILD_TYPE Debug)

include(CPack)
