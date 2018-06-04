#include "cobra.hpp"
#include "config.h"

#include <stdlib.h>
#include <iostream>
#include <cstdlib>


Parte::Parte(int n) {
  this->x = -GRID;
  this->y = -GRID;
  this->pedaco = new sf::RectangleShape(sf::Vector2f(GRID, GRID));
  this->pedaco->setPosition(this->x, this->y);
  this->pedaco->setFillColor(sf::Color::Red);
  this->prox = nullptr;
}

void Parte::repassarPos(int x, int y) {

  if(this->prox != nullptr) {
    this->prox->repassarPos(this->x, this->y);
  }

  this->x = x;
  this->y = y;
  this->pedaco->setPosition(this->x, this->y);
}

Parte* Parte::getProx() {
  return this->prox;
}

void Parte::setProx(Parte* p) {
  this->prox= p;
}

sf::RectangleShape* Parte::getGraphs() {
  return this->pedaco;
}
