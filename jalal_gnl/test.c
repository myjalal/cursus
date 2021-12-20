#include "get_next_line.h"
#include <string.h>

int main(void)
{
    int		fd;
	int		ret;
	int 	line;
    size_t  len;
	static char	*buff[4096];
    //int     i = 4;
		
	line = 0;
    fd = open("./test_files/test.txt", O_RDONLY);
    //printf("%d\n", fd);
    ret = read(fd, buff, BUFFER_SIZE); // returns number of vareable read
    printf("read returns: %d\n", ret);
    len = ft_strlen(buff[fd]);
    printf("buff len = %zu\n", len);
    printf("%s\n", buff);
	//printf("%s\n", readnewline(fd));
}

/*char    *readnewline(int fd)
{
    char    *buff;
    int     ret;

    buff = malloc(BUFFER_SIZE + 1);
    if (!buff)
        return (NULL);
    ret = read(fd, buff, BUFFER_SIZE);
    printf("read returns: %d\n", ret);
    if (ret < 0)
    {
        free (buff);
        return (NULL);
    }
    buff[ret] = '\0';
    return (buff);
}*/

size_t ft_strlen(const char *s)
{
    int i;

    i = 0;
    if (!s)
        printf("error strlen !s\n");
        return (0);
    while(s[i])
        printf("%d\n", i);
        i++;
    return (i);
}