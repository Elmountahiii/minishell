/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_done.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:34:36 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/15 13:36:46 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_heredoc_done(t_heredoc *heredoc_list)
{
	t_heredoc	*tmp;

	if (!heredoc_list)
		return (0);
	tmp = heredoc_list;
	while (tmp)
	{
		if (tmp->done == false)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
