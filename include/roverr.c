#include "roverr.h"
#include "../rovlog/rovlog.h"

int abort_children() {
}

int start_children() {
}

int safe_shutdown() {
    switch(ROVERR) {
        case ROVERR_LOSTCONNECTION:
            rovlog(FATAL, "I've lost connection to the surface, and can't re-establish a connection");
            rovlog(FATAL, "I'm going to try shutting everything down and bringing it back up again...");
            abort_children();
            start_children();
            rovlog(FATAL, "... Done.");
            break;

        case ROVERR_HEATSHUTDOWN:
            rovlog(FATAL, "Too much heat! I'm shutting down to protect myself.");
            abort_children();
            rovlog(FATAL, "Aborted children. Stopping self now.");
            stop_rovcore();
            break;

        case ROVERR_PLEASEDIE:
            rovlog(FATAL, "Someone asked very nicely for me to shut myself down. Bye!");
            abort_children();
            stop_rovcore();
            break;

        default:
            rovlog(FATAL, "Got an unrecognized shutdown request. Ignoring and resetting ROVERR. Fix that.");
            ROVERR = 0;
            break;
    }
    return ROVERR;
}
