#include <SFML/Graphics.hpp>
#include <iostream>

void drawShape(sf::RenderWindow &window);
void setUpEslapseTime();
void setUpTimer();

int main(){

	sf::RenderWindow window;
	window.create(sf::VideoMode(640, 480), "SFML Application", sf::Style::Titlebar | sf::Style::Close);

	sf::Vector2u size(400, 400);
	std::cout << size.x << " " << size.y << std::endl;

	window.setSize(size);
	window.setTitle("My first 2d Game in SFML");
	window.setPosition(sf::Vector2i(400, 100));

	while (window.isOpen()){

		window.clear();

		sf::Event event;
		while (window.pollEvent(event)){

			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (window.waitEvent(event))
		{
			std::cout << "Event actived" << std::endl;
		}

		//drawShape(window);
		//setUpEslapseTime(clock, time);
		//setUpTimer();

		window.display();
	}
	
}

void drawShape(sf::RenderWindow &window)
{
	sf::CircleShape shape;

	shape.setRadius(40.f);
	shape.setPosition(100.f, 100.f);
	shape.setFillColor(sf::Color::Blue);
	window.draw(shape);
}

void setUpEslapseTime()
{
	sf::Clock clock;
	sf::Time time = clock.getElapsedTime();
	std::cout << time.asSeconds() << std::endl;
	clock.restart();
}

void setUpTimer()
{
	sf::Time time = sf::seconds(2);
	time += sf::milliseconds(200);
	std::cout << time.asMilliseconds() << std::endl;
}