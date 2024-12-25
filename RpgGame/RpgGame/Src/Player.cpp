#include "Player.h"
#include<iostream>
#include"Math.h"

Player::Player() :

    playerSpeed(0.05f), maxFireRate(150), fireRateTimer(0)
{

}

Player::~Player() {

}

void Player::Initialize() {

    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Red);
    boundingRectangle.setOutlineThickness(1);

    size = sf::Vector2i(32, 32);
}

void Player::Load() {

	if (!Texture.loadFromFile("Assets/Player/1.png")) {

		std::cerr << "Error Loading Player textures!!!";
		return;
	}

	Sprite.setTexture(Texture);

	int xIndex = 0;
	int yIndex = 0;

	Sprite.setTextureRect(sf::IntRect(xIndex * size.x, yIndex * size.y, size.x, size.y));
	Sprite.setPosition(sf::Vector2f(100, 100));
    
    Sprite.setScale(sf::Vector2f(1.3, 1.3));

    boundingRectangle.setSize(sf::Vector2f(size.x * Sprite.getScale().x, size.y * Sprite.getScale().y));
}

void Player::Update(double deltaTime, Enemy& enemy1, sf::Vector2f &mousePosition) {

    int xIndex = 0;
    int yIndex = 0;

    sf::Vector2f position = Sprite.getPosition();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {

        Sprite.setPosition(position + sf::Vector2f(0, -5) * playerSpeed * (float)deltaTime);
        Sprite.setTextureRect(sf::IntRect(xIndex * 32, 3 * 32, 32, 32));

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {

        Sprite.setPosition(position + sf::Vector2f(0, 5) * playerSpeed * (float)deltaTime);
        Sprite.setTextureRect(sf::IntRect(xIndex * 32, yIndex * 32, 32, 32));

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {

        Sprite.setPosition(position + sf::Vector2f(5, 0) * playerSpeed * (float)deltaTime);
        Sprite.setTextureRect(sf::IntRect(xIndex * 32, 2 * 32, 32, 32));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {

        Sprite.setPosition(position + sf::Vector2f(-5, 0) * playerSpeed * (float)deltaTime);
        Sprite.setTextureRect(sf::IntRect(xIndex * 32, 1 * 32, 32, 32));
    }
    //------------------------------------------Bullet Code----------------------------------------//

    fireRateTimer += deltaTime;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && fireRateTimer >= maxFireRate) {

        bullets.push_back(Bullet());
        int lastElement = bullets.size() - 1;
        
        bullets[lastElement].Initialize(Sprite.getPosition() + sf::Vector2f(0, 18), mousePosition, 0.5f);

        fireRateTimer = 0;

        
    }
    
    for (size_t i = 0; i < bullets.size(); i++) {

        bullets[i].Update(deltaTime);

        if (enemy1.getHealth() > 0) {

            if (Math::DidRectCollision(bullets[i].GetGlobalBounds(), enemy1.Sprite.getGlobalBounds())) {

                enemy1.setHealth(-10);
                bullets.erase(bullets.begin() + i);
                std::cout << "Enemy health: " << enemy1.getHealth() << std::endl;
            }
        }
        
    }
//------------------------------------------Bullet Code----------------------------------------//

    boundingRectangle.setPosition(Sprite.getPosition());
}

void Player::Draw(sf::RenderWindow& window) {

    window.draw(Sprite);
    window.draw(boundingRectangle);

    for (size_t i = 0; i < bullets.size(); i++) {

        bullets[i].Draw(window);
    }   
}
