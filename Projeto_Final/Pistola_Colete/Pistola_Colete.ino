// 13, 12, 11
#include <TFT.h> 
#include <SPI.h>
#include <SoftwareSerial.h>

#define cs 10
#define dc 9
#define rst 8

TFT TFTscreen = TFT(cs, dc, rst);        
SoftwareSerial HC05(5, 6);

byte piezoPin = 7;      // -------> Piezzo (7)
byte buttonPin = 3;     // -------> Botão de disparo (3)
int balas;
int vidas;
int hit;
int over;
int stat;


void setup() {

// ----------------------------------------------------------------------------------------------------------------

pinMode(buttonPin,INPUT);      // -------> Botão de disparo (3)
pinMode(2, OUTPUT);           // -------> Laser 
pinMode(piezoPin,OUTPUT);  
pinMode(A4,INPUT);            //--------> Detetor

// ----------------------------------------------------------------------------------------------------------------
balas = 20;
vidas = 3;
hit = 0;
stat = 0;
over =0;
// ----------------------------------------------------------------------------------------------------------------
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



Serial.begin(9600);
HC05.begin(9600);
}

void loop() {
  Serial.println(analogRead(A4));
  if(digitalRead(buttonPin)==HIGH && balas>0){             //------->Disparar

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
    //meter as cenas dos infravermelhos
    spaceGun(600);
    digitalWrite(2,LOW);
    while(digitalRead(buttonPin)==1){
      if(analogRead(A4)==0){
        hit=1;
        break;
      }
  }
  }
  else if(balas==0){                                        //------->Sem Balas
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
  
 if(analogRead(A4)==0 || hit==1){                                    //------->Ser atingido
  vidas--;
  //-----
    if(vidas==0){                                            //------->Perder o jogo
    while(1){
    //meter uma cena a dizer end game
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
  while(stat != 2){                                                   //------->Ciclo até ser revivido  *
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
    //meter uma cena a dizer q tas morto até ser revivido
 
  }
  stat=0;
  //-----
  if(vidas==2){                                                //------->Ficar com duas vidas
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
  else if(vidas==1){                                           //------->Ficar com três vidas
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


void spaceGun(int maximum) {                                      //------->Som do tiro
for(int i = 0; i <maximum; i++) {
digitalWrite (piezoPin, HIGH);
delayMicroseconds (i);
if(analogRead(A4)==0){
        hit=1;
      }
digitalWrite (piezoPin, LOW);
delayMicroseconds (i);
}
}
