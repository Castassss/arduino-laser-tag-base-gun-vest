#include <TFT.h>
#include <SPI.h>
#include <SoftwareSerial.h>

#define cs 10
#define dc 9
#define rst 8

int opcao = 1;                                                         //-----------> 1 = recarregar | 0 = renascer

TFT TFTscreen = TFT(cs, dc, rst);
SoftwareSerial HC05(5, 6);                                            //------------> Master
void setup() {
  TFTscreen.begin();
  TFTscreen.background(0, 255, 59);
  pinMode(3, INPUT);    //botao para escolher a opção (mover)
  pinMode(2, INPUT);    //botao para selecionar a opção

  Serial.begin(9600);
  HC05.begin(9600);

  TFTscreen.setCursor(25, 80);
  TFTscreen.setTextSize(2);           //RENASCER
  TFTscreen.setTextColor(0xFFFF);
  TFTscreen.print("Renascer");

  TFTscreen.setCursor(25, 30);
  TFTscreen.setTextSize(2);           //RECARREGAR
  TFTscreen.setTextColor(0x0000);
  TFTscreen.print("Recarregar");

  TFTscreen.setCursor(8, 30);
  TFTscreen.setTextSize(2);
  TFTscreen.setTextColor(0x0000);
  TFTscreen.print(">");

}

void loop() {
  if (digitalRead(3) == 1) {                                          //---------> Trocar recarregar/renascer
    if (opcao == 1) {
      TFTscreen.background(0, 255, 59);
      TFTscreen.setCursor(25, 80);
      TFTscreen.setTextSize(2);
      TFTscreen.setTextColor(0x0000); //BRANCO
      TFTscreen.print("Renascer");

      TFTscreen.setCursor(25, 30);
      TFTscreen.setTextSize(2);
      TFTscreen.setTextColor(0xFFFF);
      TFTscreen.print("Recarregar");

      TFTscreen.setCursor(8, 80);
      TFTscreen.setTextSize(2);
      TFTscreen.setTextColor(0x0000);
      TFTscreen.print(">");
      opcao--;
    }
    else if (opcao == 0) {
      TFTscreen.background(0, 255, 59);
      TFTscreen.setCursor(25, 80);
      TFTscreen.setTextSize(2);
      TFTscreen.setTextColor(0xFFFF);  //PRETO
      TFTscreen.print("Renascer");

      TFTscreen.setCursor(25, 30);
      TFTscreen.setTextSize(2);
      TFTscreen.setTextColor(0x0000);  //BRANCO
      TFTscreen.print("Recarregar");

      TFTscreen.setCursor(8, 30);
      TFTscreen.setTextSize(2);
      TFTscreen.setTextColor(0x0000);
      TFTscreen.print(">");
      opcao++;
    }
    while (digitalRead(3) == 1) {
    }
  }
  else if (digitalRead(2) == 1) {                                         //------> Recarregar
    if (opcao == 1) {
      TFTscreen.background(0, 255, 59);
      TFTscreen.setCursor(75, 40);
      TFTscreen.setTextSize(2);
      TFTscreen.setTextColor(0x0000);  //BRANCO
      TFTscreen.print("A");
      TFTscreen.setCursor(25, 60);
      TFTscreen.print("Recarregar");
      TFTscreen.setCursor(62, 75);
      TFTscreen.print("...");
      delay(1500);
      TFTscreen.background(0, 255, 59);
      TFTscreen.setCursor(62, 35);
      TFTscreen.setTextSize(8);
      TFTscreen.setTextColor(0x0000);  //BRANCO
      TFTscreen.print("3");
      delay(1000);
      TFTscreen.background(0, 255, 59);
      TFTscreen.setCursor(62, 35);
      TFTscreen.setTextSize(8);
      TFTscreen.setTextColor(0x0000);  //BRANCO
      TFTscreen.print("2");
      delay(1000);
      TFTscreen.background(0, 255, 59);
      TFTscreen.setCursor(62, 35);
      TFTscreen.setTextSize(8);
      TFTscreen.setTextColor(0x0000);  //BRANCO
      TFTscreen.print("1");
      delay(1000);
      TFTscreen.background(0, 255, 59);
      TFTscreen.setCursor(36, 35);
      TFTscreen.setTextSize(8);
      TFTscreen.setTextColor(0x0000);  //BRANCO
      TFTscreen.print("GO");
      delay(1000);
      HC05.write(1);
      Serial.println("1");
      TFTscreen.background(0, 255, 59);

      TFTscreen.setCursor(25, 80);
      TFTscreen.setTextSize(2);           //RENASCER
      TFTscreen.setTextColor(0xFFFF);
      TFTscreen.print("Renascer");

      TFTscreen.setCursor(25, 30);
      TFTscreen.setTextSize(2);           //RECARREGAR
      TFTscreen.setTextColor(0x0000);
      TFTscreen.print("Recarregar");

      TFTscreen.setCursor(8, 30);
      TFTscreen.setTextSize(2);
      TFTscreen.setTextColor(0x0000);
      TFTscreen.print(">");
    }
    else if(opcao == 0){                                                                 //------> Renascer
      TFTscreen.background(0, 255, 59);
      TFTscreen.setCursor(75, 40);
      TFTscreen.setTextSize(2);
      TFTscreen.setTextColor(0x0000);  //BRANCO
      TFTscreen.print("A");
      TFTscreen.setCursor(35, 60);
      TFTscreen.print("Renascer");
      TFTscreen.setCursor(62, 75);
      TFTscreen.print("...");
      delay(1500);
      TFTscreen.background(0, 255, 59);
      TFTscreen.setCursor(62, 35);
      TFTscreen.setTextSize(8);
      TFTscreen.setTextColor(0x0000);  //BRANCO
      TFTscreen.print("5");
      delay(1000);
      TFTscreen.background(0, 255, 59);
      TFTscreen.setCursor(62, 35);
      TFTscreen.setTextSize(8);
      TFTscreen.setTextColor(0x0000);  //BRANCO
      TFTscreen.print("4");
      delay(1000);
      TFTscreen.background(0, 255, 59);
      TFTscreen.setCursor(62, 35);
      TFTscreen.setTextSize(8);
      TFTscreen.setTextColor(0x0000);  //BRANCO
      TFTscreen.print("3");
      delay(1000);
      TFTscreen.background(0, 255, 59);
      TFTscreen.setCursor(62, 35);
      TFTscreen.setTextSize(8);
      TFTscreen.setTextColor(0x0000);  //BRANCO
      TFTscreen.print("2");
      delay(1000);
      TFTscreen.background(0, 255, 59);
      TFTscreen.setCursor(62, 35);
      TFTscreen.setTextSize(8);
      TFTscreen.setTextColor(0x0000);  //BRANCO
      TFTscreen.print("1");
      delay(1000);
      TFTscreen.background(0, 255, 59);
      TFTscreen.setCursor(36, 35);
      TFTscreen.setTextSize(8);
      TFTscreen.setTextColor(0x0000);  //BRANCO
      TFTscreen.print("GO");
      delay(1000);
      HC05.write(2);
      Serial.println("2");
      TFTscreen.background(0, 255, 59);

      TFTscreen.setCursor(25, 80);
      TFTscreen.setTextSize(2);           //RENASCER
      TFTscreen.setTextColor(0xFFFF);
      TFTscreen.print("Renascer");

      TFTscreen.setCursor(25, 30);
      TFTscreen.setTextSize(2);           //RECARREGAR
      TFTscreen.setTextColor(0x0000);
      TFTscreen.print("Recarregar");

      TFTscreen.setCursor(8, 30);
      TFTscreen.setTextSize(2);
      TFTscreen.setTextColor(0x0000);
      TFTscreen.print(">");
      opcao++;
    }
    while (digitalRead(2) == 1) {
    }
  }

}
