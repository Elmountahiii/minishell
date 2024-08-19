/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:46:10 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/19 14:46:50 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	our_pwd(t_command *command, t_be_executed	*to_execute, int procss)
{
	char	*pwd;

	(void)command;
	(void)to_execute;
	(void)procss;
	pwd = getcwd(NULL, 0);
	printf("%s\n", pwd);
	if (procss)
		exit(0);
	else
		g_exit_status = 0;
	return ;
}
