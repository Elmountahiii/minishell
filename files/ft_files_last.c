/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files_last.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:12:45 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/09 20:06:06 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_command_files *ft_correct_out_file(t_command_files *files_list)
{
	t_command_files	*selected_file;

	selected_file = NULL;
	while (files_list)
	{
		if (files_list->fd == -1 )
		{
			selected_file = files_list;
			break ;
		}
		if (files_list->type == REDIRECTION_OUT || files_list->type == APPEND)
			selected_file = files_list;
		files_list = files_list->next;
	}
	return (selected_file);
}


t_command_files *ft_correct_in_file(t_command_files *files_list)
{
	t_command_files	*selected_file;

	selected_file = NULL;
	while (files_list)
	{
		if (files_list->fd == -1)
		{
			selected_file = files_list;
			break ;
		}
		if (files_list->type == REDIRECTION_IN)
			selected_file = files_list;
		files_list = files_list->next;
	}
	return (selected_file);
}

t_command_files	*ft_files_last(t_command_files *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
