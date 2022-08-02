/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 12:48:50 by jechekao          #+#    #+#             */
/*   Updated: 2022/08/01 18:59:08 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 42

# endif

/* Concatenates two strings, ensuring null-termination */
char	*ft_strjoin_gnl(char const	*s1, char const	*s2);

/* Retrieves next line from given file descriptor */
char	*get_next_line(int fd);

/* Returns length of a string */
size_t	ft_strlen_gnl(const char *s);

/* Find if \n is in the string*/
char	*ft_strchr_gnl(const char *string, int c);

/* Copies chars from src to dst ensuring null-termination */
char	*retline(char *buff);

/* Allocates memory and set it to '\0' */
void	*ft_calloc_gnl(size_t count, size_t size);

/* Delete line from the static variable buf */
char	*nextline(char *buff);

/* Performs a new read and adds it to static variable buf */
char	*readnewline(int fd, char *res);

/* Join old read and new read and free old read */
char	*join_free(char *buffer, char *buf);

#endif