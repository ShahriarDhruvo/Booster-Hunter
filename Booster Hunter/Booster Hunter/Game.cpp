#include <ctime>
#include <iostream>
#include "Game.h"
#include "Player.h"
#include "Collectibles.h"
#include "Platform.h"
#include "Villain.h"
#include "Score.h"
#include "Bullet.h"
#include "Life.h"
#include "Trap.h"

#define SC_WIDTH 1200
#define SC_HEIGHT 800

Game::Game()
{	
}

Game::~Game()
{
}

sf::Vector2f Game::coinRandom(int i)
{
	srand(i);
	sf::Clock clock;
	clock.restart();
	int cra, ra5, ra1, ra3, h;
	cra = rand();
	ra5 = rand();
	ra1 = rand();
	ra3 = rand();
	h = rand();
	float x = abs(((int)(2 * (cra*cra) + 3 * (ra5*ra5) - 5 * h - 0.9*(h*h))) % 1090) + 100;
	float y = abs(((int)(9 * (ra3*ra3) - 8 * (ra1*ra1) - 12 * h + 0.67*(h*h))) % 550) + 100;
	i *= 43 % i;
	return sf::Vector2f(x, y);
}

int Game::newGame()
{
	// tp = Tiles position in y axis, (ra1, ra2, ra3, ra4, ra5, cra) = random number, k's = triggers
	int ra1, ra2, ra3, ra4, ra5, cra;
	int tp = 0, k = 0, tp2 = 0, k2 = 0, tp3 = 0, k3 = 0, tp4 = 0, k4 = 0, tp5 = 0, k5 = 0;
	int y1 = 0, y2 = 0, y3 = 0, y4 = 0, y5 = 0;
	float x = 0, y = 0;
	unsigned i;

	srand(time(NULL));

	// Random Generators:
	ra1 = rand(); // These are for random tiles generate
	ra2 = rand();
	ra3 = rand();
	ra4 = rand();
	ra5 = rand();
	cra = rand(); // This is for random coin generate

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(SC_WIDTH, SC_HEIGHT), "Booster Hunter ... ...", sf::Style::Default, settings);
	window.setFramerateLimit(60);

	// Background:
	sf::RectangleShape background(sf::Vector2f(SC_WIDTH, SC_HEIGHT));
	sf::Texture backgroundTexture;
	sf::Texture backgroundTexture2;
	sf::Texture backgroundTexture3;
	if (!backgroundTexture.loadFromFile("Textures\\Backgrounds\\Background1.png")) return EXIT_FAILURE;
	if (!backgroundTexture2.loadFromFile("Textures\\Backgrounds\\Background2.png")) return EXIT_FAILURE;
	if (!backgroundTexture3.loadFromFile("Textures\\Backgrounds\\Background1.png")) return EXIT_FAILURE;
	backgroundTexture.setSmooth(true);
	backgroundTexture2.setSmooth(true);
	backgroundTexture3.setSmooth(true);

	// Life Head bar:
	sf::Texture lifeHeadTexture;
	if (!lifeHeadTexture.loadFromFile("Textures\\Hero\\HeroHead.png")) return EXIT_FAILURE;
	sf::Sprite lifeHead;
	lifeHead.setTexture(lifeHeadTexture);
	lifeHead.setPosition(-8, -5);
	sf::Sprite lifeHead2;
	lifeHead2.setTexture(lifeHeadTexture);
	lifeHead2.setPosition(1208, -5);
	lifeHead2.setScale(-1, 1);

	// Lifebar:
	sf::Texture lifeTexture;
	if (!lifeTexture.loadFromFile("Textures\\Hero\\Life.jpg")) return EXIT_FAILURE;
	Life life(lifeTexture);
	Life life2(lifeTexture);

	// Player:
	sf::Texture playerTexture;
	if (!playerTexture.loadFromFile("Textures\\Hero\\Hero.png")) return EXIT_FAILURE;
	Player player(playerTexture, sf::Vector2u(6, 6), 0.125, 125, 200.0f);
	player.position(sf::Vector2f(5, ra1 % 320));

	// Trap :
	sf::Texture trapTexture;
	if (!trapTexture.loadFromFile("Textures\\Trap\\Trap.png")) return EXIT_FAILURE;
	std::vector <Trap> traps;
	for (int h = 0; h < 120; h++)
		traps.push_back(Trap(trapTexture));

	// Coins :
	sf::Texture coinTexture;
	if (!coinTexture.loadFromFile("Textures\\Collectibles\\Coin.png")) return EXIT_FAILURE;
	std::vector <Collectibles> coins;
	for (int h = 0; h < 25; h++) {
		sf::Vector2f position = coinRandom(rand());
		coins.push_back(Collectibles(coinTexture, sf::Vector2f(45, 45), sf::Vector2f(0.65, 0.65), sf::Vector2f(position)));
	}

	// Tile :
	sf::Texture tileTexture;
	sf::Texture tileTexture2;
	if (!tileTexture.loadFromFile("Textures\\Tiles\\Tile.png")) return EXIT_FAILURE;
	if (!tileTexture2.loadFromFile("Textures\\Tiles\\Tile2.png")) return EXIT_FAILURE;
	std::vector <Platform> platforms;
	for (int h=0; h<5; h++)
		platforms.push_back(Platform(tileTexture));

	// Villain:
	sf::Texture villtexture;
	if (!villtexture.loadFromFile("Textures\\Villains\\HellHound.png")) return EXIT_FAILURE;
	Villain villain(villtexture, sf::Vector2u(6, 6), 0.125, 125, 200.0f);
	villain.position(sf::Vector2f(1100, ra5 % 320));

	// Hero's Bullet:
	sf::Texture hBullTexture;
	if (!hBullTexture.loadFromFile("Textures\\Bullets\\BlueFox'sPower.png")) return EXIT_FAILURE;
	std::vector <Bullet> hBullVec;
	bool isHFiring = false;

	// Villain's Bullet:
	sf::Texture vBullTexture;
	if (!vBullTexture.loadFromFile("Textures\\Bullets\\HellHoun'sPower.png")) return EXIT_FAILURE;
	std::vector <Bullet> vBullVec;
	bool isVFiring = false;

	// Score:
	Score hScore(sf::Vector2f(135, 50), sf::Vector2f(10, 50));
	Score vScore(sf::Vector2f(1130, 50), sf::Vector2f(1000, 50));
	
	// Clock & Events:
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
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
				isHFiring = true;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				isVFiring = true;
		}

		// Tiles movement :
		tp += 5;
		if (y1 > 700 || k == 1) {
			tp -= 10;
			k = 1;
			if (y1 < 200) k = 0;
		}
		tp2 += 5;
		if (y2 > 700 || k2 == 1) {
			tp2 -= 10;
			k2 = 1;
			if (y2 < 200) k2 = 0;
		}
		tp3 += 5;
		if (y3 > 700 || k3 == 1) {
			tp3 -= 10;
			k3 = 1;
			if (y3 < 200) k3 = 0;
		}
		tp4 += 5;
		if (y4 > 700 || k4 == 1) {
			tp4 -= 10;
			k4 = 1;
			if (y4 < 200) k4 = 0;
		}
		tp5 += 5;
		if (y5 > 700 || k5 == 1) {
			tp5 -= 10;
			k5 = 1;
			if (y5 < 200) k5 = 0;
		}

		// Setting up Tiles :
		for (i = 1; i <= 5; i++) {
			switch (i) {
			case 1:
				y1 = (ra1 % 320 + 90) + tp;
				platforms[i - 1].position(sf::Vector2f(100, y1));
				break;
			case 2:
				y2 = (ra2 % 320 + 90) + tp2;
				platforms[i - 1].position(sf::Vector2f(350, y2));
				break;
			case 3:
				y3 = (ra3 % 320 + 90) + tp3;
				platforms[i - 1].position(sf::Vector2f(600, y3));
				break;
			case 4:
				y4 = (ra4 % 320 + 90) + tp4;
				platforms[i - 1].position(sf::Vector2f(840, y4));
				break;
			case 5:
				y5 = (ra5 % 320 + 90) + tp5;
				platforms[i - 1].position(sf::Vector2f(1075, y5));
				break;
			}
		}

		// Collision Ditaction :
		sf::Vector2f direction;
		// For Tiles:
		for (Platform & platform : platforms) {
			if (platform.GetCollider().CheckCollision(player.GetCollider(), direction)) {
				player.OnCollision(direction);
				player.yPosition(platform.getPosition());
			}
			if (platform.GetCollider().CheckCollision(villain.GetCollider(), direction)) {
				villain.OnCollision(direction);
				villain.yPosition(platform.getPosition());
			}
		}
		// For Coins:
		for (Collectibles & coin : coins) {
			if (coin.GetCollider().CheckCollision(player.GetCollider(), direction)) {
				coin.move(0.0f, INT_MAX);
				hScore.addh(10);
			}
			if (coin.GetCollider().CheckCollision(villain.GetCollider(), direction)) {
				coin.move(0.0f, INT_MAX);
				vScore.addv(10);
			}
		}

		player.update(deltaTime);
		villain.update(deltaTime);

		window.clear();

		// Setting up Hero Bullet:
		if (isHFiring == true) {
			Bullet hBullet(hBullTexture, sf::Vector2f(50, 20), sf::Vector2f(1, 1));
			hBullet.position(player.getPosition());
			hBullVec.push_back(hBullet);
			isHFiring = false;
		}

		// Setting up Villain Bullet:
		if (isVFiring == true) {
			Bullet vBullet(vBullTexture, sf::Vector2f(50, 20), sf::Vector2f(1, 1));
			vBullet.position(villain.getPosition());
			vBullVec.push_back(vBullet);
			isVFiring = false;
		}

		// Bullet Collision Ditaction:
		for (int i = 0; i < vBullVec.size(); i++) {
			if (player.chkCollision(vBullVec[i]))
				life.smash1();
		}

		// Drawing Background:
		window.draw(background);

		// Drawing Tiles:
		for (Platform & platform : platforms)
			platform.Draw(window);

		// Drawing Coin :
		for (Collectibles & coin : coins)
			coin.Draw(window);

		// Setting up Trap:
		int z = 0;
		for (Trap & trap : traps) {
			if (player.GetCollider().CheckCollision(trap.GetCollider(), direction))
				life.smash1();
			if (villain.GetCollider().CheckCollision(trap.GetCollider(), direction))
				life.smash2();
			trap.setPosition(sf::Vector2f(-32 + ((signed)z * 30), 720));
			trap.Draw(window);
			z++;
		}

		// Drawing Life:
		life.Draw1(window);
		life2.Draw2(window);
		window.draw(lifeHead);
		window.draw(lifeHead2);

		// Drawing Player:
		player.Draw(window);

		// Drawing Villain:
		villain.Draw(window);

		// Drawing Score:
		hScore.Draw(window);
		vScore.Draw(window);

		// Drawing Hero Bullet:
		for (int i = 0; i < hBullVec.size(); i++) {
			hBullVec[i].Draw(window);
			hBullVec[i].fire(5, player.direction());
		}

		// Drawing Villain Bullet:
		for (int i = 0; i < vBullVec.size(); i++) {
			vBullVec[i].Draw(window);
			vBullVec[i].fire(5, villain.direction());
		}

		if (hScore.chkGameOver()) window.close();

		window.display();
	}
}
