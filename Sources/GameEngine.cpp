#include "../Headers/GameEngine.h"

GameEngine::GameEngine() {
    this->InitWindow();
    this->InitTextures();
    this->InitPlayer();
}

GameEngine::~GameEngine() {
    delete this->window;
    delete this->player;

    // Delete textures
    for (auto &i: this->textures) {
        delete i.second;
    }

    // Delete bullets
    for (auto *i: this->bullets) {
        delete i;
    }
}

// Private Functions
void GameEngine::InitWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080),
                                        "Space Shooters",
                                        sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(144);
    this->window->setVerticalSyncEnabled(false);
}

void GameEngine::InitPlayer() {
    this->player = new Player();
}

// Functions
void GameEngine::Run() {
    while (this->window->isOpen()) {
        this->Update();
        this->Render();
    }
}

void GameEngine::Update() {
    this->UpdatePollEvents();
    this->UpdateInput();
    this->player->Update();
    this->UpdateBullets();
}

void GameEngine::Render() {
    this->window->clear();

    // After clearing the window we must draw the objects
    this->player->Render(*this->window);
    for (auto *bullet: this->bullets) {
        bullet->Render(*this->window);
    }

    this->window->display();
}

void GameEngine::UpdatePollEvents() {
    sf::Event e;
    while (this->window->pollEvent(e)) {
        if (e.Event::type == sf::Event::Closed) {
            this->window->close();
        }
        if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape) {
            this->window->close();
        }
    }
}

void GameEngine::UpdateInput() {
    // Player movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        this->player->Move(-1.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        this->player->Move(1.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        this->player->Move(0.f, -1.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        this->player->Move(0.f, 1.f);
    }

    // Bullet
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->CanAttack()) {
        this->bullets.push_back(new Bullet(this->textures["Bullet"],
                                           this->player->GetPosition().x,
                                           this->player->GetPosition().y,
                                           0.f,
                                           -1.f,
                                           5.f));
    }
}

void GameEngine::InitTextures() {
    this->textures["Bullet"] = new sf::Texture();
    this->textures["Bullet"]->loadFromFile("Sprites/bullet.png");
}

void GameEngine::UpdateBullets() {
    unsigned counter = 0;

    for (auto *bullet: this->bullets) {
        bullet->Update();

        // Bullets outside of the screen are deleted
        if (bullet->GetBounds().top + bullet->GetBounds().height < 0.f) {
            delete this->bullets.at(counter);
            this->bullets.erase(this->bullets.begin() + counter);
            --counter;
        }
        ++counter;
    }
}
