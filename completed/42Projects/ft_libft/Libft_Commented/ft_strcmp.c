/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleticia <cleticia@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 21:24:37 by cleticia          #+#    #+#             */
/*   Updated: 2021/10/10 20:59:07 by cleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_strcmp(char *s1, char *s2)
{
	while (*s1++ == *s2++ && *s1 != '\0' && *s2 != '\0')
        ;
	return (*s1 - *s2);
}
