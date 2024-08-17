/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:57:21 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/17 20:46:47 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_be_executed	*give_executed()
{
	t_be_executed	*to_execute;

	to_execute = ft_calloc(1,sizeof(t_be_executed));
	if (!to_execute)
		return (NULL);
	
	return (to_execute);
}

// count the len
