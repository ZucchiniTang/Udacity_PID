#include "PID.h"
#include <iostream>
using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	p_error = 0.0;
	i_error = 0.0;
	d_error = 0.0;

	Kp_ = Kp;
	Ki_ = Ki;
	Kd_ = Kd;
}

void PID::UpdateError(double cte) {
	// equation of PID: -Kp * cte    - Kd * diff_cte - Ki * int_cte   
	//     ---------->	Kp * p_error + Kd * d_error  + Ki * i_error	
	// i_error = - diff_cte = -(p_error - cte) 
	d_error = cte - p_error;
	
	p_error = cte;

	// the integral error term is simply the sum of cte
	i_error += cte; 
	std::cout << "P = " << p_error << " | I = " << i_error << " | D = " << d_error << std::endl;
}

double PID::TotalError() {
	return Kp_ * p_error + Ki_*i_error + Kd_*d_error;
}

