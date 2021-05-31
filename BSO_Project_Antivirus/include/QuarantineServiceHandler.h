#ifndef QUARANTINESERVICEHANDLER_H
#define QUARANTINESERVICEHANDLER_H

#include <cstdlib>
#include <fstream>
#include <iostream>
//#include <stdlib.h>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>

const std::string QuarantineFolder="/usr/local/share/BSO_Project_Antivirus/quarantine/";
void MoveFileToSafety(std::string filename);
void ChangeFilePermissions(std::string filename);


#endif


