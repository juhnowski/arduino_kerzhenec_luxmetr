// SCREEN.h
#ifndef SCREEN_h
#define SCREEN_h
#include <LiquidCrystal.h>
#include <Arduino.h>

class SCREEN {
  public:
    SCREEN(LiquidCrystal* _lcd);
    virtual void init();
    virtual void show();
    LiquidCrystal* lcd;
};

#endif
