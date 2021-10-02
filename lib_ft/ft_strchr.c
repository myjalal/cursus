#include <stdio.h>
#include <string.h>
int ft_strlen(char *c)
{
	int i;
	
	i = 0;
	while (c[i])
		i++;
	return (i);
}
char *ft_strchr(const char *s, int c)
{
	int i;
	char *src;
	
	i = 0;
	src = (char *)(s);

	if (c == '\0')
		return(&src[ft_strlen(src)]);
	while (s[i])
	{
		if (c == src[i])
			return (&src[i]);
		i++;
	}
	return (0);
}

int main()
{
	char text[] = "abcdef";

	if( ft_strchr("abcdefg",'a') )
		printf("'%s' has a in it\n and the pointer of it is %p\n and the real pointer is %p\n",text, ft_strchr("abcdefg",'a'), strchr("abcdefg",'a'));
	else
		printf("'%s' does not have z in it\n",text);

	return(0);
}
