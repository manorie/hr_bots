// Copyright 2018 Mehmet Cetin

#include "game.hpp"

namespace Game {
  void Board::Print() {
    for (int i = 0; i < sizeX * sizeY; i++) {
      if (i % sizeY == 0) {
        std::cout << "\n";
      }
      std::cout << space[i] << " ";
    }
    std::cout << std::endl;
  }

  bool Board::playerPresent() {
    for (int i = 0; i < sizeX * sizeY; i++) {
      if (space[i] == "b") {
        return true;
      }
    }
    return false;
  }

  void Board::PlacePlayer(int x, int y) {
    if (x < 0 || x >= sizeX || y < 0 || y >= sizeY) {
      throw OutOfBoundsException();
    }
    if (playerPresent()) {
      throw PlayerPresentException();
    }
    space[y*sizeX+x] = "b";
  }
}  // namespace Game
