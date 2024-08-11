/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 12:35:19 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/11 15:03:12 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_clean_heredoc(t_heredoc *list_heredoc)
{
	t_heredoc	*tmp;

	while (list_heredoc)
	{
		printf("cleaning heredoc\n");
		tmp = list_heredoc;
		unlink(tmp->file_name);
		close(tmp->fd);
		list_heredoc = list_heredoc->next;
		free(tmp->file_name);
		free(tmp->dil);
		free(tmp);
	}
}
