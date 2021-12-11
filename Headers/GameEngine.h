#ifndef SPACE_SHOOTER_GAMEENGINE_H
#define SPACE_SHOOTER_GAMEENGINE_H

#include "Player.h"

class GameEngine {
private:
    sf::RenderWindow* window;

    // Player
    Player* player;

    // Private Functions
    void InitWindow();
    void InitPlayer();

public:
    GameEngine();
    virtual ~GameEngine();

    // Functions
    void Run();

    void UpdatePollEvents();
    void UpdateInput();
    void Update();
    void Render();
};

#endif //SPACE_SHOOTER_GAMEENGINE_H