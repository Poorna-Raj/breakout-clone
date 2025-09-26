cmake_minimum_required(VERSION 4.1)
project(Breakout)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src/core)
add_subdirectory(src/entities)
add_subdirectory(src/scenes)

add_executable(${PROJECT_NAME} main.cpp)

set(GLFW_INCLUDE_DIR "C:/raylib/glfw/include")
set(GLFW_LIBRARY_DIR "C:/raylib/glfw/lib-mingw-w64")

include_directories(${GLFW_INCLUDE_DIR})
link_directories(${GLFW_LIBRARY_DIR})
set(RAYLIB_PATH "C:/raylib/raylib")

file(GLOB RAYLIB_SOURCES
"${RAYLIB_PATH}/src/*.c"
)

add_library(raylib STATIC ${RAYLIB_SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE 
    "${CMAKE_SOURCE_DIR}/include"
    "${RAYLIB_PATH}/src"
    "${RAYLIB_PATH}/src/external"
)
target_link_libraries(${PROJECT_NAME} PRIVATE
    raylib
    Scenes
    Entities
    CoreLib
)
target_compile_definitions(raylib PUBLIC PLATFORM_DESKTOP)
target_include_directories(raylib PUBLIC
    ${RAYLIB_PATH}/src
    ${RAYLIB_PATH}/src/external
)

if(WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE raylib opengl32 gdi32 winmm user32 kernel32)
endif()

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
endif()