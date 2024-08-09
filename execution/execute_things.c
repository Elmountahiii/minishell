/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_things.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:35:05 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/09 10:56:00 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	close_other_pipes(t_command	*command, t_pipe *list_pipes)
{
	(void )command;
	t_pipe	*tmp;

	tmp = list_pipes;
	while (tmp)
	{
		if (tmp->fd[0] != command->fd_in)
			close(tmp->fd[0]);
		if (tmp->fd[1] != command->fd_out)
			close(tmp->fd[1]);
		tmp = tmp->next;
	}
}

void	execute_built_in(t_command	*command, t_be_executed	*to_execute, int procss)
{
	int std_out;
	int std_int;
	if (ft_is_executed(to_execute->list_files, command->index) == 0)
	{
		close_pipes(to_execute->list_pipes);
		if (procss)
			exit(1);
		exit_status = 1;
		return ;
	}
	assign_input(command, to_execute);
	assign_output(command, to_execute);
	if (procss)
		close_other_pipes(command, to_execute->list_pipes);
	std_out = dup(STDOUT_FILENO);
	std_int = dup(STDIN_FILENO);
	if (command->fd_in != STDIN_FILENO)
		dup2(command->fd_in, STDIN_FILENO);
	if (command->fd_out != STDOUT_FILENO)
		dup2(command->fd_out, STDOUT_FILENO);
	if (ft_strcmp(command->command_args[0], "echo") == 0)
		our_echo(command, to_execute, procss);
	else if (ft_strcmp(command->command_args[0], "cd") == 0)
		our_cd(command, to_execute, procss);
	else if (ft_strcmp(command->command_args[0], "pwd") == 0)
		our_pwd(command, to_execute, procss);
	else if (ft_strcmp(command->command_args[0], "unset") == 0)
		ft_unset(command, to_execute, procss);
	else if (ft_strcmp(command->command_args[0], "env") == 0)
		our_env(command, to_execute, procss);
	else if (ft_strcmp(command->command_args[0], "export") == 0)
		ft_export(command, to_execute, procss);
	else if (ft_strcmp(command->command_args[0], "exit") == 0)
		our_exit(command, to_execute, procss);
	dup2(std_out, 1);
	dup2(std_int, 0);
	close(std_out);
	close(std_int);
	if (procss)
		exit(exit_status);
	// optimize export and exit conditions
}

void	execute_things(t_be_executed	*to_execute)
{
	t_command	*commands_list;
	int 		status;
	pid_t		*pid;
	int			i;

	i = 0;
	commands_list = to_execute->commands_list;
	if (to_execute->list_size == 1 && is_built_in(commands_list->command_args[0]))
	{
		execute_built_in(commands_list, to_execute, 0);
		return ;
	}
	pid = malloc(sizeof(pid_t)*(to_execute->list_size));
	while (commands_list)
	{
		pid[i] = fork();
		if (pid[i] == 0)
		{
			if (is_built_in(commands_list->command_args[0]))
				execute_built_in(commands_list, to_execute, 1);
			else
				execute_command(commands_list, to_execute);
		}
		commands_list = commands_list->next;
		i++;
	}
	close_pipes(to_execute->list_pipes);
	i = 0;
	while (i < to_execute->list_size)
	{
		waitpid(pid[i], &status, 0);
		if (WIFEXITED(status))
			exit_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			exit_status = WTERMSIG(status);
		i++;
	}
}
