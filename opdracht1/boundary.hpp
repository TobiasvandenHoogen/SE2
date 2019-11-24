#ifndef BOUNDARY_HPP
#define BOUNDARY_HPP

#include "drawable.hpp"
class boundary: public drawable{
public:
    boundary(sf::Vector2f location, sf::Vector2f size, sf::Vector2f bounce):
        drawable(location, size, bounce)
        {}

    void draw( sf::RenderWindow & window ) const override{
		sf::RectangleShape wall;
        wall.setSize(sf::Vector2f(size));
        wall.setPosition(location);
        wall.setFillColor(sf::Color(0,255,0));
        window.draw(wall);
    }

};



#endif