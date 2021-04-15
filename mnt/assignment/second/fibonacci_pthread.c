#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define max 2^32 - 1

long long num[max];
long long total;

void *fibonacci_print(void* n)
{
	long long A = 0, B = 1, C;
	int upper = atoi(n);//字符串转整数
	for (int i = 0; i < upper; i++) {
		if (i == 0) {
			C = 0;
		} else if (i == 1) {
			C = 1;
		} else {
			C = A + B;
			A = B;
			B = C;
		}
		num[total++] = C;
	}
	pthread_exit(0);//线程结束
}

int main(int argc, char *argv[])//接受命令行参数
{
	pthread_t tid;//所创线程标识符
	pthread_attr_t attr;//线程属性标识

	if (argc != 2) {
		printf("Missing Parameter!\n");
		return -1;
	} else if (atoi(argv[1]) <= 0) {
		printf("Input Error!\n");
		return -1;
	} //错误检测，检查输入参数个数和范围

	pthread_attr_init(&attr);//设置线程属性
	pthread_create(&tid, &attr, fibonacci_print, argv[1]);//创建新线程并执行打印Fibonacci数列函数
	pthread_join(tid, NULL);//等待子进程的结束
	for (long long i = 1; i < total; i++) { //每隔5个打印便于查看
		printf("%lld ", num[i-1]);
		if (i % 5 == 0) {
				printf("\n");
		}
	}
	printf("\n");
	return 0;
}




