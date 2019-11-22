#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <SFML/Graphics.hpp>

class drawable{
protected:
    sf::Vector2f position;
    sf::Vector2f size;
public:
    drawable(sf::Vector2f position, sf::Vector2f size): 
        position( position ),
        size( size )
        {}
    virtual void draw( sf::RenderWindow & window ) const;

    bool within( int x, int a, int b ){
   return ( x >= a ) && ( x <= b );
}

   virtual void update(drawable & other);

bool overlaps( const drawable & other ){
   
   bool x_overlap = within( 
      position.x, 
      other.position.x, 
      other.position.x + other.size.x
   ) || within( 
      other.position.x, 
      position.x, 
      position.x + size.x
   );
     
   bool y_overlap = within( 
      position.y, 
      other.position.y, 
      other.position.y + other.size.y
   ) || within( 
      other.position.y, 
      position.y, 
      position.y + size.y
   );
   
   return x_overlap && y_overlap;
}
};

#endif 