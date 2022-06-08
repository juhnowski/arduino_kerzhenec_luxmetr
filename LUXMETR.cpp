// LUXMETR.cpp
#include "LUXMETR.h"
#include "BTN.h"



void LUXMETR::init() {
    lcd->begin(20, 4);
    lcd->print("Luxmetr");
    lcd->setCursor(0,1);
    lcd->write("LIGHT: ");
    lcd->setCursor(0,2);
    lcd->write("HIGHV: ");
    lcd->setCursor(0,3);
    lcd->write("OUT_T: ");
}
    
void LUXMETR::show() {
    btn1.check();
    btn2.check();
    btn3.check();
    btn4.check();

    val = analogRead(A0);
    
    lcd->setCursor(7,1);
    if ((val-val1)*(val-val1)>delta) {
      lcd->print(val);
      val1=val;
    }

    lcd->setCursor(7,2);
    lcd->print(highv);

    lcd->setCursor(7,3);
    lcd->print(temp);

};
/*
void LUXMETR::btn1_pressed(){
  Serial.println("Button 1 pressed");
  };

void LUXMETR::btn1_released(){
  Serial.println("Button 1 released");
  };

void LUXMETR::btn2_pressed(){
  Serial.println("Button 2 pressed");
  };
    
void LUXMETR::btn2_released(){
  Serial.println("Button 2 released");
  };
  
void LUXMETR::btn3_pressed(){
  Serial.println("Button 3 pressed");
  };
    
void LUXMETR::btn3_released(){
  Serial.println("Button 3 released");
  };

  
void LUXMETR::btn4_pressed(){
  Serial.println("Button 4 pressed");
  };
  
void LUXMETR::btn4_released(){
  Serial.println("Button 4 released");
  };
*/
