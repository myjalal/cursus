#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_putstr(char *s)
{
	int count;

	count = 0;
	if (!s)
		count += ft_putstr("(null)");
	else
		while (s[count] != '\0')
			count += ft_putchar(s[count]);
	return (count);
}

//int ft_putnum()

int ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		x;

	x = 0;
	i = 0;
	va_start (args, str);

	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;

		}
	}
}


int main(void)
{
	char str[] = "hello";
	//ft_printf("number is: %s", str);
	printf("%-20s", str);
}