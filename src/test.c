#include "pidlite.h"
#include <stdio.h>
//
int main(void) {
  struct pidL_Config PID = {
    .PV = 0.0,
    .SP = 20.0,
    .CV = 0.0,
    .PGain = 20.0,
    .IGain = 8.0
  };
  int i = 0;
  for (i = 0; i < 50; i++) {
    pidL_Update(&PID);
    if (i % 2) {
      PID.PV += 2.0;
    }
    printf("PV: %f     CV: %f\n", PID.PV, PID.CV);
    PID.PV += PID.CV * 100.0; 
    printf("PV: %f     CV: %f\n", PID.PV, PID.CV);    printf("PV: %f     CV: %f\n", PID.PV, PID.CV); }
  return 0;
}
