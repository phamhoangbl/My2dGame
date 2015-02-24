#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

void DiplayImages(sf::RenderWindow &window);
void setupMouseEvent(sf::Event &even);
void drawShape(sf::RenderWindow &window);
void setupKeyBoardEvent(sf::Event &even, std::string &message, std::string &display, int &index);
void setupWaitEvent(sf::RenderWindow &window, sf::Event &even);
void setupKeyBoardEvent(sf::Event &even, sf::String &message, sf::String &display, sf::Int16 &index);
void setUpEslapseTime();
void setUpTimer();

int main(){

	sf::RenderWindow window;
	window.create(sf::VideoMode(640, 480), "SFML Application", sf::Style::Titlebar | sf::Style::Close);

	sf::Vector2u size(400, 400);
	std::cout << size.x << " " << size.y << std::endl;

	window.setSize(size);
	window.setTitle("My first 2d Game in SFML");
	window.setPosition(sf::Vector2i(900, 100));

	/*std::string message = "Hello, my name is John, make SFML simple and easy";
	std::string display = "";
	int index = 0;*/


	window.clear();

	while (window.isOpen()){

		sf::Event event;
		while (window.pollEvent(event)){

			if (event.type == sf::Event::Closed)
				window.close();

			//setupKeyBoardEvent(event, message, display, index);
			//setupMouseEvent(event);
		}

		//setupWaitEvent(window, event);
		//drawShape(window);
		//setUpEslapseTime(clock, time);
		//setUpTimer();
		DiplayImages(window);
		window.display();
	}
	
}


void DiplayImages(sf::RenderWindow &window)
{
	sf::Texture pTextTure;
	sf::Sprite playerImage;

	if (!pTextTure.loadFromFile("image.png", sf::IntRect(32, 0, 32, 32)))
	{
		std::cout << "Could not load player image" << std::endl;
	}
	playerImage.setTexture(pTextTure);
	//playerImage.setPosition(100, 100);

	window.draw(playerImage);
}

void setupMouseEvent(sf::Event &even)
{
	switch (even.type)
	{
		case sf::Event::MouseEntered:
		{
			std::cout << "In bounds of game screen" << std::endl;
			break;
		}
		case sf::Event::MouseLeft:
		{	
			std::cout << "Out bounds of game screen" << std::endl;
			break;
		}
		case sf::Event::MouseMoved:
		{
			std::cout << "X: " << even.mouseMove.x << " Y: " + even.mouseMove.y << std::endl;
			break;
		}
		case sf::Event::MouseButtonPressed:
		{
			if (even.mouseButton.button == sf::Mouse::Button::Left)
			{
				std::cout << "X: " << even.mouseButton.x + " Y: " + even.mouseButton.y;
			}
			break;
		}
		case sf::Event::MouseWheelMoved:
		{
			std::cout << "Delta: " << even.mouseWheel.delta << std::endl;
			std::cout << "mouse wheel x: " << even.mouseWheel.x + "mouse wheel y: " << even.mouseWheel.y;
			break;
		}
	}
}

void setupKeyBoardEvent(sf::Event &even, std::string &message, std::string &display, int &index)
{
	if (even.type == sf::Event::KeyPressed)
	{
		if (even.key.code == sf::Keyboard::Return || even.key.code == sf::Keyboard::A)
		{
			display += message[index];

			index++;
			system("cls");
			std::cout << display;
		}
	}
}

void setupWaitEvent(sf::RenderWindow &window, sf::Event &event)
{
	if (window.waitEvent(event))
	{
		std::cout << "Event actived" << std::endl;
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