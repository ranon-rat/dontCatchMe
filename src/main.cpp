#include <SFML/Graphics.hpp>

#include <iostream>

#include "beings.h"
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(500.0, 500.0), "SFML works!");
    sf::RectangleShape player(sf::Vector2f(200.0, 200.0));
    player.setFillColor(sf::Color::Blue);

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        player.setPosition(sf::Vector2f(rand() % 120 * 0.333, rand() % 120 * 0.333));
        window.clear();
        window.draw(player);
        window.display();
    }

    return 0;
}
