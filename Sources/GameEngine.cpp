#include "../Headers/GameEngine.h"

GameEngine::GameEngine() {
    this->InitWindow();
    this->InitPlayer();
}

GameEngine::~GameEngine() {
    delete this->window;
    delete this->player;
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
}

void GameEngine::Render() {
    this->window->clear();

    // After clearing the window we must draw the objects
    this->player->Render(*this->window);

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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        this->player->Move(-1.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        this->player->Move(1.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        this->player->Move(0.f, -1.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        this->player->Move(0.f, 1.f);
    }
}
