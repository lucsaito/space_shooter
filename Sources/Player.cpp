#include "../Headers/Player.h"

Player::Player() {
    this->InitVariables();
    this->InitTexture();
    this->InitSprite();
}

Player::~Player() {

}

// Functions
void Player::Update() {
    this->UpdateAttack();
}

void Player::Render(sf::RenderTarget& target) {
    target.draw(this->sprite);
}

// Private Functions
void Player::InitSprite() {
    // Load the texture into the sprite
    this->sprite.setTexture(this->texture);

    // Set sprite size
    this->sprite.setScale(0.4f, 0.4f);
}

void Player::InitTexture() {
    // Load the texture from a file
    if (!this->texture.loadFromFile("Sprites/ship.png")) {
        std::cout << "Error when loading texture image." << std::endl;
    }
}

void Player::Move(const float X, const float Y) {
    this->sprite.move(this->Speed * X, this->Speed * Y);
}

const sf::Vector2f &Player::GetPosition() const {
    return this->sprite.getPosition();
}

void Player::UpdateAttack() {
    if (this->AttackCooldown < this->AttackCooldownMax) {
        this->AttackCooldown += 0.5f;
    }
}

const bool Player::CanAttack() {
    if (this->AttackCooldown >= this->AttackCooldownMax) {
        this->AttackCooldown = 0.f;
        return true;
    }
    return false;
}

void Player::InitVariables() {
    this->Speed = 6.f;
    this->AttackCooldownMax = 10.f;
    this->AttackCooldown = this->AttackCooldownMax;
}
