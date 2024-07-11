/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:49:20 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/16 12:06:01 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*ft_join_three(char *one, char *two, char *three)
{
	char	*join;
	char	*temp;

	if (!one || !two || !three)
		return (NULL);
	temp = ft_strjoin(one, two);
	join = ft_strjoin(temp, three);
	free(temp);
	return (join);
}
