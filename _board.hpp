// Copyright 2018 Mehmet Cetin

#ifndef BOTS_GAME_BOARD_HPP_
#define BOTS_GAME_BOARD_HPP_

#include <vector>
#include <string>
#include <iostream>
#include <exception>

namespace Game {

class Board3 {
 public:
  explicit Board3(int sXIn, int sYIn, int dirtIn) : sX(sXIn), sY(sYIn), dirt(dirtIn) {}

 private:
  int sX, sY, dirt;
};


struct position2 {
  int x;
  int y;
};

enum direction { left, right, up, down };

class Board2 {
 public:
  explicit Board2(int sizeXIn, int sizeYIn) : sizeX(sizeXIn), sizeY(sizeYIn) {
    space.reserve(sizeXIn * sizeYIn);
  }
  void CastPlayer(int x, int y);
  void CastDirt(int number);
  void MovePlayer(direction d);

 private:
  int sizeX, sizeY;
  std::vector<std::string> space;
  position2 player;
};

class Board {
 public:
  explicit Board(int x, int y) : sizeX(x), sizeY(y) {
    space.reserve(x * y);

    for (int i = 0; i < x * y; i++) {
      space.push_back("0");
    }
  }

  struct Position {
    int x;
    int y;
  };

  void Print();
  void PlacePlayer(int x, int y);
  void CastDirt(int number);
  Position GetPlayerPosition();

 private:
  int sizeX, sizeY;
  std::vector<std::string> space;

  bool playerPresent();
  void setCell(int x, int y, const std::string& value);
  std::string getCell(int x, int y);
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

class NoPlayerPresentException: public std::exception {
 public:
  const char* what() const throw() {
    return "there is not a player present on the board";
  }
};

class NotEnoughCellsException: public std::exception {
 public:
  const char* what() const throw() {
    return "not enough cells to place enough dirt";
  }
};


}  // namespace Game

#endif  // BOTS_GAME_HPP_
