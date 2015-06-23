#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class Obstacle;

class ObstacleManager
{
	public:
		ObstacleManager();
		~ObstacleManager();

		auto initialize(sf::Vector2u terrainSize, float spawnDeltaInSeconds, float obstacleSpeed, float obstacleSize) -> void;

		auto createObstacle() -> void;

		auto draw(sf::RenderTarget& target) -> void;
		auto update(sf::Time elapsed) -> void;

	private:
		std::vector<Obstacle*> obstacles;
		sf::Vector2u terrainSize;

		sf::Time spawnDelta;
		sf::Clock clock;

		float obstacleSpeed;
		float obstacleSize;
};

