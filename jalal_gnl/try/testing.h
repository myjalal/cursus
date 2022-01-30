# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
#include <stdio.h> // remove eventually, this is just for print test

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 10

char	*get_next_line(int fd);
int     main(void);

# endif