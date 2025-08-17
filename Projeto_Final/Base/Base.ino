#include <TFT.h>
#include <SPI.h>
#include <SoftwareSerial.h>

// TFT display pins
#define cs 10
#define dc 9
#define rst 8

// Menu option: 1 = Reload | 0 = Respawn
int opcao = 1;

TFT TFTscreen = TFT(cs, dc, rst);
SoftwareSerial HC05(5, 6); // Bluetooth HC-05 (Master)

void setup() {
  TFTscreen.begin();
  TFTscreen.background(0, 255, 59);

  // Input buttons
  pinMode(3, INPUT); // navigation button
  pinMode(2, INPUT); // select button

  Serial.begin(9600);
  HC05.begin(9600);

  // Initial screen
  TFTscreen.setCursor(25, 80);
  TFTscreen.setTextSize(2);
  TFTscreen.setTextColor(0xFFFF);
  TFTscreen.print("Renascer");

  TFTscreen.setCursor(25, 30);
  TFTscreen.setTextSize(2);
  TFTscreen.setTextColor(0x0000);
  TFTscreen.print("Recarregar");

  TFTscreen.setCursor(8, 30);
  TFTscreen.setTextSize(2);
  TFTscreen.setTextColor(0x0000);
  TFTscreen.print(">");
}

void loop() {
  if (digitalRead(3) == 1) { // switch between reload/respawn
    if (opcao == 1) {
      TFTscreen.background(0, 255, 59);
      TFTscreen.setCursor(25, 80);
      TFTscreen.setTextSize(2);
      TFTscreen.setTextColor(0x0000);
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
      TFTscreen.setTextColor(0xFFFF);
      TFTscreen.print("Renascer");

      TFTscreen.setCursor(25, 30);
      TFTscreen.setTextSize(2);
      TFTscreen.setTextColor(0x0000);
      TFTscreen.print("Recarregar");

      TFTscreen.setCursor(8, 30);
      TFTscreen.setTextSize(2);
      TFTscreen.setTextColor(0x0000);
      TFTscreen.print(">");
      opcao++;
    }
    while (digitalRead(3) == 1) { } // wait until button release
  }
  else if (digitalRead(2) == 1) { // confirm option
    if (opcao == 1) { // Reload
      TFTscreen.background(0, 255, 59);
      TFTscreen.setCursor(75, 40);
      TFTscreen.setTextSize(2);
      TFTscreen.setTextColor(0x0000);
      TFTscreen.print("A");
      TFTscreen.setCursor(25, 60);
      TFTscreen.print("Recarregar");
      TFTscreen.setCursor(62, 75);
      TFTscreen.print("...");
      delay(1500);

      // Countdown 3..2..1
      TFTscreen.background(0, 255, 59);
      TFTscreen.setCursor(62, 35);
      TFTscreen.setTextSize(8);
      TFTscreen.setTextColor(0x0000);
      TFTscreen.print("3");
      delay(1000);
      TFTscreen.background(0, 255, 59);
      TFTscreen.setCursor(62, 35);
      TFTscreen.setTextSize(8);
      TFTscreen.setTextColor(0x0000);
      TFTscreen.print("2");
      delay(1000);
      TFTscreen.background(0, 255, 59);
      TFTscreen.setCursor(62, 35);
      TFTscreen.setTextSize(8);
      TFTscreen.setTextColor(0x0000);
      TFTscreen.print("1");
      delay(1000);

      // GO message
      TFTscreen.background(0, 255, 59);
      TFTscreen.setCursor(36, 35);
      TFTscreen.setTextSize(8);
      TFTscreen.setTextColor(0x0000);
      TFTscreen.print("GO");
      delay(1000);

      HC05.write(1); // send reload signal
      Serial.println("1");

      // Reset screen
      TFTscreen.background(0, 255, 59);
      TFTscreen.setCursor(25, 80);
      TFTscreen.setTextSize(2);
      TFTscreen.setTextColor(0xFFFF);
      TFTscreen.print("Renascer");

      TFTscreen.setCursor(25, 30);
      TFTscreen.setTextSize(2);
      TFTscreen.setTextColor(0x0000);
      TFTscreen.print("Recarregar");

      TFTscreen.setCursor(8, 30);
      TFTscreen.setTextSize(2);
      TFTscreen.setTextColor(0x0000);
      TFTscreen.print(">");
    }
    else if(opcao == 0){ // Respawn
      TFTscreen.background(0, 255, 59);
      TFTscreen.setCursor(75, 40);
      TFTscreen.setTextSize(2);
      TFTscreen.setTextColor(0x0000);
      TFTscreen.print("A");
      TFTscreen.setCursor(35, 60);
      TFTscreen.print("Renascer");
      TFTscreen.setCursor(62, 75);
      TFTscreen.print("...");
      delay(1500);

      // Countdown 5..4..3..2..1
      TFTscreen.background(0, 255, 59);
      TFTscreen.setCursor(62, 35);
      TFTscreen.setTextSize(8);
      TFTscreen.setTextColor(0x0000);
      TFTscreen.print("5");
      delay(1000);
      TFTscreen.background(0, 255, 59);
      TFTscreen.setCursor(62, 35);
      TFTscreen.setTextSize(8);
      TFTscreen.setTextColor(0x0000);
      TFTscreen.print("4");
      delay(1000);
      TFTscreen.background(0, 255, 59);
      TFTscreen.setCursor(62, 35);
      TFTscreen.setTextSize(8);
      TFTscreen.setTextColor(0x0000);
      TFTscreen.print("3");
      delay(1000);
      TFTscreen.background(0, 255, 59);
      TFTscreen.setCursor(62, 35);
      TFTscreen.setTextSize(8);
      TFTscreen.setTextColor(0x0000);
      TFTscreen.print("2");
      delay(1000);
      TFTscreen.background(0, 255, 59);
      TFTscreen.setCursor(62, 35);
      TFTscreen.setTextSize(8);
      TFTscreen.setTextColor(0x0000);
      TFTscreen.print("1");
      delay(1000);

      // GO message
      TFTscreen.background(0, 255, 59);
      TFTscreen.setCursor(36, 35);
      TFTscreen.setTextSize(8);
      TFTscreen.setTextColor(0x0000);
      TFTscreen.print("GO");
      delay(1000);

      HC05.write(2); // send respawn signal
      Serial.println("2");

      // Reset screen
      TFTscreen.background(0, 255, 59);
      TFTscreen.setCursor(25, 80);
      TFTscreen.setTextSize(2);
      TFTscreen.setTextColor(0xFFFF);
      TFTscreen.print("Renascer");

      TFTscreen.setCursor(25, 30);
      TFTscreen.setTextSize(2);
      TFTscreen.setTextColor(0x0000);
      TFTscreen.print("Recarregar");

      TFTscreen.setCursor(8, 30);
      TFTscreen.setTextSize(2);
      TFTscreen.setTextColor(0x0000);
      TFTscreen.print(">");
      opcao++;
    }
    while (digitalRead(2) == 1) { } // wait until button release
  }
}
