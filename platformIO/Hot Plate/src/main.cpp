#include <Arduino.h>
#include <SPI.h>
#include "MCP3204.h"

uint8_t returnVal {0};
uint8_t data[3] {0};
uint8_t csPin {5};
MCP3204 adc {csPin};

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() 
{
  Serial.println(adc.readADC(0, 3.3));
  
  delay(2000);
}
