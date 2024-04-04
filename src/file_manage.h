#ifndef MEMENTOMORI_FILE_MANAGE_H
#define MEMENTOMORI_FILE_MANAGE_H

void createDOBFile();
int fileWithDOBExists();
struct tm *readDateFromFile();
struct tm *getInputUserDOB();
struct tm *getUserDOB();

#endif
