/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_executed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:52:17 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/08 14:56:04 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_is_executed(t_list_files *files , int index)
{
	t_list_files	*tmp;

	tmp = files;
	while (tmp)
	{
		if (tmp->id == index)
		{
			if (tmp->fd == -1)
			{
				write(2, "minishell : ", 12);
				write(2, tmp->name, ft_strlen(tmp->name));
				write(2, ": No such file or directory\n", 28);
				// printf("minishell : %s: No such file or directory\n", tmp->name);
				return (0);
			}
		}
		tmp = tmp->next;
	}
	return (1);
}