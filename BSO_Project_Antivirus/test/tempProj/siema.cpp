#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <sys/vfs.h>

int main(){
	struct stat sb;
	struct stat sb2;
	struct stat sb3;
	struct stat sb4;
	std::string file1 = "eluwina.txt";
	std::string file2 = "/sys/power/disk";
	std::string file3 = "../../src/obj/main.o";
	std::string file4 ="/proc/kcore";
	//printf(stat(file1.c_str(),&sb));
	//printf(stat(file2.c_str(),&sb2));
	stat(file1.c_str(), &sb);
	stat(file2.c_str(), &sb2);
	stat(file3.c_str(), &sb3);
	std::cout<<"\n";
	std::cout<<sb.st_uid;
	std::cout<<"\n";
	std::cout<<sb4.st_uid;
	std::cout<<"\n";
	std::cout<<sb3.st_uid;
	std::cout<<"\n";
	stat(file4.c_str(), &sb4);
	std::cout<<sb4.st_uid;
	std::cout<<"\n";
	std::cout<<sb.st_ino;
	std::cout<<"\n";
	std::cout<<sb2.st_ino;
	std::cout<<"\n";
	std::cout<<sb3.st_ino;
	std::cout<<"\n\n\n\n";


	struct statfs sf;
	struct statfs sf2;
	struct statfs sf3;
	struct statfs sf4;
	statfs(file1.c_str(), &sf);
	statfs(file2.c_str(), &sf2);
	statfs(file3.c_str(), &sf3);
	statfs(file4.c_str(), & sf4);
	std::cout<<sf.f_type<<"\n";
	std::cout<<sf2.f_type<<"\n";
	std::cout<<sf3.f_type<<"\n";
	std::cout<<sf4.f_type<<"\n";


}
