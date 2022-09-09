//Adam Baptista

#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Adam_BaptistaPS0");
	sf::CircleShape shape(50.f);
	shape.setFillColor(sf::Color::Red);

	sf::Texture texture;
	if (!texture.loadFromFile("sprite.jpg"))
		return EXIT_FAILURE;
	shape.setTexture(&texture);
	shape.setPosition(500, 500);
	shape.setOrigin(25, 25);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				shape.setFillColor(sf::Color::Blue);
				shape.move(-5, 0);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				shape.setFillColor(sf::Color::Green);
				shape.move(5, 0);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				shape.setFillColor(sf::Color::Red);
				shape.move(0, -5);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				shape.setFillColor(sf::Color::Yellow);
				shape.move(0, 5);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				shape.setPosition(500, 500);
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
			else
				shape.setFillColor(sf::Color::White);
			
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
	
	return 0;
}
