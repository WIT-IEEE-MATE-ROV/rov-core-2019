#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>
#include <math.h>
#include "./rov-util.h"

void clean_exit() { exit(0); }

int main(const int argc, const char *argv[]) {
    start_child("../motor-control/motor-master\0");
    start_child("../sensor-reading/sensor-master\0");
    start_child("../rovlog/rovlog-server\0");

    signal(SIGTERM, clean_exit);
    signal(SIGINT, clean_exit);
    while(true) {
        checkup_child(-1); // TODO
    }
}
