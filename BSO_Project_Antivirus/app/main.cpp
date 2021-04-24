#include<iostream>
#include<string>
#include<stdio.h>
#include<cstring>
#include "../include/HashCalculator.h"

void UserInteraction();

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
			string cmdin = GetFileHash(filename);
			cout<<"Calculated hash = : ";
			cout<< cmdin << "\n ";
			continue;
		}
		else if (first_decision == 2){
			cout<<"Not implemented\n";
			continue;
		}
		else {
			break;
			}
		}
	}
	




