#ifndef PIDLITE_H
#define PIDLITE_H
/*
Config struct for pid lib
*/
struct pidLite_Config {
  // Setpoint and process value
  double SP, PV;
  // Proportinal, integral, derivative terms
  double Pval, Ival, Out;
  // Gain factors
  const double Pgain, Igain;
};
/*
Update SP at target PID
*/
void pidLite_setSP(struct pidLite_Config *PID, double new_SP);
/*
Update PV at target PID
*/
void pidLite_setPV(struct pidLite_Config *PID, double new_PV);
/*
Calculate error
*/
double pidLite_getError(struct pidLite_Config *PID);
/*
Calculate P term
*/
void pidLite_getP(struct pidLite_Config *PID, double error);
/*
Calculate I term
*/
void pidLite_getI(struct pidLite_Config *PID, double error);
/*
Update target pid
*/
void pidLite_update(struct pidLite_Config *PID);
//
#endif
