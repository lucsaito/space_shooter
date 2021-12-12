#ifndef SPACE_SHOOTER_BULLET_H
#define SPACE_SHOOTER_BULLET_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Bullet {
private:
    sf::Sprite shape;
    sf::Vector2f direction;
    float Speed;
public:
    Bullet();
    Bullet(sf::Texture* texture, float position_X, float position_Y, float X, float Y, float Speed);
    virtual ~Bullet();

    const sf::FloatRect GetBounds() const;


    void Update();
    void Render(sf::RenderTarget& target);
};


#endif //SPACE_SHOOTER_BULLET_H
