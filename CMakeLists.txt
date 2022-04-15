cmake_minimum_required(VERSION 3.18)
file(GLOB SOURCE_DIR_FILES ./src/*.cpp)
file(GLOB HEADER_DIR_FILES ./src/include/*.hpp)

project(main)

#set the C++ standard to be used
set (CMAKE_CXX_STANDARD 11)



find_package(SFML 2 COMPONENTS graphics window system audio network REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCE_DIR_FILES} ${HEADER_DIR_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR}/include/ ${CMAKE_CURRENT_SOURCE_DIR}/vendor/)

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)