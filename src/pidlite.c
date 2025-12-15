#include "pidlite.h"
/*
Update SP for target PID
*/
void pidLite_setSP(struct pidLite_Config *PID, double new_SP)
{
  // Store input value at target PID SP
  PID->SP = new_SP;
}
/*
Update PV for target PID
*/
void pidLite_setPV(struct pidLite_Config *PID, double new_PV)
{
  // Store input value at target PID PV
  PID->PV = new_PV;
}
/*
Calculate error
*/
double pidLite_getError(struct pidLite_Config *PID)
{
  return (PID->SP - PID->PV);
}
/*
Calculate P term
*/
void pidLite_getP(struct pidLite_Config *PID, double error)
{
  // Multiply defined P_GAIN by most recent error
  PID->Pval = (PID->Pgain * error);
}
/*
Calculate I term
*/
void pidLite_getI(struct pidLite_Config *PID, double error)
{
  // Multiply I_GAIN by new error and add to moving sum
  PID->Ival += (PID->Igain * error);
}
/*
Update target pid
*/
void pidLite_update(struct pidLite_Config *PID) {
  // Find error
  double new_error = pidLite_getError(PID);
  // Calculate P term
  pidLite_getP(PID, new_error);
  // Calculate I term
  pidLite_getI(PID, new_error);
  // Sum terms and update output
  PID->Out = PID->Pval + PID->Ival;
}
