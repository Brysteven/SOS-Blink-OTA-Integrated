# ESP32 OCPP Server - Functional Specification Document

## 1. Overview

### 1.1 Purpose

Jadi project ini bertujuan membuat alat menggunakan ESP32C3 yang menjalankan pola kedip LED "SOS" dan mendukung pembaharuan kode Jarak jauh melalui over the air (OTA).

### 1.2 Goals

1. mengedipkan LED D4 sesuai "SOS" morse code
2. Memberikan output ke serial monitor untuk tiap huruf saat LED blink morse per huruf
3. Memberikan akses WiFi untuk memungkinkan implementasi fitur OTA
4. Update code dilakukan secara wireless melalui VSCode

## 2. Hardware Requirements

|komponen |Spesifikasi|
|---------|------------|
|MCU      |ESP32C3 LuatOS Core|
|LED	  |Onboard LED D4 (GPIO 13)|
|Koneksi  |WiFi 2.4GHz|

## 3. Software Architecture

### 3.1 Framework and Libraries

Framework: VSCode PlatformIO Arduino (C++)
Libraries: 
1. WiFi.h
2. ArduinoOTA.h

### 3.2 Code Flow
1. Setup
- serial begin 9600
- konfigurasi GPIO 13 OUTPUT
- connect ke WiFi SSID & Password (placeholder)
- mengaktifkan ArduinoOTA.begin()

2. Loop
- menjalankan ArduinoOTA.handle() di tiap siklus
- Menjalankan urutan kedipan kode morse "SOS" dengan delay code "S" itu 200ms dan delay code "O" 500ms
- print huruf ke serial monitor saat lampu tiap hruuf kedip
- beri delay setelah telah melakukan 1 morse code "SOS"

### 4. Network & OTA
- Mode: WiFi Station (STA)
- OTA Port: Default (port 3232)