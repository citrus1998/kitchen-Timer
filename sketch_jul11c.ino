#include "enpitshield.h"
//#include <Wire.h> // Enable this line if using Arduino Uno, Mega, etc.
//#include <Adafruit_GFX.h>
//#include "Adafruit_LEDBackpack.h"

//Adafruit_7segment matrix = Adafruit_7segment();

int min = 0; //minute
int hour = 0; //hour
int sec = 0; //second

void setup() { //Default
  
  pinMode(TACTSW0,INPUT);
  pinMode(TACTSW1,INPUT);
  pinMode(LED0,OUTPUT);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);

  //#ifndef __AVR_ATtiny85__
  Serial.begin(9600); //open the portat the speed of 9600 bps
  
  //#endif
  //matrix.begin(0x70);
  
}

void loop() { //implement

  digitalWrite(LED0, HIGH); //stopping 
  if(digitalRead(TACTSW1) == TACTSW_ON){ //TACTSW1 == HIGH
    digitalWrite(LED0, LOW); //put out LED0
    start();
    sec = 0;
    min = 0;
    hour = 0;
  }
  
} 

void start(){
  
  digitalWrite(LED1, HIGH);
  
  do{
    delay(1000); //during 1s
    sec++;
    digitalWrite(LED1, LOW);
    //matrix.print(sec, DEC);
    //matrix.writeDisplay();
  
    if(sec == 60){ //passing 60 seconds
      
      digitalWrite(LED2, HIGH); //give out LED2
      delay(1000); //during 1s
      digitalWrite(LED2, LOW);  //put out LED2
      sec = 0;
      min = min + 1;
    
      if(min == 60){ //passing 60 minutes
        
        digitalWrite(LED1, HIGH); //give out LED1
        delay(1000); //during 1s
        digitalWrite(LED1, LOW); //put out LED2
        min = 0;
        hour = hour + 1; 
      
      }
    }
    
    digitalWrite(LED3, HIGH); //Working
   
    Serial.print(hour);
    Serial.print(":");
    Serial.print(min);
    Serial.print(":");
    Serial.println(sec);
    delay(1000); //during 1s
    digitalWrite(LED3, LOW); //stopping 
    
  }while(digitalRead(TACTSW0) != TACTSW_ON);  
  
}






