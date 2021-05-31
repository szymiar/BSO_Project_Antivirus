#include "../include/AntivirusController.h"
#include "../include/HashDatabase.h"


 HashDatabase &HashDatabase::GetInstance(){
//HashDatabase& HashDatabase::GetInstance(){
	static HashDatabase instance;
//	if(!instance){
//	instance = new HashDatabase;}
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

//const int &l =0;
//HashDatabase& HashDatabase::instance = l;
//HashDatabase *HashDatabase::instance = 0;




