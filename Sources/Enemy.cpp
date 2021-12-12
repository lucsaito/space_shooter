#include "../Headers/Enemy.h"

Enemy::Enemy() {

}

Enemy::Enemy(float position_X, float position_Y) {
    this->InitShape();
    this->InitVariables();
    this->shape.setPosition(position_X, position_Y);
}

Enemy::~Enemy() {

}

void Enemy::InitVariables() {
    speed = rand() % 8 + 3;
    type = 0;
    hp = 10;
    hpMax = 0;
    damage = 1;
    points = 5;
}

void Enemy::InitShape() {
    this->shape.setRadius(rand() % 20 + 20);
    this->shape.setPointCount(rand() % 20 + 3);
    this->shape.setFillColor(sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, 255));
}

void Enemy::Update() {

    // Moves enemies down
    this->shape.move(0.f, this->speed);
}

void Enemy::Render(sf::RenderTarget& target) {
     target.draw(this->shape);
}

const sf::FloatRect Enemy::GetBounds() const {
    return this->shape.getGlobalBounds();
}