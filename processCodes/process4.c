#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void main() {
	int r;
	r = fork();
	if (r == 0) {
		printf("Child with process id: %d\n", getpid());
		printf("Parent with process id: %d\n", getppid());
		sleep(20);
		printf("Child with process id: %d\n", getpid());
		printf("Orphan child with parent process id: %d", getppid());
	}	
	else {
		printf("Parent with process id: %d\n", getpid());
		printf("Parent's parent with process id: %d\n", getppid());
	}
}
