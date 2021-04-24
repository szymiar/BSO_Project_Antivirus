#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<crypto>

using namespace std;

int main(){
	cout << "Hello World!\n";
	
	string cmdin = to_string(system("sha256sum --text ../virus_hash_database/file1.txt")).substr(0,64);
	cout << "Hash value is: " ;
	cout<< cmdin;
	
	
	return 0;
}
