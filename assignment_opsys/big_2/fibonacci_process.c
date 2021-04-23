#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

void fibonacci(long long  n)
{
	//根据递推式生成Fibonacci数列
	long long a = 0, b = 1, c;
	int total = 0;
	for (long long i = 0; i < n; i++) {
		if (i == 0) {
			c = a;
		} else if (i == 1){
			c = b;
		} else {
			c = a + b;
			a = b;
			b = c;
		}
		total++;//每5个一组输出便于查看
		printf("%lld ", c);
		if (total % 5 == 0) {
			printf("\n");
		}
	}
	printf("\n");
	exit(0);
}

int main(int argc, char *argv[]) //接受命令行参数
{
	int status = -1;

	if (argc != 2) {
		printf("Missing Parameter!\n");
		return -1;
	}
	if (atoi(argv[1]) <= 0) {
		printf("Input Error!\n");
		return -1;
	} //错误检查，检查参数个数和参数范围

	int pid = fork();//创建子进程
	if (pid == -1) {
		//若返回值为-1，未成功创建新进程
		printf("Creating Process Error!\n");
	} else if (pid == 0){
		//进入子进程，执行Fibonacci数列的生成
		fibonacci(atoi(argv[1]));
	} else {
		//进入父进程，等待子进程的结束
		wait(&status);
	}
	return 0;
}
