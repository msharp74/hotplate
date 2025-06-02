#ifndef PID_H
#define PID_H

class PID
{
  private:
    double m_controlParameter {};
    double m_kp {};
    double m_ki {};
    double m_kd {};
    double m_errorSum {};
    double previousParamValue[3] {};
    double previousParamTime[3] {};
    double previousErrorValue[3] {};
    double previousErrorTime[3] {};

  public:
    PID(double kp, double ki, double kd)
      : m_kp {kp}, m_ki {ki}, m_kd {kd}
    {}
    double updateParam(double targetValue, double currentValue, double timeInterval);
    double timeArrayAverage();
    void updateArray(double array[3], double value);
    double getControlParam() {return m_controlParameter;}

};

#endif
