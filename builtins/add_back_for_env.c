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
	int			equal_index;

	node = malloc(sizeof(t_env_list));
	equal_index = ft_str_chr_index(str, '=');
	if (equal_index < 0)
	{
		write(1, "no equal sign\n", 14);
		return NULL;
	}
	node->key = ft_substr_orig(str, 0, equal_index);
	node->value = ft_substr_orig(str, equal_index + 1, ft_strlen(str));
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