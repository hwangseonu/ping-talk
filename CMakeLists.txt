cmake_minimum_required(VERSION 3.10)
project(ping-talk)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_library(TINS_LIBRARY tins)
find_library(PTHREAD_LIBRARY pthread)
set(SOURCE_FILES main.cpp MessageReceiver.cpp MessageReceiver.h MessageSender.cpp MessageSender.h)


add_executable(ping-talk ${SOURCE_FILES})

target_link_libraries(ping-talk "${PTHREAD_LIBRARY}")
target_link_libraries(ping-talk "${TINS_LIBRARY}")
