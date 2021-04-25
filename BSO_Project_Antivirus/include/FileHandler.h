#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

std::vector<std::string> ReadFile(std::string filename);
void AppendToFile(std::vector<std::string> hashes);
void AppendToFile(std::string hash);

#endif


