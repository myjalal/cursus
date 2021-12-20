#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
#include <stdio.h> // remove eventually, this is just for print test

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 42

# endif

/* Retrieves next line from given file descriptor */
char	*get_next_line(int fd);

/* Returns length of a string */
size_t ft_strlen(const char *s);

/* Retrieves index of first appearance of i in s, or -1 */
int		ft_strchr(const char *s, int c);

/* Copies chars from src to dst ensuring null-termination */


/* Allocates enough memory to make a copy of s from start, copying len bytes */
char    *ft_substr(const char *s, unsigned int start, size_t len);

/* Concatenates two strings, ensuring null-termination */


/* Removes line from the static variable buf */


/* Performs a new read and adds it to static variable buf */


/* Performs a new read and returns read string */
char    *readnewline(int fd);

#endif

/*
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define R_LINE 1
# define R_EOF 0
# define R_ERROR -1

int		get_next_line(int fd, char **line);

size_t	ft_strlen(const char *s);
void	ft_strcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);

int		findchr(const char *s, char c);
char	*strjoin_free(char *s1, char *s2);
int		strcpy_line_bl(char **line, char *str, int i, char *buff);
int		get_read(int fd, char **line, char *buff, char **str);

#endif
*/