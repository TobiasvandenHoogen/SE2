#ifndef _BALL_HPP
#define _BALL_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"

class ball : public drawable{
private:
	sf::Vector2f speed{1, 1};

public:
	ball():
		drawable( sf::Vector2f{ 320.0, 240.0 }, sf::Vector2f{30.0, 30.0} )
		{}


	void draw( sf::RenderWindow & window ) const override{
		sf::CircleShape circle;
		circle.setRadius(size.x);
		circle.setPosition(position);
		window.draw(circle);
	}


	void update(drawable & other) override{
		speed *= other.bounce;
		position + speed;
	}

};
#endif
