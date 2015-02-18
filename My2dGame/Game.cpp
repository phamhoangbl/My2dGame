#include <SFML/Graphics.hpp>
#include <iostream>

int main(){

	sf::RenderWindow window;
	window.create(sf::VideoMode(640, 480), "SFML Application", sf::Style::Titlebar | sf::Style::Close);

	sf::Vector2u size(400, 400);
	std::cout << size.x << " " << size.y << std::endl;

	window.setSize(size);
	window.setTitle("My first 2d Game in SFML");
	window.setPosition(sf::Vector2i(400, 100));
	
	/*sf::CircleShape shape;
	shape.setRadius(40.f);
	shape.setPosition(100.f, 100.f);
	shape.setFillColor(sf::Color::Blue);*/

	while (window.isOpen()){

		sf::Event event;
		while (window.pollEvent(event)){

			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		//window.draw(shape);
		window.display();
	}

}