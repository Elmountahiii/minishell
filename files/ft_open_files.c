/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:20:14 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/21 15:06:14 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_skip_to_next_command(t_command_files **files)
{
	int	id;

	if (!files || !*files)
		return ;
	id = (*files)->index;
	while (*files && (*files)->index == id)
		*files = (*files)->next;
}

void	ft_print_ambiguous(t_command_files **files)
{
	ft_putstr_fd("minishell: ambiguous redirect\n", STDERR_FILENO);
	ft_skip_to_next_command(files);
}

void	ft_print_file_error(t_command_files **files)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	perror((*files)->file_name);
	ft_skip_to_next_command(files);
}

void	ft_open_files(t_command_files *files)
{
	t_command_files	*tmp;

	if (!files)
		return ;
	tmp = files;
	while (tmp)
	{
		if (tmp->is_ambiguous)
		{
			ft_print_ambiguous(&tmp);
			continue ;
		}
		if (tmp->type == REDIRECTION_IN)
			tmp->fd = open(tmp->file_name, O_RDONLY);
		else if (tmp->type == REDIRECTION_OUT)
			tmp->fd = open(tmp->file_name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		else if (tmp->type == APPEND)
			tmp->fd = open(tmp->file_name, O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (tmp->fd < 0)
		{
			ft_print_file_error(&tmp);
			continue ;
		}
		tmp = tmp->next;
	}
}
