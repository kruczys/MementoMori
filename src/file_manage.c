#include <stdio.h>
#include <malloc.h>
#include <time.h>

#include "file_manage.h"

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