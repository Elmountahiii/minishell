/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:50:52 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/12 15:01:59 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *get_key_value(t_env_list *env_list, char *key)
{
	t_env_list *tmp;

	tmp = env_list;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, key) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

void basic_cd(char *path, t_be_executed	*to_execute, int procss)
{
	if (chdir(path) != -1)
	{
		add_to_env("OLDPWD", get_key_value(*to_execute->env_list, "PWD"), to_execute->env_list);
		add_to_env("PWD", getcwd(NULL, 0), to_execute->env_list);
		if (procss)
			exit(0);
		else
			exit_status = 0;
	}else{
		write(2, "minishell: cd: ", 15);
		write(2, path, ft_strlen(path));
		if (errno == ENOTDIR)
			write(2, ": Not a directory\n", 18);
		else if (errno == ENOENT)
			write(2, ": No such file or directory\n", 28);
		else if (errno == EACCES)
			write(2, ": Permission denied\n", 20);
		if (procss)
			exit(1);
		else
			exit_status = 1;
	}
}

void	our_cd(t_command *command, t_be_executed	*to_execute, int procss)
{
	char		**path;

	path = command->command_args;
	if (path[1] == NULL)
		basic_cd(get_key_value(*to_execute->env_list, "HOME"), to_execute, procss);
	else
		basic_cd(path[1], to_execute, procss);
}

