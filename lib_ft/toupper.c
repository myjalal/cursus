#include <unistd.h>

int ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c = c - 32;
	}
	
	return (c);
}

void ft_putchar (char c)
{
	write(1, &c, 1);
}

int main(void)
{
	ft_putchar(ft_toupper('A'));
}
