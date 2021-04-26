#include"../include/QuarantineServiceHandler.h"


void MoveFileToSafety(std::string filename){
	std::cout<<"\n\n Moving files to safety to implement\n";

}

void ChangeFilePermissions(std::string filename){
	chmod(filename.c_str(), S_IRWXU);


}
