#include "../include/FileHandler.h"


std::vector<std::string> ReadFile(std::string filename){
	std::vector <std::string> lines;
	std::ifstream fil(filename);
	std::string line;
	while(getline(fil,line)){
		lines.push_back(line);
	}

	return lines;
	}


void  AppendToFile(std::vector<std::string> hashes, std::string filename){
	std::ofstream outfile;
	outfile.open(filename, std::ios_base::app);
	for(unsigned int i = 0; i< hashes.size(); i++){
		outfile << hashes.at(i) << "\n";
		}
	}


void  AppendToFile(std::string foldername, std::string filename){
	std::ofstream outfile;
	outfile.open(filename, std::ios_base::app);
	outfile<<foldername << "\n";
	}


void RemoveFromFile(std::string foldername, std::string filename){
	std::vector <std::string> folders;
	std::vector <std::string> newfolders;
	std::ifstream fil(filename);
	std::string folder;
	while(getline(fil,folder)){
		folders.push_back(folder);
	}
	for(unsigned int i =0; i < folders.size() ; i++){
		newfolders.push_back(folders.at(i));
		if(folders.at(i) == foldername){
			newfolders.pop_back();
			}		
		}
	ClearFile(filename);
	AppendToFile(newfolders, filename);
	}


void ClearFile(std::string filename){
	std::ofstream ofs;
	ofs.open(filename, std::ofstream::out | std::ofstream::trunc);
	ofs.close();
	}



bool CheckFileExistence(std::string filename)
	{
	std::ifstream infile(filename.c_str());
	return infile.good();
	}

bool CheckFolderExistence(std::string filename)
	{
	DIR* dir = opendir(filename.c_str());
	if (dir) {
   		 closedir(dir);
		return true;
		} 
	else if (ENOENT == errno) {
    		return false;
		} 
	else {
   		return false;
		}
	}


bool HasTxtEnding(std::string filename){
	const std::string txt = ".txt";
	if(filename.length() >= txt.length()){
		return(0== filename.compare(filename.length() - txt.length(), txt.length(), txt));
		}
	else{
		return false;
		}
}

bool IsFile(std::string filename){
	struct stat sb;
	std::filesystem::path p(filename);
	if(stat(filename.c_str(), &sb) == 0 && S_ISREG(sb.st_mode) && (std::filesystem::is_regular_file(p) ))
	{
		return true;
	}
	return false;
	}

bool CanBeScanned(std::string filename){
	struct statfs sf;
	statfs(filename.c_str(), &sf);
	if(sf.f_type == 61267){
		return true;
	}
	//std::cout<<"\n"<<sf.f_type<<"\n";
	return false;
	}

void CopyFile(std::string filename, std::string destination){
	//Copy filename to destination
	
	}

void PackFolderToZip(std::string foldername){
	//Pack	
	
}
void RemoveFile(std::string filename){
	//Remove file
	}

