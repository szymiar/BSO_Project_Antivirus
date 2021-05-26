#include "../include/AntivirusController.h"
#include "../include/PassiveScanController.h"
#include "../include/FileHandler.h"
#include "../include/PassiveScan.h"
namespace fs = std::filesystem;

//const string FoldersList;

void TurnOnPassiveScan(){
	PerformScanning();
	}



void TurnOffPassiveScan(){
	//Do something
	}



void AddFolderToPassiveScan(std::string foldername){
    AppendToFile(foldername, PassiveScanListPath); 
    PassiveScan::GetInstance()->AddFolder(foldername);
  }



void RemoveFolderFromPassiveScan(std::string foldername){
    RemoveFromFile(foldername, PassiveScanListPath);
    PassiveScan::GetInstance()->RemoveFolder(foldername);
}


void DisplayPassiveScanFoldersList(){
    for(unsigned int i =0 ; i< PassiveScan::GetInstance()->GetPassiveScanList().size() ; i++){
		std::cout<<"\n"<< PassiveScan::GetInstance()->GetPassiveScanList().at(i) <<"\n";
	}

  }

void PerformScanning(){
	for(unsigned int i =0; i< PassiveScan::GetInstance() -> GetPassiveScanList().size(); i++){
		std::string name = PassiveScan::GetInstance()->GetPassiveScanList().at(i);
		if(CheckFolderExistence(name)){ //Its a folder
			ScanPackage(name);
			}
		else if(IsFile(name)&& CheckFileExistence(name)){ //Its a file
			ScanFile(name);
			}
		else{
			std::cout<<"\nCannot find a package or file named: "<<name<<"\n";
		}
	}

}



