#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

#include <stdlib.h>

int main(int argc, int** argv)
{
	
	//calling parent argv number of times
	repPID(argv[1]);
}

//parent process
void repPID(int input)
{
    
	for(int i = 0; i < input; i++)
	{
    	//forking pid
        pid_t pid = fork();
    		
    	//fail print error
    	if(pid < 0)
    	{
    		printf("Error: pid creation failed");
    	}
    	else if(pid > 0)
    	{
    	    wait(0);
    	    exit(0);
    	}
    	//succeed, call child process
    	else if(pid == 0)
    	{
    		printf("Hello from pid %d\n", getpid());
    	}
	}
}