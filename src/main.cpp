#include <SFML/Graphics.hpp>

#include <iostream>
#include "config.h"
#include "comida.hpp"
#include "cobra.hpp"

int main() {
  sf::RenderWindow window(sf::VideoMode(L_JANELA, A_JANELA), "SFML works!");
  window.setFramerateLimit(10);

  Comida comida(1);
  Cobra cobra(1);


  std::vector<sf::Shape*> deseins;
  deseins = cobra.getGraphs();
  deseins.push_back(comida.getGraphs());
  cobra.setDir(DIR);


  int pontos = 0;

  sf::Text text();
  text.setString("asd");
  text.setFillColor(sf::Color::Red);

    while (window.isOpen()) {

      sf::Event event;
      while (window.pollEvent(event)) {
          if (event.type == sf::Event::Closed) {
            window.close();
          }
      }


    ///////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////CONTROLE
    ///////////////////////////////////////////////////////////////////////////////////////
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
      cobra.setDir(ESQ);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
      cobra.setDir(DIR);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
      cobra.setDir(CIMA);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
      cobra.setDir(BAIXO);
    }
    ///////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////

    if(cobra.getX() == comida.getX() && cobra.getY() == comida.getY()) {
      cobra.addParte();
      comida.rePos();
    }






      //PARTE DE UPDATEAR
      // comida.rePos();
      cobra.mover();
      ////////////////////////


      window.clear();
      //Desenha tutu
      window.draw(text);
      window.draw(*comida.getGraphs());
      for (int i = 0; i < cobra.getGraphs().size(); i++) {
        sf::Shape* asd = cobra.getGraphs()[i];
        window.draw(*asd);
      }
      //////////////////////
      window.display();
      // std::cout << window.getSize().y << '\n';
    }

  return 0;
}






















/*

// using namespace sf;

int main() {
const float FPS = 60.0f;
bool redraw = true;

sf::RenderWindow window(sf::VideoMode(L_JANELA, A_JANELA, 32), "Hello");
sf::Clock clock;
Comida comida(1);
sf::CircleShape* circle = comida.getGraphs();//(10.0f);
// circle.setOrigin(10.0f, 10.0f);
// circle.setPosition(0, 150.0f);

sf::Event ev;
while (window.isOpen()) {
if (clock.getElapsedTime().asSeconds() >= 1.0f / FPS) {
redraw = true;
comida.rePos();
clock.restart();
} else {
sf::Time sleepTime = sf::seconds((1.0f / FPS) - clock.getElapsedTime().asSeconds());
sleep(sleepTime);
}


//Handle input
while (window.pollEvent(ev)) {
if (ev.type == sf::Event::Closed) {
window.close();
}
}

//Draw stuff if ready
if (redraw) {
redraw = false;
window.clear(sf::Color(0, 0, 0));
window.draw(*circle);
window.display();
}
}
return 0;
}

*/
