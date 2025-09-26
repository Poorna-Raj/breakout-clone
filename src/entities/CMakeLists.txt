set(SOURCES
    Paddle.cpp
    Ball.cpp
)

add_library(Entities ${SOURCES})
target_include_directories(Entities PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(Entities PUBLIC raylib)