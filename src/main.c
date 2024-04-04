#include "time_manage.c"
#include "file_manage.c"

int main() {
    const struct tm *userDOB = getUserDOB();
    int days = daysAlive(userDOB);
    int hours = hoursAlive(userDOB);
    int minutes = minutesAlive(userDOB);
    int seconds = secondsAlive(userDOB);
    printf("You have been alive for %d days, %d hours, %d minutes, or %d seconds\n", days, hours, minutes, seconds);
    puts("How many of those have you wasted?");
}
