#include <stdio.h>
#include <time.h>

int daysAlive(struct tm *currentDate, struct tm *userDOB) {
    // return days alive
    return 0;
}

int hoursAlive(struct tm *currentDate, struct tm *userDOB) {
    // return hours alive
    return 0;
}

int minutesAlive(struct tm *currentDate, struct tm *userDOB) {
    // return minutes alive
    return 0;
}

int fileWithDOBExists() {
    FILE *file;
    if ((file = fopen("userdob.txt", "r"))) {
        fclose(file);
        return 1;
    }
    return 0;
}

void createDOBFile() {

}

struct tm *getCurrentDate() {
    time_t now = time(NULL);
    struct tm *currentDate = localtime(&now);
    return currentDate;
}

struct tm *getUserDOB() {
    // look for file with dob if doesnt exist ask user for dob and create file
    // return parsed dob as struct tm
    time_t now = time(NULL);
    struct tm *tempDate = localtime(&now);
    return tempDate;
}

int main() {
    struct tm *date = getCurrentDate();

    printf("Current date and time: %d-%02d-%02d %02d:%02d:%02d\n",
           1900 + date->tm_year,
           date->tm_mon + 1,
           date->tm_mday,
           date->tm_hour,
           date->tm_min,
           date->tm_sec);

    printf("%d", fileWithDOBExists());
    return 0;
}
