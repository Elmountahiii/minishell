/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:09:53 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/21 14:54:28 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_clean(t_be_executed *to_execute, char **array, char *line)
{
	ft_clean_tokens(&to_execute->tokens_list);
	ft_clean_heredoc(&to_execute->heredoc_list);
	ft_clean_files(&to_execute->files_list);
	ft_clean_commands(&to_execute->commands_list);
	ft_clean_pipes(&to_execute->list_pipes);
	ft_clean_array(array);
	free(line);
}
