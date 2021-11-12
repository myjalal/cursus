/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:19:04 by jechekao          #+#    #+#             */
/*   Updated: 2021/11/12 11:19:04 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*src1;
	unsigned char	*src2;

	src1 = (unsigned char *)s1;
	src2 = (unsigned char *)s2;
	while (n--)
	{
		if (*src1 != *src2)
			return (*src1 - *src2);
		src1++;
		src2++;
	}
	return (0);
}

/*int main(void)
{
	char *s1 = "\xff\xaa\xde\x12WXYZ";
	char *s2 = "\xff\xaa\xde\x12MACOSX";
	size_t size = 7;
	
	printf("ft_memcmp: %d\n", ft_memcmp(s1, s2, size));
	printf("memcmp: %d\n", ft_memcmp(s1, s2, size));
}*/
