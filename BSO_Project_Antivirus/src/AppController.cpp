#include "../include/AppController.h"
#include "../include/AntivirusController.h"
#include "../include/HashDatabase.h"
#include "../include/QuarantineServiceHandler.h"

using namespace std;
namespace fs = std::filesystem;

void ActionMenu(int decision){
	string filename;
	string path;	
	switch(decision){
	case 1: //ScanFIle
		cout<<"\n Enter file name\n";
		cin>> filename;
		ScanFile(filename);
		cout<<"\n\n File scan finished \n\n";
		break;
	case 2: //Scan Package
		cout<<"\nEnter path\n";
		cin >> path;
		ScanPackage(path);
		cout<< "\nPackage scan finished\n\n";
	break;
	case 3: //Update Hash Database (read from file)
		cout<<"\n Enter the name of file from which to update database\n";
		cin>>filename;
		UpdateHashDatabase(filename);
		cout<<"\n Virus database updated\n";
	break;
	case 4: //Display quarantined files
		for(const auto& dirEntry : fs::recursive_directory_iterator(QuarantineFolder)){
			cout<<"\n"<< dirEntry.path() <<"\n";
		}
	break;	
	case 5: // Additional security service (advanced)
		cout<<"\n Comming soon in advanced version\n";
	break;
	case 6: //End program
		EndProgram();
	break;

	}
	}


void MainMenu(){
	while(1==1){
		cout<<"\nWhat do you wanna do: \n 1 - Scan file\n";
		cout<<" 2 - Scan whole package \n";
		cout<<" 3 - Update Hash Database \n";
		cout<<" 4 - Display quarantined files \n";
		cout<<" 5 - Additional security service \n";
		cout<<" 6 - End program \n";
		string dc;
		cin >> dc;
		int decision;
		try{
		decision = stoi(dc);
		}
		catch(...){
		cout<<"\nEnter proper number\n";
		}
		if(decision == 1 || decision == 2 || decision == 3 ||  decision == 4 || decision == 5 || decision == 6) {
			ActionMenu(decision);
			cout<<"\n\n===========================\n\n";
			continue;
		}
 		cout<<"\n Wrong input\n";
		
		}
	}

void Startup(){
	//HashDatabase to Singleton, load it at the beggining from file
	//And then use it in IsDangerous
	HashDatabase *hashDatabase = hashDatabase->GetInstance();
	}

void EndProgram(){
	exit(3); //Calls global object destructors
	}
