#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *print_msg(void *ptr) {
	char *msg = (char *)ptr;
	printf("%s\n", msg);
}

void main() {
	pthread_t thread1, thread2;
	int ret1, ret2;
	char *msg1 = "This is thread 1!\n", *msg2 = "This is thread 2!\n";
	ret1 = pthread_create(&thread1, NULL, print_msg, msg1);
	ret2 = pthread_create(&thread2, NULL, print_msg, msg2);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	printf("Thread 1 return: %d\nThread 2 return: %d\n", ret1, ret2);
}
