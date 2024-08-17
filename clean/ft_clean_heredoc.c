/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:39:04 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/17 16:47:11 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_clean_heredoc(t_heredoc **heredoc)
{
	t_heredoc	*tmp;

	if (!heredoc || !(*heredoc))
		return ;
	while ((*heredoc))
	{
		tmp = (*heredoc)->next;
		unlink((*heredoc)->file_name);
		free((*heredoc)->file_name);
		free((*heredoc)->dil);
		close((*heredoc)->fd);
		free((*heredoc));
		(*heredoc) = tmp;
	}
}
