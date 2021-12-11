#ifndef SPACE_SHOOTER_GAMEENGINE_H
#define SPACE_SHOOTER_GAMEENGINE_H

#include "Player.h"

class GameEngine {
private:
    sf::RenderWindow* window;

    // Private Functions
    void InitWindow();

public:
    GameEngine();
    virtual ~GameEngine();

    // Functions
    void Run();

    void Update();
    void Render();
};

#endif //SPACE_SHOOTER_GAMEENGINE_H