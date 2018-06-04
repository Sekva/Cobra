#include "cobra.hpp"
#include "config.h"

#include <stdlib.h>
#include <iostream>
#include <cstdlib>

Cobra::Cobra(int n) {
  this->x = 20;
  this->y = 20;
  this->dir = BAIXO;
  this->teste = new sf::RectangleShape(sf::Vector2f(GRID, GRID));
  this->teste->setPosition(this->x, this->y);
  this->teste->setFillColor(sf::Color::Red);
  this->cabeca = new Parte(1);
}

int Cobra::getX() {
  return this->x;
}

int Cobra::getY() {
  return this->y;
}

std::vector<sf::Shape*> Cobra::getGraphs() {
  std::vector<sf::Shape*> v;

  Parte* x = this->cabeca;

  while (x != nullptr) {
    v.push_back(x->getGraphs());
    x = x->getProx();
  }
  
  return v;
}

void Cobra::mover() {
  switch (this->dir) {
    case CIMA:
      this->y -= GRID;
      if(this->y < -GRID) {
        this->y = A_JANELA;
      }
      this->cabeca->repassarPos(this->x, this->y);
      break;
    case BAIXO:
      this->y += GRID;
      if(this->y > A_JANELA) {
        this->y = 0;
      }
      this->cabeca->repassarPos(this->x, this->y);
      break;
    case ESQ:
      this->x -= GRID;
      if(this->x < -GRID) {
        this->x = L_JANELA;
      }
      this->cabeca->repassarPos(this->x, this->y);
      break;
    case DIR:
      this->x += GRID;
      if(this->x > L_JANELA) {
        this->x = 0;
      }
      this->cabeca->repassarPos(this->x, this->y);
      break;
  }



    if(this->x > L_JANELA) {
      this->x = GRID;
    }

    if(this->y > A_JANELA) {
      this->y = GRID;
    }



}

void Cobra::setDir(int n) {
  this->dir = n;
}

void Cobra::addParte() {
  Parte* p =  new Parte(1);

  Parte* x = this->cabeca;
  Parte* y = this->cabeca->getProx();

  while(y != nullptr) {
    x = y;
    y = y->getProx();
  }

  x->setProx(p);
}
