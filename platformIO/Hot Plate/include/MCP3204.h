#ifndef MCP3204_H
#define MCP3204_H

class MCP3204
{
  private:
    int m_csPin {};
    
  public:
    MCP3204(int csPin);
    double readADC(int channel, float refVoltage);
};

#endif
