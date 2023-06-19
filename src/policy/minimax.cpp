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
  auto actions = state->legal_actions;
  int max_value = -1e9;
  Move retmove = actions[0];

  for(auto& move:actions){
    int state_value = get_value(state->next_state(move), depth-1, player);
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
    return state->player == player ? state->evaluate() : -1*state->evaluate();
  
  auto actions = state->legal_actions;
  if(state->player == player){
    value = -1e9;

    for(auto& move:actions){
      value = std::max(value, get_value(state->next_state(move), depth-1, player));
    }
    return value;
  }
  else{
    value = 1e9;
    
    for(auto& move:actions){
      value = std::min(value, get_value(state->next_state(move), depth-1, player));
    }
    return value;
  }

}