#include "PID.h"

//using namespace std;

/*
* Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp; // Propotional
  this->Ki = Ki; // Integral
  this->Kd = Kd; // Derivative

  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;

  pre_cte = 0.0;


  //paramters
  counter = 0;
}

void PID::UpdateError(double cte) {

  // Propotional error
  p_error = cte;

  // Integral error
  i_error += cte;

  // Derivative error
  d_error = cte - pre_cte;

  pre_cte = cte;
  counter ++;
}

double PID::TotalError() {
  return -(Kp * p_error + Ki * i_error + Kd * d_error);
}

