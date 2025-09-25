#include "Scene.hpp"
#include <iostream>
#include <memory>
#include "SceneType.hpp"

class SceneManager
{
private:
    std::unique_ptr<Scene> currentScene;
    SceneType currentType;

public:
    SceneManager();
    ~SceneManager();

    void switchScene(SceneType type);
    void draw();
    void update();
    bool shouldClose() const;
};