#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *print_msg(void *ptr) {
	char *msg = (char *)ptr;
	printf("%s\n", msg);
}

void main() {
	pthread_t nthread;
	int ret, i, n;
	char *msg = "Thread created!";
	printf("Number of threads: ");
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		ret = pthread_create(&nthread, NULL, print_msg, msg);
		pthread_join(nthread, NULL);
		printf("Thread %d return: %d\n", i, ret);
	}
}
