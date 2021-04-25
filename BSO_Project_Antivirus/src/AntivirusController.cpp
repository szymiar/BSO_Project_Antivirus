#include "../include/AntivirusController.h"
#include "../include/HashCalculator.h"
#include "../include/FileHandler.h";
using namespace std;




void ScanFile(string filename){
	string hash = GetFileHash(filename);
	if(IsDangerous(hash)){
		cout<<filename <<":\n";
		cout<<"\nDangerous file \n ";
		QuarantineFile(filename);
		}
	else{
		cout<<filename <<":\n";
		cout<<"File is safe\n";
	}
	}


void ScanPackage(string path){
	//Iterate through all subfiles of path	
	// ScanFile(currentFile)
	string file;
	for(const auto& dirEntry : experimental::filesystem::recursive_directory_iterator(path)){
		file = dirEntry.path();
		ScanFile(file);
	}
	

	cout<<"\n Will arrive soon\n";
	}




bool IsDangerous(string hash){
	vector<string> database = ReadFile("../virusHashDatabase/VirusHashes.txt");
	for(int i = 0; i< database.size(); i++){
		if(hash == database.at(i)){
			return true;
		}
	}

	return false;
	}



void QuarantineFile(string filename){
	cout<<"Quarantine service to implement\n";
	}
	
