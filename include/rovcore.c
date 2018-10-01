#include <stdlib.h>
#include <stdio.h>
#include "rovcore.h"

int SETUP_STATUS_INT = -1;

void rov_error(int i) {
    switch(i) {
        case 0:
            perror("Error 0, exiting.\n"); // Be more descriptive than that
            exit(-1);
    }
}

int testfunction(void) {
    printf("This is a test function!");
    return 0;
}
