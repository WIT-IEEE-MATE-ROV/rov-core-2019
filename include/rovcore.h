#ifndef ROVCORE
#define ROVCORE

#ifdef ROVMODE
    #include "rovonly.h"
#endif
#ifndef ROVMODE
    #include "rovsim.h"
#endif

int SETUP_STATUS_INT;

void rov_error(int);
int testfunction(void);

#endif
