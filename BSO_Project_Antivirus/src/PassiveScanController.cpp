#include "../include/AntivirusController.h"
#include "../include/FileHandler.h"
namespace fs = std::filesystem;

//const string FoldersList;

void TurnOnPassiveScan(){
	//Do something
	}
	


void TurnOffPassiveScan(){
	//Do something
	}


void AddFolderToPassiveScan(std::string foldername){
    //AppendToFile(foldername, FoldersList);
  
  }


void DisplayPassiveScanFoldersList(){
    for(const auto& dirEntry : fs::recursive_directory_iterator(FoldersList)){
			std::cout<<"\n"<< dirEntry.path() <<"\n";
		}
  
  }


void RemoveFolderFromPassiveScan(std::string foldername){
  //RemoveFromFile(foldername, FoldersList);
  
}

