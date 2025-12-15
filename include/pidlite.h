#ifndef PIDLITE_H
#define PIDLITE_H
/*
Configuration header
*/
#include "config.h"
/*
If USE_FLOAT defined in config.h,
use float instead of double
*/
#ifdef USE_FLOAT
  typedef float pidL_t;
#else
  typedef double pidL_t;
#endif
/*
Config struct for pid lib
*/
struct pidL_Config {
  // Setpoint and process value
  pidL_t SP, PV;
  // Control variable (unscaled output)
  pidL_t CV;
  // CV scale bound
  const pidL_t ScaleMax;
  // Proportional and Integral gains
  // NOTE: Consider removing const
  const pidL_t PGain, IGain;
  // Proportional and integral terms
  pidL_t PTerm, ITerm;
};
/*
Update SP at tarGet PID
*/
void pidL_SetSP(struct pidL_Config *PID, pidL_t new_SP);
/*
Update PV at tarGet PID
*/
void pidL_SetPV(struct pidL_Config *PID, pidL_t new_PV);
/*
Calculate error
*/
pidL_t pidL_GetError(struct pidL_Config *PID);
/*
Calculate P term
*/
void pidL_GetP(struct pidL_Config *PID, pidL_t error);
/*
Calculate I term
*/
void pidL_GetI(struct pidL_Config *PID, pidL_t error);
/*
Update tarGet pid
*/
void pidL_Update(struct pidL_Config *PID);
//
pidL_t pidL_Compute(struct pidL_Config *PID);
#endif
