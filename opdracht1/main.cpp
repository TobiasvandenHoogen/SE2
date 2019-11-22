#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "action.hpp"
#include "boundary.hpp"

int main( int argc, char *argv[] ){

	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };
	ball my_ball;
	boundary wall_1(sf::Vector2f{0,0}, sf::Vector2f{10.0, 480}, sf::Vector2f{-1, 1});
	boundary wall_2(sf::Vector2f{0,0}, sf::Vector2f{640, 10}, sf::Vector2f{1, -1});
	boundary wall_3(sf::Vector2f{630,0}, sf::Vector2f{10.0, 480}, sf::Vector2f{-1, 1});
	boundary wall_4(sf::Vector2f{0,470}, sf::Vector2f{640, 10}, sf::Vector2f{1, 1});

	// action actions[] = {
	// 	action( sf::Keyboard::Left,  [&](){ my_ball.move( sf::Vector2f( -1.0,  0.0 )); }),
	// 	action( sf::Keyboard::Right, [&](){ my_ball.move( sf::Vector2f( +1.0,  0.0 )); }),
	// 	action( sf::Keyboard::Up,    [&](){ my_ball.move( sf::Vector2f(  0.0, -1.0 )); }),
	// 	action( sf::Keyboard::Down,  [&](){ my_ball.move( sf::Vector2f(  0.0, +1.0 )); }),
	// 	action( sf::Mouse::Left,     [&](){ my_ball.jump( sf::Mouse::getPosition( window )); })
	//};

	std::array< drawable *, 5 > objects = { &my_ball, &wall_1, &wall_2, &wall_4};
	sf::Event event;	
	while (window.isOpen()) {
		// for( auto & action : actions ){
		// 	action();
		// }

		window.clear();
		//my_ball.draw( window );
		wall_1.draw(window);
		wall_2.draw(window);
		wall_3.draw(window);
		wall_4.draw(window);

		sf::sleep( sf::milliseconds( 20 ));

      for( auto & p : objects ){
         p->draw(window);
      }
      window.display();
      hwlib::wait_ms( 200 );
      for( auto & p : objects ){
          p->update();
      }
	
	  if( event.type == sf::Event::Closed ){
				window.close();
	}
			
	}

	std::cout << "Terminating application\n";
	return 0;
}

