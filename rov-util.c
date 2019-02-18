#include "rov-util.h"
#include "stdlib.h"
#include "unistd.h"
#include "stdio.h"
#include "string.h"
#include "../rovlog/rovlog.h"

void safe_shutdown(void) {
    //TODO
}

short start_child(char *path) {
    //TODO
    int forkval = fork();
    if(forkval < 0) {
        perror("fork");
        exit(-1);
    } else if (forkval > 0) {
        // I'm the parent.
        return forkval;
    } else {
        // I'm the child, so I'm going to be the new process.
        int errval = execvp(path, NULL);
        char buff[64];
        sprintf(buff, "Process %s closed: %i ", path, errval);
        perror("child exit: ");
        rovlog(INFO, buff); // If we got here, the process closed.
    }
}

short start_child_args(char *path, char *arg) {
    int forkval = fork();
    if(forkval < 0) {
        perror("fork");
        exit(-1);
    } else if (forkval > 0) {
        // I'm the parent.
        return forkval;
    } else {
        // I'm the child, so I'm going to be the new process.
        int errval = execvp(path, arg);
        char buff[64];
        sprintf(buff, "Process %s closed: %i ", path, errval);
        perror("child exit: ");
        rovlog(INFO, buff); // If we got here, the process closed.
    }
}
short stop_child(short pid) {
    //TODO
}

short checkup_child(short pid) {
    // POSIX standard says kill -0 to check if process exists
    int killresult = kill(pid, 0);

    if(killresult != 0)
        return -1; // The process does not exist and needs to be restarted
   else 
       return 0;

   // TODO: Use the heartbeat stuff
}
