#include"../include/QuarantineServiceHandler.h"



//Move dangerous file to safe folder that can not be easilly accessed
void MoveFileToSafety(std::string filename){
	ifstream ifs(filename, ios::in | ios::binary);
	ofstream ofs(QuarantineFolder, ios::out | ios::binary);
	ofs << ifs.rdbuf();
	remove(oldname);
}

//Change file permissions so that only privileged entity can use it
void ChangeFilePermissions(std::string filename){
	chmod(filename.c_str(), S_IRUSR);

}
