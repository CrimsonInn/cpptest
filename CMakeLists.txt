project(cpptest)
cmake_minimum_required(VERSION 3.5)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -pthread")
find_package (Threads)
find_package(Protobuf REQUIRED)

ADD_SUBDIRECTORY(protobuf)
include_directories(cpptest ${PROJECT_SOURCE_DIR}/include)
include_directories(cpptest ${PROJECT_SOURCE_DIR}/protobuf)

file(GLOB SOURCES
    src/*.cc
)

add_library (common STATIC src/common/func.cc src/common/func2.cc src/common/read_protobuf.cc src/common/write_protobuf.cc)


set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
set(CMAKE_SHARED_LIBRARY_PREFIX "")

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(cpptest common proto ${PROTOBUF_LIBRARY})
