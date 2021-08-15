void *ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	int i;
	unsigned char *sr;
	unsigned char *ds;
	sr = (unsigned char *)src;
	ds = (unsigned char *)dst;
	i = 0;
	
	while(n--)
	{
		ds[i] = sr[i];
		i++;
	}
	return(dst);
}
