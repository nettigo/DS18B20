#ifndef _DS18B20_h_
#define _DS18B20_h_

#include <Arduino.h>
#include <inttypes.h>
#include <OneWire.h>

#define TEMP_ERROR -273.15f

class DS18B20
{
public:
  DS18B20(OneWire *oneWire);
  bool begin(uint8_t quality=12);
  bool request(void);
  bool request(uint8_t *address);

  bool available(void);
  float readTemperature(uint8_t *address);

private:
  OneWire *_oneWire;
  uint8_t _quality;
  bool _samePowerType;
  bool _powerType;
  uint32_t _beginConversionTime;

  bool _sendCommand(uint8_t *address, uint8_t command);
  bool _sendQuality(uint8_t *address);
  bool _receivePowerType(uint8_t *address);
};
#endif
