#include <OneWire.h>
#include <DS18B20.h>

const byte ONEWIRE_PIN = 2;

OneWire onewire(ONEWIRE_PIN);
DS18B20 sensors(&onewire);

void setup() {
  // put your setup code here, to run once:
  sensors.begin();

}

void loop() {
  // put your main code here, to run repeatedly:

}
