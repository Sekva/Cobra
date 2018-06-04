#ifndef PARTE_HPP
#define PARTE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Parte {
  private:
    int x;
    int y;
    sf::RectangleShape* pedaco;

  public:
    Parte* prox;
    Parte(int n);
    void repassarPos(int x, int y);
    Parte* getProx();
    sf::RectangleShape* getGraphs();
    void setProx(Parte* p);


};



#endif
