#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*src;

	src = (char *)(s);
	len = ft_strlen(src);
	if (c == '\0')
		return (&src[ft_strlen(src)]);
	while (len >= 0)
	{
		if (c == src[len])
			return (&src[len]);
		len--;
	}
	return (0);
}

/*int main()
{
	char text[] = "abcadef";

	if( ft_strrchr("abcdefg",'a') )
		printf("'%s' has a in it\n and the pointer of it is %p\n and the real pointer is %p\n",text, ft_strrchr("abcdefg",'a'), strrchr("abcdefg",'a'));
	else
		printf("'%s' does not have z in it\n",text);

	return(0);
}*/
