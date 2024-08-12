/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 12:39:10 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/12 11:35:00 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_clean(t_be_executed *to_execute)
{
	ft_clean_files(to_execute->commands_list->files_list);
	ft_clean_tokens(to_execute->tokens_list);
	ft_clean_heredoc(to_execute->commands_list->heredoc_list);
	ft_clean_pipes(to_execute->list_pipes);
	ft_clean_commands(to_execute->commands_list);
}
