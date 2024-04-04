#include <time.h>
#include "time_manage.h"

#include "file_manage.c"

struct tm *getCurrentDate() {
    time_t now = time(NULL);
    struct tm *currentDate = localtime(&now);
    return currentDate;
}

double getTimeDiff(struct tm *userDOB) {
    time_t timeToday = mktime(getCurrentDate());
    time_t timeAtBirth = mktime(userDOB);
    double timeDiffSecs = difftime(timeToday, timeAtBirth);
    return timeDiffSecs;
}

int daysAlive(struct tm *userDOB) {
    double timeDiff = getTimeDiff(userDOB);
    return timeDiff / (60 * 60 * 24);
}

int hoursAlive(struct tm *userDOB) {
    double timeDiff = getTimeDiff(userDOB);
    return timeDiff / (60 * 60);
}

int minutesAlive(struct tm *userDOB) {
    double timeDiff = getTimeDiff(userDOB);
    return timeDiff / 60;
}

int secondsAlive(struct tm *userDOB) {
    double timeDiff = getTimeDiff(userDOB);
    return timeDiff;
}