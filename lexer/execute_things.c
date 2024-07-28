/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_things.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:35:05 by aet-tale          #+#    #+#             */
/*   Updated: 2024/07/28 14:50:16 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


// void execute_one_command(t_command *command, t_list_files *list_of_files)
// {
// 	(void)command;
// 	(void)list_of_files;
// 	return;
// }

void execute_command(t_command *command, t_list_files *list_of_files)
{
	(void)command;
	(void)list_of_files;
	// get_command_path(command);
	return;
}

void execute_things(t_command *command_list, t_list_files *list_of_files)
{
	t_command	*tmp;
	tmp = command_list;

	// check for paths if one equals to NULL then the command does'nt exist
	// if (command_list->next == NULL)
	// {
	//	execute_one_command(command_list, list_of_files);
	// }
	while (tmp)
	{
		execute_command(tmp, list_of_files);
		tmp = tmp->next;
	}
}
