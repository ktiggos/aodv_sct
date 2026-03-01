cmake_minimum_required(VERSION 3.16)
project(aodv_sct LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(nlohmann_json REQUIRED)

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

target_link_libraries(demo_aodv_sc
	PRIVATE
	nlohmann_json::nlohmann_json
)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
