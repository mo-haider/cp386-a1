// CPP code to create three child 
// process of a parent 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 

int main() 
{ 
	int p_id, p_id1, p_id2; 

	// variable p_idwill store the 
	// value returned from fork() system call 
	p_id = fork(); 

	// If fork() returns zero then it 
	// means it is child process. 
	if (p_id == 0) { 

		// First child needs to be printed 
		// later hence this process is made 
		// to sleep for 3 seconds. 
		//sleep(3); 

		// This is first child process 
		// getpid() gives the process 
		// id and getppid() gives the 
		// parent id of that process. 
		printf("child: p_id= %d\n", getpid()); 
	} 

	else { 
		p_id1 = fork(); 
		if (p_id1 == 0) { 
			//sleep(2); 
			printf("child: p_id1= %d\n", getpid()); 
		} 
		else { 
			p_id2 = fork(); 
			if (p_id2 == 0) { 
				// This is third child which is 
				// needed to be printed first. 
				printf("child: p_id= %d\n", getpid()); 
			} 

			// If value returned from fork() 
			// in not zero and >0 that means 
			// this is parent process. 
			else { 
				// This is asked to be printed at last 
				// hence made to sleep for 3 seconds. 
				//sleep(3); 
				printf("parent --> p_id= %d\n", getppid()); 
			} 
		} 
	} 
    printf("about to terminate");
	return 0; 
} 
