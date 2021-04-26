#ifndef QUARANTINESERVICEHANDLER_H
#define QUARANTINESERVICEHANDLER_H

#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>

void MoveFileToSafety(std::string filename);
void ChangeFilePermissions(std::string filename);


#endif


