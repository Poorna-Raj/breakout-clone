#include "raylib.h"
#include "scenes/EndScene.hpp"

EndScene::EndScene() {};

EndScene::~EndScene() {};

void EndScene::update()
{
    if (IsKeyPressed(KEY_ENTER))
    {
        requestNext = true;
    }
}

void EndScene::draw()
{
    DrawText("Press ENTER to end.", 200, 200, 20, BLACK);
}

bool EndScene::shouldClose()
{
    return (IsKeyPressed(KEY_A));
}

SceneType EndScene::nextScene()
{
    return requestNext ? SceneType::START : SceneType::NONE;
}
