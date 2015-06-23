#include "Obstacle.h"

Obstacle::Obstacle(sf::Vector2f position, sf::Vector2f _velocity, float radius)
{
	shape = new sf::CircleShape(radius);
	shape->setFillColor(sf::Color::Red);
	shape->setOutlineThickness(5.f);
	shape->setOutlineColor(sf::Color::Black);

	shape->setPosition(position);

	shape->setOrigin(radius/2, radius/2);

	velocity = _velocity;
}

Obstacle::~Obstacle()
{
}

auto Obstacle::draw(sf::RenderTarget& window) -> void
{
	window.draw(*shape);
}


auto Obstacle::update(sf::Time elapsedTime) -> void
{
	shape->setPosition(shape->getPosition() + velocity * elapsedTime.asSeconds());
}

auto Obstacle::outOfScreen() -> bool
{
	sf::Vector2f pos = shape->getPosition();
	if (pos.y <= - 150 || pos.y >= 750)
	{
		return true;
	}
	else if (pos.x <= - 150 || pos.x >= 950)
	{
		return true;
	}

	return false;
}

auto Obstacle::remove() -> void
{
	toRemove = true;
}

auto Obstacle::isToRemove() -> bool
{
	return toRemove;
}