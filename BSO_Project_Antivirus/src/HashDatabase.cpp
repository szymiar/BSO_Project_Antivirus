#include "../include/AntivirusController.h"
#include "../include/HashDatabase.h"


 HashDatabase &HashDatabase::GetInstance(){
	static HashDatabase instance;
	return instance;
}

HashDatabase::~HashDatabase(){}

HashDatabase::HashDatabase(){
	Hashes = ReadFile(VirusHashes);
}

std::vector<std::string> HashDatabase::GetHashes(){
	return this->Hashes;
}

void HashDatabase::AddHashes(std::vector<std::string> newHashes){
	Hashes.insert(Hashes.end(), newHashes.begin(), newHashes.end());
}




