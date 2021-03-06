#ifndef BACKUPSERVICECONTROLLER_H
#define BACKUPSERVICECONTROLLER_H

#include <filesystem>
#include <string>
#include <sys/vfs.h>
#include <thread>
#include <unistd.h>

const std::string BackupFolderListPath = "/usr/local/share/BSO_Project_Antivirus/data/BackupService/BackupFolderList.txt";
const std::string BackupFolderPath = "/usr/local/share/BSO_Project_Antivirus/data/BackupService/BackupFolder/";
void AddFileToBackup(std::string filename);

void RemoveFileFromBackup(std::string filename);

void DisplayBackupList();


#endif
