// LUXMETR.h
#ifndef LUXMETR_h
#define LUXMETR_h
#include "BTN.h"
#include "SCREEN.h"
#include <Arduino.h>

class LUXMETR:public SCREEN {
    public:
    static void btn1_pressed(){
  Serial.println("Button 1 pressed");
  };
    static void btn1_released(){
  Serial.println("Button 1 released");
  };
    static void btn2_pressed(){
  Serial.println("Button 2 pressed");
  };
    static void btn2_released(){
  Serial.println("Button 2 released");
  };
    static void btn3_pressed(){
  Serial.println("Button 3 pressed");
  };
    static void btn3_released(){
  Serial.println("Button 3 released");
  };
    static void btn4_pressed(){
  Serial.println("Button 4 pressed");
  };
  
    static void btn4_released(){
  Serial.println("Button 4 released");
  };
    
  BTN btn1 = BTN(A1,btn1_pressed, btn1_released);
  BTN btn2 = BTN(A2,btn2_pressed, btn2_released);
  BTN btn3 = BTN(A3,btn3_pressed, btn3_released);
  BTN btn4 = BTN(A4,btn4_pressed, btn4_released); 
  
    LUXMETR::LUXMETR(LiquidCrystal* lc):SCREEN(lc){

};
    float val=0.0;
    float val1 = -1.0;
    float delta = 1.5;

    float highv = 0.0;
    float temp = 0.0;

    void init();
    void show();
    
};

#endif
