#include "../include/PassiveScan.h"
#include "../include/PassiveScanController.h"



 PassiveScan *PassiveScan::GetInstance(){
	if(!instance){
	instance = new PassiveScan;}
	return instance;
}


PassiveScan::PassiveScan(){
	PassiveScanList = ReadFile(PassiveScanListPath);
	PassiveScanState = false;
	PassiveScanPeriod = 20;
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

void PassiveScan::SetPassiveScanState(bool state){
	this->PassiveScanState = state;
	}

bool PassiveScan::GetPassiveScanState(){
	return this->PassiveScanState;
	}

void PassiveScan::SetPassiveScanPeriod(unsigned int period){
	this->PassiveScanPeriod = period;
	}

unsigned int PassiveScan::GetPassiveScanPeriod(){
	return this->PassiveScanPeriod;
	}

PassiveScan *PassiveScan::instance = 0;

