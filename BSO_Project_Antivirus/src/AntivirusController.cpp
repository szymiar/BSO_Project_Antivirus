#include "../include/AntivirusController.h"
#include "../include/HashCalculator.h"
#include "../include/FileHandler.h";
using namespace std;




void ScanFile(string filename){
	string hash = GetFileHash(filename);
	if(IsDangerous(hash)){
		cout<<"\nDangerous file \n ";
		QuarantineFile(filename);
		}
	else{
		cout<<"File is safe\n";
	}
	}


void ScanPackage(string path){
	//Iterate through all subfiles of path	
	// ScanFile(currentFile)
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
	
