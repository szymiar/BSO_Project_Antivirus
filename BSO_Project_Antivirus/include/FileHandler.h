#ifndef FILEHANDLER_H
#define FILEHANDLER_H


#include <cerrno>
#include <dirent.h>
//#include <errno.h>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <sys/stat.h>
#include <sys/vfs.h>
#include <vector>

std::vector<std::string> ReadFile(std::string filename);

void AppendToFile(std::vector<std::string> hashes,std::string filename);

void AppendToFile(std::string foldername, std::string filename);

std::string ReadFirstLineFromFile(std::string filename);

void RemoveFromFile(std::string foldername, std::string filename);

void ClearFile(std::string filename);

bool CheckFileExistence(std::string filename);

bool CheckFolderExistence(std::string filename);

bool HasTxtEnding(std::string filename);

bool IsFile(std::string filename);

bool CanBeScanned(std::string filename);

void CopyFile(std::string filename, std::string destination);

void RemoveFile(std::string filename);

#endif


