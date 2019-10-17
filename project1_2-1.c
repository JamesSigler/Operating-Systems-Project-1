#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, int** argv)
{
	
	//calling parent argv number of times
	parent(argv[1]);
	
	
}

//child process
void child(int input)
{
	//child pid
	pid_t cpid; 
	
	//forking the child 
	cpid = fork();
	
	//if running another child wait
	if(cpid > 0)
	{
		wait(0);
	}
	
	//checking for fork failure and printing error
	if(cpid < 0)
	{
	    printf("Error: Child creation failed");
	}
	
	//if fork succeeds print the pid
	else if(cpid == 0)
	{
		printf("\nHello from pid %d", getpid());
		exit(0);
	}
	
}

//parent process
void parent(int input)
{
	//parent pid
	pid_t ppid;
	
	//loop for inputed amount of times
	for(int i = 0; i < input; i++)
	{
		//forking pid
		ppid = fork();
		
		//fail print error
		if(ppid < 0)
		{
			printf("Error: Parent creation failed");
		}
		
		//succeed, call child process
		else if(ppid == 0)
		{
			child(input);
		}
		
		//waits for children and exits
		else
		{
			wait(0);
			exit(0);
		}
	}
}