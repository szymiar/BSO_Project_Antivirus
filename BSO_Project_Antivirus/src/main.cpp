#include<iostream>
#include<string>
#include<stdio.h>
#include<cstring>
#include "../include/HashCalculator.h"
#include "../include/AntivirusController.h";

void UserInteraction();
void Startup();

using namespace std;


int main(){
	cout << "Hello World \n";
	UserInteraction();
	return 0;
}


void UserInteraction(){
	while(1==1){
		cout<<"What do you wanna do: \n 1 - Scan file\n";
		cout<<" 2- Scan whole package \n Any - End ";
		int first_decision;
		cin >> first_decision;
		if(first_decision == 1){	
			cout<<"Enter filename\n";
			string filename;
			cin>> filename;
			ScanFile(filename);
			cout<<"\n File scan finished\n";
			continue;
		}
		else if (first_decision == 2){
			cout<<"Enter path\n";
			string path;
			cin >> path;
			ScanPackage(path);
			cout<<"Not implemented\n";
			continue;
		}
		else {
			break;
			}
		}
	}



void Startup(){
	//Load Files from database into memory (i.e. class HashDatabse)



	}

