set(SOURCES
    SceneManager.cpp
    BrickManager.cpp
)

add_library(CoreLib ${SOURCES})
target_include_directories(CoreLib PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(CoreLib PUBLIC raylib)
target_link_libraries(CoreLib PUBLIC Scenes)