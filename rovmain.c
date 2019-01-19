#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "include/rovcore.h"
#include "include/spawn.h"
#include "include/roverr.h"

int main(const int argc, const char *argv[]) {
    if( setup() != 0 ) {
        printf("Setup failed!\n");
        rov_error(SETUP_STATUS_INT);
    }

    ROVPIDS.sensors_PID      = spawn("./sensor-read");
    ROVPIDS.commin_PID       = spawn("./commin");
    ROVPIDS.commout_PID      = spawn("./commout");
    ROVPIDS.thrusters_PID    = spawn("./thrusters");
    ROVPIDS.genericmove_PID  = spawn("./genericmove");
    ROVPIDS.correction_PID   = spawn("./corrections");
    ROVPIDS.errorcheck_PID   = spawn("./errorcheck");
    
    while(true) {
        checkup();

        if(ROVERR != 0) {
            // Something broke!
            safe_shutdown(ROVERR);
            return ROVERR;
        }
    }
}

