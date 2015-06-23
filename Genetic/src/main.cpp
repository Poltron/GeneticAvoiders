#include <SFML/Graphics.hpp>
#include "ObstacleManager.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Droids");
	sf::Clock clock;

	ObstacleManager obstacles;
	obstacles.initialize(window.getSize(), 2.f, 100.f, 50.f);

	while (window.isOpen())
	{
		sf::Time elapsed = clock.restart();

		/* events */
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		/* update */

		obstacles.update(elapsed);

		/* draw */

		window.clear(sf::Color::White);

		obstacles.draw(window);

		window.display();
	}

	return 0;
}