#ifndef BEAM_HPP
#define BEAM_HPP

#include "boundary.hpp"

class beam : public drawable{

public:
beam(sf::Vector2f location, sf::Vector2f size, sf::Vector2f bounce):
    drawable(location, size, bounce)
    {}

    void draw( sf::RenderWindow & window ) const override{
		sf::RectangleShape wall;
        wall.setSize(sf::Vector2f(size));
        wall.setPosition(location);
        wall.setFillColor(sf::Color(0,255,255));
        window.draw(wall);

    }

    void keyPressed(int y){
        location.y += y;
    }


};




#endif 