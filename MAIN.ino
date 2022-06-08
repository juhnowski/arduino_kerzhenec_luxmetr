#include <LiquidCrystal.h>
#include "LED.h"
#include "BTN.h"
#include <SD.h>

//  test sinusoid
  float angle = 0.0;
  
const int adc0Pin = A0;
const int adc1Pin = A1;
const int adc2Pin = A2;
const int adc3Pin = A3;
const int adc4Pin = A4;

float val=0.0;
float val1 = -1.0;
float delta = 1.5;

float highv = 0.0;
float temp = 0.0;

float button_1 = 0.0;
float button_2 = 0.0;
float button_3 = 0.0;
float button_4 = 0.0;

void btn1_pressed(){
  Serial.println("Button 1 pressed");
}

void btn1_released(){
  Serial.println("Button 1 released");
}

void btn2_pressed(){
  Serial.println("Button 2 pressed");
}

void btn2_released(){
  Serial.println("Button 2 released");
}

void btn3_pressed(){
  Serial.println("Button 3 pressed");
}

void btn3_released(){
  Serial.println("Button 3 released");
}

void btn4_pressed(){
  Serial.println("Button 4 pressed");
}

void btn4_released(){
  Serial.println("Button 4 released");
}

 LED led1(5);
 BTN btn1(A1,btn1_pressed, btn1_released);
 BTN btn2(A2,btn2_pressed, btn2_released);
 BTN btn3(A3,btn3_pressed, btn3_released);
 BTN btn4(A4,btn4_pressed, btn4_released);
 
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); //lcd(8, 9, 10, 11, 12, 13);
 
void setup() {
    Serial.begin(115200);
    pinMode(adc0Pin, INPUT);
    
    pinMode(adc1Pin, INPUT);
    pinMode(adc2Pin, INPUT);
    pinMode(adc3Pin, INPUT);
    pinMode(adc4Pin, INPUT);
    
    lcd.begin(20, 4);
    lcd.print("Luxmetr");
    lcd.setCursor(0,1);
    lcd.write("LIGHT: ");
    lcd.setCursor(0,2);
    lcd.write("HIGHV: ");
    lcd.setCursor(0,3);
    lcd.write("OUT_T: ");
}

void test_sin(){
//  test sinusoid
  angle = angle + 0.1;
  if (angle == 90.1) {
    angle = 0.0;
  }
  val = sin(angle)*100;
  analogWrite(adc0Pin, val);
}

void loop() {
    btn1.check();
    btn2.check();
    btn3.check();
    btn4.check();
  
    val = analogRead(adc0Pin);

    button_1 = analogRead(adc1Pin);
    button_2 = analogRead(adc2Pin);
    button_3 = analogRead(adc3Pin);
    button_4 = analogRead(adc4Pin);
    
    lcd.setCursor(7,1);
    if ((val-val1)*(val-val1)>delta) {
      lcd.print(val);
      val1=val;
    }

    lcd.setCursor(7,2);
    lcd.print(highv);

    lcd.setCursor(7,3);
    lcd.print(temp);


 //   val = map(val, 0, 1023, 0, 255);
    //Serial.print(val);
    //Serial.println();
    delay(1);
}
