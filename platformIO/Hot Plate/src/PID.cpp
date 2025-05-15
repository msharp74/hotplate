#include "PID.h"
#include "Arduino.h"

void PID::updateParamArrays(double error, double ms)
{
  m_previousParamValue[0] = m_previousParamValue[1];
  m_previousParamValue[1] = m_previousParamValue[2];
  m_previousParamValue[2] = error;

  m_previousParamTime[0] = m_previousParamTime[1];
  m_previousParamTime[1] = m_previousParamTime[2];
  m_previousParamTime[2] = ms;
}

double PID::updateParam(double targetValue, double currentValue)
{
  double error {targetValue - currentValue};
  updateParamArrays(error, millis());

  m_errorSum += error;
  //three-point backward difference
  double derivative {(m_previousParamTime[0] - 4 * m_previousParamTime[1] + 3 * m_previousParamTime[2]) / (2 * ((m_previousParamTime[1] - m_previousParamTime[0]) + (m_previousParamTime[2] - m_previousParamTime[1])) / 2)};

  double proportionalTerm {m_kp * error};
  double integralTerm {m_ki * m_errorSum};
  double differentialTerm {m_kd * derivative};

  return (proportionalTerm + integralTerm + differentialTerm);
}
