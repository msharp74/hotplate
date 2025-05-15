#ifndef PID_H
#define PID_H

class PID
{
  private:
    double m_kp {};
    double m_ki {};
    double m_kd {};
    double m_errorSum {};
    double m_previousParamValue[3] {};
    long m_previousParamTime[3] {};

    void updateParamArrays(double error, double ms);

  public:
    PID(double kp, double ki, double kd)
      : m_kp {kp}, m_ki {ki}, m_kd {kd}
    {}
    double updateParam(double targetValue, double currentValue);

};

#endif
