#include <iostream>
#include <exception>
#include "game.hpp"

int main() {
  Game::Board brd = Game::Board(10, 10);
  try {
    brd.PlacePlayer(5, 4);
  } catch(std::exception& e) {
    std::cout << e.what();
  }

  brd.CastDirt(25);

  brd.Print();
  return 0;
}
