#include "../Headers/Player.h"

Player::Player() {
    this->InitTexture();
    this->InitSprite();
    this->Speed = 5.f;
}

Player::~Player() {

}

// Functions
void Player::Update() {

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
