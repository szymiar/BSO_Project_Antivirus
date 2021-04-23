#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main(){
	cout << "Hello World!";
	
	int cmdin = system("sha256sum ../virus_hash_database/file1.txt");
	cout << "Hash value is" ;
	cout<< cmdin;
	
	
	return 0;
}
