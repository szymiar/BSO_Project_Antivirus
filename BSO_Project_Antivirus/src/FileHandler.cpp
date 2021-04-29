#include "../include/FileHandler.h"

using namespace std;

vector<string> ReadFile(string filename){
	vector <string> hashes;
	ifstream fil(filename);
	string hash;
	while(getline(fil,hash)){
		hashes.push_back(hash);
	}

	return hashes;
	}


void  AppendToFile(vector<string> hashes, string filename){
	ofstream outfile;
	outfile.open(filename, ios_base::app);
	for(unsigned int i = 0; i< hashes.size(); i++){
		outfile << hashes.at(i) << "\n";
		}
	}

bool CheckFileExistence(string filename)
	{
	ifstream infile(filename.c_str());
	return infile.good();
	}
