// Copyright 2018 Mehmet Cetin

#include "board.hpp"

namespace game {
  void board::set_player(int x, int y) {
    player = position { x, y };
  }

  cell board::get_cell(int x, int y) {
    return space[y*size_x+x];
  }

  void board::set_cell(int x, int y, cell c) {
    space[y*size_x+x] = c;
  }

  position board::get_player() {
    return player;
  }

  void board::cast_dirt(int number) {
    std::vector<position> empty_cells;

    for (int i = 0; i < size_x; i++) {
      for (int j = 0; j < size_y; j++) {
        if (get_cell(i, j) == clean) {
          empty_cells.push_back(position {i, j});
        }
      }
    }

    unsigned seed = time(NULL);
    std::shuffle(empty_cells.begin(), empty_cells.end(), std::default_random_engine(seed));

    for (int i = 0; i < number; i++) {
      set_cell(empty_cells[i].x, empty_cells[i].y, dirty);
    }
  }

  void board::print_player_pos() {
    std::cout << "Player at x:" << player.x << " y:" << player.y << std::endl;
  }

  std::string board::get_cell_string(int x, int y) {
    switch (get_cell(x, y)) {
        case dirty:
          return "d";
        case clean:
          if (player.x == x && player.y == y) {
            return "b";
          } else {
            return "o";
          }
      }
  }

  void board::print_board() {
    print_player_pos();
    for (int i = 0; i < size_x; i++) {
      for (int j = 0; j < size_y; j++) {
          std::cout << get_cell_string(i, j);
        }
      std::cout << std::endl;
    }
  }

  void masked_board::print_board() {
    print_player_pos();
    std::string temp_cell_string;

    for (int i = 0; i < size_x; i++) {
      for (int j = 0; j < size_y; j++) {
        temp_cell_string = get_cell_string(i, j);

        if (i < player.x - 1 || i > player.x + 1 || j < player.y - 1 || j > player.y + 1) {
          std::cout << "-";
        } else {
          std::cout << temp_cell_string;
        }
      }
      std::cout << std::endl;
    }
  }

  void play::print_board() {
    brd.print_board();
  }

  void play::move(action act) {
    actions++;
    position player = brd.get_player();

    switch (act) {
      case up:
        brd.set_player(player.x - 1, player.y);
        break;
      case down:
        brd.set_player(player.x + 1, player.y);
        break;
      case left:
        brd.set_player(player.x, player.y - 1);
        break;
      case right:
        brd.set_player(player.x, player.y + 1);
        break;
      case clear:
        if (brd.get_cell(player.x, player.y) != dirty) {
          ended = true;
          return;
        }
        brd.set_cell(player.x, player.y, clean);
    }

    if (player.x < 0 || player.y < 0) {
      ended = true;
    }
    if (player.x >= brd.get_size_x() || player.y >= brd.get_size_x()) {
      ended = true;
    }
  }

  int board::get_size_x() {
    return size_x;
  }

  int board::get_size_y() {
    return size_y;
  }

  int play::dirt_left() {
    int dirt = 0;
     for (int i = 0; i < brd.get_size_x(); i++) {
      for (int j = 0; j < brd.get_size_y(); j++) {
          if (brd.get_cell(i, j) == dirty) {
            dirt++;
          }
        }
     }
     return dirt;
  }

  bool play::is_ended() {
    return ended;
  }
}  // namespace game
