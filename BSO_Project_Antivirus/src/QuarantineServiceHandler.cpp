#include"../include/QuarantineServiceHandler.h"



//Move dangerous file to safe folder that can not be easilly accessed
void MoveFileToSafety(std::string filename){
	std::ifstream ifs(filename, std::ios::in | std::ios::binary);
	std::size_t index = filename.find_last_of("/");
	std::string substr = filename.substr(index+1,filename.size()+1);	
	std::string newname = QuarantineFolder + "/" + substr;
	std::ofstream ofs(newname, std::ios::out | std::ios::binary);
	ofs << ifs.rdbuf();
	std::remove(filename.c_str());
}

//Change file permissions so that only privileged entity can use it
void ChangeFilePermissions(std::string filename){
	chmod(filename.c_str(), S_IRUSR);
}
