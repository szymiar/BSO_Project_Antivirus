#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <dirent.h>
#include <errno.h>


std::vector<std::string> ReadFile(std::string filename);

void AppendToFile(std::vector<std::string> hashes,std::string filename);

void AppendToFile(std::string foldername, std::string filename);


void RemoveFromFile(std::string foldername, std::string filename);

void ClearFile(std::string filename);

bool CheckFileExistence(std::string filename);

bool CheckFolderExistence(std::string filename);

#endif


