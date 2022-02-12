#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>




int num(int num_arg, ...)
{
	va_list args;
	va_start(args, num_arg);
	
	for (int i = 0; i < num_arg; i++)
	{
		int x = va_arg(args, int);
		printf ("x= %d\n", x);
	}

}


int main(void)
{
	num(7, 5, 6, 8, 50);
	return 0;

}