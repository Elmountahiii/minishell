/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:45:58 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/18 13:32:39 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_handle_expand_1(char *buffer, int *i, int *j, int *index)
{
	*j = ft_join_key(buffer, ft_itoa(exit_status), *j);
	(*i)++;
	(*index)++;
}

void	ft_count_1(int *len, int *index)
{
	char	*tmp;

	tmp = ft_itoa(exit_status);
	*len += ft_strlen(tmp);
	(*index)++;
	free(tmp);
}

void	ft_count_2(char *value, t_env_list *env, int *len)
{
	char	*tmp;

	tmp = ft_get_value(value, env);
	*len += ft_strlen(tmp);
	free(tmp);
}

void	ft_init_value(int *i, int *j, int *index)
{
	*i = 0;
	*j = 0;
	*index = 0;
}

void	ft_increment(int *i, int *j)
{
	(*i)++;
	(*j)++;
}
