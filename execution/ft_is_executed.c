/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_executed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:52:17 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/07 12:58:08 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_is_executed(char **commands)
{
	int		i;
	
	if (!commands)
		return (0);
	i = 0;
	if (ft_strlen(commands[i]) == 0)
		return (0);
	return (1);
}