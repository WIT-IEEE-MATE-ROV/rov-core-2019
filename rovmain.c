#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>
#include <math.h>
#include "./rov-util.h"

void clean_exit() { exit(0); }

int main(const int argc, const char *argv[]) {
    char paths[][64] = {
        "../motor-control/motor-master",
        "../motor-control/thruster-control",
        "../motor-control/thruster-control",
        "../motor-control/thruster-control",
        "../motor-control/thruster-control",
        "../motor-control/thruster-control",
        "../motor-control/thruster-control",
        "../motor-control/thruster-control",
        "../motor-control/thruster-control",
        "../sensor-reading/sensor-master",
        "../sensor-reading/barometer",
        "../sensor-reading/PH_Probe",
        "../sensor-reading/accel-gyro",
        "../sensor-reading/distance_sensor",
        "../sensor-reading/temp-sensor",
        "\0"
    };
    char args[][64] = {
        ".",
        "T_H_FRONTLEFT",
        "T_H_FRONTRIGHT",
        "T_H_BACKLEFT",
        "T_H_BACKRIGHT",
        "T_V_LEFT",
        "T_V_RIGHT",
        "T_V_FRONT",
        "T_V_BACK",
        ".",
        ".",
        ".",
        ".",
        ".",
        ".",
        "\0",
    };

    int path_array_length;
    for(path_array_length = 0; paths[path_array_length][0] != '\0'; ++path_array_length);
    
    int args_array_length;
    for(args_array_length = 0; args[args_array_length][0] != '\0'; ++args_array_length);

    if(path_array_length != args_array_length) {
        perror("Arguments array length does not equal programs array length, check your programs and args!\n");
        exit(-1);
    }

    short pids[path_array_length];

    for(int n = 0; n < path_array_length; ++n) {
        if(args[n][0] == '.') {
            pids[n] = start_child(paths[n]);
        } else {
            pids[n] = start_child_args(paths[n], args[n]);
        }
    }

    signal(SIGTERM, clean_exit);
    signal(SIGINT, clean_exit);
    while(true) {
        for(int n = 0; n < path_array_length; ++n) {
            int result = checkup_child(pids[n]);
            if(result == -2) {
                // Heartbeat failed, so kill the process
                kill(pids[n], 4);
                result = -1; // Set it to -1 so we can indicate it is down
            }

            if(result == -1) {  
                if(args[n][0] == '.') {
                    pids[n] = start_child(paths[n]);
                } else {
                    pids[n] = start_child_args(paths[n], args[n]);
                }
            }
        }
    }
}
