#include "../include/AntivirusController.h"
#include "../include/HashCalculator.h"
#include "../include/FileHandler.h"
#include "../include/HashDatabase.h"
#include "../include/QuarantineServiceHandler.h"
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
		cout<<"\nFile is safe\n\n";
	}
	}


void ScanPackage(string path){
	string file;
	for(const auto& dirEntry : experimental::filesystem::recursive_directory_iterator(path)){
		file = dirEntry.path();
		ScanFile(file);
	}
	cout<< "\n Package scanned \n\n ";	
	}




bool IsDangerous(string hash){
	HashDatabase *hashDatabase = hashDatabase->GetInstance();
	for(int i = 0; i< hashDatabase->GetHashes().size(); i++){
		if(hash == hashDatabase -> GetHashes().at(i)){
			return true;
		}
	}

	return false;
	}



void QuarantineFile(string filename){
	ChangeFilePermissions(filename);
	MoveFileToSafety(filename);
	cout<<"\n\n Quarantine applied to the file \n\n";
	}
	

void UpdateHashDatabase(string filename){
	vector<string> hashes = ReadFile(filename);
	AppendToFile(hashes, "../virusHashDatabase/VirusHashes.txt");
	HashDatabase *hashDatabase = hashDatabase -> GetInstance();
	hashDatabase->AddHashes(hashes); //Update singleton
	
	}
