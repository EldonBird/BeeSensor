#include <DHT.h>
#include <DHT_U.h>

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>


#define DHTTYPE DHT11

WiFiClient wifiClient;



DHT dht(D4, DHTTYPE);

byte mac[6];

void setup () {
  Serial.begin(115200);
  WiFi.begin("TMOBILE-wifi", "finishing.linguini.quote.chaplain");
 
  while (WiFi.status() != WL_CONNECTED) {
 
    delay(1000);
    Serial.println("Connecting..");
 
  }
  Serial.println("Connected to WiFi Network");

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(D4, INPUT);
  digitalWrite(LED_BUILTIN, LOW);

  WiFi.macAddress(mac);
 
}

 
void loop() {

  digitalWrite(LED_BUILTIN, LOW);

  dht.begin();

  float hum = dht.readHumidity();
  float temp = dht.readTemperature(false);
  

  
 
  if (WiFi.status() == WL_CONNECTED) { 
 
    HTTPClient http;
 
    http.begin(wifiClient, "http://127.0.0.1:24640/Submit");
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
 
    String requestData = ("temp=" + String(temp) + "&hum" + String(hum) + "&mac" + mac.c_str());
    int httpCode = http.POST(requestData);

    String payload = http.getString();
    Serial.println("Transmitting");
 
    http.end();  
 
  }


  delay(1000);                      // Wait for a second
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(2000);                      // Wait for two seconds (to demonstrate the active low LED)

}
