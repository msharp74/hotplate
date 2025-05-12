#include <Arduino.h>
#include <SPI.h>

uint8_t returnVal {0};
uint8_t data[5] {0};
uint8_t csPin {5};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SPI.begin();
  data[0] = 0b01100000;
  data[1] = 0;
  data[2] = 0;
  pinMode(csPin, OUTPUT);
  digitalWrite(csPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
  digitalWrite(csPin, LOW);

  data[0] = 0b11011000;
  data[1] = 0;
  data[2] = 0;
  data[3] = 0;
  data[4] = 0;

  // Serial.print("Data First Index Sent: \t");
  // Serial.println(data[0], BIN);
  // Serial.print("Data Second Index Sent: \t");
  // Serial.println(data[1], BIN);
  // Serial.print("Data Third Index Sent: \t");
  // Serial.println(data[2], BIN);
  // Serial.print("Data Third Index Sent: \t");
  // Serial.println(data[4], BIN);
  // Serial.print("Data Third Index Sent: \t");
  // Serial.println(data[5], BIN);

  // SPI.transfer(data, 5);
  SPI.transfer(0b00001100);
  uint8_t val1 = SPI.transfer(0);
  uint8_t val2 = SPI.transfer(0);
  Serial.println(val1, BIN);
  Serial.println(val2, BIN);

  // Serial.print("\nData First Index Received: \t");
  // Serial.println(data[0], BIN);
  // Serial.print("Data Second Index Received: \t");
  // Serial.println(data[1], BIN);
  // Serial.print("Data Third Index Received: \t");
  // Serial.println(data[2], BIN);
  // Serial.print("Data Third Index Received: \t");
  // Serial.println(data[3], BIN);
  // Serial.print("Data Third Index Received: \t");
  // Serial.println(data[4], BIN);

  // Serial.println(val, BIN);

  unsigned int voltageBits {0};
  // voltageBits = ((data[1] & 0b00000111) << 8) | data[2];
  // double voltage {3.3 * static_cast<double>(voltageBits) / 4096.0};
  // Serial.println(voltage);
  // Serial.print("\n\n\n");

  digitalWrite(csPin, HIGH);
  SPI.endTransaction();

  delay(2000);
}
