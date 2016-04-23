#include <UbidotsESP8266.h>
#include <SoftwareSerial.h> 

#define SSID "Your_WiFi_SSID_here"
#define PASS "Your_WiFi_PASWORD_here"

#define TOKEN "Your_token_here"
#define ID "Your_VariableID_here"

// Create a Client object
Ubidots client(TOKEN);

void setup() {
  Serial.begin(9600);
  // Connect Wifi
  client.wifiConnection(SSID,PASS);
  // Open TCP connection
  client.tcpConnection();
}

void loop() {
  float value = analogRead(A0);
  // Send one value
  client.saveValue(ID,value);
}
