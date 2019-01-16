#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Game.h"
#include "Menu.h"

#define SC_WIDTH 1200
#define SC_HEIGHT 800

std::string readText(const char* fileName)
{
	std::ifstream file(fileName);
	return std::string(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
}

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(SC_WIDTH, SC_HEIGHT), "Booster Hunter ... ...", sf::Style::Default, settings);
	Menu menu(SC_WIDTH, SC_HEIGHT);
	
	sf::Text credits;
	sf::Font font;
	font.loadFromFile("Font\\comicbd.ttf");
	credits.setFont(font);
	credits.setFillColor(sf::Color::Green);
	credits.setString(readText("credits.txt"));
	credits.setPosition(SC_WIDTH / 2 - 200, SC_HEIGHT / 2 - 150);

	sf::Text control;
	sf::Font font2;
	font2.loadFromFile("Font\\comicbd.ttf");
	control.setFont(font2);
	control.setFillColor(sf::Color::Green);
	control.setString(readText("controls.txt"));
	control.setPosition(SC_WIDTH / 2 - 200, SC_HEIGHT / 2 - 120);

	Game play;

	while(window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::KeyReleased:
				switch (event.key.code) {
				case sf::Keyboard::Up:
					menu.moveUp();
					break;
				case sf::Keyboard::Down:
					menu.moveDown();
					break;
				case sf::Keyboard::Return:
					switch (menu.getPressedItem()) {
					case 0:
						window.close();
						play.newGame();
						break;
					case 1:
						while (window.isOpen()) {
							while (window.pollEvent(event)) {
								if (event.type == sf::Event::EventType::Closed)
									window.close();
							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
								break;
							window.clear();
							window.draw(control);
							window.display();
						}
						break;
					case 2:
						while (window.isOpen()) {
							while (window.pollEvent(event)) {
								if (event.type == sf::Event::EventType::Closed)
									window.close();
							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
								break;
							window.clear();
							window.draw(credits);
							window.display();
						}
						break;
					case 3:
						window.close();
						break;
					}
					break;
				case sf::Event::Closed:
					window.close();
					break;
				}
			}
		}
		window.clear();
		menu.Draw(window);
		window.display();
	}
	return 0;
}
