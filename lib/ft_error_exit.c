/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:34:53 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/09 17:53:50 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_error_exit(char *message, char *error)
{
	int	i;

	i = 0;
	while (message && message[i])
	{
		write(2, &message[i], 1);
		i ++;
	}
	i = 0;
	write(2, " : ", 3);
	while (error && error[i])
	{
		write(2, &error[i], 1);
		i ++;
	}
	write(2, "\n", 1);
	exit(1);
}
