#pragma once
#include "../state/state.hpp"


/**
 * @brief Policy class for Alphabeta policy, 
 * your policy class should have get_move method
 */
class Alphabeta {
public:
  static Move get_move(State *state, int depth, int player);
  static int get_value(State *state, int depth, int player, int alpha = -1e9, int beta = 1e9);
};