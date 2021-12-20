#include "get_next_line.h"

int main(void)
{
    int		fd;
	int		ret;
	int 	line;
	char	*buff = NULL;
		
	line = 0;
    
    fd = open("./test_files/test.txt", O_RDONLY);
    printf("%d\n", fd);
    
    /*while ((ret = get_next_line(fd, &buff)) > 0)
	{
		printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
		free(buff);
	}
	printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
	if (ret == -1)
		printf("-----------\nError\n");
	else if (ret == 0)
		printf("-----------\nEnd of file\n");
	close(fd);

	return (0);*/
	 
	printf("%s\n", readnewline(fd));
}