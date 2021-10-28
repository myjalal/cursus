
int ft_memcmp(const void *s1, const void *s2, unsigned int n)
{
	unsigned char *src1;
	unsigned char *src2;
	
	src1 = (unsigned char*)s1;
	src2 = (unsigned char*)s2;
	while (n--)
	{
		if (*src1 != *src2)
			return (*src1 - *src1);
		src1++;
		src2++;
	}
	return (0);
}
