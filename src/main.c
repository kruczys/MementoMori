#include <stdio.h>
#include <time.h>
#include <malloc.h>

// DOB - date of birth

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

int fileWithDOBExists() {
    FILE *file;
    if ((file = fopen("userdob.dat", "rb"))) {
        fclose(file);
        return 1;
    }
    return 0;
}

struct tm *readDateFromFile() {
    FILE *file;
    if ((file = fopen("userdob.dat", "rb"))) {
        struct tm *userDOB = malloc(sizeof(struct tm));
        fread(userDOB, sizeof(struct tm), 1, file);
        fclose(file);
        return userDOB;
    }
    return NULL;
}

struct tm *getInputUserDOB() {
    struct tm *userDOB = malloc(sizeof(struct tm));
    scanf("%d %d %d", &userDOB->tm_year, &userDOB->tm_mon, &userDOB->tm_mday);
    userDOB->tm_year -= 1900;
    userDOB->tm_mon -= 1;
    userDOB->tm_hour = 0;
    userDOB->tm_min = 0;
    userDOB->tm_sec = 0;
}

void createDOBFile() {
    FILE *file;
    const struct tm *userDOB = getInputUserDOB();
    file = fopen("userdob.dat", "wb");
    fwrite(userDOB, sizeof(*userDOB), 1, file);
    fclose(file);
}

struct tm *getUserDOB() {
    if(fileWithDOBExists())
        return readDateFromFile();
    createDOBFile();
    return getUserDOB();
}

int main() {
    struct tm *userDOB = getUserDOB();
    int days = daysAlive(userDOB);
    int hours = hoursAlive(userDOB);
    int minutes = minutesAlive(userDOB);
    int seconds = secondsAlive(userDOB);
    printf("You have been alive for %d days, %d hours, %d minutes, or %d seconds\n", days, hours, minutes, seconds);
    puts("How many of those have you wasted?");
}
