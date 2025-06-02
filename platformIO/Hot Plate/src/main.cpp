#include <Arduino.h>
#include <SPI.h>
#include "MCP3204.h"
#include "PID.h"

const uint8_t pwmPin {4};
const uint8_t csPin {5};
uint8_t returnVal {0};
uint8_t data[3] {0};
MCP3204 adc {csPin};
PID pid {0.1, 0.1, 0};

struct ReflowSubsectionDetails
{
  int temp;        //in degrees celsius
  int duration;    //in seconds
};

enum ReflowSubsection
{
  preheat,
  soak,
  reflow,
  numSubsections
};

//define all reflow profiles for any solder paste that is to be used
ReflowSubsectionDetails SN42BI58[ReflowSubsection::numSubsections] {(80, 120), (110, 120), (155, 35)};


void setup()
{
  Serial.begin(9600);
  pinMode(4, OUTPUT);


}

void loop()
{
  unsigned long currentTime {millis()};
  while (millis() - currentTime < 1.0) {}
  if (millis() - currentTime > 1.0)
  {
    analogWrite(4, pid.getControlParam());
    //PID;
  }
  Serial.println(adc.readADC(0, 3.3));
  
  delay(2000);
}
