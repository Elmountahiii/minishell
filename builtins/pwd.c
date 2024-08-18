/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:46:10 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/15 12:46:41 by aet-tale         ###   ########.fr       */
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
		exit_status = 0;
	return ;
}
