#include <ArduinoJson.h>
// #include <WiFi.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// WIFI VALUES
const char *AP_SSID = "wifiname"; //WIFI NAME
const char *AP_PWD = "wifipass"; // WIFI PASS
String EDP_URL = "apiurl"; //APIURL

//DEVICE VALUES
String controllerId = "1234567890";
String devicePass = "password";

//MEASUREMENT VALUES
float tempC; // temperature in Celsius
float tempF; // temperature in Fahrenheit

//DB MEASUREMENT COLLUMN NAME
String COL = "probe_therm_measure";



WiFiMulti wifiMulti;

// DS18B20 config
#define SENSOR_PIN  17 // ESP32 pin GPIO17 connected to DS18B20 sensor's DATA pin

OneWire oneWire(SENSOR_PIN);
DallasTemperature DS18B20(&oneWire);

void setup() {
  Serial.begin(9600);

  delay(5000);
  wifiMulti.addAP(AP_SSID, AP_PWD);

  DS18B20.begin();    // initialize the DS18B20 sensor
}

void loop() {
  DS18B20.requestTemperatures();       // send the command to get temperatures
  tempC = DS18B20.getTempCByIndex(0);  // read temperature in °C
  tempF = tempC * 9 / 5 + 32; // convert °C to °F
  postDataToServer();
}

void postDataToServer() {
 
  Serial.println("Checking wifi connection...");
  // Block until we are able to connect to the WiFi access point
  if (wifiMulti.run() == WL_CONNECTED) {
     
    Serial.println("Posting JSON data to server...");

    HTTPClient http;   
     
    http.begin(EDP_URL);  
    http.addHeader("Content-Type", "application/json");         
     
    StaticJsonDocument<200> doc;
    // Add values in the document
    //
    doc["controller_id"] = controllerId;
    doc["device_pass"] = devicePass;
    doc[COL] = tempF;
     
    String requestBody;
    serializeJson(doc, requestBody);
     
    int httpResponseCode = http.POST(requestBody);
 
    if(httpResponseCode>0){
       
      String response = http.getString();                       
       
      Serial.println(httpResponseCode);   
      Serial.println(response);
      delay(1000);
    } else {
      Serial.printf("Error occurred while sending HTTP POST: %s\n", http.errorToString(httpResponseCode).c_str());
    }
     
  }
}