#include "../include/AntivirusController.h"
#include "../include/HashCalculator.h"
using namespace std;




void ScanFile(string filename){
	string hash = GetFileHash(filename);
	if(IsDangerous(hash)){
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
	if(hash == "To implement"){
		return true;
	}
	return false;
	}



void QuarantineFile(string filename){
	cout<<"Quarantine service to implement\n";
	}
	
