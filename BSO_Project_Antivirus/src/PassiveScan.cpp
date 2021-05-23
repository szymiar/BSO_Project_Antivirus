#include "../include/PassiveScan.h"
#include "../include/PassiveScanController.h"



 PassiveScan *PassiveScan::GetInstance(){
	if(!instance){
	instance = new PassiveScan;}
	return instance;
}


PasiveScan::PassiveScan(){
	PassiveScanList = ReadFile();
}

std::vector<std::string> PassiveScan::GetPassiveScanList(){
	return this->PassiveScanList;
}

void PassiveScan::AddFolder(std::string foldername){
	PassiveScanList.push_back(foldername);
}

PassiveScan *PassiveScan::instance = 0;
