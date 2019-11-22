#ifndef BOUNDARY_HPP
#define BOUNDARY_HPP

#include "drawable.hpp"

class boundary: public drawable{

public:
    sf::Vector2f bounce;
    boundary(sf::Vector2f position, sf::Vector2f size, sf::Vector2f bounce):
        drawable(position, size),
        bounce ( bounce )
        {}

    void draw( sf::RenderWindow & window ) const override{
		sf::RectangleShape wall;
        wall.setSize(sf::Vector2f(size));
        wall.setPosition(position);
        wall.setFillColor(sf::Color(0,0,255));
        window.draw(wall);


	}
};

#endif