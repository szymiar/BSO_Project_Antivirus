#ifndef PASSIVESCANCONTROLLER_H
#define PASSIVESCANCONTROLLER_H

#include <filesystem>
#include <sys/vfs.h>
#include <string>

void TurnOnPassiveScan();

void TurnOffPassiveScan();

void AddFolderToPassiveScan(std::string foldername);

void RemoveFolderFromPassiveScan(std::string foldername);

void DisplayPassiveScanFoldersList();

#endif
