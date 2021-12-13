#ifndef SPACE_SHOOTER_GAMEENGINE_H
#define SPACE_SHOOTER_GAMEENGINE_H

#include <map>
#include <string>
#include <sstream>
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

    // GUI
    sf::Font font;
    sf::Text point_counter;
    sf::Texture background_texture;
    sf::Sprite background;
    unsigned points;


    // Player
    Player* player;
    sf::RectangleShape player_hp_bar;
    sf::RectangleShape player_hp_bar_back;

    // Enemies
    float SpawnTimer;
    float SpawnTimerMax;
    std::vector<Enemy*> enemies;


    // Private Functions
    void InitWindow();
    void InitTextures();
    void InitPlayer();
    void InitEnemies();
    void InitGUI();
    void InitBackground();
    void InitVariables();

public:
    GameEngine();
    virtual ~GameEngine();

    // Functions
    void Run();

    void UpdatePollEvents();
    void UpdateInput();
    void UpdateBullets();
    void UpdateEnemies();
    void UpdateCombat();
    void UpdateCollision();
    void UpdateBackground();
    void UpdateGUI();
    void Update();
    void Render();
    void RenderGUI();
    void RenderBackground();
};

#endif //SPACE_SHOOTER_GAMEENGINE_H