// Copyright 2018 Mehmet Cetin

#include "game.hpp"
#include <vector>
#include <algorithm>
#include <random>

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

  void Board::setCell(int x, int y, const std::string& value) {
    if (x < 0 || x >= sizeX || y < 0 || y >= sizeY) {
      throw OutOfBoundsException();
    }
    space[y*sizeX+x] = value;
  }

  std::string Board::getCell(int x, int y) {
    if (x < 0 || x >= sizeX || y < 0 || y >= sizeY) {
      throw OutOfBoundsException();
    }
    return space[y*sizeX+x];
  }

  void Board::PlacePlayer(int x, int y) {
    if (playerPresent()) {
      throw PlayerPresentException();
    }
    setCell(x, y, "b");
  }

  void Board::CastDirt(int number) {
    std::vector<position> positions;

    for (int i = 0; i < sizeX; i++) {
      for (int j = 0; j < sizeY; j++) {
        if (getCell(i, j) == "0") {
          positions.push_back(position {i, j});
        }
      }
    }
    if (number > positions.size()) {
      throw NotEnoughCellsException();
    }

    unsigned seed = time(NULL);
    std::shuffle(positions.begin(), positions.end(), std::default_random_engine(seed));

    for (int i = 0; i < number; i++) {
      setCell(positions[i].x, positions[i].y, "d");
    }
  }
}  // namespace Game
