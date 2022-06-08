#include <LiquidCrystal.h>
#include "LED.h"
#include "LUXMETR.h"
#include <SD.h>

 
LED led1(5);
 
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); //lcd(8, 9, 10, 11, 12, 13);
LUXMETR screen_1(&lcd);
 
void setup() {
    Serial.begin(115200);
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    pinMode(A2, INPUT);
    pinMode(A3, INPUT);
    pinMode(A4, INPUT);
    pinMode(A5, INPUT);
    screen_1.init();
}

/*
void test_sin(){
//  test sinusoid
  angle = angle + 0.1;
  if (angle == 90.1) {
    angle = 0.0;
  }
  val = sin(angle)*100;
  analogWrite(A0, val);
}
*/

void loop() {
  screen_1.show();


 //   val = map(val, 0, 1023, 0, 255);
    //Serial.print(val);
    //Serial.println();
    delay(1);
}
