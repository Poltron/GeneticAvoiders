#include "ObstacleManager.h"

#include "Obstacle.h"

#include <iostream>

ObstacleManager::ObstacleManager()
{
}

auto ObstacleManager::initialize(sf::Vector2u _terrainSize, float _spawnDelta, float _obstacleSpeed, float _obstacleSize) -> void
{
	terrainSize = _terrainSize;
	spawnDelta = sf::Time(sf::seconds(_spawnDelta));

	obstacleSpeed = _obstacleSpeed;
	obstacleSize = _obstacleSize;

	clock.restart();

	createObstacle();
}

auto ObstacleManager::draw(sf::RenderTarget& target) -> void
{
	for each(auto obstacle in obstacles)
	{
		obstacle->draw(target);
	}
}

auto ObstacleManager::update(sf::Time elapsed) -> void
{
	if (clock.getElapsedTime() >= spawnDelta)
	{
		createObstacle();
		clock.restart();
	}

	for each(auto obstacle in obstacles)
	{
		obstacle->update(elapsed);

		if (obstacle->outOfScreen())
		{
			obstacle->remove();
		}
	}

	obstacles.erase(std::remove_if(obstacles.begin(), obstacles.end(), [](Obstacle* o){ return o->isToRemove(); }), obstacles.end());
}

auto ObstacleManager::createObstacle() -> void
{
	int max = 3;
	int min = 0;
	int random = min + (rand() % (int)(max - min + 1));
	
	sf::Vector2f position;
	sf::Vector2f velocity;

	if (random == 0) // il part de la gauche
	{
		max = terrainSize.y;
		min = 0;
		int randomY = min + (rand() % (int)(max - min + 1));
		position.x = -obstacleSize * 2;
		position.y = (float)randomY;

		velocity.x = obstacleSpeed;
		velocity.y = 0;
	}
	else if (random == 1) // il part d'en haut
	{
		max = terrainSize.x;
		min = 0;
		int randomX = min + (rand() % (int)(max - min + 1));
		position.x = (float)randomX;
		position.y = -obstacleSize*2;

		velocity.x = 0.f;
		velocity.y = obstacleSpeed;
	}
	else if (random == 2) // il part de la droite
	{
		max = terrainSize.y;
		min = 0;
		int randomY = min + (rand() % (int)(max - min + 1));
		position.x = terrainSize.x + obstacleSize * 2.f;
		position.y = (float)randomY;

		velocity.x = -obstacleSpeed;
		velocity.y = 0;
	}
	else if (random == 3) // il part d'en bas
	{
		max = terrainSize.x;
		min = 0;
		int randomX = min + (rand() % (int)(max - min + 1));
		position.x = (float)randomX;
		position.y = terrainSize.y + obstacleSize * 2.f;

		velocity.y = -obstacleSpeed;
		velocity.x = 0;
	}

	obstacles.push_back(new Obstacle(position, velocity, obstacleSize));
}

ObstacleManager::~ObstacleManager()
{
}