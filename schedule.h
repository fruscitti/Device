#ifndef __SCHEDULE
#define __SCHEDULE

class State;
class Scheduler;

typedef bool (*state_pre_check)(Scheduler *);

class State {
  protected:
    state_pre_check * _pre_checks;
  
  public:
    State(byte id, state_pre_check pre_checks[]) : _id(id), _pre_checks(pre_checks) {
    }

    virtual void init(Scheduler * s) {
      _start_time = millis();
    }

    virtual void handle(Scheduler * s) {
    }

    virtual void quit(Scheduler * s) {
    }

    state_pre_check * get_pre_checks() {
      return _pre_checks;
    }

    int start_time() {
      return _start_time;
    }
    
  protected:
    int  _start_time;
    byte _id;
};

class Scheduler {
  protected:
    State * prev_state;
    State * curr_state;
    State * next_state;
    
  public:
     Scheduler() {
     }

     void transition_to(State * s); 
     void run();
};

#endif
