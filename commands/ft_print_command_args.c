/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_command_args.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:37:26 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/15 14:45:41 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_print_command_args(t_command *command)
{
	int i;

	i = 0;
	while (command->command_args && command->command_args[i])
	{
		printf("'\033[32m%s\033[0m'",  command->command_args[i]);
		i++;
	}
	printf("\n");
}
