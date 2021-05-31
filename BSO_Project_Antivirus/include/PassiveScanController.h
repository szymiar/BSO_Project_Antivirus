#ifndef PASSIVESCANCONTROLLER_H
#define PASSIVESCANCONTROLLER_H

#include <cstdlib>
#include <dirent.h>
#include <filesystem>
#include <iterator>
#include <string>
#include <sys/vfs.h>
#include <syslog.h>
#include <thread>
#include <unistd.h>



const std::string PassiveScanListPath="/usr/local/share/BSO_Project_Antivirus/data/passiveScanList/PassiveScanList.txt";
const std::string PassiveScanResults ="/usr/local/share/BSO_Project_Antivirus/data/scanResults/PassiveScanResults.txt";
const std::string PassiveScanStatePath="/usr/local/share/BSO_Project_Antivirus/data/passiveScanList/PassiveScanState.txt";

void TurnOnPassiveScan();

void TurnOffPassiveScan();

void AddFolderToPassiveScan(std::string foldername);

void RemoveFolderFromPassiveScan(std::string foldername);

void DisplayPassiveScanFoldersList();

void PerformThreadScanning();

void PerformDaemonScanning();

#endif
