size_t ft_strlen(const char *c)
{
	int i;
	i = 0;
	
	while (c[i])
		i++;
	return (i);
}
