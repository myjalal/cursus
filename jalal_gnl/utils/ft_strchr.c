#include "../get_next_line.h"

int ft_strchr(const char *s, int c)
{
    unsigned char   c_unsigned;
    int             i;

    i = 0;
    if (!s)
        return (-1);
    c_unsigned = (unsigned char)c;

    while (s[i])
    {
        if (s[i] == c_unsigned)
            return (i);
        i++;
    }
    if (c_unsigned == '\0')
        return (i);
    return (-1);
}