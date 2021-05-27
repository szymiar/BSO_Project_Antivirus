#ifndef PASSIVESCAN_H
#define PASSIVESCAN_H

#include "FileHandler.h"

class PassiveScan
{
private:
static PassiveScan *instance;

std::vector<std::string> PassiveScanList;

bool PassiveScanState;  //true - on ;;; false - off

unsigned int PassiveScanPeriod;  //In seconds

PassiveScan();
public: 
 static PassiveScan *GetInstance();
std::vector<std::string> GetPassiveScanList();

void AddFolder(std::string foldername);
 
void RemoveFolder(std::string foldername);

void SetPassiveScanState(bool state);

bool GetPassiveScanState();

void SetPassiveScanPeriod(unsigned int period);

unsigned int GetPassiveScanPeriod();


};

#endif
