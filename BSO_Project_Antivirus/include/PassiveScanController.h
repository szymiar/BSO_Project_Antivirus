#ifndef PASSIVESCANCONTROLLER_H
#define PASSIVESCANCONTROLLER_H

#include <filesystem>
#include <sys/vfs.h>
#include <string>
#include <unistd.h>
#include <thread>

const std::string PassiveScanListPath="data/passiveScanList/PassiveScanList.txt";
const std::string PassiveScanResults ="data/scanResults/PassiveScanResults.txt";
void TurnOnPassiveScan();

void TurnOffPassiveScan();

void AddFolderToPassiveScan(std::string foldername);

void RemoveFolderFromPassiveScan(std::string foldername);

void DisplayPassiveScanFoldersList();

void PerformScanning();

#endif
