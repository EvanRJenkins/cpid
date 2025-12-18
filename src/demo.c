#include "pidlite.h"
#include <stdio.h>
#include <unistd.h> // for sleep
//
#define ADJUSTMENT_FACTOR 200.0f
//
void ask_for_sp(struct pidL_Config *PID)
{   
    printf("Enter new SP: ");
    scanf("%f", &PID->SP);
    printf("\n");
}
int main(void) {
	struct pidL_Config PID = {
		.PV = 0.0f,
		.SP = 0.0f,
		.CV = 0.0f,
		.PGain = 16.0f,
		.IGain = 4.0f
	};
    ask_for_sp(&PID);
    int i = 0;
    for (i = 0; i < 70; i++) {
        pidL_Update(&PID);
        pidL_Adjust(&PID, ADJUSTMENT_FACTOR);
        printf("SP: %f,   PV: %f\n", PID.SP, PID.PV);
        sleep(1);
    }
	return 0;
}
