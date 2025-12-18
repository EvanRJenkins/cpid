#include "pidlite.h"
#include <float.h>
#include <math.h>
#include <stdio.h>
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
  PID->PTerm = (PID->PGain * error);
}
/*
Calculate I term
*/
void pidL_GetI(struct pidL_Config *PID, pidL_t error)
{
  // Multiply I_GAIN by new error and add to moving sum
  PID->ITerm += (PID->IGain * error);
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
  pidL_t sum = (PID->PTerm + PID->ITerm);
  // Normalize sum
  pidL_t scaled = (sum / SCALE_FACTOR);
  if (scaled > SCALE_MAX) {
    scaled = SCALE_MAX;
  }
  else if (scaled < SCALE_MIN) {
    scaled = SCALE_MIN;
  }
  // Give scaled value to CV
  PID->CV = scaled;
}
/*
Adjust PV of target pidL
*/
void pidL_Adjust(struct pidL_Config *PID, pidL_t adjustment_factor)
{
    PID->PV += PID->CV * adjustment_factor;
Zero PTerm, ITerm
*/
void pidL_ClearTerms(struct pidL_Config * PID) {
  PID->PTerm = 0.0;
  PID->ITerm = 0.0;
}
