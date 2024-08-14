/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files_last.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:12:45 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/11 14:59:18 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_command_files *ft_correct_out_file(t_command_files *files_list)
{
	t_command_files	*selected_file;
	t_command_files	*tmp;

	selected_file = NULL;
	tmp = files_list;
	while (tmp)
	{
		if (tmp->fd == -1)
		{
			selected_file = tmp;
			break ;
		}
		if (tmp->type == REDIRECTION_OUT || tmp->type == APPEND)
			selected_file = tmp;
		tmp = tmp->next;
	}
	return (selected_file);
}


t_command_files *ft_correct_in_file(t_command_files *files_list)
{
	t_command_files	*selected_file;
	t_command_files	*tmp;

	selected_file = NULL;
	tmp = files_list;
	while (tmp)
	{
		if (tmp->fd == -1)
		{
			selected_file = tmp;
			break ;
		}
		if (tmp->type == REDIRECTION_IN)
			selected_file = tmp;
		tmp = tmp->next;
	}
	return (selected_file);
}

t_command_files	*ft_files_last(t_command_files *lst)
{
	t_command_files *tmp = lst;
	if (!tmp)
		return (NULL);
	while (tmp->next)
    		tmp = tmp->next;
	return (tmp);
}
