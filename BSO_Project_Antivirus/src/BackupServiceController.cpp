#include "../include/BackupServiceController.h"
#include "../include/FileHandler.h"


void AddFileToBackup(std::string filename){
    	std::size_t index = filename.find_last_of("/");
	std::string name = filename.substr(index+1, filename.size()+1);
	AppendToFile(name, BackupFolderListPath);
    	std::string newLocation = BackupFolderPath + "/" + name;
	CopyFile(filename, newLocation);
  }



void RemoveFileFromBackup(std::string filename){
	RemoveFromFile(filename, BackupFolderListPath);
   	std::string path = BackupFolderPath + "/" + filename;
   	RemoveFile(path);
}


void DisplayBackupList(){
    	std::vector <std::string> BackupFolderList = ReadFile(BackupFolderListPath);
	for(unsigned int i =0 ; i< BackupFolderList.size() ; i++){
		    std::cout<<"\n"<< BackupFolderList.at(i) <<"\n";
	  }
}
 

void SendZipToExternalBackup(){
  PackFolderToZip(BackupFolderPath);
  //SendZip();
}

void DownloadZipFromExternalBackup(){
  //Maybe 
}
