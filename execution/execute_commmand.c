/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commmand.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 12:42:46 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/21 18:50:09 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_error(char *prefix, char *command)
{
	write(2, prefix, ft_strlen(prefix));
	write(2, command, ft_strlen(command));
	write(2, ": ", 2);
}

int	is_directory(const char *path)
{
	struct stat	path_stat;

	if (stat(path, &path_stat) != 0)
	{
		perror("stat");
		return (0);
	}
	return (S_ISDIR(path_stat.st_mode));
}

void	before_execution(t_command *command, t_be_executed *to_execute)
{
	char	**args;

	args = command->command_args;
	if (args == NULL || args[0] == NULL)
		exit(0);
	else if (command->path == NULL)
	{
		write(2, "minishell: ", 11);
		write(2, args[0], ft_strlen(args[0]));
		write(2, ": command not found\n", 20);
		exit(127);
	}
	else if (ft_is_path(args[0]))
		ft_check_path_correct(args[0]);
	else if (ft_is_path(command->path))
		ft_check_path_correct(command->path);
	assign_input(command, to_execute);
	assign_output(command, to_execute);
	if (command->in_type != STDIN_FILENO)
		dup2(command->fd_in, STDIN_FILENO);
	if (command->out_type != STDOUT_FILENO)
		dup2(command->fd_out, STDOUT_FILENO);
	close_pipes(to_execute->list_pipes);
}

void	execute_command(t_command *command, t_be_executed *to_execute)
{
	char	**env;

	if (ft_is_executed(command) == 0)
	{
		close_pipes(to_execute->list_pipes);
		exit(1);
	}
	before_execution(command, to_execute);
	env = give_array_str(*to_execute->env_list);
	execve(command->path, command->command_args, env);
	print_error("minishell: ", command->command_args[0]);
	if (errno == 13)
		exit(126);
	exit(127);
}
