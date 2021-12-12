#include "../Headers/GameEngine.h"

GameEngine::GameEngine() {
    this->InitWindow();
    this->InitTextures();
    this->InitGUI();
    this->InitBackground();
    this->InitVariables();
    this->InitPlayer();
    this->InitEnemies();
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

    //  Delete enemies
    for (auto *enemy: this->enemies) {
        delete enemy;
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
    this->UpdateCollision();

    this->UpdateBullets();
    this->UpdateEnemies();
    this->UpdateCombat();

    this->UpdateGUI();
    this->UpdateBackground();
}

void GameEngine::Render() {
    this->window->clear();

    // Sets background
    this->RenderBackground();

    // After clearing the window we must draw the objects
    this->player->Render(*this->window);

    for (auto *bullet: this->bullets) {
        bullet->Render(*this->window);
    }

    for (auto *enemy: this->enemies) {
        enemy->Render(*this->window);
    }

    this->RenderGUI();

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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->player->CanAttack()) {
        this->bullets.push_back(new Bullet(this->textures["Bullet"],
                                           this->player->GetPosition().x + this->player->GetBounds().width/2.f,
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

void GameEngine::UpdateEnemies() {
    // Spawn enemies
    this->SpawnTimer += 0.5f;
    if (this->SpawnTimer >= this->SpawnTimerMax) {
        // Enemy shapes are created here
        this->enemies.push_back(new Enemy(rand() % this->window->getSize().x - 20.f, -100.f));
        this->SpawnTimer = 0.f;
    }

    // Update
    unsigned counter = 0;

    for (auto *enemy: this->enemies) {
        enemy->Update();

        // Bullets outside of the screen are deleted
        if (enemy->GetBounds().top > this->window->getSize().y) {
            delete this->enemies.at(counter);
            this->enemies.erase(this->enemies.begin() + counter);
            --counter;
        } else if (enemy->GetBounds().intersects(this->player->GetBounds())){
            // Condition if the enemy hits the player
            delete this->enemies.at(counter);
            this->enemies.erase(this->enemies.begin() + counter);
            --counter;
        }
        ++counter;
    }

}

void GameEngine::InitEnemies() {
    this->SpawnTimerMax = 50.f;
    this->SpawnTimer = this->SpawnTimerMax;
}

void GameEngine::InitGUI() {
    if (!this->font.loadFromFile("Fonts/HaarlemSerif.ttf")) {
        std::cout << "Failed to load font" << std::endl;
    }
    this->point_counter.setFont(this->font);
    this->point_counter.setCharacterSize(12);
    this->point_counter.setFillColor(sf::Color::White);
    this->point_counter.setString("This is a test string");
}

void GameEngine::UpdateGUI() {
    std::stringstream ss;
    ss << "Points: " << this->points;
    this->point_counter.setString(ss.str());
}

void GameEngine::RenderGUI() {
    this->window->draw(this->point_counter);
}

void GameEngine::UpdateCombat() {
    for (int i = 0; i < enemies.size(); ++i) {
        bool enemy_was_deleted = false;

        for (int k = 0; k < this->bullets.size() && enemy_was_deleted == false; k++) {
            // Finds the bullet collision with enemy
            if (this->enemies[i]->GetBounds().intersects(this->bullets[k]->GetBounds())) {
                // Increases the point number
                this->points += this->enemies[i]->GetPoints();

                delete this->enemies[i];
                this->enemies.erase(this->enemies.begin() + i);

                delete this->bullets[k];
                this->bullets.erase(this->bullets.begin() + k);


                enemy_was_deleted = true;

            }
        }
    }
}

void GameEngine::InitBackground() {
    if (!this->background_texture.loadFromFile("Sprites/space.jpg")) {
        std::cout << "Error when loading background." << std::endl;
    }
    this->background.setTexture(this->background_texture);
}

void GameEngine::UpdateBackground() {

}

void GameEngine::RenderBackground() {
    this->window->draw(this->background);
}

void GameEngine::UpdateCollision() {
    // Keeps the play on the screen
    if (this->player->GetBounds().left < 0.f) {
        this->player->SetPosition(0.f, this->player->GetBounds().top);
    }
    if (this->player->GetBounds().top < 0.f) {
        this->player->SetPosition(this->player->GetBounds().left, 0.f);
    }

    if (this->player->GetBounds().left + this->player->GetBounds().width >= this->window->getSize().x) {
        this->player->SetPosition(this->window->getSize().x - this->player->GetBounds().width, this->player->GetBounds().top);
    }

    if (this->player->GetBounds().top + this->player->GetBounds().height >= this->window->getSize().y) {
        this->player->SetPosition(this->player->GetBounds().left, this->window->getSize().y - this->player->GetBounds().height);
    }

}

void GameEngine::InitVariables() {
    this->points = 0;
}

