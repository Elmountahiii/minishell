/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_back_for_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:42:50 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/15 10:42:51 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_str_chr_index(char *s, char c)
{
	int	i;
	int	length;

	i = 0;
	if (!s)
		return (-1);
	length = ft_strlen(s);
	while (i <= length)
	{
		if (s[i] == ((char)c))
			return (i);
		i++;
	}
	return (-1);
}

t_env_list	*creat_env_node(char *str)
{
	t_env_list	*node;
	char		*tmp;
	int			equal_index;

	if (ft_strncmp(str, "_=", 2) == 0)
		return (NULL);
	node = malloc(sizeof(t_env_list));
	equal_index = ft_str_chr_index(str, '=');
	tmp = NULL;
	node->key = ft_substr_orig(str, 0, equal_index);
	if (!ft_strncmp(str, "OLDPWD=", 7))
		node->value = NULL;
	else
		node->value = ft_substr_orig(str, equal_index + 1, ft_strlen(str));
	if (ft_strcmp(node->key, "SHLVL") == 0)
	{
		tmp = node->value;
		node->value = ft_itoa(ft_atoi(node->value) + 1);
		free(tmp);
	}
	node->next = NULL;
	return (node);
}

void	add_back_for_env(t_env_list	**list, char	*str)
{
	t_env_list	*tmp;

	tmp = *list;
	if (!(*list))
	{
		*list = creat_env_node(str);
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = creat_env_node(str);
}
