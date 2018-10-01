#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "include/rovcore.h"

int main(const int argc, const char *argv[]) {
    if( setup() != 0 ) {
        printf("Setup failed!\n");
        rov_error(SETUP_STATUS_INT);
    }

    testfunction();

    return 0;
}

