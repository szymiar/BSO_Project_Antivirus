#include"../include/QuarantineServiceHandler.h"



//Move dangerous file to safe folder that can not be easilly accessed
void MoveFileToSafety(std::string filename){
	std::string cmd = "mv " + filename + " " + QuarantineFolder;
	system(cmd.c_str());
}

//Change file permissions so that only privileged entity can use it
void ChangeFilePermissions(std::string filename){
	chmod(filename.c_str(), S_IRWXU);


}
