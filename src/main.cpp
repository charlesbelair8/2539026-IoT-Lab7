#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include <WiFi.h>
#include <WebServer.h>

Adafruit_BMP280 bmp;


float temperature;

const char* ssid = "BestWifiEver";
const char* password = "password123";

WebServer server(80);
// Paste the webpage code here	

// Create the following function after the webpage code:
void handleRoot()
{
 
}

void setup()
{
  Serial.begin(115200);
  Serial.println("Program Started");
  
  Wire.begin();
 
    if(bmp.begin(0x76))
    {
      Serial.println("BMP280 Found");
      }
    else
    {
      Serial.println("BMP280 Not Found");
   }

  WiFi.softAP(ssid, password);
    Serial.print("IP Address: ");
    Serial.println(WiFi.softAPIP());
  
  server.begin();
    Serial.println("Web Server Started");

  // BMP280 code
	// LED code
	// Wi-Fi code
	// Routes
	// Server start
}
void loop(){
   temperature = bmp.readTemperature();
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" C");
      delay(1000);
}
