cmake_minimum_required(VERSION 3.15.0)
project(SimpleTorrent)

set(CMAKE_CXX_STANDARD 20)

include_directories(lib)

include(FetchContent)

FetchContent_Declare(bencode
  GIT_REPOSITORY https://github.com/fbdtemme/bencode.git
  GIT_TAG "1.0.1")

FetchContent_MakeAvailable(bencode)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG "1.10.5") # The commit hash for 1.10.x. Replace with the latest from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)

add_subdirectory(src)