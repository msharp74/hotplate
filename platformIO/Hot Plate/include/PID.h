#ifndef PID_H
#define PID_H

class PID
{
  private:
    double m_kp {};
    double m_ki {};
    double m_kd {};
    double errorSum {};
    double previousParamValue[3] {};
    double previouParamTime[3] {};

  public:
    PID(double kp, double ki, double kd)
      : m_kp {kp}, m_ki {ki}, m_kd {kd}
    {}
    double updateParam(double targetValue, double currentValue);

};

#endif
