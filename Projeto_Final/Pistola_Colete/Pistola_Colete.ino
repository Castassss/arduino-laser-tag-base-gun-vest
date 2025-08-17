// 13, 12, 11
#include <TFT.h> 
#include <SPI.h>
#include <SoftwareSerial.h>

// TFT display pins
#define cs 10
#define dc 9
#define rst 8

TFT TFTscreen = TFT(cs, dc, rst);        
SoftwareSerial HC05(5, 6);

// Pin definitions
byte piezoPin = 7;      // Piezo speaker
byte buttonPin = 3;     // Trigger button
int balas;              // Bullets
int vidas;              // Lives
int hit;                // Hit flag
int over;               // Game over flag
int stat;               // Status (Bluetooth commands)

void setup() {
  // Hardware setup
  pinMode(buttonPin, INPUT);   // trigger button
  pinMode(2, OUTPUT);          // IR/Laser emitter
  pinMode(piezoPin, OUTPUT);   // piezo speaker
  pinMode(A4, INPUT);          // IR sensor

  // Initial values
  balas = 20;
  vidas = 3;
  hit = 0;
  stat = 0;
  over = 0;

  // Display setup
  TFTscreen.begin();
  TFTscreen.background(255,255,255);

  TFTscreen.setCursor(15,90);
  TFTscreen.setTextSize(2);
  TFTscreen.setTextColor(0x0000);
  TFTscreen.print("Vidas - III");

  TFTscreen.setCursor(2,20);
  TFTscreen.setTextSize(2);
  TFTscreen.setTextColor(0x0000);
  TFTscreen.print("Balas - 20/20");

  // Serial + Bluetooth
  Serial.begin(9600);
  HC05.begin(9600);
}

void loop() {
  Serial.println(analogRead(A4));

  // Shooting
  if(digitalRead(buttonPin)==HIGH && balas>0){     
    TFTscreen.setCursor(98,20);
    TFTscreen.setTextSize(2);
    TFTscreen.setTextColor(0xFFFF);
    TFTscreen.print(balas);

    balas--;
    TFTscreen.setCursor(98,20);
    TFTscreen.setTextSize(2);
    TFTscreen.setTextColor(0x0000);
    TFTscreen.print(balas);
    
    digitalWrite(2,HIGH);
    spaceGun(600); // play shot sound
    digitalWrite(2,LOW);

    while(digitalRead(buttonPin)==1){
      if(analogRead(A4)==0){
        hit=1;
        break;
      }
    }
  }

  // Out of bullets → wait for reload
  else if(balas==0){                                
    while(stat != 1){
       HC05.listen();
       if (HC05.available()>0) { 
         HC05.listen();
         stat = HC05.read();
       }
       if(analogRead(A4)==0){
         hit=1;
         break;
       }
    }
    stat=0;
    TFTscreen.setCursor(98,20);
    TFTscreen.setTextSize(2);
    TFTscreen.setTextColor(0xFFFF);
    TFTscreen.print(balas);
    balas=20;
    TFTscreen.setCursor(98,20);
    TFTscreen.setTextSize(2);
    TFTscreen.setTextColor(0x0000);
    TFTscreen.print(balas);
  }
  
  // Being hit
  if(analogRead(A4)==0 || hit==1){      
    vidas--;

    // Game over
    if(vidas==0){                        
      while(1){
        if(over==0){
          TFTscreen.background(255 ,0,0);
          over=1;
        }
        TFTscreen.setCursor(30,60);
        TFTscreen.setTextSize(2);
        TFTscreen.setTextColor(0xFFFF);
        TFTscreen.print("GAME OVER");
      }
    }

    // Wait until respawn command received
    while(stat != 2){                       
      TFTscreen.background(255 ,0,0);
      TFTscreen.setCursor(27,55);
      TFTscreen.setTextSize(3);
      TFTscreen.setTextColor(0x0000);
      TFTscreen.print("Wasted");

      HC05.listen();
      if (HC05.available()>0) { 
        HC05.listen();
        stat = HC05.read();
      }

      delay(700);

      TFTscreen.background(255,255,255);
      TFTscreen.setCursor(27,55);
      TFTscreen.setTextSize(3);
      TFTscreen.setTextColor(0x0000);
      TFTscreen.print("Wasted");

      if(stat != 2){
        HC05.listen();
        if (HC05.available()>0) { 
          HC05.listen();
          stat = HC05.read();
        }
      }
      delay(700);
    }

    stat=0;

    // Update display after respawn
    if(vidas==2){                       
      TFTscreen.background(255,255,255);
      TFTscreen.setCursor(2,20);
      TFTscreen.setTextSize(2);
      TFTscreen.setTextColor(0x0000);
      TFTscreen.print("Balas - 20/20");
      TFTscreen.setCursor(15,90);
      TFTscreen.setTextSize(2);
      TFTscreen.setTextColor(0x0000);
      TFTscreen.print("Vidas - II");
    }
    else if(vidas==1){                  
      TFTscreen.background(255,255,255);
      TFTscreen.setCursor(2,20);
      TFTscreen.setTextSize(2);
      TFTscreen.setTextColor(0x0000);
      TFTscreen.print("Balas - 20/20");
      TFTscreen.setCursor(15,90);
      TFTscreen.setTextSize(2);
      TFTscreen.setTextColor(0x0000);
      TFTscreen.print("Vidas - I");
    }
    hit=0;
    balas=20;
  }
}

// Play shot sound with piezo
void spaceGun(int maximum) {    
  for(int i = 0; i < maximum; i++) {
    digitalWrite(piezoPin, HIGH);
    delayMicroseconds(i);
    if(analogRead(A4)==0){
      hit=1;
    }
    digitalWrite(piezoPin, LOW);
    delayMicroseconds(i);
  }
}
