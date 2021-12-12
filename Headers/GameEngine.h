#ifndef SPACE_SHOOTER_GAMEENGINE_H
#define SPACE_SHOOTER_GAMEENGINE_H

#include <map>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

class GameEngine {
private:
    // Window of the game
    sf::RenderWindow* window;

    // Resources
    std::map<std::string, sf::Texture*> textures;
    std::vector<Bullet*> bullets;


    // Player
    Player* player;

    // Enemies
    float SpawnTimer;
    float SpawnTimerMax;
    std::vector<Enemy*> enemies;


    // Private Functions
    void InitWindow();
    void InitTextures();
    void InitPlayer();
    void InitEnemies();

public:
    GameEngine();
    virtual ~GameEngine();

    // Functions
    void Run();

    void UpdatePollEvents();
    void UpdateInput();
    void UpdateEnemies();
    void UpdateBullets();
    void Update();
    void Render();
};

#endif //SPACE_SHOOTER_GAMEENGINE_H