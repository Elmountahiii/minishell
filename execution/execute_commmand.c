/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commmand.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 12:42:46 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/05 18:11:40 by aet-tale         ###   ########.fr       */
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
	// write(1, env[0], ft_strlen(env[0]));
	// write(1, "command->path\n", ft_strlen("command->path\n"));
	// printf("hh\n");
	// printf("kk %s\n", env[0]);
	// printf("pp\n");
	// printf("env[0]%s\n", env[0]);
	execve(command->path, command->command_args, env);
	print_error("minishell: ", command->command_args[0]);
	exit(errno);
}
