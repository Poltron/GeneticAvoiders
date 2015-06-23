#pragma once
#include "Entity.h"

class Obstacle : Entity
{
	public:
		Obstacle(sf::Vector2f position, sf::Vector2f velocity, float radius);
		~Obstacle();

		auto draw(sf::RenderTarget& window) -> void override;
		auto update(sf::Time elapsedTime) -> void override;

		auto outOfScreen() -> bool;
		auto remove() -> void;
		auto isToRemove() -> bool;

	private:
		sf::CircleShape* shape;
		bool toRemove;
};

