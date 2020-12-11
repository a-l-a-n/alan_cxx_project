cmake_minimum_required(VERSION 2.8)
project(test)

#set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_STANDARD 11)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

#gflags
find_package(gflags REQUIRED)
include_directories(${gflags_INCLUDE_DIR})

#glog
find_package(Glog REQUIRED)
include_directories(${GLOG_INCLUDE_DIRS})

#gtest
#enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

#Protobuf
find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS proto/config.proto)

# 可直接包含include目录下的头文件
include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${PROJECT_SOURCE_DIR}/utils")

#lib
aux_source_directory(${PROJECT_SOURCE_DIR}/src LIB_SRC)
aux_source_directory(${PROJECT_SOURCE_DIR}/include LIB_SRC)
add_library(process ${LIB_SRC} ${PROTO_SRCS} ${PROTO_HDRS})

#exe
add_executable(test main.cc)
target_link_libraries(test
  process
  gflags
  glog::glog
  ${PROTOBUF_LIBRARIES}
)

#unit test
add_executable(unit_test test/unit_test.cc)
target_link_libraries(unit_test ${GTEST_LIBRARY} pthread)
