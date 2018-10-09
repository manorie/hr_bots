// Copyright 2018 Mehmet Cetin

#ifndef BOTS_GAME_BOARD_HPP_
#define BOTS_GAME_BOARD_HPP_

#include <string>
#include <vector>
#include <random>
#include <iostream>

namespace game {
enum cell { dirty, clean };

struct position {
  int x;
  int y;
};

class board {
 public:
  board(int size_x_in, int size_y_in) : size_x(size_x_in), size_y(size_y_in),
  space(size_x_in * size_y_in, clean) { }

  cell get_cell(int x, int y);
  std::string get_cell_string(int x, int y);
  void set_cell(int x, int y, cell c);
  void set_player(int x, int y);
  void cast_dirt(int number);
  void print_player_pos();
  void print_board();

 protected:
  int size_x, size_y;
  position player;

 private:
  std::vector<cell> space;
};

class masked_board : public board {
 public:
  masked_board(int size_x_in, int size_y_in) : board(size_x_in, size_y_in) {}
  void print_board();
};
}  // namespace game

#endif  // BOTS_GAME_HPP_
