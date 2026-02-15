#include <Arduino.h>
#include <WiFi.h>
#include <ArduinoOTA.h>

// WiFi credentials
const char* ssid = "WiFi name";
const char* password = "WiFi password";

// GPIO pin for LED
const int LED_PIN = 12;

// Morse code timings (ms)
const int DOT = 250;   // S
const int DASH = 500;  // O
const int SYMBOL_GAP = 100;
const int LETTER_GAP = 600;

void setupWiFi() {
  Serial.println("\n\nStarting WiFi connection...");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  
  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 20) {
    delay(500);
    Serial.print(".");
    attempts++;
  }
  
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWiFi connected!");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\nWiFi connection failed!");
  }
}

void setupOTA() {
  ArduinoOTA.onStart([]() {
    Serial.println("OTA Update started");
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nOTA Update finished");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error: %u\n", error);
  });
  
  ArduinoOTA.begin();
  Serial.println("OTA Ready");
}

void blinkDot() {
  digitalWrite(LED_PIN, HIGH);
  delay(DOT);
  digitalWrite(LED_PIN, LOW);
  delay(SYMBOL_GAP);
}

void blinkDash() {
  digitalWrite(LED_PIN, HIGH);
  delay(DASH);
  digitalWrite(LED_PIN, LOW);
  delay(SYMBOL_GAP);
}

void blinkLetter(char letter) {
  if (letter == 'S') {
    Serial.print("S");
    for (int i = 0; i < 3; i++) blinkDot();
  } else if (letter == 'O') {
    Serial.print("O");
    for (int i = 0; i < 3; i++) blinkDash();
  }
  delay(LETTER_GAP);
}

void blinkSOS() {
  Serial.print("SOS: ");
  blinkLetter('S');
  blinkLetter('O');
  blinkLetter('S');
  Serial.println(" [Complete]");
  delay(1000);
}

void setup() {
  Serial.begin(9600);
  delay(2000);
  
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  
  setupWiFi();
  setupOTA();
}


void loop() {
 ArduinoOTA.handle();
 blinkSOS(); 
}
