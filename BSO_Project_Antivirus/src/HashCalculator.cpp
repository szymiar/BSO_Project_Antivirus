#include<iostream>
#include<string>
#include<cstdio>
#include<memory>
#include<stdexcept>
#include<array>
#include<stdio.h>
#include<cstring>

using namespace std;
string GetFileHash(string filename);


int main(){
	std::cout << "Hello World!\n";
	string file = "main.cpp";
	string cmdin =  GetFileHash(file);	
	std::cout << "Hash value is: " ;
	std::cout<< cmdin;
	
	if(cmdin !="e998cfb6782f241601ac1cbee2862f3d7229bf1aca0b7c808cf521a2b7c4b61b"){
		cout<<"\nDziala";}
	return 0;
}

string GetFileHash(string filename){
	string cmd = "sha256sum " + filename;
	string data;
	FILE * stream;
	const int max_buffer= 256;
	char buffer[max_buffer];
	cmd.append(" 2>&1");
	stream = popen(cmd.c_str(), "r");
	if(stream){
		while(!feof(stream))
			if(fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
		pclose(stream);
	}
	return data.substr(0,64);
	}

