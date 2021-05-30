#ifndef PASSIVESCANCONTROLLER_H
#define PASSIVESCANCONTROLLER_H

#include <filesystem>
#include <sys/vfs.h>
#include <string>
#include <unistd.h>
#include <thread>
#include <dirent.h>
#include <iterator>
#include <syslog.h>
#include <cstdlib>



const std::string PassiveScanListPath="/usr/local/share/BSO_Project_Antivirus/data/passiveScanList/PassiveScanList.txt";
const std::string PassiveScanResults ="/usr/local/share/BSO_Project_Antivirus/data/scanResults/PassiveScanResults.txt";
const std::string PassiveScanStatePath="/usr/local/share/BSO_Project_Antivirus/data/passiveScanList/PassiveScanState.txt";

void TurnOnPassiveScan();

void TurnOffPassiveScan();

void AddFolderToPassiveScan(std::string foldername);

void RemoveFolderFromPassiveScan(std::string foldername);

void DisplayPassiveScanFoldersList();

void PerformScanning();

#endif
