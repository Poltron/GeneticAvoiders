#pragma once

#include <SFML/Graphics.hpp>

class Entity
{
	public:
		virtual auto draw(sf::RenderTarget& target) -> void = 0;
		virtual auto update(sf::Time elapsedTime) -> void = 0;

	protected:
		sf::Vector2f velocity;
};

