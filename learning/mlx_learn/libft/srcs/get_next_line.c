/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 12:48:59 by jechekao          #+#    #+#             */
/*   Updated: 2022/08/01 18:59:24 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*retline(char *buff)
{
	char	*line;
	int		i;

	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	line = ft_calloc_gnl(i + 2, sizeof(char));
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
	ret = ft_calloc_gnl((ft_strlen_gnl(buff) - i + 1), sizeof(char));
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
		res = ft_calloc_gnl(1, 1);
	buff = ft_calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
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
		if (ft_strchr_gnl(buff, '\n'))
			break ;
	}
	free(buff);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buff = readnewline(fd, buff);
	if (!buff)
		return (NULL);
	line = retline(buff);
	buff = nextline(buff);
	return (line);
}
