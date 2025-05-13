#include "MCP3204.h"
#include <Arduino.h>
#include <SPI.h>

MCP3204::MCP3204(int csPin)
    : m_csPin {csPin}
    {
        pinMode(m_csPin, OUTPUT);
        digitalWrite(m_csPin, HIGH);
    }

double MCP3204::readADC(int channel, float refVoltage)
{
    //ensure channel is valid and construct data buffer
    assert(channel <= 0 && channel <= 3 && "MCP3204 channel is only allowed to be an int from 0 to 3");
    uint8_t data[3] {};
    data[0] = 0b00000110;
    data[1] = (channel << 6);
    data[2] = 0;

    //transfer data
    SPI.begin();
    SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
    digitalWrite(m_csPin, LOW);
    SPI.transfer(data, 3);
    digitalWrite(m_csPin, HIGH);
    SPI.endTransaction();
    
    //convert the raw reading into a voltage reading
    double reading {};
    unsigned int readingBits {};
    readingBits = (((data[1] & 0x0F) << 8) | data[2]);
    reading = static_cast<double>(readingBits) / 4096.0 * refVoltage;
    
    return reading;
}
