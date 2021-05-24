#include "../include/PassiveScan.h"
#include "../include/PassiveScanController.h"



 PassiveScan *PassiveScan::GetInstance(){
	if(!instance){
	instance = new PassiveScan;}
	return instance;
}


PassiveScan::PassiveScan(){
	PassiveScanList = ReadFile(PassiveScanListPath);
}

std::vector<std::string> PassiveScan::GetPassiveScanList(){
	return this->PassiveScanList;
}

void PassiveScan::AddFolder(std::string foldername){
	PassiveScanList.push_back(foldername);
}

void PassiveScan::RemoveFolder(std::string foldername){
	for(unsigned int i =0 ; i< PassiveScanList.size(); i++){
		if( foldername == PassiveScanList.at(i)){
				PassiveScanList.erase(PassiveScanList.begin() + i);
		}
	}
}

PassiveScan *PassiveScan::instance = 0;
