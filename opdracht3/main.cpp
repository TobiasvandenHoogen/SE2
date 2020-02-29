#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "fstream"

int main(){

      std::ifstream file("shapes.txt");
      file.open("shapes.txt");
      try {
         for(;;){
            screen_objects.add( screen_object_read( input ));
         }
      } catch ( end_of_file ){
         // do nothing
      } catch ( std::exception & problem ){
         std::cout << problem.what();
      }


    sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "factory" };
    while (window.isOpen()) {
		sf::Event event;
		if( window.pollEvent(event) ){
			if (event.type == sf::Event::Closed) {
				window.close();
			}

        }  
        sf::sleep(sf::milliseconds(20));         
    }
return 0;
}

