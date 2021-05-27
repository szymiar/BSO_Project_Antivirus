#include "../include/BackupServiceController.h"
#include "../include/FileHandler.h"

std::vector<std::string> BackupFolderList = ReadFile(BackupFolderListPath);

void AddFileToBackup(std::string filename){
    //AppendToFile(filename, BackupFolderListPath); 
    //CopyFile(filename, BackupFolderPath); //Copy file(filename) to backup folder
  }



void RemoveFileFromBackup(std::string filename){
    //RemoveFromFile(filename, BackupFolderListPath);
    //std::string copy = BackupFolderPath + "/" + filename
    //RemoveFile(filename);   
  //BackupFolderList = ReadFile(BackupFolderListPath); //Reload
}


void DisplayBackupList(){
    for(unsigned int i =0 ; i< BackupFolderList ; i++){
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
