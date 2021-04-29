#include "../include/HashDatabase.h"



 HashDatabase *HashDatabase::GetInstance(){
	if(!instance){
	instance = new HashDatabase;}
	return instance;
}


HashDatabase::HashDatabase(){
	Hashes = ReadFile("virusHashDatabase/VirusHashes.txt");
}

std::vector<std::string> HashDatabase::GetHashes(){
	return this->Hashes;
}

void HashDatabase::AddHashes(std::vector<std::string> newHashes){
	Hashes.insert(Hashes.end(), newHashes.begin(), newHashes.end());
}

HashDatabase *HashDatabase::instance = 0;





