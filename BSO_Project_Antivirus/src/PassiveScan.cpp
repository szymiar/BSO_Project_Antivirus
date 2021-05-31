#include "../include/PassiveScanController.h"
#include "../include/PassiveScan.h"



/* PassiveScan *PassiveScan::GetInstance(){
	if(!instance){
	instance = new PassiveScan;}
	return instance;
}*/

PassiveScan &PassiveScan::GetInstance(){
	static PassiveScan instance;
	return instance;

}

PassiveScan::~PassiveScan(){

}

PassiveScan::PassiveScan(){
	PassiveScanList = ReadFile(PassiveScanListPath);
	PassiveScanState = false;
	PassiveScanPeriod = 20;
	IsDaemonOn = false;
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

void PassiveScan::SetIsDaemonOn(bool b){
	this->IsDaemonOn = b;
	}

bool PassiveScan::GetIsDaemonOn(){
	return this->IsDaemonOn;
	}

PassiveScan *PassiveScan::instance = 0;

