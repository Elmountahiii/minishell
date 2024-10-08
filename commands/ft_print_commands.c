/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:18:53 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/19 16:04:36 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_get_token_typee(t_token_type type)
{
	if (type == WORD)
		return ("WORD");
	else if (type == SINGLE_QUOTE_WORD)
		return ("SINGLE_QUOTE_WORD");
	else if (type == DOUBLE_QUOTE_WORD)
		return ("DOUBLE_QUOTE_WORD");
	else if (type == ENV)
		return ("ENV");
	else if (type == PIPE)
		return ("PIPE");
	else if (type == APPEND)
		return ("APPEND");
	else if (type == HEREDOC)
		return ("HEREDOC");
	else if (type == SPACE_TOKEN)
		return ("SPACE_TOKEN");
	else if (type == REDIRECTION_IN)
		return ("REDIRECTION_IN");
	else if (type == REDIRECTION_OUT)
		return ("REDIRECTION_OUT");
	return ("UNKNOWN");
}

char	*ft_get_file_type(t_ttype type)
{
	if (type == STDIN_IO)
		return ("STDIN_IO");
	else if (type == STDOUT_IO)
		return ("STDOUT_IO");
	else if (type == FILE_IO)
		return ("FILE_IO");
	else if (type == PIPE_IO)
		return ("PIPE_IO");
	return ("UNKNOWN");
}

char	*get_is_true(bool is_true)
{
	if (is_true)
		return ("true");
	return ("false");
}

void	ft_print_commands(t_command *command_list)
{
	t_command	*tmp;

	tmp = command_list;
	while (tmp)
	{
		printf("ID: \033[32m%d\033[0m\n", tmp->index);
		printf("in_t: '\033[0;34m%s\033[0m', out_t: '\033[0;34m%s\033[0m'\n",
			ft_get_file_type(tmp->in_type), ft_get_file_type(tmp->out_type));
		printf("input: '\033[32m%s\033[0m', output: '\033[32m%s\033[0m' \n",
			tmp->in_file, tmp->out_file);
		printf("fd_in: %d , fd_out %d\n",
			tmp->fd_in, tmp->fd_out);
		printf("is_heredoc: %s, is_append: %s, is_ambiguous: %s\n",
			get_is_true(tmp->is_heredoc),
			get_is_true(tmp->is_append),
			get_is_true(tmp->is_ambiguous));
		printf("path: %s\n", tmp->path);
		printf("Command: \033[32m\033[0m");
		ft_print_command_args(tmp);
		printf("commands len : %d\n", ft_array_len(tmp->command_args));
		printf("--------------------\n");
		tmp = tmp->next;
	}
}
