#include "pidlite.h"
#include <stdio.h>

#define OUTPUT_FACTOR 0.10

int main(void) {
  struct pidL_Config PID = {
    .PV = 0.0,
    .SP = 50.0,
    .CV = 0.0,
    .ScaleMax = 200.0,
    .PGain = 10.0,
    .IGain = 2.0
  }; 
  int i = 0;
  for (i = 0; i < 50; i++) {
    pidL_Update(&PID);
    if (i % 2) {
      PID.PV += 1.5;
    }
    printf("Setpoint: %f     Process Value: %f\n", PID.SP, PID.PV);
    PID.PV += PID.CV * OUTPUT_FACTOR;
    printf("Setpoint: %f     Process Value: %f\n", PID.SP, PID.PV);
  }
  return 0;
}
