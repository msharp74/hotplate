#include <Arduino.h>
#include <SPI.h>

uint8_t returnVal {0};
uint8_t data[3] {0};
uint8_t csPin {5};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SPI.begin();
  data[0] = 0b00000110;
  data[1] = 0;
  data[2] = 0;
  pinMode(csPin, OUTPUT);
  digitalWrite(csPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  SPI.beginTransaction(SPISettings(14000000, MSBFIRST, SPI_MODE0));
  digitalWrite(csPin, LOW);

  data[0] = 0b00000110;
  data[1] = 0;
  data[2] = 0;

  SPI.transfer(data, 3);
  Serial.print("Data First Index: \t");
  Serial.println(data[0], BIN);
  Serial.print("Data Second Index: \t");
  Serial.println(data[1], BIN);
  Serial.print("Data Third Index: \t");
  Serial.println(data[2], BIN);

  unsigned int voltageBits {0};
  

  digitalWrite(csPin, HIGH);
  SPI.endTransaction();

  sleep(2);
}
