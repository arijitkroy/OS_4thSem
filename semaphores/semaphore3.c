#include <stdio.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/types.h>

void main() {
	int semid, count = 0, key = 0x30, nsem = 1;
	while (1) {
		semid = semget((key_t)key++, nsem, IPC_CREAT | 0666);
		if (semid == -1) break;
		count++;
		printf("Created semaphore with id: %d\n", semid);
	}
	printf("Total semaphores: %d\n", count);
}
