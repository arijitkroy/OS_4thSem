#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void main() {
	int r;
	r = fork();
	if (r > 0)
		printf("Parent with process id: %d\n", getppid());
	else if (r == 0)
		printf("Child with process id: %d\n", getpid());
	else
		printf("Fork failed!\n");
}
