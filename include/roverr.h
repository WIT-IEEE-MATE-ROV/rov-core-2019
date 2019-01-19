#ifndef ROVERRORS
#define ROVERRORS

#define ROVERR_LOSTCONNECTION 0x404
#define ROVERR_HEATSHUTDOWN   0xF112E
#define ROVERR_PLEASEDIE      0xD1E
struct RovPIDs {
    short sensors_PID;
    short commin_PID;
    short commout_PID;
    short thrusters_PID;
    short genericmove_PID;
    short correction_PID;
    short errorcheck_PID;
} ROVPIDS;
int ROVERR = 0;

int safe_shutdown();
int abort_children();
int start_children();

#endif
