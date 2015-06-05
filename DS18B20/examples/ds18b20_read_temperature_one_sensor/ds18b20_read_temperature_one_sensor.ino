// Reads the temperature from one DS18B20 sensor

#include <OneWire.h>
#include <DS18B20.h>

// 1-Wire bus Arduino pin
const byte ONEWIRE_PIN = 2;

// Sensor address
// EXAMPLE:
// byte sensorAddress[8] = {0x28, 0xB1, 0x6D, 0xA1, 0x3, 0x0, 0x0, 0x11};
byte sensorAddress[8] = {/* your sensor address */};

// 1-Wire object
OneWire onewire(ONEWIRE_PIN);
// DS18B20 sensors object
DS18B20 sensors(&onewire);

void setup() {
  // Serial port setup
  while(!Serial);
  Serial.begin(9600);
  
  // DS18B20 sensors setup
  sensors.begin();
}

void loop() {
  // Requests sensor for measurement
  sensors.request(sensorAddress);
  
  // Waiting (block the program) for measurement reesults
  while(!sensors.available());
  
  // Reads the temperature from sensor
  float temperature = sensors.readTemperature(sensorAddress);
  
  // Prints the temperature on Serial Monitor
  Serial.print(temperature);
  Serial.println(F(" 'C"));
}
