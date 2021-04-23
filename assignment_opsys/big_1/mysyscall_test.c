#include <unistd.h>
#include <sys/syscall.h> 
#include <sys/types.h> 

int main()
{
	syscall(335);
	return 0;
}
