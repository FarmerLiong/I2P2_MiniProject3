#pragma once
#include "../state/state.hpp"


/**
 * @brief Policy class for minimax policy, 
 * your policy class should have get_move method
 */
class Minimax{
public:
  static Move get_move(State *state, int depth, int player);
  static int get_value(State *state, int depth, int player);
  static Move get_max_move(State *state, int depth);
};