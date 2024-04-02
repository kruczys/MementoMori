#include <stdio.h>
#include <time.h>

// DOB - date of birth

struct tm *getCurrentDate() {
    time_t now = time(NULL);
    struct tm *currentDate = localtime(&now);
    return currentDate;
}

int daysAlive(struct tm *currentDate, struct tm *userDOB) {
    // return days alive
    return 0;
}

int hoursAlive(struct tm *userDOB) {
    // return hours alive
    struct tm *currentDate = getCurrentDate();
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

int isFileWithDOBProper() {
    return 1;
}

const struct tm *parseDateFromFile() {
    struct tm *temp = getCurrentDate();
    return temp;
}

const struct tm *getInputUserDOB() {
    return NULL;
}

void createDOBFile() {
    FILE *file;
    const struct tm *userDOB = getInputUserDOB();
    file = fopen("userdob.txt", "w");
    fprintf(file, "%s", asctime(userDOB));
    fclose(file);
}



const struct tm *getUserDOB() {
    // for now user dob will be current date
    if(fileWithDOBExists() && isFileWithDOBProper())
        return parseDateFromFile();
    createDOBFile();
    return getUserDOB();

    // should also check if date in file is proper if not then create new file from prompt
    // here will call function to get dob from file instead of returning null
    // return getUserDOBFromFile
    // will call function to get userDOB from prompt
    // if file exists but date is not proper then it should be overwritten by proper date
}

int main() {
    getUserDOB();
    return 0;
}
