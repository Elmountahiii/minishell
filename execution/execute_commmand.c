/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commmand.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 12:42:46 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/03 16:41:20 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void print_error(char *prefix, char *command)
{
	write(2, prefix, ft_strlen(prefix));
	write(2, command, ft_strlen(command));
	write(2, ": ", 2);
	if (errno == 14)
		write(2, "command not found\n", 18);
	// else if (errno == 2)
	// {
			
	// }
}

char	**give_array_str(t_env_list *env_list)
{
	char **env;
	char *line;

	env = NULL;
	line = NULL;
	while (env_list)
	{
		line = ft_strjoin(env_list->key, env_list->value);
		ft_append_to_list(env, line);
		// don't forget to free the array
		free(line);
		env_list = env_list->next;
	}
	return (env);
}

void	execute_command(t_command *command,	t_be_executed	*to_execute)
{
	char **env;
	// (void)list_of_pipes;
	(void)command;
	// int std_out;
	// int std_int;

	assign_input(command, to_execute);
	assign_output(command, to_execute);
	// workd on out ad in files
	// std_out = dup(1);
	// std_int = dup(0);
	dup2(command->fd_out, 1);
	dup2(command->fd_in, 0);
	env = give_array_str(command->env_list);
	execve(command->path, command->command_args, env);
	print_error("minishell: ", command->command_args[0]);
	// printf("erno: %i\n", errno);
	// perror("mini:");
	// printf("comaand: %i\n", command->index);
	// (void)command;
	// dup2(command->fd_in, 0);
	// dup2(command->fd_out, 1);
	// check if builtin
	// close pipes
	exit(errno);
}
