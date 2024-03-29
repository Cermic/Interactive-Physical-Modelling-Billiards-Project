cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Interactive-Physical-Modelling LANGUAGES CXX)

file(GLOB_RECURSE headerFiles "headers/*.h")
file(GLOB_RECURSE sourceFiles "source/*.cpp")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/headers)

find_package(SDL2 CONFIG REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(GLUT REQUIRED)

add_executable(${PROJECT_NAME} ${headerFiles} ${sourceFiles})

target_link_libraries(${PROJECT_NAME} PRIVATE GLEW::GLEW)
target_link_libraries(${PROJECT_NAME} PRIVATE GLUT::GLUT)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2 SDL2::SDL2main)