#include "SceneType.hpp"
#include "Scene.hpp"
#include "entities/Paddle.hpp"
#include <memory>

class GameScene : public Scene
{
private:
    bool startPressed = false;

public:
    std::unique_ptr<Paddle> player;

    GameScene();
    ~GameScene();

    void update();
    void draw();

    SceneType nextScene();
};