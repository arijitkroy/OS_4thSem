#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void main() {
	fork();
	fork();
	fork();
	printf("Process id: %d\nParent process id: %d\n", getpid(), getppid());
}
