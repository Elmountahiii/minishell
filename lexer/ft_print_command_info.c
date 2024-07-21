/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_command_info.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:31:21 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/21 15:38:17 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
	// else if (type == DEFAULT_IO)
	// 	return ("DEFAULT_IO\n");
	return ("UNKNOWN\n");
}

void	ft_print_command_info(t_command *command)
{
	int i = 0;
	
	while (command)
	{
		//printf("command path : %s\n", command->path);
		printf("in_type : %s", ft_get_file_type(command->in_type));
		printf("out_type : %s", ft_get_file_type(command->out_type));
		printf("in_file : %s\n", command->in_file);
		printf("out_file : %s\n", command->out_file);
		printf("is_append : %d\n", command->is_append);
		printf("is_heredoc : %d\n", command->is_heredoc);
		while (command->command_args[i] != NULL)
		{
			printf("command arg : %s\n", command->command_args[i]);
			i++;
		}
		i = 0;
		command = command->next;
		printf("--------------------\n");
	}
}
