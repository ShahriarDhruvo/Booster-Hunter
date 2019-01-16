#pragma once
#include <SFML/Graphics.hpp>

#define Max_Number_Of_Items 4

class Menu
{
public:
	Menu(int width, int height);
	~Menu();
	void moveUp();
	void moveDown();
	void Draw(sf::RenderWindow & window);
	int getPressedItem() { return selected_item_index; }
private:
	int selected_item_index;
	sf::Font font;
	sf::Font font2;
	sf::Font font3;
	sf::Text menu[Max_Number_Of_Items];
	sf::Text game_name;
};

