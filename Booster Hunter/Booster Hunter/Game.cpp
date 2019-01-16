#include <ctime>
#include "Game.h"
#include "Player.h"
#include "Collectibles.h"
#include "Platform.h"
#include <iostream>

#define SC_WIDTH 1200
#define SC_HEIGHT 800

Game::Game()
{	
}

Game::~Game()
{
}

void Game::newGame()
{
	// tp = Tiles position in y axis, (ra1, ra2, ra3, ra4, ra5, cra) = random number, k's = triggers;
	int ra1, ra2, ra3, ra4, ra5, cra;
	int j, x, y, up = 1, jump;
	int tp = 0, k = 0, tp2 = 0, k2 = 0, tp3 = 0, k3 = 0, tp4 = 0, k4 = 0, tp5 = 0, k5 = 0;
	int y1 = 0, y2 = 0, y3 = 0, y4 = 0, y5 = 0;
	unsigned i;

	srand(time(NULL));

	// Random Generators :
	ra1 = rand(); // These are for random tiles generate
	ra2 = rand();
	ra3 = rand();
	ra4 = rand();
	ra5 = rand();
	cra = rand(); // These are for random coin generate

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(SC_WIDTH, SC_HEIGHT), "Booster Hunter ... ...", sf::Style::Default, settings);
	window.setFramerateLimit(60);

	// Background :
	sf::RectangleShape background(sf::Vector2f(SC_WIDTH, SC_HEIGHT));
	sf::Texture backgroundTexture;
	sf::Texture backgroundTexture2;
	sf::Texture backgroundTexture3;
	backgroundTexture.loadFromFile("Textures\\Backgrounds\\Background1.png");
	backgroundTexture2.loadFromFile("Textures\\Backgrounds\\Background2.png");
	backgroundTexture3.loadFromFile("Textures\\Backgrounds\\Background3.png");
	backgroundTexture.setSmooth(true);
	backgroundTexture2.setSmooth(true);
	backgroundTexture3.setSmooth(true);

	// Lifebar:
	sf::Texture lifeHeadTexture;
	sf::Texture lifeTexture;
	lifeHeadTexture.loadFromFile("Textures\\Hero\\HeroHead.png");
	lifeTexture.loadFromFile("Textures\\Hero\\Life.jpg");
	sf::Sprite lifeHead;
	lifeHead.setTexture(lifeHeadTexture);
	lifeHead.setPosition(-8, -5);
	lifeHeadTexture.setSmooth(true);
	sf::Sprite life;
	life.setTexture(lifeTexture);
	lifeTexture.setSmooth(true);
	life.setScale(0.07, 0.07);
	std::vector <sf::Sprite> lifeSprite(10, sf::Sprite(lifeTexture));

	// Player:
	sf::Texture playerTexture;
	playerTexture.loadFromFile("Textures\\Hero\\Hero.png");
	Player player(playerTexture, sf::Vector2u(6, 6), 0.125, 125, 200.0f);
	player.position(sf::Vector2f(5, ra1 % 320));

	// Trap :
	sf::Texture trapTexture;
	trapTexture.loadFromFile("Textures\\Trap\\Trap.png");
	sf::Sprite trap;
	trap.setScale(2, 2);
	trap.setTexture(trapTexture);
	trapTexture.setSmooth(true);
	std::vector <sf::Sprite> trapSprite(120, sf::Sprite(trapTexture));

	// Coin :
	sf::Texture coinTexture;
	coinTexture.loadFromFile("Textures\\Collectibles\\Coin.png");
	sf::Sprite coin;
	coin.scale(0.12, 0.12);
	coin.setTexture(coinTexture);
	coinTexture.setSmooth(true);
	std::vector <sf::Sprite> coinSprite((cra % 5 + 1), sf::Sprite(coinTexture));

	// Tile :
	sf::Texture tileTexture;
	sf::Texture tileTexture2;
	tileTexture.loadFromFile("Textures\\Tiles\\Tile.png");
	tileTexture2.loadFromFile("Textures\\Tiles\\Tile2.png");
	tileTexture.setSmooth(true);
	tileTexture2.setSmooth(true);

	// Platforms:
	std::vector <Platform> platforms;

	platforms.push_back(Platform(tileTexture, sf::Vector2f(150.0f, 55.0f)));
	platforms.push_back(Platform(tileTexture, sf::Vector2f(150.0f, 55.0f)));
	platforms.push_back(Platform(tileTexture, sf::Vector2f(150.0f, 55.0f)));
	platforms.push_back(Platform(tileTexture, sf::Vector2f(150.0f, 55.0f)));
	platforms.push_back(Platform(tileTexture, sf::Vector2f(150.0f, 55.0f)));

	sf::Clock clock;
	sf::Event event;
	float deltaTime;

	// Game Loop :
	while (window.isOpen())
	{
		// Handeling Times:
		sf::Time time = clock.getElapsedTime();
		if (time.asSeconds() > 16) clock.restart();
		deltaTime = clock.restart().asSeconds();

		// Setting up the Background:
		if (time.asSeconds() > 5 && time.asSeconds() < 10) background.setTexture(&backgroundTexture2);
		else if (time.asSeconds() > 10) background.setTexture(&backgroundTexture3);
		else background.setTexture(&backgroundTexture);

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::Closed)
				window.close();
		}

		// Tiles movement :
		tp += 5;
		if (y1 > 700 || k == 1) {
			tp -= 10;
			k = 1;
			if (y1 < 150) k = 0;
		}
		tp2 += 5;
		if (y2 > 700 || k2 == 1) {
			tp2 -= 10;
			k2 = 1;
			if (y2 < 150) k2 = 0;
		}
		tp3 += 5;
		if (y3 > 700 || k3 == 1) {
			tp3 -= 10;
			k3 = 1;
			if (y3 < 150) k3 = 0;
		}
		tp4 += 5;
		if (y4 > 700 || k4 == 1) {
			tp4 -= 10;
			k4 = 1;
			if (y4 < 150) k4 = 0;
		}
		tp5 += 5;
		if (y5 > 700 || k5 == 1) {
			tp5 -= 10;
			k5 = 1;
			if (y5 < 150) k5 = 0;
		}

		player.update(deltaTime);

		// Collision Ditaction :
		sf::Vector2f direction;

		for (Platform & platform : platforms) {
			if (platform.GetCollider().CheckCollision(player.GetCollider(), direction));
			player.OnCollision(direction);
		}


		window.clear();
		window.draw(background);

		// Setting up Tiles :
		for (i = 1; i <= 5; i++) {
			switch (i) {
			case 1:
				platforms[i - 1].scale(sf::Vector2f(((ra5 % 3) / 10.0) + 1, 0.6));
				y1 = (ra1 % 320 + 90) + tp;
				platforms[i - 1].position(sf::Vector2f(100, y1));
				break;
			case 2:
				platforms[i - 1].scale(sf::Vector2f(((ra4 % 3) / 10.0) + 1, 0.6));
				y2 = (ra2 % 320 + 90) + tp2;
				platforms[i - 1].position(sf::Vector2f(350, y2));
				break;
			case 3:
				platforms[i - 1].scale(sf::Vector2f(((ra3 % 3) / 10.0) + 1, 0.6));
				y3 = (ra3 % 320 + 90) + tp3;
				platforms[i - 1].position(sf::Vector2f(600, y3));
				break;
			case 4:
				platforms[i - 1].scale(sf::Vector2f(((ra2 % 3) / 10.0) + 1, 0.6));
				y4 = (ra4 % 320 + 90) + tp4;
				platforms[i - 1].position(sf::Vector2f(840, y4));
				break;
			case 5:
				platforms[i - 1].scale(sf::Vector2f(((ra1 % 3) / 10.0) + 1, 0.6));
				y5 = (ra5 % 320 + 90) + tp5;
				platforms[i - 1].position(sf::Vector2f(1075, y5));
				break;
			}
		}

		// Drawing Coin :
		for (j = 1; j <= 5; j++) {
			switch (j) {
			case 1:
				x = 10;
				y = (ra1 % 320 + 50) + tp;
				break;
			case 2:
				x = 260;
				y = (ra2 % 320 + 50) + tp2;
				break;
			case 3:
				x = 510;
				y = (ra3 % 320 + 50) + tp3;
				break;
			case 4:
				x = 750;
				y = (ra4 % 320 + 50) + tp4;
				break;
			case 5:
				x = 985;
				y = (ra5 % 320 + 50) + tp5;
				break;
			}
			for (i = 0; i < coinSprite.size(); i++) {
				coin.setPosition(x + 20 + (i * 30), y);
				window.draw(coin);
			}
		}

		// Drawing Trap:
		for (i = 0; i < trapSprite.size(); i++) {
			trap.setPosition(-50 + ((signed)i * 30), 720);
			window.draw(trap);
		}

		// Drawing Life:
		for (i = 0; i < lifeSprite.size(); i++) {
			life.setPosition(60 + ((signed)i * 30), 5);
			window.draw(life);
		}

		// Drawing Tiles:
		for (Platform & platform : platforms)
			platform.Draw(window);

		window.draw(lifeHead);
		player.Draw(window);
		window.display();
	}
}
