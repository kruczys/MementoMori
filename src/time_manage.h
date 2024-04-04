#ifndef MEMENTOMORI_TIME_MANAGE_H
#define MEMENTOMORI_TIME_MANAGE_H

struct tm *getCurrentDate();
double getTimeDiff(struct tm *userDOB);
int daysAlive(struct tm *userDOB);
int hoursAlive(struct tm *userDOB);
int minutesAlive(struct tm *userDOB);
int secondsAlive(struct tm *userDOB);

#endif
