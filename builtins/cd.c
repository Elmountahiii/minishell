/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:50:52 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/02 17:50:53 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void our_cd(char	**path, t_env_list **env, int procss)
{
	int exit_sts;

	exit_sts = 0;
	// change the exit_sts
	our_export("OLDPWD", getcwd(NULL, 0), env, 0);
	chdir(path[1]);
	our_export("PWD", getcwd(NULL, 0), env, 0);
	// printf("%s\n", getcwd(NULL, 0));
	if (procss)
		exit(exit_sts);
}

