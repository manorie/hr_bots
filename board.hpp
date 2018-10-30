// Copyright 2018 Mehmet Cetin

#ifndef BOARD_HPP_
#define BOARD_HPP_

#include <string>
#include <vector>
#include <random>
#include <iostream>
#include <algorithm>
#include <unordered_map>

namespace game {
enum cell { dirty, clean };

struct position {
  int x;
  int y;

  std::string to_string() {
    return std::to_string(x) + std::to_string(y);
  }

  std::string pos_down_string() {
    return std::to_string(x+1) + std::to_string(y);
  }

  std::string pos_up_string() {
    return std::to_string(x-1) + std::to_string(y);
  }

  std::string pos_right_string() {
    return std::to_string(x) + std::to_string(y+1);
  }

  std::string pos_left_string() {
    return std::to_string(x) + std::to_string(y-1);
  }
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
  std::vector<cell> get_space();

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
  int actions_count();

  int get_brd_size_x();
  int get_brd_size_y();
  std::vector<cell> get_brd_space();
  position get_player_position();
  cell get_brd_cell(int x, int y);

 private:
  game::masked_board& brd;
  bool ended;
  int actions;
};

class player {
 public:
  explicit player(game::play& ply_in) : ply(ply_in), cells_seen({}) {}
  void play();

 private:
  game::play& ply;
  std::unordered_map<std::string, bool> cells_seen;
};
}  // namespace game

#endif  // BOARD_HPP_
