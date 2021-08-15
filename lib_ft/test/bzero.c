#include <strings.h>
#include <stdio.h>

int main(void)
{
	char s[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '\0'};
	char d[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', '\0'};
	memcpy(d, s, 11);
	printf("%s\n",d);
	return (0);
}
