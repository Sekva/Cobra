#include "comida.hpp"
#include "config.h"

#include <stdlib.h>
#include <iostream>
#include <cstdlib>

Comida::Comida(int nu) {
  std::srand(std::time(nullptr));
  this->x = std::rand()/((RAND_MAX + 1u)/(L_JANELA / GRID));
  this->y = std::rand()/((RAND_MAX + 1u)/(A_JANELA / GRID));
  this->x = this->x * GRID;
  this->y = this->y * GRID;
  // sf::CircleShape shape(RAIO_COMIDA);
  this->circulo = new sf::CircleShape(RAIO_COMIDA);
  this->circulo->setPosition(this->x, this->y);
  this->circulo->setFillColor(sf::Color(255, 119, 0));

}

int Comida::getX() {
  return this->x;
}
int Comida::getY() {
  return this->y;
}
sf::CircleShape* Comida::getGraphs() {
  return this->circulo;
}

void Comida::rePos() {
  float x1 = std::rand()/((RAND_MAX + 1u)/(L_JANELA / 10));
  float y1 = std::rand()/((RAND_MAX + 1u)/(A_JANELA / 10));
  this->x = x1 * GRID;
  this->y = y1 * GRID;
  this->circulo->setPosition(this->x, this->y);
}

void Comida::setPos(float x, float y) {
  this->x = x;
  this->y = y;
  this->circulo->setPosition(this->x, this->y);
}
