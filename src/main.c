#include <stdio.h>
#include <time.h>
#include <malloc.h>

// DOB - date of birth

struct tm *getCurrentDate() {
    time_t now = time(NULL);
    struct tm *currentDate = localtime(&now);
    return currentDate;
}

int daysAlive(struct tm *userDOB) {
    // return days alive
    struct tm *currentDate = getCurrentDate();
    return 0;
}

int hoursAlive(struct tm *userDOB) {
    // return hours alive
    struct tm *currentDate = getCurrentDate();
    return 0;
}

int minutesAlive(struct tm *userDOB) {
    // return minutes alive
    struct tm *currentDate = getCurrentDate();
    return 0;
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
    return NULL;
}

void createDOBFile() {
    FILE *file;
    const struct tm *userDOB = getCurrentDate();
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
    struct tm *test = getUserDOB();
    printf("%s", asctime(test));
    return 0;
}
