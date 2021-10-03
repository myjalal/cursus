#include <string.h>
#include <xlocale.h>
#include <stdio.h>

int main(void)
{
	const char *largestring = "Foo Bar Baz";
	const char *smallstring = "Bar";
	char *ptr;
	 
	ptr = strnstr(largestring, smallstring, 3);
	printf("%p", ptr);
}
