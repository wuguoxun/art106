//This code is designed by Guoxun Wu

#include <Adafruit_TLC5947.h>

//LED Matrtix
#include "LedControl.h"

LedControl lc=LedControl(12,11,10,1);

//Led 24 channal 
#define NUM_TLC5974 1

#define data   4
#define clock   5
#define latch   6
#define oe  -1  // set to -1 to not use the enable pin (its optional)

Adafruit_TLC5947 tlc = Adafruit_TLC5947(NUM_TLC5974, clock, data, latch);

/* we always wait a bit between updates of the display */
unsigned long delaytime=500;
  byte six[8]={B00000000,B11011011,B11011011,B00000000,B00000000,B11011011,B11011011,B00000000};
  byte five[8]={B00000000,B01100110,B01100110,B00011000,B00011000,B01100110,B01100110,B00000000};
  byte four[8]={B00000000,B01100110,B01100110,B00000000,B00000000,B01100110,B01100110,B00000000};
  byte three[8]={B11000000,B11000000,B00000000,B00011000,B00011000,B00000000,B00000011,B00000011};
  byte two[8]={B00000000,B00000000,B00000000,B01100110,B01100110,B00000000,B00000000,B00000000};
  byte one[8]={B00000000,B00000000,B00000000,B00011000,B00011000,B00000000,B00000000,B00000000};

//part 1 code
#define DEBUG 0


int soundSensor=8;

int first = 2;
int second = 3;
int third = 4;
int fourth = 5;
int fifth = 6;
int sixth = 7;
int del = 50;

//int pressed = 0;


boolean LEDStatus=false;

void setup() {
    Serial.begin(9600);
  Serial.println("TLC5974 test");

    for (int i=first; i<=sixth; i++) {
      pinMode(i, OUTPUT);
    }
  pinMode(soundSensor,INPUT);

//  pinMode(first,OUTPUT);
//  pinMode(second, OUTPUT);
//  pinMode(third, OUTPUT);
//  pinMode(fourth, OUTPUT);
//  pinMode(fifth, OUTPUT);
//  pinMode(sixth, OUTPUT);

  randomSeed(analogRead(0));

  #ifdef DEBUG
    Serial.begin(9600);
  #endif


{
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);
}

}

void one1() {
  /* here is the data for the characters */
  
  /* now display them one by one with a small delay */
  lc.setRow(0,0,one[0]);
  lc.setRow(0,1,one[1]);
  lc.setRow(0,2,one[2]);
  lc.setRow(0,3,one[3]);
  lc.setRow(0,4,one[4]);
  lc.setRow(0,5,one[5]);
  lc.setRow(0,6,one[6]);
  lc.setRow(0,7,one[7]);
  
  delay(delaytime);
}
void two2() {
  /* here is the data for the characters */
  
  /* now display them one by one with a small delay */
  lc.setRow(0,0,two[0]);
  lc.setRow(0,1,two[1]);
  lc.setRow(0,2,two[2]);
  lc.setRow(0,3,two[3]);
  lc.setRow(0,4,two[4]);
  lc.setRow(0,5,two[5]);
  lc.setRow(0,6,two[6]);
  lc.setRow(0,7,two[7]);
  
  delay(delaytime);
}
void three3() {
  /* here is the data for the characters */
  
  /* now display them one by one with a small delay */
  lc.setRow(0,0,three[0]);
  lc.setRow(0,1,three[1]);
  lc.setRow(0,2,three[2]);
  lc.setRow(0,3,three[3]);
  lc.setRow(0,4,three[4]);
  lc.setRow(0,5,three[5]);
  lc.setRow(0,6,three[6]);
  lc.setRow(0,7,three[7]);
  
  delay(delaytime);
}
void four4() {
  /* here is the data for the characters */
  
  /* now display them four by four with a small delay */
  lc.setRow(0,0,four[0]);
  lc.setRow(0,1,four[1]);
  lc.setRow(0,2,four[2]);
  lc.setRow(0,3,four[3]);
  lc.setRow(0,4,four[4]);
  lc.setRow(0,5,four[5]);
  lc.setRow(0,6,four[6]);
  lc.setRow(0,7,four[7]);
 
  delay(delaytime);
}
void five5() {
  /* here is the data for the characters */
  
  /* now display them five by five with a small delay */
  lc.setRow(0,0,five[0]);
  lc.setRow(0,1,five[1]);
  lc.setRow(0,2,five[2]);
  lc.setRow(0,3,five[3]);
  lc.setRow(0,4,five[4]);
  lc.setRow(0,5,five[5]);
  lc.setRow(0,6,five[6]);
  lc.setRow(0,7,five[7]);

  delay(delaytime);
}
void six6() {
  /* here is the data for the characters */
  
  /* now display them six by six with a small delay */
  lc.setRow(0,0,six[0]);
  lc.setRow(0,1,six[1]);
  lc.setRow(0,2,six[2]);
  lc.setRow(0,3,six[3]);
  lc.setRow(0,4,six[4]);
  lc.setRow(0,5,six[5]);
  lc.setRow(0,6,six[6]);
  lc.setRow(0,7,six[7]);
  
  delay(delaytime);
}


void setAllLEDs(int value) {
  for (int i=first; i<=sixth; i++) {
    digitalWrite(i, value);
  }
}

void showNumber(int number) {
  digitalWrite(first, HIGH);
  if (number >= 2) {
    digitalWrite(second, HIGH);
  }
  if (number >= 3) {
    digitalWrite(third, HIGH);    
  }
  if (number >= 4) {
    digitalWrite(fourth, HIGH);    
  }
  if (number >= 5) {
    digitalWrite(fifth, HIGH);    
  }
  if (number == 6) {
    digitalWrite(sixth, HIGH);    
  }
}


void buildUpTension() {
  // light LEDs from left to right and back to build up tension
  // while waiting for the dice to be thrown
  // left to right
  for (int i=first; i<=sixth; i++) {
    if (i!=first) {
      digitalWrite(i-1, LOW);
    }
    digitalWrite(i, HIGH);
    delay(100);
  }
  // right to left
  for (int i=sixth; i>=first; i--) {
    if (i!=sixth) {
      digitalWrite(i+1, LOW);
    }
    digitalWrite(i, HIGH);
    delay(100);
  }
}

int throwDice() {
  // get a random number in the range [1,6]
  int randNumber = random(1,7);
  
  #ifdef DEBUG
    Serial.println(randNumber);
  #endif
  
  return randNumber;
}

//void setAllLEDs(int value) {
//  for (int i=first; i<=sixth; i++) {
//    digitalWrite(i, value);
//  }
//}
void loop() {
  int SensorData=digitalRead(soundSensor); 

  if(SensorData==1){

            setAllLEDs(HIGH);
              if(LEDStatus==false){
        LEDStatus=true;
              
               buildUpTension();
    int thrownNumber = throwDice();
    showNumber(thrownNumber);
              }
   else{
        LEDStatus=false;
    setAllLEDs(LOW);
   }
   
 int x;
  if(SensorData==1)
{
 x = random(1,6);
}
switch(x){
case 1 : one1();
break;
case 2 : two2();
break;
case 3 : three3();
break;
case 4 : four4();
break;
case 5 : five5();
break;
case 6 : six6();
break;}
     delay(1200);

}

   else{
        LEDStatus=false;
    setAllLEDs(LOW);
   }

} 
