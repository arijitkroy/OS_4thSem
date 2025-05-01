#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void main() {
	if (fork() > 0) {
		printf("Parent\n");
		sleep(20);
	}
}
