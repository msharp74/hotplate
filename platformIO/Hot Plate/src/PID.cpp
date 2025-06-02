#include "PID.h"
#include "Arduino.h"

double PID::updateParam(double targetValue, double currentValue, double timeInterval)
{
  double error {targetValue - currentValue};
  updateArray(previousErrorValue, error);
  updateArray(previousErrorTime, timeInterval);
  updateParamArrays(error, millis());

  m_errorSum += error;
  //three-point backward difference
  double derivative {(m_previousParamTime[0] - 4 * m_previousParamTime[1] + 3 * m_previousParamTime[2]) / (2 * ((m_previousParamTime[1] - m_previousParamTime[0]) + (m_previousParamTime[2] - m_previousParamTime[1])) / 2)};

  //Three-point backward difference formula
  double derivative {(previousErrorValue[0] - 4 * previousErrorValue[1] + 3 * previousErrorValue[2]) / (2* timeArrayAverage())};

  double proportionalTerm {m_kp * error};
  double integralTerm {m_ki * m_errorSum};
  double differentialTerm {m_kd * derivative};

  m_controlParameter += proportionalTerm + integralTerm + differentialTerm;
  return m_controlParameter;
}

double PID::timeArrayAverage()
{
  double sum {};

  for (int index {0}; index < 3; index ++)
  {
    sum += previousErrorValue[index];
  }

  double average {sum / 3};
  return average;
}

void PID::updateArray(double array[3], double value)
{
  array[0] = array[1];
  array[1] = array[2];
  array[2] = value;
}