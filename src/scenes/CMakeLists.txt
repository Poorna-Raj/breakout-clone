set(SOURCES 
    GameScene.cpp
    StartScene.cpp
    EndScene.cpp
)

add_library(Scenes ${SOURCES})
target_include_directories(Scenes PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(Scenes PUBLIC raylib)
target_link_libraries(Scenes PUBLIC Entities)