#include "../include/AntivirusController.h"
#include "../include/PassiveScanController.h"
#include "../include/FileHandler.h"
#include "../include/PassiveScan.h"
namespace fs = std::filesystem;

const bool on = true;
const bool off = false;


void TurnOnPassiveScan(){
	ClearFile(PassiveScanResults);
	PassiveScan::GetInstance()->SetPassiveScanState(on);
	std::thread t(PerformScanning);
	t.detach();
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
	
	pid_t pid, sid;
	pid = fork();
	if(pid>0)
	{
		exit(EXIT_SUCCESS);
	}
	else if(pid<0)
	{
		exit(EXIT_FAILURE);
	}
	umask(0);
	openlog("daemon-name", LOG_NOWAIT | LOG_PID , LOG_USER);
	syslog(LOG_NOTICE, "Successfully started daemon-name");
	sid =setsid();
	if(sid<0)
	{
		syslog(LOG_ERR, "Could not generate session ID for child process");
		exit(EXIT_FAILURE);
	}
	std::cout<<"\nCheck\n";
	std::cout<<"\nCheck 2\n";
	/*if((chdir("/")) < 0)
	{	
		std::cout<<"\nlol\n";
		syslog(LOG_ERR, "Could not change working directory to /");
		exit(EXIT_FAILURE);
	}*/
	std::cout<<"\nCheck5\n";
	//close(STDIN_FILENO);
	//close(STDOUT_FILENO);
	//close(STDERR_FILENO);

	std::cout<<"\nCheck 1\n";

	while(PassiveScan::GetInstance()->GetPassiveScanState()){
		sleep(PassiveScan::GetInstance()->GetPassiveScanPeriod());
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
	std::cout<<"\nCheck 2\n";
	syslog(LOG_NOTICE, "Stopping daemon-name");
	closelog();
	exit(EXIT_SUCCESS);
}
