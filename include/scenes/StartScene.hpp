#include "SceneType.hpp"
#include "Scene.hpp"

class StartScene : public Scene
{
private:
    bool startPressed = false;

public:
    StartScene();
    ~StartScene();

    void update();
    void draw();
    bool shouldClose();

    SceneType nextScene();
};