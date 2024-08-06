/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:45:01 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/06 11:37:56 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_open_heredoc(t_command *command)
{
	command->fd_in = open(command->in_file, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (command->fd_in < 0)
		perror("Error opening heredoc file");
}
