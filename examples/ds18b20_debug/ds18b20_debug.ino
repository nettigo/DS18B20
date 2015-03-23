// Reads the temperature from DS18B20 sensor with debug check

#include <OneWire.h>
#include <DS18B20.h>

// 1-Wire bus Arduino pin
const byte ONEWIRE_PIN = 2;

// Sensor address
// EXAMPLE:
// const byte sensorAddress[8] PROGMEM = {0x28, 0xB1, 0x6D, 0xA1, 0x3, 0x0, 0x0, 0x11};
const byte sensorAddress[8] PROGMEM = {/* Your sensor address here */};


// 1-Wire object
OneWire onewire(ONEWIRE_PIN);
// DS18B20 sensors object
DS18B20 sensors(&onewire);

void setup() {
  // Serial port setup
  while(!Serial);
  Serial.begin(9600);

  // DS18B20 sensors setup
  // *** E() checks for errors and prints it on Serial Monitor with line number
  E(sensors.begin());

  // The first requests sensor for measurement
  // Address from Flash memory
  // *** E() checks for errors and prints it on Serial Monitor with line number
  E(sensors.request(FA(sensorAddress)));
}

void loop() {
  // If the sesor measurement is ready, prnt the results
  if (sensors.available())
  {
    // Reads the temperature from sensor
    // *** Address from Flash memory
    float temperature = sensors.readTemperature(FA(sensorAddress));

    // *** TE() checks the wrong temperature and prints it on Serial Monitor with line number
    TE(temperature);

    // Prints the temperature on Serial Monitor
    Serial.print(temperature);
    Serial.println(F(" 'C"));

    // Another requests sensor for measurement
    // Address from Flash memory
    // *** E() checks for errors and prints it on Serial Monitor with line number
    E(sensors.request(FA(sensorAddress)));
  }

  // Here, put your code performs without delay
}
