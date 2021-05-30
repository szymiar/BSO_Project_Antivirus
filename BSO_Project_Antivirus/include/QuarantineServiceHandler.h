#ifndef QUARANTINESERVICEHANDLER_H
#define QUARANTINESERVICEHANDLER_H

#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>

const std::string QuarantineFolder="/usr/local/share/BSO_Project_Antivirus/quarantine";
void MoveFileToSafety(std::string filename);
void ChangeFilePermissions(std::string filename);


#endif


