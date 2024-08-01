/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_command_paths.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:50:49 by aet-tale          #+#    #+#             */
/*   Updated: 2024/07/30 14:51:26 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_check_path(t_env_list *env_list)
{
	while (env_list)
	{
		if (ft_strncmp(env_list->key, "PATH", 4) == 0)
			return (env_list->value);
		env_list = env_list->next;
	}
	return (NULL);
}

char	*search_for_path(char *command, t_env_list *env)
{
	char	**path_list;
	int		i;
	char	*path;
	// char	*env_path;

	i = 0;
	path_list = ft_split_dil(ft_check_path(env), ':');
	while (command && path_list && path_list[i])
	{
		path = ft_join_three(path_list[i], "/", command);
		if (access(path, F_OK) != -1 && access(path, X_OK) != -1)
		{
			ft_free_split(path_list, ft_split_count(path_list));
			return (path);
		}
		free(path);
		i++;
	}
	ft_free_split(path_list, ft_split_count(path_list));
	return (NULL);
}

void	fill_command_paths(t_command *command_list, t_env_list *env)
{
	char *cmd;

    while (command_list)
    {
		cmd = command_list->command_args[0];
		if (ft_strncmp(cmd, "./", 2) == 0 || ft_strncmp(cmd, "../", 3) == 0 || ft_strncmp(cmd, "/", 1) == 0)
			command_list->path = cmd;
		else
			command_list->path = search_for_path(cmd, env);
        command_list = command_list->next;   
    }
}

