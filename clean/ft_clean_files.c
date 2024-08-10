/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:22:46 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/10 13:08:11 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_clean_files(t_command_files *list_of_files)
{
	t_command_files	*tmp;

	while (list_of_files)
	{
		tmp = list_of_files;
		free(tmp->name);
		free(tmp);
		list_of_files = list_of_files->next;
	}
}
