/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:50:41 by jechekao          #+#    #+#             */
/*   Updated: 2022/05/29 18:50:58 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// managing errors
#include "push_swap.h"

int	error_exit(char *error, int err_exit)
{
	if (err_exit != 0)
		ft_putstr_fd(error, 2);
	exit(err_exit);
}
