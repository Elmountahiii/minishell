/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 09:57:35 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/20 12:10:33 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_list(t_command *list)
{
	int	i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}
