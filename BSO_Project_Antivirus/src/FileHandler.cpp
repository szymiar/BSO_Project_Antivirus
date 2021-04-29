#include "../include/FileHandler.h"


std::vector<std::string> ReadFile(std::string filename){
	std::vector <std::string> hashes;
	std::ifstream fil(filename);
	std::string hash;
	while(getline(fil,hash)){
		hashes.push_back(hash);
	}

	return hashes;
	}


void  AppendToFile(std::vector<std::string> hashes, std::string filename){
	std::ofstream outfile;
	outfile.open(filename, std::ios_base::app);
	for(unsigned int i = 0; i< hashes.size(); i++){
		outfile << hashes.at(i) << "\n";
		}
	}

bool CheckFileExistence(std::string filename)
	{
	std::ifstream infile(filename.c_str());
	return infile.good();
	}
