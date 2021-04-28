#ifndef ANTIVIRUSCONTROLLER_H
#define ANTIVIRUSCONTROLLER_H

#include <filesystem>
#include <sys/vfs.h>
#include <string>

void ScanFile(std::string filename);

void ScanPackage(std::string path);

bool IsDangerous(std::string hash);

void QuarantineFile(std::string filename);

void UpdateHashDatabase(std::string filename);

#endif

