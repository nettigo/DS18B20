# DS18B20 sensor library for Arduino

### Advantages:

- Easy
- Async
- Sensor adresses in SRAM or Flash memory
- Easy debug with exceptions

### Disadvantages

- It does not support hardware alarms (nobody cares ;-) )

### Example
```C++
// Asynchronously reads the temperature from sensor DS18B20

#include <OneWire.h>
#include <DS18B20.h>

// 1-Wire bus Arduino pin
const byte ONEWIRE_PIN = 2;

// Sensor address
// EXAMPLE:
// byte sensorAddress[8] = {0x28, 0xB1, 0x6D, 0xA1, 0x3, 0x0, 0x0, 0x11};
byte sensorAddress[8] = {/* your sensor address here */};


OneWire onewire(ONEWIRE_PIN);
DS18B20 sensors(&onewire);

void setup() {
  while(!Serial);
  Serial.begin(9600);
  
  // DS18B20 sensors setup
  sensors.begin();
  
  // The first requests sensor for measurement
  sensors.request(sensorAddress);
}

void loop() {
  // If the sesor measurement is ready, print the results
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
```

### Framework

```C++
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
```

### Reference

#### DS18B20 sensors(&onewire)

Constructor

Argument: Pointer to OneWire object

Return: New DS18B20 object

#### bool begin(quality)

Setup for all ds19b20 sensors in 1-Wire bus.

Argument: quality - measurement resolution in bits (from 9 to 12), default: 12

Return: 

true 

- if all operations were successful

false 
- when the bus is physically damaged
- when devices not respond
- when device address is not valid
- when no devices detected

#### sensors.request()

Request for temperature measurements on all devices

Return:

true 

- if operation were successful

false 

- if devices have different ways of power (combinations of normal and parasite in one bus)
- if devices not responding

#### sensors.request(&address)

Request for temperature measurements on device

Argument: Pointer to an array of device address

Return:
true 

- if operation were successful

false 

- if device not responding

#### sensors.request(FA(address))

Request for temperature measurements on device

Argument: Pointer to an array in flash memory of device address

Return:

true 

- if operation was successful

false 

- if device not responding

#### sensors.available()

Checks if devices completed the measurement

Return:

true 

- the measurement was completed

false 

- the measurement wasn't completed

#### sensors.readTemperature(&address)

Read temperature from device

Argument: Pointer to an array of device address

Return: temperature in degrees Celsius
If the temperature is TEMP_ERROR value - measurement failed because:

- the bus is physically damaged
- devices are not responding
- data from the device is not valid
- no device found with given address

#### sensors.readTemperature(FA(&address))

Read temperature from device

Argument: Pointer to an array in flash memory of device address

Return: temperature in degrees Celsius
If the temperature is TEMP_ERROR value - measurement failed because:

- the bus is physically damaged
- devices not respond
- when data from the device is not valid
- when not detect device of thad address

#### FA(&address)

Pointer type to an array in flash memory of device address

#### E(function(...))

Exceptions catcher
Checks for errors and prints it on Serial Monitor with line number

#### TE(temperature)

Temperature value exception catcher
Checks the wrong temperature and prints it on Serial Monitor with line number

