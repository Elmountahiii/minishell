/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:50:52 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/03 15:36:31 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	our_cd(t_command *command, t_be_executed	*to_execute, int procss)
{
	int exit_sts;
	char **path;

	exit_sts = 0;
	path = command->command_args;
	add_to_env("OLDPWD", getcwd(NULL, 0), to_execute->env_list);
	chdir(path[1]);
	add_to_env("PWD", getcwd(NULL, 0), to_execute->env_list);
	if (procss)
		exit(exit_sts);
}

