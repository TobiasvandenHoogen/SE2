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
        bool x_overlap_right = within(   
        location.x, 
        other.location.x, 
        other.location.x + other.size.x );
        
        bool x_overlap_left = within( 
        location.x + size.x,
        other.location.x - other.size.x,
        other.location.x
    );

    bool x = x_overlap_right || x_overlap_left;
        
    bool y_overlap_top = within(
        location.y, 
        other.location.y, 
        other.location.y + other.size.y
    );

    bool y_overlap_bottom = within(
        location.y + (size.y * 2), 
        other.location.y - other.size.y, 
        other.location.y
    );
     
    bool y = y_overlap_top || y_overlap_bottom;
   
    
     return x && y;
    }
};

#endif 