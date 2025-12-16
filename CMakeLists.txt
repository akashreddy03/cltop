cmake_minimum_required(VERSION 3.20)
project(cltop LANGUAGES C CXX VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")
find_package(Curses REQUIRED)

include_directories(
    ${CURSES_INCLUDE_DIR}
    ${PROJECT_SOURCE_DIR}/include
)

file(GLOB_RECURSE SOURCES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)

add_executable(cltop ${SOURCES})

target_link_libraries(cltop PRIVATE ${CURSES_LIBRARIES})
