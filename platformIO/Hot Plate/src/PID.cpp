class PID
{
  private:
    double m_kp {0};
    double m_ki {0};
    double m_kd {0};

  public:
    PID(double kp, double ki, double kd)
      : m_kp {kp}, m_ki {ki}, m_kd {kd}
    {}
    

};