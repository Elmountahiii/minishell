/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:50:52 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/19 14:46:50 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_key_value(t_env_list *env_list, char *key)
{
	t_env_list	*tmp;

	tmp = env_list;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, key) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

int	no_home(char *path, int procss)
{
	if (path == NULL)
	{
		write(2, "minishell: cd: HOME not set\n", 28);
		if (procss)
			exit(1);
		else
			g_exit_status = 1;
		return (1);
	}
	return (0);
}

int	check_pa(char *path, t_be_executed *to_execute, int procss)
{
	if (chdir(path) != -1)
	{
		add_to_env("OLDPWD", get_key_value(*to_execute->env_list, "PWD"),
			to_execute->env_list);
		add_to_env("PWD", getcwd(NULL, 0), to_execute->env_list);
		if (procss)
			exit(0);
		else
			g_exit_status = 0;
		return (1);
	}
	else
		return (0);
}

void	basic_cd(char *path, t_be_executed *to_execute, int procss)
{
	if (no_home(path, procss) || check_pa(path, to_execute, procss))
		return ;
	else
	{
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
			g_exit_status = 1;
	}
}

void	our_cd(t_command *command, t_be_executed *to_execute, int procss)
{
	char	**path;

	path = command->command_args;
	if (path[1] == NULL)
		basic_cd(get_key_value(*to_execute->env_list, "HOME"), to_execute,
			procss);
	else
		basic_cd(path[1], to_execute, procss);
}
