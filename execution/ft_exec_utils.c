/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:45:50 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/22 15:07:20 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_no_file(char *command)
{
	write(2, "minishell: ", 11);
	write(2, command, ft_strlen(command));
	write(2, ": No such file or directory\n", 28);
	exit(127);
}
