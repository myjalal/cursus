#include <string.h>
#include <stdio.h>

int main(void)
{
  int i = 30;
  char dest[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
  char src[] = "abcdefghijk";
  printf("dest befor memmove: %s\n", dest);
  memmove(dest, src, i);
  dest[11] = '0';
  printf("dest after memmove: %s\n", dest);
  printf("%d", dest[1]);
}

