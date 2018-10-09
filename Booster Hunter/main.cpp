#include "SFML/Graphics.hpp"

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(640, 480), "Booster Hunter ... ...");
    CircleShape shape(100.0f, 5);
    shape.setFillColor(Color::Red);

    while (window.isOpen())
    {
        Event evnt;
        while (window.pollEvent(evnt))
        {
            if (evnt.type == Event::Closed)
                window.close();
        }

        window.clear(Color::Green);
        window.draw(shape);
        window.display();
    }

    return 0;
}
