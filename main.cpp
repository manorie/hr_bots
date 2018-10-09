#include <iostream>
#include <exception>
#include "board.hpp"

int main() {
  game::masked_board brd = game::masked_board(5, 5);

  brd.cast_dirt(10);
  brd.set_player(3, 3);

  brd.print_board();
  return 0;
}
