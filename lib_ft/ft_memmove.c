#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;
	char *ft_dst;
	const char *ft_src;
	i = 0;
	ft_dst = dst;
	ft_src = src;
	
	while (i < len)
	{
		ft_dst[i] = ft_src[i];
		i++;
	}
	return (0);
}
/*int main(void)
{
	char dst[] = "abc";
	const char src[] = "12345";
	int len = 10;
	printf("dst is: %s and src is: %s\n", dst, src);
	ft_memmove(dst, src, len);
	printf("dst is: %s and src is: %s\n", dst, src);
	return (0);
}

#include <string.h>
#include <stdio.h>

void *ft_memmove(void *dest, const void *src, unsigned int n){

   char *s;
   char *d;
   int i;

   s = (char*) src;
   d = (char*) dest;
   i = 0;

   while(src && i < n)
   {
     d[i] = s[i];
     i++;
   }
   if (s[i] == '\0')
   {
     d[i] = s[i];
   }
}

int main(void)
{
  int i = 9;
  int c = 10;
  int d = 0;
  char dest[] = "0102030405060708090";
  char src[] = "abcdefgh";
  char ft_dest[] = "0102030405060708090";
  char ft_src[] = "abcdefgh";
  char test[30];
  char ft_test[30];

  printf("dest before memmove: %s\n", dest);
  memmove(dest, src, i);
  printf("dest after memmove: %s\n", dest);
  
  printf("ft_dest before memmove: %s\n", ft_dest);
  ft_memmove(ft_dest, ft_src, i);
  printf("ft_dest after memmove: %s\n", ft_dest); 

  while (dest[c])
  {
    test[d] = dest[c];
    d++;
    c++;
  }
  test[d] = '\0';
  c = 10;
  d = 0;
  while (ft_dest[c])
  {
    ft_test[d] = ft_dest[c];
    d++;
    c++;
  }
  ft_test[d] = '\0';
  printf("this is memmove: %s and this is ft-memmove: %s", test, ft_test);
}
*/
