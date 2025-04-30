#include <iostream>
#include <unistd.h>
#include "/home/matt/WiringPi/wiringPi/wiringPi.h"
#include "/home/matt/WiringPi/wiringPi/wiringPiSPI.h"
#include <string.h>

int main() {
  wiringPiSetupPinType(WPI_PIN_BCM);
  pinMode(2, OUTPUT);

  wiringPiSPISetup(0,  25000);
  unsigned char data[3] = {0};
  int returnValue {0};
  const double v_ref = 3.3;

  data[0] = 0b00000110;
  data[1] = 0;
  data[2] = 0;

  //std::string unsigned int charToByteString(unsigned char input)
  //{
    
    
  //}

  while (1)
  {
    data[0] = 0b00000110;
    data[1] = 0;
    data[2] = 0;

    returnValue = wiringPiSPIDataRW(0, data, 3);
    std::cout << "returnValue = " << returnValue << std::endl;
    std::cout << "data[0] = 0x" << std::hex << (unsigned int)data[0] << std::endl;
    std::cout << "data[1] = 0x" << std::hex << (unsigned int)data[1] << std::endl;
    std::cout << "data[2] = 0x" << std::hex << (unsigned int)data[2] << std::endl;

    unsigned int voltage_bits = {0};
    voltage_bits = ((data[1] << 8) | (data[2]));
    double voltage = {0};
    voltage = (double)voltage_bits / 4096 * v_ref;
    std::cout << voltage << std::endl;

    digitalWrite(2, HIGH);
    //std::cout << "HIGH" << std::endl;
    sleep(2);
    digitalWrite(2, LOW);
    //std::cout << "LOW" << std::endl;
    sleep(2);
  }
  wiringPiSPIClose(0);

  std::cout << "Hello, World!" << std::endl;
  return 0;
}
