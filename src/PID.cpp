#include "PID.h"
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;  //proportional Controller
  this->Ki = Ki;  //integral Controller
  this->Kd = Kd;  //differential Controller
  p_error = i_error = d_error = 0;
}

void PID::UpdateError(double cte) {
  //difference between previous cte and current cte
  d_error = cte - p_error; 
  //update prevoius cte with current cte
  p_error = cte; 
  //accumlated cte
  i_error += cte; 

  std::cout << "P: " << Kp*p_error << " I: " << Ki*i_error << " D: " << Kd*d_error << std::endl; 
}

double PID::TotalError() {
  double e = -Kp * p_error - Kd * d_error - Ki * i_error; 
  if (e > 1){
    e = 1.0;
  }
  if (e < -1){
    e = -1.0;
  }

  return e;
}

