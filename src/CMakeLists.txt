cmake_minimum_required(VERSION 3.19.0)

add_executable(main main.cpp)

target_link_libraries(main bencode::bencode cpr::cpr crypto)
