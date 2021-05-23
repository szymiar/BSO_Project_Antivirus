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


void  AppendToFile(std::string foldername, std::string filename){
	std::ofstream outfile;
	outfile.open(filename, std::ios_base::app);
	outfile<<foldername;
	}


void RemoveFromFile(std::string foldername, std::string filename){
	std::vector <std::string> folders;
	std::vector <std::string> newfolders;
	std::ifstream fil(filename);
	std::string folder;
	while(getline(fil,folder)){
		folders.push_back(folder);
	}
	for(int i =0; i < folders.size() ; i++){
		newfolders.push_back(folders.at(i));
		if(folders.at(i) == foldername){
			newfolders.pop_back();
			}		
		}
	ClearFile(filename);
	AppendToFile(newfolders, filename);
	}


void ClearFile(std::string filename){
	std::ofstream ofs;
	ofs.open(filename, std::ofstream::out | std::ofstream::trunc);
	ofs.close();
	}



bool CheckFileExistence(std::string filename)
	{
	std::ifstream infile(filename.c_str());
	return infile.good();
	}

bool CheckFolderExistence(std::string filename)
	{
	DIR* dir = opendir(filename.c_str());
	if (dir) {
   		 closedir(dir);
		return true;
		} 
	else if (ENOENT == errno) {
    		return false;
		} 
	else {
   		return false;
		}
	}
