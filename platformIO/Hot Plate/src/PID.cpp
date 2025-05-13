#include "PID.h"

double PID::updateParam(double targetValue, double currentValue)
{
  double error {targetValue - currentValue};
  errorSum += error;

  double proportionalTerm {m_kp * error};
  double integralTerm {m_ki * errorSum};
  double differentialTerm {m_kd};
}
