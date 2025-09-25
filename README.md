# 🚀 Embedded Drivers Library  

A curated collection of **AVR peripheral drivers** built from scratch, designed to be reusable, modular, and easy to integrate into embedded systems projects.  

This repository is my personal effort in learning and mastering embedded systems development with **AVR Microcontrollers**, with guidance and inspiration from **Eng. Mohamed Tarek**.  

---

## 📚 Available Drivers  
- 🔌 **GPIO** – General Purpose I/O driver for pin/port control  
- ⌨️ **Keypad** – Matrix keypad scanning and input handling  
- 🖥️ **LCD** – HD44780-compatible character LCD driver  coming soon...
- ⏱️ **Timer** – Timer0/1/2 drivers for delays, counters, and PWM  coming soon...
- 📡 **ADC** – Analog-to-Digital Converter driver for sensor interfacing  coming soon...
- ⚡ More drivers coming soon...  

---

## 🛠️ Features  
- Modular `.c` and `.h` files for each driver  
- Clean folder structure (each driver has its own directory)  
- Portable code for **ATmega16/32** (easily adaptable to other AVR MCUs)  
- Written in **C (GNU99)**, tested with **AVR-GCC** and **AVR Studio / Atmel Studio**  

---

## 📂 Repository Structure  

Embedded-Drivers-Library/

│── GPIO/

   │ ├── gpio.c

   │ ├── gpio.h
   │


│── Keypad/

   │ ├── keypad.c

   │ ├── keypad.h
   
   │ ├── gpio.c # dependency

   │ ├── gpio.h
   │


│── LCD/

   │ ├── lcd.c

   │ ├── lcd.h
   │


│── ADC/

   │ ├── adc.c

   │ ├── adc.h
   │


│── Timer/

   │ ├── timer.c

   │ ├── timer.h
   │


└── README.md

## ⚙️ How to Use  

1. Clone the repository:  
   ```bash
   git clone https://github.com/Berryy2/Embedded-Drivers-Library.git

2. Include the driver you need in your project:
  ex:
  #include "gpio.h"
  #include "keypad.h"
  #include "lcd.h"
3. Compile with AVR-GCC or import into Atmel Studio.

🤝 Credits

Developed by Mohamed Maged Elsayed Ahmed Elberry

Special thanks to Eng. Mohamed Tarek for guidance and mentorship

🌟 Contributing

Contributions are welcome!

Fork the repo

Add new drivers or improve existing ones

Submit a Pull Request 🚀

Note: Driver will be added one by one at a time.

📜 License

This project is open-source and available under the MIT License.
