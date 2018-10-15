// Copyright 2018 Mehmet Cetin

#ifndef BOARD_HPP_
#define BOARD_HPP_

#include <string>
#include <vector>
#include <random>
#include <iostream>
#include <algorithm>

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
  position get_player();
  void cast_dirt(int number);
  void print_player_pos();
  void print_board();
  int get_size_x();
  int get_size_y();

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

enum action { up, down, left, right, clear };

class play {
 public:
  explicit play(game::masked_board& brd_in) : brd(brd_in), actions(0), ended(false) {}
  void print_board();
  void move(action act);
  bool is_ended();
  int dirt_left();

 private:
  game::masked_board& brd;
  bool ended;
  int actions;
};
}  // namespace game

#endif  // BOARD_HPP_
