/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:45:01 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/07 10:59:26 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_open_heredoc(t_heredoc *heredoc)
{
	heredoc->fd = open(heredoc->file_name, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (heredoc->fd < 0)
		perror("Error opening heredoc file");
}
