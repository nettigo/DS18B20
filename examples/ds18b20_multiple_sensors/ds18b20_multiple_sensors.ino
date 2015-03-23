// Reads the temperature from multiple sensors DS18B20.

#include <OneWire.h>
#include <DS18B20.h>

// 1-Wire bus Arduino pin
const byte ONEWIRE_PIN = 2;

// Number of sensors
const byte SENSORS_NUM = /* number */;

// Sensors address
// EXAMPLE:
// const byte sensorsAddress[SENSORS_NUM][8] PROGMEM = {
//     0x28, 0xB1, 0x6D, 0xA1, 0x3, 0x0, 0x0, 0x11,
//     0x28, 0x87, 0x6A, 0xA1, 0x3, 0x0, 0x0, 0x1F
// };

const byte sensorsAddress[SENSORS_NUM][8] PROGMEM = {
    /* Your #1 sensor address here,
       Your #2 sensor address here,
    ...*/
};


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

  // The first requests to all sensors for measurement
  sensors.request();
}

void loop() {
  // If the sesor measurement is ready, prnt the results
  if (sensors.available())
  {
    for (byte i=0; i<SENSORS_NUM; i++)
    {
      // Reads the temperature from sensor
      // *** Indexed address from Flash memory
      float temperature = sensors.readTemperature(FA(sensorsAddress[i]));

      // Prints the temperature on Serial Monitor
      Serial.print(F("#"));
      Serial.print(i);
      Serial.print(F(": "));
      Serial.print(temperature);
      Serial.println(F(" 'C"));
    }

    // Another requests to all sensors for measurement
    sensors.request();
  }

  // Here, put your code performs without delay
}
