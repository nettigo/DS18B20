// Search addresses of sensors DS18B20

#include <OneWire.h>

OneWire onewire(2);

void setup()
{
  while(!Serial);
  Serial.begin(9600);
}

void loop()
{
  byte address[8];
  
  onewire.reset_search();
  while(onewire.search(address))
  {
    if (address[0] != 0x28)
      continue;
      
    if (OneWire::crc8(address, 7) != address[7])
    {
      Serial.println(F("1-Wire bus connection error!"));
      break;
    }
    
    for (byte i=0; i<8; i++)
    {
      Serial.print(F("0x"));
      Serial.print(address[i], HEX);
      
      if (i < 7)
        Serial.print(F(", "));
    }
    Serial.println();
  }
  
  while(1);
}
