#include "get_next_line.h"
//#include <stdio.h>
//#include <fcntl.h>

char    *retline(char *buff)
{
    char    *line;
    int     i;

    i = 0;
    if (!buff[i])
        return (NULL);
    while (buff[i] && buff[i] != '\n')
        i++;
    line = ft_calloc(i + 2, sizeof(char));
    i = 0;
    while (buff[i] && buff[i] != '\n')
    {
        line[i] = buff[i];
        i++;
    }
    if (buff[i] && buff[i] != '\n')
        line[i++] = '\n';
    return (line);
}

char    *nextline(char *buff)
{
    char    *ret;
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (buff[i] && buff[i] != '\n')
        i++;
    if (!buff[i])
    {
        free(buff);
        return (NULL);
    }
    ret = ft_calloc((ft_strlen(buff) - i + 1), sizeof(char));
    i++;
    while (buff[i])
        ret[j++] = buff[i++];
    free(buff);
    return(ret);
}

char    *readnewline(int fd, char *res)
{
    char    *buff;
    int     ret;

    if (!res)
        res = ft_calloc(1, 1);
    buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    ret = 1;
    while (ret > 0)
    {
        ret = read(fd, buff, BUFFER_SIZE);
        if (ret < 0) //or ret == -1
        {
            free (buff);
            return (NULL);
        }
        buff[ret] = '\0';
        res = joinNfree (res, buff);
        if (ft_strchr(buff, '\n'))
            break;
    }
    free(buff);
    return (res);
}

char    *get_next_line(int fd)
{
    static char     *buffer;
    char            *line;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
    buffer = readnewline(fd, buffer);
	if (!buffer)
		return (NULL);
    line = retline(buffer);
    buffer = nextline(buffer);
    return (line);
}

/*
int main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	fd1 = open("tests/test.txt", O_RDONLY);
	fd2 = open("tests/test2.txt", O_RDONLY);
	fd3 = open("tests/test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}*/