// Copyright 2018 Mehmet Cetin

#ifndef BOTS_GAME_HPP_
#define BOTS_GAME_HPP_

#include <vector>
#include <string>
#include <iostream>
#include <exception>

namespace Game {

class Board {
 public:
  explicit Board(int x, int y) : sizeX(x), sizeY(y) {
    space.reserve(x * y);

    for (int i = 0; i < x * y; i++) {
      space.push_back("0");
    }
  }

  void Print();
  void PlacePlayer(int x, int y);

 private:
  int sizeX, sizeY;
  std::vector<std::string> space;
  bool playerPresent();
};

class OutOfBoundsException: public std::exception {
 public:
  const char* what() const throw() {
    return "x or y coordiante is out of board space";
  }
};

class PlayerPresentException: public std::exception {
 public:
  const char* what() const throw() {
    return "there is already a player present on the board";
  }
};


}  // namespace Game

#endif  // BOTS_GAME_HPP_
