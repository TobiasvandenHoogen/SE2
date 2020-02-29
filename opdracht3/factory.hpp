#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string> 

class factory{
public:
   screen_object * screen_object_read( std::ifstream & input ){
   sf::Vector2f position;
   std::string name;
   input >> position >> name;

   if( name == "CIRCLE" ){
      . . .
      return new circle( . . . );

   } else if( name == "RECTANGLE" ){
      . . .
      return new rectangle( . . . );

   } else if( name == "PICTURE" ){
      . . .
      return new picture( . . . );

   } else if( name == "" ){
      throw end_of_file();
   }

   throw unknown_shape( name );
}
};
