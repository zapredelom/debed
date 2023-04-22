cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 20)
project(debed)

include_directories(${CMAKE_SOURCE_DIR}/include)

if(MSVC)
  add_compile_definitions(_WIN32_WINNT=_WIN32_WINNT_WIN10)
  add_compile_options(/MD)
  list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/build/generators")
  list(APPEND CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/build/generators")
else()
  list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/build/Release/generators")
  list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/build/Debug/generators")
  list(APPEND CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/build/Releas/generators")
  list(APPEND CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/build/Debug/generators")
endif()

find_package(Boost REQUIRED)

add_executable(debed main.cpp)
add_subdirectory(src)
add_dependencies(debed draw_server)

target_link_libraries(debed PRIVATE  boost::boost draw_server)
