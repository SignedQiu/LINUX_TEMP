#include <unistd.h>
#include <stdio.h>

int main()
{
	printf("first proess:%d\n", fork());
	return 0;
}
