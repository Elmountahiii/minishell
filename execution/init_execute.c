/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:57:21 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/20 12:12:11 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_be_executed	*give_executed(void)
{
	t_be_executed	*to_execute;

	to_execute = ft_calloc(1, sizeof(t_be_executed));
	if (!to_execute)
		return (NULL);
	return (to_execute);
}
