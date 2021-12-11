#ifndef SPACE_SHOOTER_PLAYER_H
#define SPACE_SHOOTER_PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Player {
private:
    sf::Sprite sprite;
    sf::Texture texture;

    // Private Functions
    void InitSprite();
    void InitTexture();

public:
    Player();
    virtual ~Player();

    // Functions
    void Update();
    void Render(sf::RenderTarget& target);
};


#endif //SPACE_SHOOTER_PLAYER_H
