#include "../include/PassiveScan.h"
#include "../include/PassiveScanController.h"



 PassiveScan *PassiveScan::GetInstance(){
	if(!instance){
	instance = new PassiveScan;}
	return instance;
}


PasiveScan::PassiveScan(){
	PassiveScanList = ReadFile(PassiveScanListPath);
}

std::vector<std::string> PassiveScan::GetPassiveScanList(){
	return this->PassiveScanList;
}

void PassiveScan::AddFolder(std::string foldername){
	PassiveScanList.push_back(foldername);
}

void PassiveScan::RemoveFolder(std::string foldername){
	for(int i =0 ; i< PassiveScanList.size(); i++){
		if( foldername == PassiveScanList.at(i)){
				PassiveScanList.erase(i);
		}		
	}
}

PassiveScan *PassiveScan::instance = 0;
