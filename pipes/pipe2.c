#include <stdio.h>
#include <unistd.h>

void main() {
	int p1[2], p2[2], ret1, ret2, pid;
	char p1Msg[20] = "Hi", p2Msg[20] = "Hello", readMsg[20];
	ret1 = pipe(p1);
	if (ret1 == -1) printf("Pipe 1 error!\n");
	ret2 = pipe(p2);
	if (ret2 == -1) printf("Pipe 2 error!\n");
	pid = fork();
	if (pid != 0) {
		close(p1[0]);
		close(p2[1]);
		printf("Parent writing msg: %s\n", p1Msg);
		write(p1[1], p1Msg, sizeof(p1Msg));
		read(p2[0], readMsg, sizeof(readMsg));
		printf("Parent reading msg: %s\n", readMsg);
	}
	else {
		close(p1[1]);
		close(p2[0]);
		printf("Child writing msg: %s\n", p2Msg);
		write(p2[1], p2Msg, sizeof(p2Msg));
		read(p1[0], readMsg, sizeof(readMsg));
		printf("Child reading msg: %s\n", readMsg);
	}
}
