#include "scenes/SceneManager.hpp"
#include "scenes/StartScene.hpp"
#include "scenes/GameScene.hpp"
#include <iostream>

SceneManager::SceneManager()
{
    switchScene(SceneType::START);
}

SceneManager::~SceneManager() {};

void SceneManager::switchScene(SceneType type)
{
    currentType = type;
    switch (type)
    {
    case SceneType::START:
        currentScene = std::make_unique<StartScene>();
        break;
    case SceneType::GAME:
        currentScene = std::make_unique<GameScene>();
        break;
    default:
        currentScene = nullptr;
        break;
    }
}

void SceneManager::update()
{
    if (currentScene)
    {
        currentScene->update();
        if (auto startScene = dynamic_cast<StartScene *>(currentScene.get()))
        {
            SceneType next = startScene->nextScene();

            if (next != SceneType::NONE)
            {
                switchScene(next);
            }
        }
    }
}

void SceneManager::draw()
{
    if (currentScene)
    {
        currentScene->draw();
    }
}

bool SceneManager::shouldClose() const
{
    return currentScene && currentScene->shouldClose();
}