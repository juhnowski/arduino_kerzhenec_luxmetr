// BTN.cpp
#include "BTN.h"

BTN::BTN(int _pin, call_back_pressed _back_pressed, call_back_released _back_released) {
  pin   = _pin;
  state = LOW;
  back_pressed = _back_pressed;
  back_released = _back_released;
  pinMode(pin, INPUT);
}
    
void BTN::check() {
  if (analogRead(pin)>1000) {
    if (state == LOW) {
      back_pressed();
      state = HIGH;     
    } else {
      if (onPressedCounter++ > timeout) {
        back_pressed();
      };
    }
  } else {
    if (state == HIGH){
      state = LOW;
      back_released();
      onPressedCounter = 0;
    }
  }
}
