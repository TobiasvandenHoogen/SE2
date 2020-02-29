#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ball.hpp"
#include "boundary.hpp"
#include "beam.hpp"

int main( int argc, char *argv[] ){

	sf::sleep(sf::milliseconds(1));  
	//initialize sound     
	sf::SoundBuffer buffer;
	if(!buffer.loadFromFile("floop2_x.wav")){
		std::cout << "error" << std::endl;
	}
	sf::Sound sound;
	sound.setBuffer( buffer );
	sound.play();
	
	//declare window and objects
	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "ping pong game" };
	
	static ball my_ball(sound);
	static beam leftbeamX(sf::Vector2f{25, 100}, sf::Vector2f{25, 150}, sf::Vector2f{-1, 1});
	static beam leftbeamY(sf::Vector2f{25, 100}, sf::Vector2f{24, 150}, sf::Vector2f{1, -1});	
	static beam rightbeamX(sf::Vector2f{590, 100}, sf::Vector2f{25, 150}, sf::Vector2f{-1, 1});
	static beam rightbeamY(sf::Vector2f{591, 100}, sf::Vector2f{24, 150}, sf::Vector2f{1, -1});
	static boundary top(sf::Vector2f{0,0}, sf::Vector2f{640, 10}, sf::Vector2f{1, -1});
	static boundary right(sf::Vector2f{630,0}, sf::Vector2f{10, 480}, sf::Vector2f{-1, 1});
	static boundary bottom(sf::Vector2f{0,470}, sf::Vector2f{640, 10}, sf::Vector2f{1, -1});
	static boundary left(sf::Vector2f{0,0}, sf::Vector2f{10, 480}, sf::Vector2f{-1, 1});


	//put objects in array
	drawable *objects[]= {&my_ball, &top, &right, &bottom, &left, &leftbeamX, &leftbeamY, &rightbeamX, &rightbeamY};


	while (window.isOpen()) {
		window.clear();
		sf::Event event;
		if( window.pollEvent(event) ){
			if (event.type == sf::Event::Closed) {
				window.close();
			}

		if(event.type == sf::Event::KeyPressed){
			if (event.key.code == sf::Keyboard::W) {
				leftbeamX.move(-10);
				leftbeamY.move(-10);
			}
			if (event.key.code == sf::Keyboard::S) {
				leftbeamX.move(10);
				leftbeamY.move(10);
			}

			if (event.key.code == sf::Keyboard::Up) {
				rightbeamX.move(-10);
				rightbeamY.move(-10);
			}
			if (event.key.code == sf::Keyboard::Down) {
				rightbeamX.move(10);
				rightbeamY.move(10);
			}
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

	}

	return 0;
}

