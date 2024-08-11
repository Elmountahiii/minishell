/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_command_info.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:31:21 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/11 13:33:45 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *ft_get_token_type(t_token_type type)
{
	if (type == WORD)
		return ("WORD\n");
	else if (type == SINGLE_QUOTE_WORD)
		return ("SINGLE_QUOTE_WORD\n");
	else if (type == DOUBLE_QUOTE_WORD)
		return ("DOUBLE_QUOTE_WORD\n");
	else if (type == ENV)
		return ("ENV\n");
	else if (type == PIPE)
		return ("PIPE\n");
	else if (type == APPEND)
		return ("APPEND\n");
	else if (type == HEREDOC)
		return ("HEREDOC\n");
	else if (type == SPACE_TOKEN)
		return ("SPACE_TOKEN\n");
	else if (type == REDIRECTION_IN)
		return ("REDIRECTION_IN\n");
	else if (type == REDIRECTION_OUT)
		return ("REDIRECTION_OUT\n");
	return ("UNKNOWN\n");
}

char	*ft_get_file_type(IOType type)
{
	if (type == STDIN_IO)
		return ("STDIN_IO\n");
	else if (type == STDOUT_IO)
		return ("STDOUT_IO\n");
	else if (type == FILE_IO)
		return ("FILE_IO\n");
	else if (type == PIPE_IO)
		return ("PIPE_IO\n");
	return ("UNKNOWN\n");
}

void	ft_print_command_info(t_command	*command)
{
	int	i;
	t_command *tmp;

	i = 0;
	tmp = command;
	while (tmp)
	{
		printf("path : %s\n", tmp->path);
		printf("in_type : %s", ft_get_file_type(tmp->in_type));
		printf("out_type : %s", ft_get_file_type(tmp->out_type));
		printf("in_file : %s\n", tmp->in_file);
		printf("out_file : %s\n", tmp->out_file);
		printf("is_append : %d\n", tmp->is_append);
		printf("is_heredoc : %d\n", tmp->is_heredoc);
		printf("index : %d\n", tmp->index);
		printf("fd_in : %d\n", tmp->fd_in);
		printf("fd_out : %d\n", tmp->fd_out);
		printf("dil : %s\n", tmp->dil);
		printf("commands arguments  : \n");
		while (tmp->command_args[i])
		{
			printf("%s ",tmp->command_args[i]);
			i++;
		}
		printf("\n");
		i = 0;
		printf("heredoc list : \n");
		while (tmp->heredoc_list)
		{
			printf("name : %s , dil : %s , fd %d\n", tmp->heredoc_list->file_name, tmp->heredoc_list->dil, tmp->heredoc_list->fd);
			tmp->heredoc_list = tmp->heredoc_list->next;
		}		
		i = 0;
		printf("files_list : \n");
		while (tmp->files_list)
		{
			printf("name : %s , fd %d ,type %s", tmp->files_list->name,tmp->files_list->fd ,ft_get_token_type(tmp->files_list->type));
			tmp->files_list = tmp->files_list->next;
		}
		i = 0;
		printf("--------------------\n");
		tmp = tmp->next;
	}
}
