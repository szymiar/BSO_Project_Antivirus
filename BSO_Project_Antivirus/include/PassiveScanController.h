#ifndef PASSIVESCANCONTROLLER_H
#define PASSIVESCANCONTROLLER_H

#include <filesystem>
#include <sys/vfs.h>
#include <string>


const std::string PassiveScanListPath="passiveScanList/PassiveScanList.txt";

void TurnOnPassiveScan();

void TurnOffPassiveScan();

void AddFolderToPassiveScan(std::string foldername);

void RemoveFolderFromPassiveScan(std::string foldername);

void DisplayPassiveScanFoldersList();

void PerformScanning();

#endif
