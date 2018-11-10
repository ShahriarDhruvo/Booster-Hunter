#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <bits/stdc++.h>

#define SC_WIDTH 1200
#define SC_HEIGHT 800

int main()
{
    // tp = Tiles position in y axis, (ra1, ra2, ra3, ra4, ra5, cra) = random number, k = trigger
    int ra1, ra2, ra3, ra4, ra5, cra;
    int tp=0, k, j, x, y, up=1;
    unsigned i;

    // Random Generators :
    ra1 = rand(); // These are for random tiles generate
    ra2 = rand();
    ra3 = rand();
    ra4 = rand();
    ra5 = rand();
    cra = rand(); // These are for random coin generate

    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(SC_WIDTH, SC_HEIGHT), "Booster Hunter ... ...");
    window.setFramerateLimit(60);

    // Background :
    sf::RectangleShape background(sf::Vector2f(SC_WIDTH, SC_HEIGHT));
    sf::Texture backgroundTexture;

    backgroundTexture.loadFromFile("D:\\My Programs\\In SFML\\Booster Hunter\\Textures\\Backgrounds\\Background1.png");
    background.setTexture(&backgroundTexture);

    // Hero :
    sf::Texture heroTexture;
    heroTexture.loadFromFile("D:\\My Programs\\In SFML\\Booster Hunter\\Textures\\Hero\\Hero.png");
    sf::Sprite hero;
    hero.setScale(1.3, 1.3);
    hero.setTexture(heroTexture);
    hero.setPosition(0, (ra1%320-20)+tp);
    sf::Vector2u hTextureSize = heroTexture.getSize();
    hTextureSize.x /= 6;
    hTextureSize.y /= 6;
    hero.setTextureRect(sf::IntRect(hTextureSize.x*0, hTextureSize.y*1, hTextureSize.x, hTextureSize.y));

    // Trap :
    sf::Texture trapTexture;
    trapTexture.loadFromFile("D:\\My Programs\\In SFML\\Booster Hunter\\Textures\\Trap\\Trap.png");
    sf::Sprite trap;
    trap.setScale(2, 2);
    trap.setTexture(trapTexture);
    std::vector <sf::Sprite> trapSprite(120, sf::Sprite(trapTexture));

    // Coin :
    sf::Texture coinTexture;
    coinTexture.loadFromFile("D:\\My Programs\\In SFML\\Booster Hunter\\Textures\\Collectibles\\Coin.png");
    sf::Sprite coin;
    coin.scale(0.12, 0.12);
    coin.setTexture(coinTexture);
    std::vector <sf::Sprite> coinSprite((cra%5+1), sf::Sprite(coinTexture));

    // Tile :
    sf::Texture tileTexture;
    sf::Sprite tile;

    tileTexture.loadFromFile("D:\\My Programs\\In SFML\\Booster Hunter\\Textures\\Tiles\\Tile.png");
    tile.setTexture(tileTexture);

    sf::Clock clock;
    sf::Event event;

    // Game Loop :
    while (window.isOpen())
    {
        sf::Time time = clock.getElapsedTime();
        if(time.asSeconds()>12) clock.restart();

        // Background :
//        if(time.asSeconds()>5) backgroundTexture.loadFromFile("D:\\My Programs\\In SFML\\Booster Hunter\\Textures\\Backgrounds\\Background2.png");
//        else backgroundTexture.loadFromFile("D:\\My Programs\\In SFML\\Booster Hunter\\Textures\\Backgrounds\\Background1.png");
//        background.setTexture(&backgroundTexture);

        // Tile :
//        if(time.asSeconds()>5) tileTexture.loadFromFile("D:\\My Programs\\In SFML\\Booster Hunter\\Textures\\Tiles\\Tile2.png");
//        else tileTexture.loadFromFile("D:\\My Programs\\In SFML\\Booster Hunter\\Textures\\Tiles\\Tile.png");
//        tile.setTexture(tileTexture);

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::EventType::Closed)
                window.close();
            if(event.type == sf::Event::EventType::KeyPressed) {
                if(event.key.code == sf::Keyboard::Left) {
                    hero.move(-5, 0);
                    if(up>5) up=1;
                    hero.setTextureRect(sf::IntRect(hTextureSize.x*up, hTextureSize.y*1, hTextureSize.x, hTextureSize.y));
                    up++;
                }
                if(event.key.code == sf::Keyboard::Right) {
                    hero.move(5, 0);
                    if(up>5) up=1;
                    hero.setTextureRect(sf::IntRect(hTextureSize.x*up, hTextureSize.y*1, hTextureSize.x, hTextureSize.y));
                    up++;
                }
            }
        }

        // Tiles movement :
        tp += 5;
        if(tp > 300 || k == 1) {
            tp -= 10;
            k = 1;
            if(tp == 0) k = 0;
        }

        window.clear();
        window.draw(background);

        // Drawing Tiles :
        for(i=1; i<=5; i++) {
            switch(i) {
                case 1:
                    tile.setScale(((ra5%3)/10.0)+1, 0.6);
                    tile.setPosition(0, (ra1%320+80)+tp);
                    break;
                case 2:
                    tile.setScale(((ra4%3)/10.0)+1, 0.6);
                    tile.setPosition(250, (ra2%320+80)+tp);
                    break;
                case 3:
                    tile.setScale(((ra3%3)/10.0)+1, 0.6);
                    tile.setPosition(500, (ra3%320+80)+tp);
                    break;
                case 4:
                    tile.setScale(((ra2%3)/10.0)+1, 0.6);
                    tile.setPosition(740, (ra4%320+80)+tp);
                    break;
                case 5:
                    tile.setScale(((ra1%3)/10.0)+1, 0.6);
                    tile.setPosition(975, (ra5%320+80)+tp);
                    break;
            }
            window.draw(tile);
        }

        // Drawing Coin :
        for(j=1; j<=5; j++) {
            switch(j) {
                case 1:
                    x = 10;
                    y = (ra1%320+50)+tp;
                    break;
                case 2:
                    x = 260;
                    y = (ra2%320+50)+tp;
                    break;
                case 3:
                    x = 510;
                    y = (ra3%320+50)+tp;
                    break;
                case 4:
                    x = 750;
                    y = (ra4%320+50)+tp;
                    break;
                case 5:
                    x = 985;
                    y = (ra5%320+50)+tp;
                    break;
            }
            for(i=0; i<coinSprite.size(); i++) {
                coin.setPosition(x+(i*30), y);
                window.draw(coin);
            }
        }

        // Drawing Trap :
        for(i=0; i<trapSprite.size(); i++) {
            trap.setPosition(-50+((signed)i*30), 720);
            window.draw(trap);
        }

        window.draw(hero);
        window.display();
    }

    return 0;
}
