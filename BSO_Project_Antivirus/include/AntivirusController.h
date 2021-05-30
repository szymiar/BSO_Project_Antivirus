#ifndef ANTIVIRUSCONTROLLER_H
#define ANTIVIRUSCONTROLLER_H

#include <filesystem>
#include <sys/vfs.h>
#include <string>

const std::string VirusHashes = "/usr/local/share/BSO_Project_Antivirus/data/virusHashDatabase/VirusHashes.txt";
const std::string ActiveScanResults = "/usr/local/share/BSO_Project_Antivirus/data/scanResults/ActiveScanResults.txt";
void ScanFile(std::string filename, std::string resultFile);

void ScanPackage(std::string path, std::string resultFile);

bool IsDangerous(std::string hash);

void QuarantineFile(std::string filename, std::string resultFile);

void UpdateHashDatabase(std::string filename);

void DisplayScanResults(std::string filename);

#endif

