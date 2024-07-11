/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_not_found.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:26:48 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/11 14:29:09 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_command_not_found(char *command)
{
	int	i;

	i = 0;
	ft_print("Command not found : ", 2);
	while (command && command[i])
	{
		write(2, &command[i], 1);
		i ++;
	}
	ft_print("\n", 2);
}
