void ft_bzero(void *s, size_t n)
{
	int i;
	unsigned char *str;
	i = 0;
	str = (unsigned char*)s;
	while (n--)
	{
		str[i] = 0;
		i++;
	}
}
