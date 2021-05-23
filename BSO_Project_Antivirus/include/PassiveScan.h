#ifndef PASSIVESCAN_H
#define PASSIVESCAN_H

#include "FileHandler.h"

class PassiveScan
{
private:
static PassiveScan *instance;

std::vector<std::string> PassiveScanList;

PassiveScan();
public: 
 static PassiveScan *GetInstance();
std::vector<std::string> GetPassiveScanList();

void AddFolder(std::string foldername);
 
void RemoveFolder(std::string foldername);

};

#endif
