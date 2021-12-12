#include "../Headers/Enemy.h"

Enemy::Enemy() {

}

Enemy::Enemy(float position_X, float position_Y) {
    this->InitVariables();
    this->InitShape();

    this->shape.setPosition(position_X, position_Y);
}

Enemy::~Enemy() {

}

void Enemy::InitVariables() {
    this->point_count = rand() % 8 + 3;
    this->speed = static_cast<float>(this->point_count);
    this->type = 0;
    this->hpMax = static_cast<int>(this->point_count);
    this->hp = this->hpMax;
    this->damage = this->point_count;
    this->points = this->point_count;
}

void Enemy::InitShape() {
    this->shape.setRadius(this->point_count * 9);
    this->shape.setPointCount(this->point_count);
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

const int &Enemy::GetPoints() const{
    return this->points;
}
