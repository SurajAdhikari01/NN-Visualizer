cmake_minimum_required(VERSION 3.20)
project(NN-Visualizer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE APP_SRC "${CMAKE_SOURCE_DIR}/src/*.cpp")
add_executable(NN-Visualizer ${APP_SRC})

target_include_directories(NN-Visualizer PUBLIC ${CMAKE_SOURCE_DIR}/include)

# --- Dependencies ---
find_package(raylib CONFIG REQUIRED)
find_package(Eigen3 REQUIRED NO_MODULE)
find_package(Armadillo REQUIRED)

# mlpack and ensmallen are header-only on Arch, no CMake config files exist
find_path(MLPACK_INCLUDE_DIR mlpack.hpp
    PATHS /usr/include /usr/local/include
)
find_path(ENSMALLEN_INCLUDE_DIR ensmallen.hpp
    PATHS /usr/include /usr/local/include
)

if(NOT MLPACK_INCLUDE_DIR)
  message(FATAL_ERROR "mlpack.hpp not found. Is mlpack installed?")
endif()
if(NOT ENSMALLEN_INCLUDE_DIR)
  message(FATAL_ERROR "ensmallen.hpp not found. Is ensmallen installed?")
endif()

message(STATUS "Found mlpack headers: ${MLPACK_INCLUDE_DIR}")
message(STATUS "Found ensmallen headers: ${ENSMALLEN_INCLUDE_DIR}")

target_include_directories(NN-Visualizer PUBLIC
    ${ARMADILLO_INCLUDE_DIRS}
    ${MLPACK_INCLUDE_DIR}
    ${ENSMALLEN_INCLUDE_DIR}
)

target_link_libraries(NN-Visualizer
    PRIVATE
        raylib
        Eigen3::Eigen
        ${ARMADILLO_LIBRARIES}
)
