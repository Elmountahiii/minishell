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
	our_export("OLDPWD", getcwd(NULL, 0), to_execute->env_list, 0);
	chdir(path[1]);
	our_export("PWD", getcwd(NULL, 0), to_execute->env_list, 0);
	if (procss)
		exit(exit_sts);
}

