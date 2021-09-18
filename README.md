# F12017 UDP Telemetry for ESP32

[![License: MIT](https://img.shields.io/badge/license-MIT-orange.svg)](LICENSE) 

________________________________________________________

## **Description:**
This repository contains an arduino code to handle the UDP telemetry of the F1 2017 game. This code was developed for the ESP32 board

## **Settings:**
1. Define the **SSID** and **PASSWORD** of the local network in the sketch
2. Open the serial monitor on **115200** and get the IP and PORT of the connection.
3. In the game, go to **GAME OPTIONS** --> **SETTINGS** --> **UDP Telemetry Settings**
4. Define:
    - UDP Telemetry = ON
    - Broadcast Mode = OFF
    - IP Address = ESP32 connection IP
    - Port = 20777
