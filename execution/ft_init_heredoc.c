/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:21:26 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/06 11:55:24 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_init_heredoc(t_command *command)
{
	if (!command)
		return ;
	while (command)
	{
		if (command->in_type == FILE_IO && command->is_heredoc)
		{
			ft_open_heredoc(command);
			ft_fill_heredoc(command);
		}
		command = command->next;
	}
}