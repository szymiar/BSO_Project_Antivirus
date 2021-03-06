#include "../include/AntivirusController.h"
#include "../include/AppController.h"
#include "../include/BackupServiceController.h"
#include "../include/HashDatabase.h"
#include "../include/PassiveScan.h"
#include "../include/PassiveScanController.h"
#include "../include/QuarantineServiceHandler.h"

namespace fs = std::filesystem;

void ActionMenu(int decision){
	std::string filename;
	std::string path;
	switch(decision){
	case 1: //ScanFile
		std::cout<<"\n Enter file name\n";
		std::cin>> filename;
		if(!CheckFileExistence(filename)){
			std::cout<<"\n File does not exist\n\n";
			break;
		}
		if(CheckFolderExistence(filename)){
			std::cout<<"\nIt is a directory\n";
			break;
		}
		if(!CanBeScanned(filename)){
			std::cout<<"\nFile cannot be scanned\n";
			break;
		}
		ClearFile(ActiveScanResults);
		ScanFile(filename, ActiveScanResults);
		DisplayScanResults(ActiveScanResults);
		std::cout<<"\n\n File scan finished \n\n";
		break;
	case 2: //Scan Package
		std::cout<<"\nEnter path\n";
		std::cin >> path;
		if(!CheckFolderExistence(path)){
			std::cout<<"\n Wrong path\n\n";
			break;
		}
		ClearFile(ActiveScanResults);
		ScanPackage(path,ActiveScanResults);
		DisplayScanResults(ActiveScanResults);
		std::cout<< "\nPackage scan finished\n\n";
		break;
	case 3: //Update Hash Database (read from file)
		std::cout<<"\n Enter the name of file from which to update database\n";
		std::cin>>filename;
		if(!CheckFileExistence(filename)){
			std::cout<<"\n File does not exist\n\n";
			break;
		}
		if(!HasTxtEnding(filename)){
			std::cout<<"\n Is not a proper file\n";
			break;
		}
		UpdateHashDatabase(filename);
		std::cout<<"\n Virus database updated\n";
		break;
	case 4: //Display quarantined files
		for(const auto& dirEntry : fs::recursive_directory_iterator(QuarantineFolder)){
			std::cout<<"\n"<< dirEntry.path() <<"\n";
		}
		break;	
	case 5: // Additional security service (advanced)
		BackupServiceMenu();
		break;
	case 6: //Passive scan menu
		PassiveScanMenu();
		break;
	case 7: //End program
		EndProgram();
		break;

	}
}

void PassiveScanActionMenu(int decision){
	std::string filename;
	std::string path;
	switch(decision){
	case 1: //Turn on passive scanning
		//Passive scaning handler/controller etc
		std::cout<<"\nPassive scanning turned on"<<std::endl;
		TurnOnPassiveScan();
		break;
	case 2: //Turn off
		TurnOffPassiveScan();
		std::cout<<"\n Passive scanning turned off\n";
		break;
	case 3: //Add folder to passive scan
		std::cout<<"\n Enter the name of folder to add\n";
		std::cin>>filename;
		if(!CheckFolderExistence(filename)){
			std::cout<<"\n File does not exist\n\n";
			break;
		}
		AddFolderToPassiveScan(filename);
		std::cout<<"\n Folder added to passive scan \n";
		break;
	case 4: //Remove folder from passive scan
		std::cout<<"\n Enter the name of folder to remove\n";
		std::cin>>filename;
		RemoveFolderFromPassiveScan(filename);
		std::cout<<"\n Folder removed from passive scan \n";
		break;	
	case 5: //Display passive scan list
		DisplayPassiveScanFoldersList();
		break;	
	case 6: //Display current scanning results
		DisplayScanResults(PassiveScanResults);
		break;
	}
}


void BackupServiceActionMenu(int decision){
	std::string filename;
	std::string path;
	switch(decision){
	case 1: //Add file to backup
		std::cout<<"\n Enter file name\n";
		std::cin>> filename;
		if(!CheckFileExistence(filename)){
			std::cout<<"\n File does not exist\n\n";
			break;
		}
		if(CheckFolderExistence(filename)){
			std::cout<<"\nIt is a directory\n";
			break;
		}
		if(!CanBeScanned(filename)){
			std::cout<<"\nFile cannot be used\n";
			break;
		}
		std::cout<<"\nFile added to backup"<<std::endl;
		AddFileToBackup(filename);
		break;
	case 2: //Remove file from backup
		std::cout<<"\n Enter the name of file to remove\n";
		std::cin>>filename;
		RemoveFileFromBackup(filename);
		std::cout<<"\n File removed from backup \n";
		break;	
	case 3: //Display backup list
		DisplayBackupList();
		break;
	}
}



void MainMenu(){
	while(1==1){
		std::cout<<"\nWhat do you wanna do: \n 1 - Scan file\n";
		std::cout<<" 2 - Scan whole package \n";
		std::cout<<" 3 - Update Hash Database \n";
		std::cout<<" 4 - Display quarantined files \n";
		std::cout<<" 5 - Additional security service \n";
		std::cout<<" 6 - Open passive scan menu \n";
		std::cout<<" 7 - End program \n";
		std::string dc;
		std::cin >> dc;
		int decision;
		try{
		decision = stoi(dc);
		}
		catch(...){
		std::cout<<"\nEnter proper number\n";
		}
		if(decision == 1 || decision == 2 || decision == 3 ||  decision == 4 || decision == 5 || decision == 6 || decision == 7) {
			ActionMenu(decision);
			std::cout<<"\n\n===========================\n\n";
			continue;
		}
 		std::cout<<"\n Wrong input\n";
		}
	}




void PassiveScanMenu(){
	while(1==1){
		std::cout<<"\nPassive scan menu opened\n";
		std::cout<<"\nWhat do you wanna do: \n";
		std::cout<<" 1 - Turn on passive scanning\n";
		std::cout<<" 2 - Turn off passive scanning \n";
		std::cout<<" 3 - Add folder to passive scan \n";
		std::cout<<" 4 - Remove folder from passive scan \n";
		std::cout<<" 5 - Display folders added to passive scan \n";
		std::cout<<" 6 - Display current scanning results \n";
		std::cout<<" 7 - Back to main menu \n";
		std::string dc;
		std::cin >> dc;
		int decision;
		try{
		decision = stoi(dc);
		}
		catch(...){
		std::cout<<"\nEnter proper number\n";
		}
		if(decision == 1 || decision == 2 || decision == 3 ||  decision == 4 ||  decision == 5|| decision ==6) {
			PassiveScanActionMenu(decision);
			std::cout<<"\n\n===========================\n\n";
			continue;
		}
		else if(decision == 7){
			std::cout<<"\nBack to main menu\n";
			break;
		}
 		std::cout<<"\n Wrong input\n";
		}
	}

void BackupServiceMenu(){
	while(1==1){
		std::cout<<"\nBackup service menu opened\n";
		std::cout<<"\nWhat do you wanna do: \n";
		std::cout<<" 1 - Add file to backup\n";
		std::cout<<" 2 - Remove file from backup \n";
		std::cout<<" 3 - Display files in backup \n";
		std::cout<<" 4 - Back to main menu \n";
		std::string dc;
		std::cin >> dc;
		int decision;
		try{
		decision = stoi(dc);
		}
		catch(...){
		std::cout<<"\nEnter proper number\n";
		}
		if(decision == 1 || decision == 2 || decision == 3 ) {
			BackupServiceActionMenu(decision);
			std::cout<<"\n\n===========================\n\n";
			continue;
		}
		else if(decision == 4){
			std::cout<<"\nBack to main menu\n";
			break;
		}
 		std::cout<<"\n Wrong input\n";
		}
	}


void Startup(){
	HashDatabase::GetInstance();
	PassiveScan::GetInstance();
	std::string current_state = ReadFirstLineFromFile(PassiveScanStatePath);
	if(current_state == "on"){
		PassiveScan::GetInstance().SetIsDaemonOn(true);
		}
	}

void EndProgram(){
	if(PassiveScan::GetInstance().GetPassiveScanState()&& !PassiveScan::GetInstance().GetIsDaemonOn() ){
		ClearFile(PassiveScanStatePath);
		AppendToFile("on", PassiveScanStatePath);
		std::thread th(PerformDaemonScanning);
		th.detach();
		sleep(2);
	}
	exit(3); //Calls global object destructors
	}
