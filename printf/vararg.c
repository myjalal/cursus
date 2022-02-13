#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

//1 = str, 2 = char
int ft_putstr(char *s, char c, int i)
{
	int count;

	count = 0;
	if (!s && i == 1)
		count += ft_putstr("(null)", 0, 1);
	else if (i == 2)
	{
		write(1, &c, 1);
		return (1);
	}
	else if (s && i == 1)
		while (s[count])
			count += ft_putstr(0, s[count], 2);
	return (count);
}


int main(void)
{
	char c = '-';
	char str[] = "hello world";
	//ft_putstr(0, '-', 2);
	ft_putstr()
	return 0;
}

/*int main()
{
	int i = 5;

	char str[] = "hello world";

	if (i++ == 1)
		printf("%c\n", str[i]);
	else
		printf("%d", i);
	//printf("%c\n", str[i++]);
	printf("%d\n", i);
	return 0;
}*/


/*int num(int num_arg, ...)
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

}*/