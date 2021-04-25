#include<iostream>
#include<string>
#include<stdio.h>
#include<cstring>
//#include "../include/HashCalculator.h"
#include "../include/AntivirusController.h";
#include "../include/FileHandler.h";

void MainMenu();
void Startup();

using namespace std;


int main(){
	cout << "Hello World \n";
	MainMenu();

	return 0;
}


void MainMenu(){
	while(1==1){
		cout<<"What do you wanna do: \n 1 - Scan file\n";
		cout<<" 2- Scan whole package \n Any - End \n";
		int first_decision;
		cin >> first_decision;
		if(first_decision == 1){	
			cout<<"Enter filename\n";
			string filename;
			cin>> filename;
			ScanFile(filename);
			cout<<"\n\n File scan finished \n\n";
			continue;
		}
		else if (first_decision == 2){
			cout<<"Enter path\n";
			string path;
			cin >> path;
			ScanPackage(path);
			continue;
		}
		else {
			break;
			}
		}
	}



void Startup(){
	//HashDatabase to Singleton, load it at the beggining from file
	//And then use it in IsDangerous


	}

