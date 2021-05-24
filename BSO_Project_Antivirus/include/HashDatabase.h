#ifndef HASHDATABASE_H
#define HASHDATABASE_H

#include "FileHandler.h"

class HashDatabase
{
private:
static HashDatabase *instance;
//static HashDatabase& instance;
std::vector<std::string> Hashes;

HashDatabase();
public: 
 static HashDatabase *GetInstance();
//static HashDatabase& GetInstance();
std::vector<std::string> GetHashes();

void AddHashes(std::vector<std::string> newHashes);

};

#endif

