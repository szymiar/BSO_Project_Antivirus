#include "../include/AntivirusController.h"
#include "../include/HashCalculator.h"
#include "../include/FileHandler.h"
#include "../include/HashDatabase.h"
#include "../include/QuarantineServiceHandler.h"
namespace fs = std::filesystem;



void ScanFile(std::string filename){
	if(IsFile(filename)){
		std::cout<<"\nCheck 3\n";
		std::string hash = GetFileHash(filename);
		std::cout<<hash<<"\n";
		if(IsDangerous(hash)){
			std::cout<<filename <<":\n";	
			std::cout<<"\nDangerous file \n ";
			QuarantineFile(filename);
			}
		else{
			std::cout<<filename <<":\n";
			std::cout<<"\nFile is safe\n\n";
			}
		}
	}

void ScanPackage(std::string path){
	std::string filename;
	std::cout<<"\nCheck 1\n";
	for(auto&  dirEntry :  fs::recursive_directory_iterator(path,fs::directory_options::skip_permission_denied)){

		filename = dirEntry.path();
		if(filename.rfind("/sys/kernel/security/apparmor/revision",0)==0   || filename.rfind("/dev/core",0)==0 || filename.rfind("/sys/kernel/debug",0)==0|| filename.rfind("/proc/kmsg",0)==0 || filename.rfind("/proc/kcore",0)==0 || filename.rfind("/proc/",0)==0 ){
			continue;
		}
		std::cout<<"\nCheck 2\n";
		ScanFile(filename);
	}

	std::cout<< "\n Package scanned \n\n ";	
	}




bool IsDangerous(std::string hash){
	//HashDatabase *hashDatabase = hashDatabase->GetInstance();
	for(unsigned int i = 0; i< HashDatabase::GetInstance()->GetHashes().size(); i++){
		if(hash == HashDatabase::GetInstance()->GetHashes().at(i)){
			return true;
		}
	}

	return false;
	}



void QuarantineFile(std::string filename){
	ChangeFilePermissions(filename);
	MoveFileToSafety(filename);
	std::cout<<"\n\n Quarantine applied to the file \n\n";
	}
	

void UpdateHashDatabase(std::string filename){
	std::vector<std::string> hashes = ReadFile(filename);
	AppendToFile(hashes, VirusHashes);
	HashDatabase::GetInstance()->AddHashes(hashes); //Update singleton
	}
