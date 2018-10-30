// Copyright 2018 Mehmet Cetin

#include <iostream>
#include <exception>
#include "board.hpp"

int main() {
  game::masked_board brd = game::masked_board(5, 5);
  brd.cast_dirt(10);
  brd.set_player(0, 0);

  game::play play = game::play(brd);
  game::player player = game::player(play);
  player.play();

  return 0;
}
