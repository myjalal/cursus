/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 13:22:46 by jechekao          #+#    #+#             */
/*   Updated: 2022/01/30 13:23:57 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*retline(char *buff)
{
	char	*line;
	int		i;

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
	if (buff[i] && buff[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*nextline(char *buff)
{
	char	*ret;
	int		i;
	int		j;

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
	return (ret);
}

char	*readnewline(int fd, char *res)
{
	char	*buff;
	int		ret;

	if (!res)
		res = ft_calloc(1, 1);
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret < 0)
		{
			free (buff);
			return (NULL);
		}
		buff[ret] = '\0';
		res = join_free (res, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer[fd] = readnewline(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = retline(buffer[fd]);
	buffer[fd] = nextline(buffer[fd]);
	return (line);
}
