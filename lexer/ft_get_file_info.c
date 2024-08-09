/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:06:41 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/09 11:07:07 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_get_file_info(char *file_name)
{
	struct stat fileStat;

	if (stat(file_name, &fileStat) == 0)
	{
		if (S_ISDIR(fileStat.st_mode))
		{
			printf("minishell : %s is a directory\n", file_name);
			exit(127);
		}
	}
	return (0);
}