#include "Scene.hpp"
#include "SceneType.hpp"

class EndScene : public Scene
{
private:
    bool requestNext = false;

public:
    EndScene();
    ~EndScene();

    void draw();
    void update();
    bool shouldClose();

    SceneType nextScene();
};