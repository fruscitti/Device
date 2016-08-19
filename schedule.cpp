#include <stdio.h>
#include <Arduino.h>
#include "schedule.h"

void Scheduler::transition_to(State * s) {
  if (s != curr_state) {
    next_state = s;  
  }
}

void Scheduler::run() {
  if (curr_state == NULL && next_state == NULL) return;

  // Transitions
  if (curr_state != next_state) {
    if (curr_state) curr_state->quit(this);
    prev_state = curr_state;
    curr_state = next_state;
    curr_state->init(this);
    return; // Transition in init??
  }

  // Pre_checks
  state_pre_check * pre_checks = curr_state->get_pre_checks();
  while (*pre_checks) {
    if ((*pre_checks)(this)) return; // Transition
    pre_checks++;
  }

  curr_state->handle(this);
}

