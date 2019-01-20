#include "Menu.h"

Menu::Menu(int width, int height)
{
	font.loadFromFile("Font\\consolaz.ttf");
	font2.loadFromFile("Font\\comicbd.ttf");

	game_name.setFont(font2);
	game_name.setFillColor(sf::Color::Yellow);
	game_name.setString("Booster Hunter ... ...");
	game_name.setCharacterSize(54);
	game_name.setStyle(sf::Text::Bold);
	game_name.setPosition(width / 2 - 250, height / (Max_Number_Of_Items + 1) * 1);

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(width / 2 - 25, height / (Max_Number_Of_Items + 1) * 2 + 30);

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Controls");
	menu[1].setPosition(width / 2 - 25, height / (Max_Number_Of_Items + 1) * 3 - 20);

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Credits");
	menu[2].setPosition(width / 2 - 25, height / (Max_Number_Of_Items + 1) * 4 - 70);

	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::White);
	menu[3].setString("Exit");
	menu[3].setPosition(width / 2 - 25, height / (Max_Number_Of_Items + 1) * 5 - 120);

	selected_item_index = 0;
}


Menu::~Menu()
{
}

void Menu::Draw(sf::RenderWindow & window)
{
	window.draw(game_name);
	for (int i = 0; i < Max_Number_Of_Items; i++) {
		window.draw(menu[i]);
	}
}

void Menu::moveUp()
{
	if (selected_item_index - 1 >= 0) {
		menu[selected_item_index].setFillColor(sf::Color::White);
		selected_item_index--;
		menu[selected_item_index].setFillColor(sf::Color::Red);
	}
}

void Menu::moveDown()
{
	if (selected_item_index + 1 < Max_Number_Of_Items) {
		menu[selected_item_index].setFillColor(sf::Color::White);
		selected_item_index++;
		menu[selected_item_index].setFillColor(sf::Color::Red);
	}
}