/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ambig.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:44:33 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/15 19:59:12 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_all_spaces(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_ambig(t_command_files *files)
{
	if (!files)
		return (0);
	if (ft_array_len(files->files) > 1)
		return (1);
	// if (ft_all_spaces(files->files[0]))
	// 	return (1);
	
	return (0);
}