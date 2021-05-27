#include "../include/AntivirusController.h"
#include "../include/PassiveScanController.h"
#include "../include/FileHandler.h"
#include "../include/PassiveScan.h"
namespace fs = std::filesystem;

const bool on = true;
const bool off = false;


void TurnOnPassiveScan(){
	PassiveScan::GetInstance()->SetPassiveScanState(on);
	std::thread t(PerformScanning);
	t.detach();
	//PerformScanning();
	}



void TurnOffPassiveScan(){
	PassiveScan::GetInstance()->SetPassiveScanState(off);
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
	//int j =0;
	while(PassiveScan::GetInstance()->GetPassiveScanState()){
		sleep(PassiveScan::GetInstance()->GetPassiveScanPeriod());
		//if(j==1) PassiveScan::GetInstance()->SetPassiveScanState(off);
		//j++;
		for(unsigned int i =0; i< PassiveScan::GetInstance() -> GetPassiveScanList().size(); i++){
			std::string name = PassiveScan::GetInstance()->GetPassiveScanList().at(i);
			if(CheckFolderExistence(name)){ //Its a folder
				ScanPackage(name,PassiveScanResults);
				}
			else if(IsFile(name)&& CheckFileExistence(name)){ //Its a file
				ScanFile(name, PassiveScanResults);
				}
			else{
				std::string message = "\nCannot find file or package named: " + name;
				AppendToFile(message, PassiveScanResults);
			}
		}
	}
}



