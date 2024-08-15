/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:21:45 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/15 12:50:01 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_print_array(char **array)
{
	if (!array)
		return ;
	while (*array)
	{
		printf("'%s'\n", *array);
		array++;
	}
}
