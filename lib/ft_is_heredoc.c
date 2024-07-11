/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:34:49 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/11 13:35:31 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_heredoc(char c, char *str)
{
	if (c == '<' && str && str[0] == '<')
		return (1);
	return (0);
}
