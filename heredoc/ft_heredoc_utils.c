/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:17:46 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/19 14:35:38 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_re_open(t_heredoc **tmp)
{
	if (!tmp || !(*tmp))
		return ;
	close((*tmp)->fd);
	(*tmp)->fd = open((*tmp)->file_name, O_RDONLY);
	if ((*tmp))
		(*tmp) = (*tmp)->next;
}
