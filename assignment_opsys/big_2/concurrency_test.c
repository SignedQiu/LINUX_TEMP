#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <pthread.h>

void* input(void* p)
{
	printf("pid1");
	char c;
	scanf("%c", &c);
	p = &c;
	pthread_exit(0);
}

void* check(void* p)
{
	printf("pid2");
	char c = *(char*)p;
	if ((c < '0' || c > '9') && c != 'q') {
		printf("Input Error!\n");
	}
	pthread_exit(0);
}

int main()
{
	char p;
	p = '1';
	pthread_t tid1, tid2;
	pthread_attr_t attr1, attr2;
	pthread_attr_init(&attr1);
        pthread_attr_init(&attr2);
	while(p != 'q') {
	pthread_create(&tid1, &attr1, input, &p);
	pthread_join(tid1, NULL);
	pthread_create(&tid2, &attr2, check, &p);
	pthread_join(tid2, NULL);
	}
	return 1;
}

