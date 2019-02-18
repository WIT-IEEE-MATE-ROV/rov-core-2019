#ifndef ROVUTIL
#define ROVUTIL


#define ROVERR_LOSTCONNECTION  0x404
#define ROVERR_HEATSHUTDOWN    0xF112E
#define ROVERR_SHUTDOWNREQUEST 0xD1E
struct RovPIDs {                                                                                                  
    short sensors_PID;
    short commin_PID;
    short commout_PID;
    short thrusters_PID;
    short genericmove_PID;
    short correction_PID;
    short errorcheck_PID;
} ROVPIDS;


int SETUP_STATUS_INT;

void safe_shutdown(void);
short start_child(char *);
short start_child_args(char*, char*);
short stop_child(short);
short checkup_child(short);

#endif
