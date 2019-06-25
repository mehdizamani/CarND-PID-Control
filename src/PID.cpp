#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */   
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
  previous_cte = 0.0;
  total_err = 0.0;
  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;
  data_points = 0;
  averageErr = 0.0;
  
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
   d_error = cte - previous_cte ;
   p_error = cte ;
   previous_cte = cte;
   i_error += cte;
   total_err +=cte;   
   data_points ++;
   if (data_points !=0)
	   averageErr = total_err/data_points;

}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  double dTemp = -1*(Kp*p_error + Kd*d_error + Ki*i_error);
  return dTemp;  // TODO: Add your total error calc here!
}