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

  brd.Print();
  return 0;
}
