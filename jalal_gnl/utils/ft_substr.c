#include "../get_next_line.h"

char    *ft_substr(const char *s, unsigned int start, size_t len)
{
    char    *dst;
    size_t  s_len;
    size_t  i;

    i = 0;
    s_len = ft_strlen(s);
    if (!s || start >= s_len)
    {
        dst = (char *)malloc(1);
        if (dst == NULL)
            return (NULL);
        dst[0] = '\0';
        return(dst);
    }
    if (len > s_len)
		len = s_len;
    dst = (char *)malloc(len + 1);
    if (dst == NULL)
        return (NULL);
    while (i++ < start)
        s++;
    ft_strlcpy()
}