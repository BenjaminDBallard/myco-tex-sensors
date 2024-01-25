#include <WiFi.h>
#include <HTTPClient.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// user config: TODO
const char WIFI_SSID[] = "ssd"; // CHANGE IT
const char WIFI_PASSWORD[] = "pass"; // CHANGE IT

//DS18B20 config
#define SENSOR_PIN  17 // ESP32 pin GPIO17 connected to DS18B20 sensor's DATA pin

OneWire oneWire(SENSOR_PIN);
DallasTemperature DS18B20(&oneWire);
float tempC; // temperature in Celsius
float tempF; // temperature in Fahrenheit

void setup() {
 // open serial
  Serial.begin(9600);
  Serial.println("*****************************************************");
  Serial.println("********** Program Start : Connect ESP32 Therm to DB.");
  Serial.println("Wait for WiFi... ");

  // connecting to the WiFi network
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // connected
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());

  // initialize device.
  DS18B20.begin();    // initialize the DS18B20 sensor
}

void loop() {
  // Print temperature sensor details.
  DS18B20.requestTemperatures();       // send the command to get temperatures
  tempC = DS18B20.getTempCByIndex(0);  // read temperature in °C
  tempF = tempC * 9 / 5 + 32; // convert °C to °F
  Serial.print("probe_therm_measure: ");
  Serial.println(tempF);    // print the temperature in °F


  delay(500);    // delay
}