#ifndef ROVUTIL
#define ROVUTIL


#define ROVERR_LOSTCONNECTION  0x404
#define ROVERR_HEATSHUTDOWN    0xF112E
#define ROVERR_SHUTDOWNREQUEST 0xD1E

int SETUP_STATUS_INT;

void safe_shutdown(void);
short start_child(char *);
short stop_child(short);
short checkup_child(short);

#endif
