/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_files.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:13:40 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/09 18:28:38 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_select_files(t_command *command)
{
	t_command_files	*last_file;
	t_heredoc		*last_heredoc;
	
	if (!command)
		return ;
	last_file = ft_files_last(command->files_list);
	last_heredoc = ft_heredoc_last(command->heredoc_list);
	(void)last_file;
	(void)last_heredoc;
	if (command->is_heredoc)
	{
		printf("heredoc\n");
	}else
	{
		printf("file\n");
	}
}