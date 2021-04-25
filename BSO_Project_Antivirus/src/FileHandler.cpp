#include "../include/FileHandler.h"

using namespace std;


vector<string> ReadFile(string filename){
	vector <string> hashes;
	ifstream fil(filename);
	string hash;
	while(getline(fil,hash)){
		hashes.push_back(hash);
	}

	return hashes;
	}


void  AppendToFile(vector<string> hashes){
	//Add new Hashes
	}


void AppendToFile(string hash){
	//Add new hash
	}
