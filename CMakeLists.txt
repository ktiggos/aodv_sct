cmake_minimum_required(VERSION 3.16)
project(aodv_sct LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(aodv_test
  src/test.cpp
)

target_include_directories(aodv_test
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(aodv_s1
	src/supervisor_s1
)

target_include_directories(aodv_s1
	PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/include
)
