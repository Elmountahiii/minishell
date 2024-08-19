/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:20:04 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/19 11:11:49 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_assign_fds(t_command *command, t_tokens_list *list, int index)
{
	t_tokens_list	*tmp;

	if (!command)
		return ;
	tmp = list;
	if (index > 0 && command->in_type == STDIN_IO)
		command->in_type = PIPE_IO;
	if (tmp && tmp->next)
	{
		if (tmp->type == SPACE_TOKEN)
			tmp = tmp->next;
		if (tmp && tmp->type == PIPE && command->out_type == STDOUT_IO)
			command->out_type = PIPE_IO;
	}
	command->index = index;
	if (command->out_type == STDIN_IO)
		command->fd_in = STDIN_FILENO;
	if (command->out_type == STDOUT_IO)
		command->fd_out = STDOUT_FILENO;
}

t_command	*ft_add_command(t_command **command_list,
	t_tokens_list *tokens, t_env_list *env_list)
{
	int				index;
	t_command		*command;
	t_tokens_list	*tmp;

	if (!tokens)
		return (NULL);
	index = 0;
	tmp = tokens;
	while (tmp)
	{
		command = ft_create_command(&tmp, env_list);
		ft_assign_fds(command, tmp, index);
		ft_command_addback(command_list, command);
		index++;
		if (tmp)
			tmp = tmp->next;
	}
	return (*command_list);
}
