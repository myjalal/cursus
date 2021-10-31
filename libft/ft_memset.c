#include "libft.h"

void *ft_memset(void *b, int c, size_t len)
{
	unsigned char *str;
	str = (unsigned char *)b;
	while(len--)
	{
		str[len] = (unsigned char)c;
	}
	return(b);
}

/*int main()
{
	
	int array [] = { 54, 85, 20, 63, 21 };
	size_t size = sizeof( int ) * 5;
	int length;
	
	// Display the initial values
	for( length=0; length<5; length++) {
		printf( "%d ", array[ length ] );
	}
	printf( "\n" );
	
	// Reset the memory bloc
	ft_memset( array, 0, size );
	
	// Display the new values 
	for( length=0; length<5; length++) {
		printf( "%d ", array[ length ] );
	}
	printf( "\n" );
	
	return 0;
}*/
