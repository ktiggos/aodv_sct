cmake_minimum_required(VERSION 3.16)
project(aodv_sct LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(demo_aodv_sc
	src/demo_aodv_sc.cpp
	src/vcu.cpp
	src/sc_s1.cpp
	src/sc_s2.cpp
)

target_include_directories(demo_aodv_sc
	PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/include
)
