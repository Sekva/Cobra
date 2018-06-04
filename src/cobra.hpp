#ifndef COBRA_HPP
#define COBRA_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "parte.hpp"


class Cobra {

  private:
    int x;
    int y;
    sf::RectangleShape* teste;
    Parte* cabeca;
    int dir;

  public:
    Cobra(int n);
    int getX();
    int getY();
    std::vector<sf::Shape*> getGraphs();
    void mover();
    void setDir(int n);
    void addParte();


};





#endif
