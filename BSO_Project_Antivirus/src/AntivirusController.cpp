#include "../include/AntivirusController.h"
#include "../include/HashCalculator.h"
#include "../include/FileHandler.h"
#include "../include/HashDatabase.h"
#include "../include/QuarantineServiceHandler.h"
using namespace std;
namespace fs = std::filesystem;



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
	string filename;
	
	for(auto&  dirEntry :  fs::recursive_directory_iterator(path,fs::directory_options::skip_permission_denied)){

		filename = dirEntry.path();
		if(filename.rfind("/sys/kernel/security/apparmor/revision",0)==0   || filename.rfind("/proc/",0)==0 || filename.rfind("/sys/kernel/debug",0)==0|| filename.rfind("/dev/",0)==0 || filename.rfind("/run",0)==0){
		continue;
		}
		cout<<"\n"<<filename<<"\n";
		ScanFile(filename);
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



