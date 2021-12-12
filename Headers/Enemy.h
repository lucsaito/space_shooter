#ifndef SPACE_SHOOTER_ENEMY_H
#define SPACE_SHOOTER_ENEMY_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Enemy {
private:
    unsigned point_count;
    sf::CircleShape shape;
    float speed;
    int type;
    int hp;
    int hpMax;
    int damage;
    int points;

    void InitShape();
    void InitVariables();
public:
    Enemy();
    Enemy(float position_X, float position_Y);
    virtual ~Enemy();

    const sf::FloatRect GetBounds() const;
    const int& GetPoints() const;

    void Update();
    void Render(sf::RenderTarget& target);
};


#endif //SPACE_SHOOTER_ENEMY_H
