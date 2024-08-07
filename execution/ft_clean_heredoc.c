/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:52:16 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/06 11:42:36 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_clean_heredoc(t_command *command)
{
	if (!command)
		return ;
	unlink(command->in_file);
}
