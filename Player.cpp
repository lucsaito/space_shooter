#include "Player.h"

Player::Player() {
    this->InitSprite();
    this->InitTexture();
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
}

void Player::InitTexture() {
    // Load the texture from a file


}

