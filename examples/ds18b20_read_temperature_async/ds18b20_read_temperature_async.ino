// Asynchronously reads the temperature from sensor DS18B20

#include <OneWire.h>
#include <DS18B20.h>

// 1-Wire bus Arduino pin
const byte ONEWIRE_PIN = 2;

// Sensor address
// EXAMPLE:
// byte sensorAddress[8] = {0x28, 0xB1, 0x6D, 0xA1, 0x3, 0x0, 0x0, 0x11};
byte sensorAddress[8] = {/* your sensor address here */};


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
  
  // The first requests sensor for measurement
  sensors.request(sensorAddress);
}

void loop() {
  // If the sesor measurement is ready, prnt the results
  if (sensors.available())
  {
    // Reads the temperature from sensor
    float temperature = sensors.readTemperature(sensorAddress);
    
    // Prints the temperature on Serial Monitor
    Serial.print(temperature);
    Serial.println(F(" 'C"));
    
    // Another requests sensor for measurement
    sensors.request(sensorAddress);
  }
  
  // Here, put your code performs without delay
}
