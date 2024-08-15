/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:48:32 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/15 12:48:46 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_substrl(char  *s, int start, int len)
{
	char			*sub_str;
	int				s_len;
	int	i;

	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		return (strdup(""));
	}
	if (len >= ft_strlen(s + start))
	{
		return (strdup(s + start));
	}
	i = 0;
	sub_str = malloc(sizeof(char) * len + 1);
	if (!sub_str)
		return (NULL);
	while (s[start + i] && i < len)
	{
		sub_str[i] = s[start + i];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}