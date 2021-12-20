#include "get_next_line.h"

char    *readnewline(int fd)
{
    char    *buff;
    int     ret;

    buff = malloc(BUFFER_SIZE + 1);
    if (!buff)
        return (NULL);
    ret = read(fd, buff, BUFFER_SIZE);
    if (ret < 0)
    {
        free (buff);
        return (NULL);
    }
    buff[ret] = '\0';
    return (buff);
}