#include "SceneType.hpp"
#include "Scene.hpp"

class GameScene : public Scene
{
private:
    bool startPressed = false;

public:
    GameScene();
    ~GameScene();

    void update();
    void draw();

    SceneType nextScene();
};