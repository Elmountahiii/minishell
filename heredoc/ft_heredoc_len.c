/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:19:08 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/19 14:35:53 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_count_heredoc(t_heredoc **heredoc_list)
{
	t_heredoc	*tmp;
	int			len;

	if (!heredoc_list || !*heredoc_list)
		return (0);
	len = 0;
	tmp = *heredoc_list;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}
