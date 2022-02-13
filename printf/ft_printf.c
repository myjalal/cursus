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

int ft_putnum(long ln)
{
	int	x;

	x = 0;
	
	if (ln < 0)
	{
		x++;
		ln *= -1;
		ft_putstr(0, '-', 2);
	}
	if (ln > 9)
		x += ft_putnum(ln / 10);
	ft_putstr(0, ln % 10 + 48, 2);
	x++;
	return (x);
}

int ft_puthexa(unsigned long ln, char conver)
{
	char	*str;
	int		x;

	x = 0;
	if (conver == 'x')
		str = "0123456789abcdef";
	else if (conver == 'X')
		str = "0123456789ABCDEF";
	else if (conver == 'p' && ln / 16 > 0);
		x += ft_puthexa(ln / 16, conver);
	

}

int is_percent(va_list args, const char *conver)
{
	if (*conver == 's')
		return(ft_putstr(va_arg(args, char *), 0, 1));
	else if (*conver == 'c')
		return (ft_putstr(0, va_arg(args, int), 2));
	else if (*conver == 'p')
		{
			write(1, "0x", 2);
			return (ft_puthexa(va_arg(args, unsigned long), *conver));
		}
	else if (*conver == 'd' || *conver == 'i')
		return (ft_putnum(va_arg(args, int)));
	else if (*conver == 'u')
		return (ft_putnum(va_arg(args, unsigned int)));
	else if (*conver == 'x' || *conver == 'X')
		return (ft_puthexa(va_arg(args, unsigned long), *conver));
	else if (*conver == '%')
		return (ft_putstr(0, '%', 2));

	
	return (0);
}

int ft_printf(const char *str, ...)
{
	if (!str || !*str)
		return (0);
	va_list	args;
	int		x;

	x = 0;
	va_start (args, str);

	while (*str != '\0')
	{
		if (*str == '%')
			{
				x += is_percent(args, ++str);
				str++;
			}
		else
			x += ft_putstr(0, *str++, 2);
	}
	va_end(args);
	return (x);
}


int main(void)
{
	char str[] = "ninapoo";
	char c = '\n';
	int i = -123456789;
	//ft_printf("number is: %s", str);
	ft_printf("%u\n", -123456789);
//	write(1, '\n', 1);
}