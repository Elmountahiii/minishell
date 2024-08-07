/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commmand.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 12:42:46 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/07 14:01:57 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void print_error(char *prefix, char *command)
{
	// struct stat fileStat;
	// printf("command is : %s\n", command);
	
	// if (stat(command, &fileStat) == 0)
	// {
	// 	perror(prefix);
	// 	printf("is adirectory\n");
	// 	exit(127);
	// }
	(void)command;
	perror(prefix);
	if (errno == ENOENT || errno == ENOTDIR)
		exit(127);
	else if (errno == ENOEXEC)
		exit(126);
	else if (errno == EACCES)
		exit(126);
	else
		exit(1);
		
	// write(2, prefix, ft_strlen(prefix));
	// write(2, command, ft_strlen(command));
	// write(2, ": ", 2);
	// printf("\nerror number is : %d\n",errno);
	// if (errno == 14)
	// {
	// 	write(2, "command not found\n", 18);
	// 	exit(127);
	// }
	// else if (errno == 8)
	// {
	// 	write(2, "cannot execute binary file: Exec format error\n", 46);
	// 	exit(126);
	// }else if (errno == 2)
	// {
	// 	write(2, "No such file or directory\n", 26);
	// 	exit(127);
	// }
	// else if(errno == 13)
	// {
	// 	write(2, "permission denied\n", 18);
	// 	exit(126);
	// }
	// // else if (errno == 2)
	// // {
			
	// // }
}

char	**append_to_array(char **array, char *str) {
    int len = 0;

    // Find the length of the array
    while (array && array[len]) {
        len++;
    }

    // Allocate memory for the new array
    char **new_array = (char **)calloc(len + 2, sizeof(char *));
    if (!new_array) {
        return NULL;
    }

    // Copy the old array to the new array
    for (int i = 0; i < len; i++) {
        new_array[i] = strdup(array[i]);
    }

    // Add the new string to the end of the new array
    new_array[len] = strdup(str);

    // Set the last element to NULL
    new_array[len + 1] = NULL;

    // Free the old array
    if (array) {
        free(array);
    }

    return new_array;
}

char	**give_array_str(t_env_list *env_list)
{
	char **env;
	char *line;

	env = NULL;
	line = NULL;
	while (env_list)
	{
		line = ft_join_three(env_list->key, "=", env_list->value);
		// printf("%s\n", line);
		env = append_to_array(env, line);
		// don't forget to free the array
		env_list = env_list->next;
	}
	return (env);
}

void close_pipes(t_pipe *list_pipes)
{
	t_pipe	*tmp;

	tmp = list_pipes;
	while (tmp)
	{
		// if(tmp->fd[0] != )
		close(tmp->fd[0]);
		close(tmp->fd[1]);
		tmp = tmp->next;
	}
}

void	execute_command(t_command *command,	t_be_executed	*to_execute)
{
	char **env;
	// int	i = 0;
	// (void)i;

	assign_input(command, to_execute);
	assign_output(command, to_execute);
	dup2(command->fd_out, 1);
	dup2(command->fd_in, 0);
	close_pipes(command->list_pipes);
	env = give_array_str(*to_execute->env_list);
	close_pipes(command->list_pipes);
	// you should check if the command is executed or not 
	// if the commands args is null of empty doesn't execute the command
	if (ft_is_executed(command->command_args) == 0)
		exit(0);
	execve(command->path, command->command_args, env);
	print_error("minishell: ", command->command_args[0]);
	// why
	close_pipes(command->list_pipes);
	// close(command->fd_out);
	// close(command->fd_in);
	// close(1);
	// close(0);
	// exit(errno);
}
