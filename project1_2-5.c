#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

#include <stdlib.h>

int main(int argc, int** argv)
{
	//check for right arguments
	if (argc != 2) {
		printf("Error: Invalid # of arguments\n");
		exit(1);
	}

	//change arguments to int
	int input = atoi(argv[1]);
	
	//calling process argv number of times
	repPID(input);
}

//2.5 process
void repPID(int input)
{	
	//creating pid variable and initializing for loop to work on oak server
	pid_t pid;
	int i;
	for(i = 0; i < input; i++)
	{
    	//forking pid
        pid = fork();
        
    		
    	//fail print error
    	if(pid < 0)
    	{
    		printf("Error: pid creation failed");
    	}
		//waiting for last process to finish
    	else if(pid > 0)
    	{
    	    wait(0);
    	    exit(0);
    	}
    	//succeed, call print message
    	else if(pid == 0)
    	{
    		printf("Hello from pid %d\n", getpid());
    	}
	}
}