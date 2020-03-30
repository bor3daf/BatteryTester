int ledRED = 5;
int ledGREEN = 6;
int ledBLUE = 7;

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 


#define OLED_RESET     4 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16


void setup() {
  pinMode(A2,INPUT);
  pinMode(ledRED,OUTPUT);
  pinMode(ledBLUE,OUTPUT);
  pinMode(ledGREEN,OUTPUT);
  Serial.begin (9600);
  Serial.begin(9600);

 
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); 
  }

 

}

void loop () {
if ((analogRead(A2) < 21)) {
    digitalWrite(ledGREEN,LOW);
    digitalWrite(ledBLUE,HIGH);
    digitalWrite(ledRED,LOW);
    
   }
 
 if ((analogRead(A2) < 320)&& (analogRead(A2) > 20)) {
    digitalWrite(ledGREEN,LOW);
    digitalWrite(ledBLUE,LOW);
    digitalWrite(ledRED,HIGH);
    delay(1000);
    digitalWrite(ledRED,LOW);
    delay(500);
    
   }
 if ((analogRead(A2) > 319) && (analogRead(A2) < 380)) {
    digitalWrite(ledGREEN,HIGH);
    digitalWrite(ledBLUE,LOW);
    digitalWrite(ledRED,LOW);
    delay(1000);
    digitalWrite(ledGREEN,LOW);
    delay(500);
    
  }
 if (analogRead(A2) > 380)  {

  
    digitalWrite(ledGREEN,HIGH);
    digitalWrite(ledBLUE,HIGH);
    digitalWrite(ledRED,HIGH);
    delay(500);
    digitalWrite(ledRED,LOW);
    delay(500);
    digitalWrite(ledGREEN,LOW);
    digitalWrite(ledRED,HIGH);
    delay(500);
      
}


  
  display.clearDisplay();
  display.setTextSize(1); 
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(25, 0);
  display.println(("Serial Monitor"));
  
  
  display.setTextSize(2); 
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(50, 20);
  display.println(analogRead(A2));
  display.display();    
  
    
  
}
