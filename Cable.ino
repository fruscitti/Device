class Cable {
  protected:
    byte _pin;
    bool _state;
    int  _last_debounce;
    int  _last_read;
  public:
    Cable(byte pin): _pin(pin) {}

    void setup();
    bool read_state();    
  
}

void Cable::setup() {
  pinMode(_pin, INPUT_PULLUP);
  _state = true;
  _last_debounce = 0;

  if (digitalRead(_pin) == HIGH)
    _state = false;
}

bool Cable::read_state() {
  if (!_state) return HIGH;
  
  if (_last_debounce == 0) {
    _last_debounce = millis();
    _last_read = digitalRead(_pin);
    return LOW;
  }

  
}



