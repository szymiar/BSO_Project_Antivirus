#include "../include/AntivirusController.h"
#include "../include/HashCalculator.h"
#include "../include/FileHandler.h"
#include "../include/HashDatabase.h"
#include "../include/QuarantineServiceHandler.h"
namespace fs = std::filesystem;



void ScanFile(std::string filename, std::string resultFile){
	AppendToFile(filename, resultFile);
	if(IsFile(filename)&& CanBeScanned(filename)){
		std::string hash = GetFileHash(filename);
		AppendToFile(hash, resultFile);
		//std::cout<<hash<<"\n";
		if(IsDangerous(hash)){
			std::string message = "File is dangerous";
			AppendToFile(message,resultFile);
			//std::cout<<filename <<":\n";	
			//std::cout<<"\nDangerous file \n ";
			QuarantineFile(filename, resultFile);
		}
		else{
			std::string message = "File is safe";
			AppendToFile(message, resultFile);
			//std::cout<<filename <<":\n";
			//std::cout<<"\nFile is safe\n\n";
		}
	}
	else{
		std::string message = "File cannot be scanned\n Probably it is not a regular file";
		AppendToFile(message,resultFile);

	}
	}

void ScanPackage(std::string path, std::string resultFile){
	std::string filename;
	for(auto&  dirEntry :  fs::recursive_directory_iterator(path,fs::directory_options::skip_permission_denied)){

		filename = dirEntry.path();
		if(filename.rfind("/sys/kernel/debug",0)==0 ){
			continue;
		}
		ScanFile(filename,resultFile);
	}

	//std::cout<< "\n Package scanned \n\n ";	
	}




bool IsDangerous(std::string hash){
	for(unsigned int i = 0; i< HashDatabase::GetInstance().GetHashes().size(); i++){
		if(hash == HashDatabase::GetInstance().GetHashes().at(i)){
			return true;
		}
	}
	return false;
	}



void QuarantineFile(std::string filename, std::string resultFile){
	ChangeFilePermissions(filename);
	MoveFileToSafety(filename);
	std::string message = "Quarantine applied to the file";
	AppendToFile(message,resultFile);

	//std::cout<<"\n\n Quarantine applied to the file \n\n";
	}


void UpdateHashDatabase(std::string filename){
	std::vector<std::string> hashes = ReadFile(filename);
	AppendToFile(hashes, VirusHashes);
	HashDatabase::GetInstance().AddHashes(hashes); //Update singleton
	}



void DisplayScanResults(std::string filename){
	std::vector<std::string> lines =ReadFile(filename);
	for(unsigned int i =0; i<lines.size() ; i++){
		std::cout<<"\n"<< lines.at(i)<<"\n";
		}
	}

