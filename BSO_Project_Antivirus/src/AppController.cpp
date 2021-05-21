#include "../include/AppController.h"
#include "../include/AntivirusController.h"
#include "../include/HashDatabase.h"
#include "../include/QuarantineServiceHandler.h"

//using namespace std;
namespace fs = std::filesystem;

void ActionMenu(int decision){
	std::string filename;
	std::string path;
	switch(decision){
	case 1: //ScanFIle
		std::cout<<"\n Enter file name\n";
		std::cin>> filename;
		if(!CheckFileExistence(filename)){
			std::cout<<"\n File does not exist\n\n";
		break;
		}
		ScanFile(filename);
		std::cout<<"\n\n File scan finished \n\n";
		break;
	case 2: //Scan Package
		std::cout<<"\nEnter path\n";
		std::cin >> path;
		if(!CheckFileExistence(path)){
		std::cout<<"\n Wrong path\n\n";
		break;
		}
		ScanPackage(path);
		std::cout<< "\nPackage scan finished\n\n";
	break;
	case 3: //Update Hash Database (read from file)
		std::cout<<"\n Enter the name of file from which to update database\n";
		std::cin>>filename;
		if(!CheckFileExistence(filename)){
		std::cout<<"\n File does not exist\n\n";
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
		std::cout<<"\n Comming soon in advanced version\n";
	break;
	case 6: //End program
		EndProgram();
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
		std::cout<<" 6 - End program \n";
		std::string dc;
		std::cin >> dc;
		int decision;
		try{
		decision = stoi(dc);
		}
		catch(...){
		std::cout<<"\nEnter proper number\n";
		}
		if(decision == 1 || decision == 2 || decision == 3 ||  decision == 4 || decision == 5 || decision == 6) {
			ActionMenu(decision);
			std::cout<<"\n\n===========================\n\n";
			continue;
		}
 		std::cout<<"\n Wrong input\n";
		}
	}

void Startup(){
	//HashDatabase to Singleton, load it at the beggining from file
	//And then use it in IsDangerous
	HashDatabase::GetInstance();
	}

void EndProgram(){
	exit(3); //Calls global object destructors
	}
