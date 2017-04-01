project(cpptest)
cmake_minimum_required(VERSION 3.5)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -pthread")
find_package (Threads)


include_directories(cpptest "${PROJECT_SOURCE_DIR}/include")
file(GLOB SOURCES
    src/*.cc
)

add_library (common STATIC src/common/func.cc src/common/func2.cc)


set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
set(CMAKE_SHARED_LIBRARY_PREFIX "")

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(cpptest common)
