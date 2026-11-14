#include <ESP8266WiFi.h>

const char* ssid = "*************"; //keep a 10 character wifi username
const char* password = "***********"; // dont use password less than 8 characters long and dont use 123456789 and check WPA2 personal is set for WI-FI


const int onboardLed = LED_BUILTIN; // Usually GPIO2 / D4 on NodeMCU

void setup() {
  Serial.begin(115200);
  pinMode(onboardLed, OUTPUT);
  
  // Turn LED ON (low) while trying to connect
  digitalWrite(onboardLed, HIGH); 

  WiFi.begin(ssid,password);
  Serial.print("Connecting to Wi-Fi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected to Wi-Fi!");
  
  // Once connected, turn the built-in LED OFF (high) 
  // Or turn it ON if you want it glowing when connected:
  digitalWrite(onboardLed, HIGH); // HIGH = OFF for active-LOW LED
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    // If you want the LED to stay ON when connected:
    digitalWrite(onboardLed, LOW); // LOW = ON
  } else {
    // If disconnected, turn LED OFF or blink:
    digitalWrite(onboardLed, HIGH); // HIGH = OFF
  }
}
