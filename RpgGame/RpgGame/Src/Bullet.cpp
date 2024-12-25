#include "Bullet.h"
#include "Math.h"

Bullet::Bullet():
	speed(0)
{
}

Bullet::~Bullet()
{
}

void Bullet::Initialize(const sf::Vector2f &position, sf::Vector2f &target, float speed)
{

	this->speed = speed;

	rectangleShape.setPosition(position);
	rectangleShape.setSize(sf::Vector2f(10, 5));
	rectangleShape.setFillColor(sf::Color::Yellow);
	
	direction = Math::NormalizeVector(target - position);
}

void Bullet::Update(double deltaTime)
{
	rectangleShape.setPosition(rectangleShape.getPosition() + direction * speed * (float)deltaTime);
}

void Bullet::Draw(sf::RenderWindow &window)
{
	window.draw(rectangleShape);
}
