cmake_minimum_required(VERSION 3.20)

project(NN-Visualizer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE APP_SRC "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_executable(NN-Visualizer ${APP_SRC})

target_include_directories(NN-Visualizer PUBLIC ${CMAKE_SOURCE_DIR}/include)

if(WIN32)
  find_package(raylib CONFIG REQUIRED)
  target_link_libraries(NN-Visualizer PRIVATE raylib)
else()
  find_package(raylib CONFIG REQUIRED)
  target_link_libraries(NN-Visualizer PRIVATE raylib)
endif()
