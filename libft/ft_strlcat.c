/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:21:51 by jechekao          #+#    #+#             */
/*   Updated: 2021/11/12 11:21:51 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	dest_size;
	unsigned int	src_size;

	i = 0;
	dest_size = 0;
	src_size = 0;
	while (src[src_size])
		src_size++;
	while (dest[dest_size])
		dest_size++;
	if (size <= dest_size)
		return (size + src_size);
	while (i < size - dest_size - 1 && src[i])
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	dest[dest_size + i] = '\0';
	return (src_size + dest_size);
}
/*
int main()
{
	char first[] = "This is ";
	char last[] = "a potentially long string";
	int r;
	int size = 0;
	char buffer[size];

	strcpy(buffer,first);
	r = ft_strlcat(buffer,last,size);

	puts(buffer);
	printf("Value returned: %d\n",r);
	if( r > size )
		puts("String truncated");
	else
		puts("String was fully copied");

	return(0);
}
*/
