# Arduino Laser Tag — Base + Gun/Vest (TFT + Bluetooth)
![License](https://img.shields.io/badge/license-MIT-green)
![Platform](https://img.shields.io/badge/platform-Arduino-blue)
![Language](https://img.shields.io/badge/language-C++-lightgrey)

DIY Arduino Laser Tag system with two modules: **Base Station** and **Gun/Vest**.  
The project uses **TFT displays**, **Bluetooth HC-05**, **piezo speaker**, and **IR/laser emitter** to simulate a simple tag game.  
Players have limited bullets and lives, while the Base allows **reload** and **respawn**.


---

## 🔧 Features
- TFT display menus for user interaction  
- Bullet and life counters on Gun/Vest  
- Bluetooth (HC-05) communication between modules  
- Sound feedback with piezo buzzer  
- IR/Laser emitter for shooting detection  
- Base station for reload and respawn options  

---

## 🔌 Wiring (Pin Map)

### 📟 Base Station
| Component           | Arduino Pin | Notes                  |
|---------------------|-------------|------------------------|
| TFT CS              | D10         | Chip Select            |
| TFT DC              | D9          | Data/Command           |
| TFT RST             | D8          | Reset                  |
| Button (navigate)   | D3          | Move through menu      |
| Button (select)     | D2          | Confirm option         |
| HC-05 RX            | D5          | SoftwareSerial RX      |
| HC-05 TX            | D6          | SoftwareSerial TX      |

---

### 🔫 Gun / Vest
| Component           | Arduino Pin | Notes                  |
|---------------------|-------------|------------------------|
| TFT CS              | D10         | Chip Select            |
| TFT DC              | D9          | Data/Command           |
| TFT RST             | D8          | Reset                  |
| Trigger Button      | D3          | Fire                   |
| IR / Laser Emitter  | D2          | Send shot signal       |
| IR Receiver         | A4          | Detect being hit       |
| Piezo Buzzer        | D7          | Sound effect           |
| HC-05 RX            | D5          | SoftwareSerial RX      |
| HC-05 TX            | D6          | SoftwareSerial TX      |

---

## 📌 Hardware
- Arduino Uno/Nano (compatible)  
- TFT display (CS: D10, DC: D9, RST: D8)  
- HC-05 Bluetooth module (RX: D5, TX: D6)  
- Push buttons (Base: D2, D3; Gun trigger: D3)  
- IR/Laser emitter (D2) + IR receiver (A4)  
- Piezo speaker (D7)  

---

## 📶 Bluetooth Setup (HC-05)

1. **Wiring**  
   - HC-05 VCC → 5V  
   - HC-05 GND → GND  
   - HC-05 TX → Arduino D5 (RX of SoftwareSerial)  
   - HC-05 RX → Arduino D6 (TX of SoftwareSerial)  

2. **Pairing**  
   - Default name: `HC-05`  
   - Default PIN: `1234` (ou `0000`)  
   - Baud rate: `9600`  

3. **Communication**  
   - Base Station sends:  
     - `1` → **Reload** command  
     - `2` → **Respawn** command  
   - Gun/Vest listens and reacts to commands.  


---

## ▶️ How to Run
1. Open Arduino IDE.  
2. Install required libraries: `TFT.h`, `SPI.h`, `SoftwareSerial.h`.  
3. Upload `Base/` code to the Base Arduino.  
4. Upload `Pistola_Colete/` code to the Gun/Vest Arduino.  
5. Connect wiring as described above.  
6. Power on both modules and start playing!  

---

## 🛠️ Troubleshooting & Notes

- **Button bouncing** → sometimes button presses register multiple times.  
  🔧 Fix: use `INPUT_PULLUP` and implement a simple debounce (e.g. with `millis()`).

- **IR detection too sensitive** → analogRead on A4 may trigger noise.  
  🔧 Fix: add a small capacitor as a filter or handle noise in software (ignore very short pulses).

- **Delays block execution** → current code uses `delay()` which freezes other actions.  
  🔧 Improvement: replace with non-blocking timing using `millis()`.

- **HC-05 pairing issues** → ensure baud rate is `9600`, default PIN is `1234` or `0000`.  
  If connection fails, reset module or check RX/TX wiring.

- **Large files on GitHub** → avoid committing generated `.hex` or `build/` folders (already covered by `.gitignore`).

---


## 📜 License
MIT License – free to use, learn, and adapt.
