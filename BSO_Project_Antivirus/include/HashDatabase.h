#ifndef HASHDATABASE_H
#define HASHDATABASE_H

#include <iostream>
#include <string>

class HashDatabase
{
private:
	std::string[] Hashes;

public:

	std::string[] GetHashes();
	
	HashDatabase(std::string[] hashes){
		Hashes = hashes;
	}
};

std::string[] GetHashes();
#endif

