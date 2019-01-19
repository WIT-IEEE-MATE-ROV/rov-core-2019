#include <unistd.h>
#include <stdlib.h>

#include "roverr.h"
#include "../../rovlog/rovlog.h"

void checkup(void) {
}

int spawn(char *path) {
    short pid = fork();
    
    if(pid == 0) {    // If 0, this is the child process
        execl("/bin/sh", "sh", "-c", path, (char *) 0); // Run that command you wanted
        exit(0);      // done!
    }

    if(pid == -1) {
        rovlog(FATAL, "Couldn't spawn a child process.");
    }

    return pid; // If not 0, this is the parent process
}
