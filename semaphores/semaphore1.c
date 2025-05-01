#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/types.h>

void main() {
	int semid, nsem, key;
	printf("Enter key (in hex) and nsem: ");
	scanf("%x %d", &key, &nsem);
	semid = semget((key_t)key, nsem, IPC_CREAT | 0666);
	printf("Created semaphore with id: %d\n", semid);
}
