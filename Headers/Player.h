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
    float AttackCooldown;
    float AttackCooldownMax;

    int hp;
    int hp_max;

    // Private Functions
    void InitVariables();
    void InitSprite();
    void InitTexture();

public:
    Player();
    virtual ~Player();

    const sf::Vector2f& GetPosition() const;
    const sf::FloatRect GetBounds() const;
    const int& GetHp() const;
    const int& GetMaxHp() const;
    void SetHp(const int hp_value);
    void LoseHp(const int value);

    void SetPosition(const sf::Vector2f position);
    void SetPosition(const float x, const float y);

    // Functions
    void Move(const float X, const float Y);
    const bool CanAttack();

    void UpdateAttack();
    void Update();
    void Render(sf::RenderTarget& target);
};


#endif //SPACE_SHOOTER_PLAYER_H
