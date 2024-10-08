/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:50:23 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/19 14:37:54 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_print_heredoc(t_heredoc *heredoc)
{
	t_heredoc	*tmp;

	if (!heredoc)
		return ;
	tmp = heredoc;
	while (tmp)
	{
		printf("id:'%d' , fd:'%d' , file:'%s' , dil: '%s' , expand: '%s'\n",
			tmp->index, tmp->fd, tmp->file_name, tmp->dil,
			get_is_true(tmp->expand_line));
		tmp = tmp->next;
	}
}
