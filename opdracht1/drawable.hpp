#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
class drawable{
protected:
    sf::Vector2f location;
    sf::Vector2f size;
public:
    sf::Vector2f bounce;
    drawable(sf::Vector2f location, sf::Vector2f size, sf::Vector2f bounce):
        location( location ),
        size( size ),
        bounce( bounce )
    {}

    virtual void draw( sf::RenderWindow & window ) const = 0;
    virtual void update() {};
    virtual void interact(const drawable & other ) {};

    bool within( int x, int a, int b ){
        return ( x >= a ) && ( x <= b );
    }

    
    bool overlaps( const drawable & other ){
      bool x_overlap = within( 
      location.x, 
      other.location.x, 
      other.location.x + other.size.x
   ) || within( 
      other.location.x, 
      location.x, 
      location.x + size.x
   );
     
   bool y_overlap = within( 
      location.y, 
      other.location.y, 
      other.location.y + other.size.y
   ) || within( 
      other.location.y, 
      location.y, 
      location.y + size.y
   );
     return x_overlap && y_overlap;
    }
};

#endif 