#ifndef _BALL_HPP
#define _BALL_HPP


#include "drawable.hpp"
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class ball : public drawable{
private:
    sf::Vector2f speed = {-1, 1};
    sf::Sound & sound;

public:

	ball(sf::Sound & sound):
        sound( sound ),
        drawable(sf::Vector2f{320, 260}, sf::Vector2f{30, 30}, sf::Vector2f{0, 0})
        {}


	void draw( sf::RenderWindow & window ) const override{
        	sf::CircleShape circle;
	        circle.setRadius( size.x );
            circle.setFillColor(sf::Color{0, 0, 255});
	        circle.setPosition( location );
	        window.draw( circle );
    }

    void update() override{
        location.x += speed.x;
        location.y += speed.y;
    }

    //check if ball overlaps 
    void interact(const drawable & other) override{
        if( this != & other){
        if( overlaps( other )){
            speed.x *= other.bounce.x;
            speed.y *= other.bounce.y;
            playSound(sound);
         }
      }
    }


    void playSound(sf::Sound& sound){
    	sound.play();
    }
    

};

#endif