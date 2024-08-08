/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:50:52 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/08 16:39:18 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *get_pwd_value(t_env_list *env_list)
{
	t_env_list *tmp;

	tmp = env_list;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, "PWD") == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

void	our_cd(t_command *command, t_be_executed	*to_execute, int procss)
{
	int			exit_sts;
	char		**path;

	exit_sts = 0;
	path = command->command_args;
	
	if (chdir(path[1]) != -1)
	{
		add_to_env("OLDPWD", get_pwd_value(*to_execute->env_list), to_execute->env_list);
		add_to_env("PWD", getcwd(NULL, 0), to_execute->env_list);
	}else{
		write(2, "minishell: cd: ", 10);
		write(2, path[1], ft_strlen(path[1]));
		if (errno == ENOTDIR)
			write(2, ": Not a directory\n", 18);
		else if (errno == ENOENT)
			write(2, ": No such file or directory\n", 28);
		else if (errno == EACCES)
			write(2, ": Permission denied\n", 20);
		if (procss)
			exit_sts = 1;
		else
			exit_status = 1;
	}
	if (procss)
		exit(exit_sts);
}

