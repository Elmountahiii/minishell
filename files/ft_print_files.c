/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:05:00 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/17 22:58:17 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_get_files_type(t_token_type type)
{
	if (type == REDIRECTION_IN)
		return ("REDIRECTION_IN");
	if (type == REDIRECTION_OUT)
		return ("REDIRECTION_OUT");
	if (type == APPEND)
		return ("APPEND");
	if (type == HEREDOC)
		return ("HEREDOC");
	return ("UNKNOWN");
}

char	*ft_get_files_ambiguous(bool is_ambiguous)
{
	if (is_ambiguous)
		return ("true");
	return ("false");
}

void	ft_printf_files(t_command_files *files)
{
	t_command_files	*tmp;

	tmp = files;
	while (tmp)
	{
		printf("id: %d, fd: %d type: %s is_ambiguous: %s\n",
			tmp->index, tmp->fd,
			ft_get_files_type(tmp->type),
			ft_get_files_ambiguous(tmp->is_ambiguous));
		printf("file_name: %s\n", tmp->file_name);
		printf("ambiguous_name: %s\n", tmp->ambiguous_name);
		tmp = tmp->next;
	}
	printf("\n");
}
