#include "../Headers/Bullet.h"


Bullet::Bullet() {

}

Bullet::Bullet(sf::Texture* texture, float position_X, float position_Y, float X, float Y, float Speed) {
    this->shape.setTexture(*texture);

    this->shape.setPosition(position_X, position_Y);

    this->direction.x = X;
    this->direction.y = Y;
    this->Speed = Speed;
}

Bullet::~Bullet() {

}

// Functions
void Bullet::Update() {
    // Movement of bullet
    this->shape.move(this->Speed * this->direction);
}

void Bullet::Render(sf::RenderTarget &target) {
    target.draw(this->shape);
}

const sf::FloatRect Bullet::GetBounds() const {
    return this->shape.getGlobalBounds();
}
