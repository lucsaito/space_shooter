#ifndef SPACE_SHOOTER_PLAYER_H
#define SPACE_SHOOTER_PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

class Player {
private:
    sf::Sprite sprite;
    sf::Texture texture;
    float Speed;

    // Private Functions
    void InitSprite();
    void InitTexture();

public:
    Player();
    virtual ~Player();

    // Functions
    void Move(const float X, const float Y);

    void Update();
    void Render(sf::RenderTarget& target);
};


#endif //SPACE_SHOOTER_PLAYER_H
