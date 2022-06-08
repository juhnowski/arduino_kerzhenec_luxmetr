// BTN.h
#ifndef BTN_h
#define BTN_h

#include <Arduino.h>

typedef void (*call_back_pressed) ();
typedef void (*call_back_released) ();

class BTN {
  private:
    int pin;
    unsigned char state;
    int onPressedCounter = 0;
    int timeout = 100;
    call_back_pressed back_pressed;
    call_back_released back_released;
    
  public:
    BTN(int pin, call_back_pressed back_pressed, call_back_released back_released);
    void check();    
};

#endif
