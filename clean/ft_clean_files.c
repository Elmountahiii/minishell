/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:22:46 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/12 16:45:57 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_clean_files(t_command_files *list_of_files)
{
	t_command_files	*tmp;
	
	while (list_of_files)
	{
		tmp = list_of_files;
		if (tmp)
		{
		if (tmp->fd > 2)
			close(tmp->fd);
		free(tmp->name);
			
		// free(tmp);
		}
		list_of_files = list_of_files->next;
	}
}
