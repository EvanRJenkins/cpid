#include "pidlite.h"
/*
Update SP for tarGet PID
*/
void pidL_SetSP(struct pidL_Config *PID, pidL_t new_SP)
{
  // Store input value at tarGet PID SP
  PID->SP = new_SP;
}
/*
Update PV for tarGet PID
*/
void pidL_SetPV(struct pidL_Config *PID, pidL_t new_PV)
{
  // Store input value at tarGet PID PV
  PID->PV = new_PV;
}
/*
Calculate error
*/
pidL_t pidL_GetError(struct pidL_Config *PID)
{
  return (PID->SP - PID->PV);
}
/*
Calculate P term
*/
void pidL_GetP(struct pidL_Config *PID, pidL_t error)
{
  // Multiply defined P_GAIN by most recent error
  PID->Pval = (PID->Pgain * error);
}
/*
Calculate I term
*/
void pidL_GetI(struct pidL_Config *PID, pidL_t error)
{
  // Multiply I_GAIN by new error and add to moving sum
  PID->Ival += (PID->Igain * error);
}
/*
Update target pidL
*/
void pidL_Update(struct pidL_Config *PID) {
  // Find error
  pidL_t new_error = pidL_GetError(PID);
  // Calculate P term
  pidL_GetP(PID, new_error);
  // Calculate I term
  pidL_GetI(PID, new_error);
  // Sum terms and Update output
  PID->CV = PID->Pval + PID->Ival;
}
