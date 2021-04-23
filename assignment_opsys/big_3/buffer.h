#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

typedef struct parameter{
	int *time;
	int *ptr;
}para;

#define  BUFFER_SIZE 5 //缓冲区最大元素个数
typedef int buffer_item; //缓冲区元素类型
