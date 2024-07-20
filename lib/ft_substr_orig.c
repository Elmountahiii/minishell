/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_orig.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:45:22 by aet-tale          #+#    #+#             */
/*   Updated: 2024/07/20 13:14:47 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*ft_substr_orig(char *s, unsigned int start, size_t len)
{
	size_t	sl;
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	sl = ft_strlen(s);
	if (start >= sl)
		len = 0;
	else if (start + len >= sl)
		len = sl - start;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}
