/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:18:37 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/23 15:03:41 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_is_path(char *cmd)
{
	if (ft_strncmp(cmd, "./", 2) == 0 || ft_strncmp(cmd, "../", 3) == 0
		|| ft_strncmp(cmd, "/", 1) == 0)
		return (1);
	return (0);
}

void	ft_check_path_correct(char *cmd)
{
	struct stat	filestat;

	if (stat(cmd, &filestat) == -1)
	{
		write(2, "minishell: ", 11);
		write(2, cmd, ft_strlen(cmd));
		write(2, ": ", 2);
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		write(2, "\n", 1);
		exit(127);
	}
	if (S_ISDIR(filestat.st_mode))
	{
		write(2, "minishell: ", 11);
		write(2, cmd, ft_strlen(cmd));
		write(2, ": is a directory\n", 17);
		exit(126);
	}
	if (access(cmd, X_OK) == -1)
	{
		write(2, "minishell: ", 11);
		write(2, cmd, ft_strlen(cmd));
		write(2, ": permission denied\n", 21);
		exit(126);
	}
}
