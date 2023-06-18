#include <cstdlib>

#include "../state/state.hpp"
#include "./minimax.hpp"


/**
 * @brief get a legal action by minimax
 * 
 * @param state Now state
 * @param depth 
 * @return Move 
 */
Move Minimax::get_move(State *state, int depth, int player){
  if(!state->legal_actions.size())
    state->get_legal_actions();
  
  int max_value = -1e9, state_value;
  Move retmove;

  for(auto& move:state->legal_actions){
    state_value = get_value(state->next_state(move), depth-1, player);
    if(state_value > max_value){
      max_value = state_value;
      retmove = move;
    }
  }
  return retmove;
}

int Minimax::get_value(State *state, int depth, int player){
  int value; 
  if(depth == 0)
    return state->evaluate();
  if(state->player == player){
    value = -1e9;
    for(auto& move:state->legal_actions){
      value = std::max(value, get_value(state->next_state(move), depth-1, player));
    }
    return value;
  }
  else{
    value = 1e9;
    for(auto& move:state->legal_actions){
      value = std::min(value, get_value(state->next_state(move), depth-1, player));
    }
    return value;
  }

}