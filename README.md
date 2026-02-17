# ESP32-C3 SOS LED Blinking with OTA

Author: Bryan Steven

Ini adalah project menggunakan **ESP32-C3 (LuatOS Core)** untuk mengirim sinyal Morse SOS melalui LED Internal. Project ini juga sudah dilengkapi fitur **OTA (Over-The-Air)**, jadi bisa update kodenya lewat WiFi tanpa perlu colok kabel USB.

## 🛠️ Hardware yang Digunakan
* **Board:** ESP32-C3 LuatOS Core.
* **LED:** On-board LED D4 (terhubung ke **GPIO 13**).
* **Koneksi:** WiFi 2.4GHz.

## 🚀 Fitur Utama
1. **Sinyal SOS:** Otomatis kedip 3x cepat (S), 3x lama (O), 3x cepat (S).
2. **Serial Monitor:** Menampilkan teks "S" atau "O" setiap kali urutan kedipan selesai.
3. **OTA Update:** Update firmware nirkabel via PlatformIO + WiFi.

## 📂 Struktur Folder
* `src/main.cpp`: Kode utama (Logika Morse & OTA).
* `docs(FSD)/FSD-Project.md`: Dokumen spesifikasi teknis project.
* `platformio.ini`: Konfigurasi environment & library.
