# Arduino Laser Tag — Base + Gun/Vest (TFT + Bluetooth)
DIY Arduino Laser Tag system with two modules: **Base Station** and **Gun/Vest**.  
The project uses **TFT displays**, **Bluetooth HC-05**, **piezo speaker**, and **IR/laser emitter** to simulate a simple tag game.  
Players have limited bullets and lives, while the Base allows **reload** and **respawn**.



## 🗂️ Project Structure
Projeto_Final/
 ├─ Base/             # Base station (menu + Bluetooth)
 ├─ Pistola_Colete/   # Gun/Vest (bullets, lives, IR detection)
 └─ README.md

---

## 🔧 Features
- TFT display menus for user interaction  
- Bullet and life counters on Gun/Vest  
- Bluetooth (HC-05) communication between modules  
- Sound feedback with piezo buzzer  
- IR/Laser emitter for shooting detection  
- Base station for reload and respawn options  

---

## 📌 Hardware
- Arduino Uno/Nano (compatible)  
- TFT display (CS: D10, DC: D9, RST: D8)  
- HC-05 Bluetooth module (RX: D5, TX: D6)  
- Push buttons (Base: D2, D3; Gun trigger: D3)  
- IR/Laser emitter (D2) + IR receiver (A4)  
- Piezo speaker (D7)  

---

## ▶️ How to Run
1. Open Arduino IDE.  
2. Install required libraries: `TFT.h`, `SPI.h`, `SoftwareSerial.h`.  
3. Upload `Base/` code to the Base Arduino.  
4. Upload `Pistola_Colete/` code to the Gun/Vest Arduino.  
5. Connect wiring as described above.  
6. Power on both modules and start playing!  

---

## 📖 Notes
- Buttons can be improved with `INPUT_PULLUP` and debounce.  
- IR emission can be refined with 38kHz modulation for better realism.  
- Constants for bullets/lives are easy to adjust in code.  
- Recommended to add photos of wiring and setup for clarity.  

---

## 📜 License
MIT License – free to use, learn, and adapt.
