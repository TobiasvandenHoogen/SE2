#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ball.hpp"
#include "boundary.hpp"
#include "beam.hpp"

int main( int argc, char *argv[] ){

	sf::sleep(sf::milliseconds(1));      
	sf::SoundBuffer buffer;
	if(!buffer.loadFromFile("floop2_x.wav")){
		std::cout << "error" << std::endl;
	}
	sf::Sound sound;
	sound.setBuffer( buffer );
	sound.play();

	bool a = true;

	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };
	static ball my_ball(sound);
	static beam leftbeam(sf::Vector2f{25, 100}, sf::Vector2f{25, 150}, sf::Vector2f{-1, 1});
	static beam rightbeam(sf::Vector2f{590, 100}, sf::Vector2f{25, 150}, sf::Vector2f{-1, 1});
	static boundary top(sf::Vector2f{0,0}, sf::Vector2f{640, 10}, sf::Vector2f{1, -1});
	static boundary right(sf::Vector2f{630,0}, sf::Vector2f{640, 480}, sf::Vector2f{-1, 1});
	static boundary bottom(sf::Vector2f{0,470}, sf::Vector2f{640, 480}, sf::Vector2f{1, -1});
	static boundary left(sf::Vector2f{0,0}, sf::Vector2f{10, 480}, sf::Vector2f{-1, 1});


	drawable *objects[]= {&my_ball, &top, &right, &bottom, &left, &leftbeam, &rightbeam};


	while (window.isOpen()) {
		window.clear();
		sf::Event event;
		if( window.pollEvent(event) ){
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		for( auto & p : objects ){
         p->draw(window);
      }
      	for( auto & p : objects ){
          p->update();
      	}
      	for( auto & p : objects ){
         	for( auto & other : objects ){
            	p->interact( *other );
         	} 
      	}
		window.display();

		sf::sleep(sf::milliseconds(1));

	}
	return 0;
}

