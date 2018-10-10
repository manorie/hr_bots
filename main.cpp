#include <iostream>
#include <exception>
#include "board.hpp"

int main() {
  game::masked_board brd = game::masked_board(5, 5);
  brd.cast_dirt(10);
  brd.set_player(0, 0);

  game::play play = game::play(brd);

  char move;
  while (!play.is_ended()) {
    std::cin >> move;

    switch (move) {
      case 'a':
        play.move(game::left);
        break;
      case 's':
        play.move(game::down);
        break;
      case 'd':
        play.move(game::right);
        break;
      case 'w':
        play.move(game::up);
        break;
      case 'c':
        play.move(game::clear);
        break;
    }
    play.print_board();
  }

  return 0;
}
