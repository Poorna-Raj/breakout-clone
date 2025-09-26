#include "SceneType.hpp"
#include "Scene.hpp"
#include "entities/Paddle.hpp"
#include <memory>
#include "entities/Ball.hpp"
#include "core/BrickManager.hpp"

class GameScene : public Scene
{
private:
    bool startPressed = false;

public:
    std::unique_ptr<Paddle> paddle;
    std::unique_ptr<Ball> ball;
    BrickManager brickManager;

    GameScene();
    ~GameScene();

    void update();
    void draw();

    void addBall(Paddle &paddle);
    void checkBallWallCollision();
    void checkBallPaddleCollision(Ball &ball, Paddle &paddle);
    void checkGameStart();

    SceneType nextScene();
};