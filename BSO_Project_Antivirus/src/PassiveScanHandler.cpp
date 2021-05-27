#include "../include/PassiveScanHandler.h"

FILE *LaunchLogWindow(){
	char *name = tempnam(NULL,NULL);
	char cmd[256];
	
	mkfifo(name,0777);
	if(fork()==0){
		sprintf(cmd, "gnome-terminal -e cat %s", name);
		system(cmd);
		exit(0);
	}
	return fopen(name,"w");

	}

/*int main()
{
	FILE *log = LaunchLogWindow();
	for(;;)
	{
		fprintf(log, "Hello world!\n");
	}
}*/






