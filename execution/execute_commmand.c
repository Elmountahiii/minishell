/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commmand.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 12:42:46 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/15 15:32:12 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void print_error(char *prefix, char *command)
{
	// struct stat fileStat;
	
	// if (stat(command, &fileStat) == 0)
	// {
	// 	// perror(prefix);
		
	// 	printf("minishell : %s is a directory\n", command);
	// 	exit(127);
	// }
	
	write(2, prefix, ft_strlen(prefix));
	write(2, command, ft_strlen(command));
	write(2, ": ", 2);
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
        new_array[i] = ft_strdup(array[i]);
    }

    // Add the new string to the end of the new array
    new_array[len] = ft_strdup(str);

    // Set the last element to NULL
    new_array[len + 1] = NULL;

    //Free the old array
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

int is_directory(const char *path) {
    struct stat path_stat;
    if (stat(path, &path_stat) != 0) {
        perror("stat");
        return 0; // Return 0 if stat fails
    }
    return S_ISDIR(path_stat.st_mode);
}

void	execute_command(t_command *command,	t_be_executed	*to_execute)
{
	char	**env;
	char	**args;
	// int	i = 0;
	// (void)i;
	if (ft_is_executed(command) == 0)
	{
		close_pipes(to_execute->list_pipes);
		exit(1);
	}
	args = command->command_args;
	if (args == NULL || args[0] == NULL)
		exit(0);
	else if(command->path == NULL)
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
	//close_pipes(command->list_pipes);
	close_pipes(to_execute->list_pipes);
	env = give_array_str(*to_execute->env_list);
	execve(command->path, command->command_args, env);
	print_error("minishell: ", command->command_args[0]);
	if (errno == 13)
		exit(126);
	exit(127);
}
