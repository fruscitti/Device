
#include "schedule.h"

class WaitState: public State {
  public:
    static const byte ID = 1;
    WaitState(state_pre_check pre_checks[]) : State(ID, pre_checks) {
    }

    virtual void init(Scheduler * s) {
      
    }

    virtual void handle(Scheduler * s) {
      
    }

    virtual void quit(Scheduler * s) {
      
    }
};

bool check1(Scheduler * s) {
  return false;
}


WaitState wa1((state_pre_check[]){check1, NULL});
WaitState wa2((state_pre_check[]){check1, NULL});


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
