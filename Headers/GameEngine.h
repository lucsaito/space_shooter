#ifndef SPACE_SHOOTER_GAMEENGINE_H
#define SPACE_SHOOTER_GAMEENGINE_H

#include <map>
#include "Player.h"
#include "Bullet.h"

class GameEngine {
private:
    // Window of the game
    sf::RenderWindow* window;

    // Resources
    std::map<std::string, sf::Texture*> textures;
    std::vector<Bullet*> bullets;


    // Player
    Player* player;

    // Private Functions
    void InitWindow();
    void InitTextures();
    void InitPlayer();

public:
    GameEngine();
    virtual ~GameEngine();

    // Functions
    void Run();

    void UpdatePollEvents();
    void UpdateInput();
    void UpdateBullets();
    void Update();
    void Render();
};

#endif //SPACE_SHOOTER_GAMEENGINE_H