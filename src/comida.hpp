#ifndef COMIDA_HPP
#define COMIDA_HPP

#include "config.h"
#include <SFML/Graphics.hpp>

class Comida {

  private:
    float x;
    float y;
    sf::CircleShape* circulo;


  public:
    Comida(int nu);
    int getX();
    int getY();
    sf::CircleShape* getGraphs();
    void rePos();
    void setPos(float x, float y);


};





#endif
