#include "testing.h"
#include <stdio.h>
#include <fcntl.h>



char	*get_next_line(int fd)
{
    char    *buf;
    int     ret;

    buf = malloc(BUFFER_SIZE + 1);
    if (!buf)
        return(NULL);
    ret = read(fd, buf, BUFFER_SIZE);
    if (ret < 0)
    {
        free(buf);
        printf("read failed"); //remove
        return(NULL);
    }
    buf[ret] = '\0';
    return (buf);


}


int main(void)
{
    char    *line;
    int     i;
    int     fd;
    i = 1;
    while (i < 3)
    {
        fd = open("test.txt", O_RDONLY);
        line = get_next_line(fd);
        printf("line[%d]: %s\n", i, line);
        //free(line);
        i++;
    }
    close(fd);
    return(0);
}