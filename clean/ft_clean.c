/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 12:39:10 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/12 13:25:05 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_clean(t_be_executed *to_execute)
{
	t_command	*tmp;
	while (to_execute->commands_list)
	{
	tmp = to_execute->commands_list->next;
	ft_clean_files(to_execute->commands_list->files_list);
	ft_clean_heredoc(to_execute->commands_list->heredoc_list);
	ft_clean_commands(to_execute->commands_list);
	to_execute->commands_list = tmp;
	}
	
	// ft_clean_files(to_execute->commands_list->files_list);
	ft_clean_tokens(to_execute->tokens_list);
	// ft_clean_heredoc(to_execute->commands_list->heredoc_list);
	ft_clean_pipes(to_execute->list_pipes);
	// ft_clean_commands(to_execute->commands_list);
	free(to_execute);
}
